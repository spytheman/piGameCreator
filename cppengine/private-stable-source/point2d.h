#ifndef POINT2D_H
#define POINT2D_H
#include "pgframework.h"


class gcObject;

class point2d
{
public:
	int x;
	int y;
	
/*
	Computes the distance between 2 points 
*/
	real distance(point2d* a, point2d* b);
	
/*
	Computes the distance between this point and object 
*/
	real distanceTo(gcObject* object);
};

#endif //POINT2D_H