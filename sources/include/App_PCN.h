/*
 * App_PCN.h
 *
 *  Created on: 09/07/2012
 *      Author: Ana María Orozco
 */

#ifndef APP_PCN_H_
#define APP_PCN_H_

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


#include "BaseWaveApplLayer.h"
#include "mobility/traci/TraCIMobility.h"
#include <PcnMsg_m.h>
#include <PcnInitialMsg_m.h>
#include <PcnAccidentMsg_m.h>
#include <PcnNotificationMsg_m.h>
#include <iostream>
#include <string>
#include <list>
#include "Accident.h"
#include <omnetpp.h>

using namespace std;

/**
 * PCN Application
 */
class App_PCN : public BaseWaveApplLayer {

	public:
		virtual void initialize(int stage);

	public:
		static const simsignalwrap_t mobilityStateChangedSignal;

	public:
		TraCIMobility* traci;
		simtime_t lastDroveAt;
		double appZone;
		bool sentMessage, sentAccidentMsg,pcnAccidentPermit;
		bool sentInitialMessage, accidentOccurred, accidentResolved;
		int accidentMsgTimes, intervalMsg, msgCont, numberRxCounter;
		list<Accident*> accidentList;
		int numSent, numReceived;
		simsignal_t accidentSent, numberPacketReceivedAppl;

	public:
		virtual void onBeacon(WaveShortMessage* wsm);
		virtual void onData(WaveShortMessage* wsm);

		void sendMessage();
		void sendInitialMsg();

		virtual void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj);
		void handlePositionUpdate();
		void handleLowerMsg(cMessage* msg);

		void handleSelfMsg(cMessage* msg);
		void sendMsgTimer();
		void sendAccidentResolved();

};

#endif /* APP_PCN_H_ */
