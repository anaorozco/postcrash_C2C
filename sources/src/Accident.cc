/*
 * Accident.cpp
 *
 *  Created on: 10/08/2012
 *      Author: Ana Maria Orozco
 */

#include "Accident.h"
#include "mobility/traci/TraCIMobility.h"
#include "modules/application/traci/TraCIDemo11p.h"

Accident::Accident(Coord* c, int id) {
	this->accidentCoord = c;
	this->msgId = id;  // For accidentResolved messages ID = 0, for the others, Id > 0
	this->resolved = false;
}

Accident::Accident(Coord* c) {
	this->accidentCoord = c;
	this->msgId = 0;
	this->resolved = false;
}

bool Accident::compare(Accident* a){
	if(accidentCoord->x == a->accidentCoord->x && accidentCoord->y == a->accidentCoord->y &&
			msgId == a->msgId){return true;}
	else{
		return false;
	}
}

bool Accident::compareCoord(Accident* a){
	if(accidentCoord->x == a->accidentCoord->x && accidentCoord->y == a->accidentCoord->y){return true;}
		else{
			return false;
		}
}

Accident::~Accident() {
	// TODO Auto-generated destructor stub
}
