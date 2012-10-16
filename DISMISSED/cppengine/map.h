#ifndef MAP_H
#define MAP_H
#include "pgframework.h"
#include "gcString.h"
#include "variant.h"


class map
{
public:
	
/*
	Sets given value into given key . 
*/
	void set(gcString key, variant* value);
	
/*
	Gets the value stored into given key . If the key do not exists, exception will be thrown. 
*/
	variant* val(gcString key);
};

#endif //MAP_H
