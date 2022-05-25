/*
 * DrgLayer.cpp
 *
 *  Created on: 10/07/2012
 *      Author: Roger Michoud, Ana María Orozco
 */

#include "DrgLayer.h"
#include "Accident.h"
#include "mobility/traci/TraCIMobility.h"
#include "modules/application/traci/TraCIDemo11p.h"
#include <string.h>
#include <math.h>
#include <string>
#include <omnetpp.h>

using namespace std;


// Define the module as a .ned
Define_Module(DrgLayer);



//const of the classes
const simsignalwrap_t DrgLayer::mobilityStateChangedSignal = simsignalwrap_t(MIXIM_SIGNAL_MOBILITY_CHANGE_NAME);
double range, accidentX,accidentY,accidentZ;
double distanceAcc = -1;


//initialize function
void DrgLayer::initialize(int stage) {
	BaseWaveApplLayer::initialize(stage);

	if (stage == 0) {
			traci = TraCIMobilityAccess().get(getParentModule());
			findHost()->subscribe(mobilityStateChangedSignal, this);

			sentMessage = false;
			lastDroveAt = simTime();
			ownAccidentBool = false;
			wsmSentCounter = 0;
			wsmReceivedCounter = 0;
			accidentFlag = false;

			// stat signals
			geocastAlgorithm = registerSignal("algorithm");
			geocastPacketRx = registerSignal("geocastPacketRx");
			timeAccidentReceived = registerSignal("timeAccidentReceived");
			timeAccidentAnnounced = registerSignal("timeAccidentAnnounced");
			distanceToAccident = registerSignal("distanceToAccident");
			numberPacketSent = registerSignal("numberPacketSent");
			numberPacketReceived = registerSignal("numberPacketReceived");
			currentDist = registerSignal("currentDist");
		}

}

//function to browse and find a element in the list
bool DrgLayer::searchForwardedMsg(Accident* toFind){

	if (forwardedAcc.empty()){return false;}
	else {

		//creating the iterators

		list<Accident*>::iterator pos;
		for(pos = forwardedAcc.begin(); pos != forwardedAcc.end(); ++pos){
				Accident* test = *pos;
				if(toFind->compare(test)){
					return true;
				}
		}
	}
	return false;
}

// Signal function (traci)
void DrgLayer::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj) {
	Enter_Method_Silent();
	if (signalID == mobilityStateChangedSignal) {
		handlePositionUpdate(obj);
	}
}


// position handler (mobility)
void DrgLayer::handlePositionUpdate(cObject* obj) {
	ChannelMobilityPtrType const mobility = check_and_cast<ChannelMobilityPtrType>(obj);
	curPosition = mobility->getCurrentPosition();
	registerPosition();
}

void DrgLayer::registerPosition(){

	if(simTime()==406.8){
	Coord coordAcc = new Coord(4755.11,11022.1,1.895);
	double distAcc = curPosition.distance(coordAcc);
	emit(currentDist,distAcc);
	}
}



// message handler (lower,self,upper)
void DrgLayer::handleLowerMsg(cMessage* msg) {

	WaveShortMessage* wsm = dynamic_cast<WaveShortMessage*>(msg);
	ASSERT(wsm);
	std::string typeAccident = wsm->getName();

	if (std::string(wsm->getName()) == "beacon") {
		onBeacon(wsm);
	}
	else if (std::string(wsm->getName()) == "data") {
		onData(wsm);
	}

	if(std::string(wsm->getName())== "pcnAccident"){
		wsmReceivedCounter++;    // MALDITA METRICA
		emit(numberPacketReceived,wsmReceivedCounter);  // MALDITA METRICA

	}
	// Wsm carrying the PCN application packet
	/*else if(typeAccident.compare("pcnAccidentResolved")==0){
		Coord * accidentPos;
		bool isAccidentInList = false;
		accidentPos = &(wsm->getSenderPos());
		// AccidentResolved --> msgId = 0;
		int msgId = 0;
		Accident* receivedAcc = new Accident(accidentPos,msgId);

		//check if the accidentResloved has already been forwarded
		if (!(searchForwardedMsg(receivedAcc))){
				//forward of accidentResolved msg and add to the list
				list<Accident*>::iterator pos;
				for(pos = forwardedAcc.begin(); pos != forwardedAcc.end(); ++pos){
					//Accident* test = *pos;
					if((*pos)->compareCoord(receivedAcc)){
						pos = forwardedAcc.erase(pos);
						--pos;
					}
				}

				forwardedAcc.push_front(receivedAcc);
				WaveShortMessage * newWsm = wsm->dup();
				sendApplMsg(wsm->getName(),wsm->getSenderPos());
				sendWSM(newWsm);
		}
	}*/

	else if (typeAccident.compare(0,11,"pcnAccident") == 0){

		//test if accident is in the list
		Coord * accidentPos;
		accidentPos = &(wsm->getSenderPos());
		// how to get it from the string
		int stringSize = typeAccident.length();
		int msgId = (int)typeAccident[stringSize-1];
		Accident* receivedAcc = new Accident(accidentPos,msgId);
		// stat collection for PacketRatio test:
		double receivedTime = simTime().dbl();

		emit(timeAccidentReceived,receivedTime);
		emit(geocastPacketRx,true);



		if(!(searchForwardedMsg(receivedAcc))){

			//adding the accident to the list
			forwardedAcc.push_front(receivedAcc);

			sendApplMsg(wsm->getName(),wsm->getSenderPos());



			// forwarding decision
			if (routingDecision(wsm)){
				WaveShortMessage * newWsm = wsm->dup();
				//actual forwarding
				sendWSM(newWsm);
			}
		}
	}

	//if we received from the network a message accidentResolved remove from the list (if it is in the list)

	else {
		DBG << "unknown message (" << wsm->getName() << ")  received\n";
	}
	delete(wsm);

}

