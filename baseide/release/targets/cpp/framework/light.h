#ifndef LIGHT_H
#define LIGHT_H
#include "pgframework.h"



class light
{
public:
	
/*
	Enables the lighting system and initializes it. 
	Returns wheither success or not. 
	
	Lighting system may not be supported on some platforms, for example, the web browsers or some mobile phones so you must always check if the initialization completes. 
*/
	static bool enable();
	
/*
	Disables the lighting system and stops rendering any light.
*/
	static void disable();
};

#endif //LIGHT_H