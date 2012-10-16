#ifndef POINT_H
#define POINT_H
#include "pgframework.h"



class point
{
public:
	real x;
	real y;
	real z;
	
/*
	Computes the distance between 2 points 
*/
	static real distance(point* a, point* b);
	
/*
	Computes the distance between this point and object 
*/
	real distanceTo(point* p);
};

#endif //POINT_H