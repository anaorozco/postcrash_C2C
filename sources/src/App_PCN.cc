/*
 * App_PCN.cc
 *
 *  Created on: 06/08/2012
 *      Author: Ana María Orozco
 */

//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "App_PCN.h"
#include "mobility/traci/TraCIMobility.h"
#include <PcnMsg_m.h>
#include <PcnInitialMsg_m.h>
#include <cmessage.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <stdexcept>
#include <list>
#include "BaseWaveApplLayer.h"
#include "Accident.h"
#include <omnetpp.h>

using namespace std;

Define_Module(App_PCN);

const simsignalwrap_t App_PCN::mobilityStateChangedSignal = simsignalwrap_t(MIXIM_SIGNAL_MOBILITY_CHANGE_NAME);

void App_PCN::initialize(int stage) {
	BaseWaveApplLayer::initialize(stage);
	if (stage == 0) {
		traci = TraCIMobilityAccess().get(getParentModule());
		findHost()->subscribe(mobilityStateChangedSignal, this);

		sentAccidentMsg = false;
		sentMessage = false;
		lastDroveAt = simTime();
		//appZone = 800;    // For PCN_App the application range (appZone) is 800m
		appZone = par("appZone");
		msgCont = 1;  	 // Getting parameter values from omnetpp.ini file and initialize variables
		accidentOccurred = false;
		accidentResolved = false;

		pcnAccidentPermit = par("pcnAccidentPermit");
		accidentMsgTimes = par("accidentMsgTimes");
		intervalMsg = par("intervalMsg");

		accidentSent = registerSignal("accidentSent");

		sendInitialMsg();  // Initialization message for network layer

		numberPacketReceivedAppl = registerSignal("numberPacketReceivedAppl");
		numberRxCounter = 0;

		WATCH(numSent);
	}
}


void App_PCN::onBeacon(WaveShortMessage* wsm) {}
void App_PCN::onData(WaveShortMessage* wsm) {}

void App_PCN::sendMessage() {

		PcnAccidentMsg* accidentMsg = new PcnAccidentMsg();
		const char* accidentStatus = "pcnAccident";
		accidentMsg->setAccidentStatus(accidentStatus);
		accidentMsg->setWamData("test_accident");
		accidentMsg->setPcnMsgID(msgCont);
		findHost()->getDisplayString().updateWith("r=16,red");

		Coord cur = traci->getCurrentPosition();
		Coord *currentPoint = &cur;
		Accident* acc = new Accident(currentPoint);
		bool inList = false;

		list<Accident*>::iterator pos;
		for(pos = accidentList.begin(); pos != accidentList.end(); ++pos){
			inList = (*pos)->compareCoord(acc);   // check if there is an Accident with the same coords
		}

		if(!inList){
			accidentList.push_front(acc);   // List that contains accidents record.
			DBG << " * * * * Accident alert stored with coordinates (x,y): "<< currentPoint->x << "," << currentPoint->y << endl;
		}

		BaseWaveApplLayer::sendDown(accidentMsg);
		double timeAccident = simTime().dbl();
		emit(accidentSent,timeAccident); // save time when a accidentMessage is sent, for stat

		DBG << " * * * * Accident msg sent (accidentMsgTimes): "<< msgCont<< endl;
		msgCont++;
		sentMessage = true;

}


void App_PCN::sendInitialMsg(){

	sentInitialMessage = true;
	PcnInitialMsg* initialMsg = new PcnInitialMsg();
	initialMsg->setAppZone(this->appZone);
	BaseWaveApplLayer::sendDown(initialMsg);   // Appl message for network layer
	DBG << " * * * InitialMessageSent in node"<< endl;
}


void App_PCN::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj) {
	Enter_Method_Silent();
	if (signalID == mobilityStateChangedSignal) {
		handlePositionUpdate();
	}
}

void App_PCN::handlePositionUpdate() {

	if (traci->getSpeed() < 1) {
		if ((simTime() - lastDroveAt >= 4) && (pcnAccidentPermit)) {    // original: (simTime() - lastDroveAt >= 10)
			if (!sentMessage){
				findHost()->getDisplayString().updateWith("r=16,green");
				scheduleAt(simTime(), new cMessage);
				accidentOccurred = true;
			}
		}
	}
	else {
		lastDroveAt = simTime();
		if(accidentOccurred && !accidentResolved){
			sendAccidentResolved();
		}
	}
}

void App_PCN::handleLowerMsg(cMessage* msg){

	PcnNotificationMsg* pcnNoti = dynamic_cast<PcnNotificationMsg*>(msg);
	string accStatus = pcnNoti -> getAccidentStatus();

	if (std::string(pcnNoti->getAccidentStatus()) == "pcnAccidentResolved") {
			findHost()->getDisplayString().updateWith("r=16,blue");

			Coord cordAcc = pcnNoti->getCoordinates();
			Coord *cordPoint = &cordAcc;
			Accident* accPoint = new Accident(cordPoint);

			list<Accident*>::iterator pos;
			bool inListResolved = false;

			for(pos = accidentList.begin(); pos != accidentList.end(); ++pos){
				inListResolved = ((*pos)->compareCoord(accPoint));   // check if there is an Accident with the same coords
				if(inListResolved) { break; }
			}

			if(inListResolved){
				(*pos)->resolved=true;
				DBG << " * * * * AccidentResolved updated with coordinates (x,y) is now Solved! "<< cordAcc.x << "," << cordAcc.y << endl;
			}



			DBG << " * * * * AccidentResolved message received with coordinates (x,y): "<< cordAcc.x << "," << cordAcc.y << endl;
		}

	else if (accStatus.compare(0,11,"pcnAccident") == 0){
		// app response to an accident

		numberRxCounter++;
		emit(numberPacketReceivedAppl,numberRxCounter);
		findHost()->getDisplayString().updateWith("r=16,yellow");
		bool inList = false;
		Coord cordAcc = pcnNoti->getCoordinates();
		Coord *cordPoint = &cordAcc;
		Accident* accPoint = new Accident(cordPoint);

		list<Accident*>::iterator pos;
		for(pos = accidentList.begin(); pos != accidentList.end(); ++pos){
			inList = (*pos)->compareCoord(accPoint);   // check if there is an Accident with the same coords
			if(inList){ break; }
		}

		if(!inList){
			accidentList.push_front(accPoint); // if inList = false, then add this accident notification
			DBG << " * * * * Accident alert stored with coordinates (x,y): "<< cordAcc.x << "," << cordAcc.y << endl;
		}

		DBG << " * * * * Accident alert in coordinates (x,y): "<< cordAcc.x << "," << cordAcc.y << endl;
	}

}

// define handleSelfMsg for timer use
void App_PCN::handleSelfMsg(cMessage* msg) {
	delete(msg);
	if(accidentMsgTimes>0){
		sendMsgTimer();
		accidentMsgTimes--;
	}
	DBG << "* * * * * Time waited before sending another message (intervalMsg) in seconds: " << intervalMsg << endl;

}

void App_PCN::sendMsgTimer(){
	sendMessage();
	scheduleAt(simTime() + intervalMsg,  new cMessage);
}

void App_PCN::sendAccidentResolved(){

	PcnAccidentMsg* accResolved = new PcnAccidentMsg();
	const char* accidentStatus = "pcnAccidentResolved";
	accResolved->setAccidentStatus(accidentStatus);
	accResolved->setWamData("test_accident");
	accResolved->setPcnMsgID(0);
	BaseWaveApplLayer::sendDown(accResolved);
	accidentResolved = true;
	DBG << " * * * * AccidentResolved sent "<< endl;

}

