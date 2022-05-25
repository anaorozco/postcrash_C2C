/*
 * DrgLayer.h
 *
 *  Created on: 10/07/2012
 *      Author: Roger Michoud, Ana Mar�a Orozco
 */

#ifndef DRGLAYER_H_
#define DRGLAYER_H_

#include "BaseWaveApplLayer.h"
#include "mobility/traci/TraCIMobility.h"
#include "PcnAccidentMsg_m.h"
#include "PcnInitialMsg_m.h"
#include "PcnNotificationMsg_m.h"
#include <list>
#include <vector>
#include <iostream>
#include "Accident.h"
#include <omnetpp.h>

using namespace std;

class DrgLayer : public BaseWaveApplLayer {
public:
		void initialize(int stage);
		double range, distanceAcc, accidentX,accidentY,accidentZ;
		list<Accident*> forwardedAcc;
		Coord ownAccidentCoord; //if this module have an accident, accident coordonate.
		bool ownAccidentBool;


	protected:
		static const simsignalwrap_t mobilityStateChangedSignal;

	protected:
		TraCIMobility* traci;
		simtime_t lastDroveAt;
		simsignal_t geocastAlgorithm ,geocastPacketRx, timeAccidentReceived,
		timeAccidentAnnounced, distanceToAccident, numberPacketSent, numberPacketReceived,
		currentDist;
		bool sentMessage, accidentFlag;
		std::string typeMsg;
		int wsmSentCounter,wsmReceivedCounter;

	protected:
		virtual void onBeacon(WaveShortMessage* wsm);
		virtual void onData(WaveShortMessage* wsm);
		void sendMessage(std::string accidentStatus);
		bool routingDecision(WaveShortMessage* wsm);
		void sendApplMsg(const char* accidentStatus,Coord& accidentPos);
		void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj);
		void handlePositionUpdate();
		bool searchForwardedMsg(Accident* toFind);


	public:
		virtual ~DrgLayer();

		WaveShortMessage* prepareWSM(std::string name, int lengthBits, t_channel channel, int priority, int rcvId, int serial);

		void handlePositionUpdate(cObject* obj);
		void handleLowerMsg(cMessage* msg);
		void handleSelfMsg(cMessage* msg);
		void handleUpperMsg(cMessage* msg);
		void initPcn(PcnInitialMsg* initPcn);
		void accPcn(PcnAccidentMsg* pcnAcc);
		void sendWSM(WaveShortMessage* wsm);
		void finish();
		void registerPosition();
};

#endif /* DRGLAYER_H_ */
