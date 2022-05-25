/*
 * Accident.h
 *
 *  Created on: 10/08/2012
 *      Author: Ana Maria Orozco
 */

#ifndef ACCIDENT_H_
#define ACCIDENT_H_
#include "mobility/traci/TraCIMobility.h"
#include "modules/application/traci/TraCIDemo11p.h"

class Accident {
public:
	Accident(Coord* c, int id);
	Accident(Coord* c);
	virtual ~Accident();

public:
	Coord* accidentCoord;
	int msgId;
	bool resolved;

	bool compare(Accident* a);
	bool compareCoord(Accident* a);
};

#endif /* ACCIDENT_H_ */
