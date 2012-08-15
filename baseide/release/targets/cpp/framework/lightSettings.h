#ifndef LIGHTSETTINGS_H
#define LIGHTSETTINGS_H
#include "pgframework.h"



class lightSettings
{
public:
	
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