void DrgLayer::handleSelfMsg(cMessage* msg) {
	switch (msg->getKind()) {
		case SEND_BEACON_EVT: {
			sendWSM(prepareWSM("beacon", beaconLengthBits, type_CCH, beaconPriority, 0, -1));
			scheduleAt(simTime() + par("beaconInterval").doubleValue(), sendBeaconEvt);
			break;
		}
		default: {
			if (msg)
				DBG << "APP: Error: Got Self Message of unknown kind! Name: " << msg->getName() << endl;
			break;
		}
	}
}

void DrgLayer::handleUpperMsg(cMessage* msg){

	// cast in WaveAppMsg
	WaveAppMsg* wApp = dynamic_cast<WaveAppMsg*>(msg);

	//the type of the WaveAppMsg define which kind of WaveAppMsg is
	switch(wApp->getApplicationType()){

	case 1: {
		PcnMsg* pMsg = dynamic_cast<PcnMsg*>(wApp);
		const char* str = pMsg->getPcnTypeMsg();
		string typeMsg(str);
		DBG << "Type of msg: " << pMsg->getPcnTypeMsg() << endl;
		if(typeMsg.compare("i") == 0){
				//strcmp ("i",pMsg->getPcnTypeMsg())){
			DBG << "Initial Msg catched" << endl;
			PcnInitialMsg* initMsg = dynamic_cast<PcnInitialMsg*>(pMsg);
			initPcn(initMsg);
		}
		else if(typeMsg.compare("a")== 0){
				 //strcmp (pMsg->getPcnTypeMsg(),"a")){
			DBG << "Accident Msg catched" << endl;
			PcnAccidentMsg* pcnAcc = dynamic_cast<PcnAccidentMsg*>(pMsg);
			accPcn(pcnAcc);
		}
		else{
		DBG <<"Unknown type of Pcn message" << endl;
		}
		break;
	}
	default : DBG <<"DRG application type error : Unknown type of WaveAppMsg " << endl;
	break;
	}
}



// Type of message and routing decision
void DrgLayer::initPcn(PcnInitialMsg* initPcn){
	// range for routing Decision
	range = initPcn->getAppZone();
	DBG << " * * * InitialMessageReceived in node"<< endl;
	delete(initPcn);


}

void DrgLayer::accPcn(PcnAccidentMsg* pcnAcc){
	//std::string stateAccident = pcnAcc->getAccidentStatus();
	sentMessage = false;
	const char* str = pcnAcc->getAccidentStatus();
	int msgId = pcnAcc->getPcnMsgID();
	string stateAccident(str);



	//if it is an accidentResolve msg -> remove it from the list
	if ((stateAccident.compare("pcnAccidentResolved")==0)){
		ownAccidentBool = true;
		Accident* ownAccident = new Accident(&ownAccidentCoord,msgId);
		DBG << "Coord of accidentResolved msg  (x,y): " << ownAccidentCoord.x << "," << ownAccidentCoord.y << endl;
		//check if it is in the list
		list<Accident*>::iterator pos;
		for(pos = forwardedAcc.begin(); pos != forwardedAcc.end(); ++pos){
				//Accident* test = *pos;
				DBG << "AccidentResolved coord comparation accPcn "<< endl;
				if((*pos)->compareCoord(ownAccident)){
					DBG << "Enter in comparation if"<< endl;
					pos = forwardedAcc.erase(pos);
					--pos;
				}
		}
		//adding to msg list the accidentResolved
		forwardedAcc.push_front(ownAccident);
	}


	//if it is an accident msg -> check if it is already in the list, else add it
	else if ((stateAccident.compare(0,11,"pcnAccident"))==0){
		ownAccidentCoord = curPosition;
		ownAccidentBool = true;
		Accident* ownAccident = new Accident(&ownAccidentCoord,msgId);

		;
		DBG << "assignation of ownAccidentCoord" << endl;
		if(!(searchForwardedMsg(ownAccident))){
				forwardedAcc.push_front(ownAccident);
		}
	}



	//add the msgId to the string sent in the WSM packet
	char msgIdChar = (char)msgId;
	//char numstr[msgId]; // enough to hold all numbers up to 64-bits
	//sprintf(numstr, "%d", msgId);
	//stateAccident = stateAccident + numstr;
	stateAccident.push_back(msgIdChar);

	//findHost()->getDisplayString().updateWith("r=16,green");
	if (!sentMessage){
			sendMessage(stateAccident);
			emit(timeAccidentAnnounced,simTime().dbl());
		}
	delete(pcnAcc);

}

