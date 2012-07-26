#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "pgframework.h"
#include "gcString.h"



class exception
{
public:
	
/*
	Returns a string containing the exception text. 
*/
	gcString gcToString();
	
/*
	Creates an exception instance, which text is set to the given string. 
*/
	exception* gcFromString();
	
/*
	The type of exception. This field if useful for exception handling 
*/
	gcString type;
	
/*
	Contains data about the exception. For example, a division by zero exception may contain the divisible 
*/
	gcString data;
	
/*
	This text describes the exception and must be as user-friendly as possible. 
*/
	gcString text;
	
/*
	Throws this exception. 
	To simplify development you can also use the global throw() function. 
*/
	void gcThrow();
};

#endif //EXCEPTION_H