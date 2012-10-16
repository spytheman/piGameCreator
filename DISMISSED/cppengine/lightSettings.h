#ifndef LIGHTSETTINGS_H
#define LIGHTSETTINGS_H
#include "pgframework.h"



class lightSettings
{
public:	
/*
	Disables the lighting system and stops rendering any light. 
*/
	static void disable();
	
/*
	Enables the lighting system and initializes it. 
	Returns wheither success or not. 
	
	Lighting system may not be supported on some platforms, for example, the web browsers or some mobile phones so you must always check if the initialization completes. 
*/
	static bool enable();

	
/*
	The object will be rendered without any lighting effects. It will not receive shadows or light contributions and will not cast shadows. 
*/
	bool fullBright;
	
/*
	If set, the object will block the light and cast a shadow. 
*/
	bool castShadow;
};

#endif //LIGHTSETTINGS_H