bool DrgLayer::routingDecision(WaveShortMessage* wsm){
	Coord accidentPos = wsm->getSenderPos();


	//calculus to know if it is in the ZOF

	//ZOF - ZOR
	double margin = 0;  // must be al least 200m
	double zof = range + margin;
	double deltaX = abs(accidentPos.x - curPosition.x);
	double deltaY = abs(accidentPos.y - curPosition.y);
	double dist = sqrt(pow(deltaX,2)+pow(deltaY,2));

	accidentX = accidentPos.x;
	accidentY = accidentPos.y;
	accidentZ = accidentPos.z;

	accidentFlag = true;

	double distCoord = curPosition.distance(accidentPos);
	// stats
	double distance = dist;
	emit(distanceToAccident,distance);
	distanceAcc = distCoord;

	if (distCoord<zof){
		emit(geocastAlgorithm, distCoord);
		return true;
	}
	else {return false;}
}



// Sending procedures
void DrgLayer::sendApplMsg(const char* accidentStatus,Coord& accidentPos){
	// app packet to send to upper layer
	PcnNotificationMsg* notiMsg = new PcnNotificationMsg();
	notiMsg->setAccidentStatus(accidentStatus);
	notiMsg->setCoordinates(accidentPos);
	sendUp(notiMsg);
}

void DrgLayer::sendWSM(WaveShortMessage* wsm) {

	wsmSentCounter++;
	// emitir señal wsmSentCounter
	emit(numberPacketSent,wsmSentCounter);
	sendDelayedDown(wsm,individualOffset);
}

void DrgLayer::sendMessage(std::string accidentStatus) {
	sentMessage = true;
	t_channel channel = dataOnSch ? type_SCH : type_CCH;
	sendWSM(prepareWSM(accidentStatus, dataLengthBits, channel, dataPriority, -1,2));
}



//Msg WSM preparation
WaveShortMessage*  DrgLayer::prepareWSM(std::string name, int lengthBits, t_channel channel, int priority, int rcvId, int serial) {
	WaveShortMessage* wsm =		new WaveShortMessage(name.c_str());
	//wsm->addBitLength(headerLength);
	//wsm->addBitLength(lengthBits);
	//WaveShortMessage* wsm =		new WaveShortMessage("pcnAccident");
	wsm->addBitLength(256);
	wsm->addBitLength(320);
	switch (channel) {
		case type_SCH: wsm->setChannelNumber(Channels::SCH1); break; //will be rewritten at Mac1609_4 to actual Service Channel. This is just so no controlInfo is needed
		case type_CCH: wsm->setChannelNumber(Channels::CCH); break;
	}
	wsm->setPsid(0);
	wsm->setPriority(priority);
	wsm->setWsmVersion(1);
	wsm->setTimestamp(simTime());
	wsm->setSenderAddress(myId);
	wsm->setRecipientAddress(rcvId);

	if(ownAccidentBool){
		DBG << "Coord of accidentResolved wsm packet x: " << ownAccidentCoord.x << " y: " << ownAccidentCoord.y << endl;
		wsm->setSenderPos(ownAccidentCoord);
		ownAccidentBool = false;

	}
	else{
		wsm->setSenderPos(curPosition);
	}
	wsm->setSerial(serial);

	if (name == "beacon") {
		DBG << "Creating Beacon with Priority " << priority << " at Applayer at " << wsm->getTimestamp() << std::endl;
	}
	if (name == "data") {
		DBG << "Creating Data with Priority " << priority << " at Applayer at " << wsm->getTimestamp() << std::endl;
	}

	return wsm;
}



// Finish and destructor
void DrgLayer::finish() {
	if (sendBeaconEvt->isScheduled()) {
		cancelAndDelete(sendBeaconEvt);
	}
	else {
		delete sendBeaconEvt;
	}
}

DrgLayer::~DrgLayer() {

}

//unused functions
void DrgLayer::onBeacon(WaveShortMessage* wsm){};
void DrgLayer::onData(WaveShortMessage* wsm){};

