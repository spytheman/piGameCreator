#ifndef PHYSICSSIMULATOR_H
#define PHYSICSSIMULATOR_H
#include "pgframework.h"
#include "gcArray.h"


class gcObject;

class physicsSimulator
{
public:
	
/*
	how precise the simulation will be. May not be affected in some platforms. 
*/
	int precision;
	gcArray<gcObject*>* objects;
	
/*
	Adds an object to thee simulator. 
*/
	void addObject(gcObject* object);
	
/*
	Steps the simulation. 
*/
	void step();
	
/*
	If this is set to true, the simulator will not run. 
*/
	bool paused;
};

#endif //PHYSICSSIMULATOR_H