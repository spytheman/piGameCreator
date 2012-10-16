#ifndef OBJECTREPRESENTATION_H
#define OBJECTREPRESENTATION_H
#include "pgframework.h"
#include "gcString.h"


class rectangle;

class objectRepresentation
{
public:	gcString type();

	
/*
	Sets a rectangle representation 
*/
	void setRectangle(rectangle* r);
	
/*
	Sets a text representation 
*/
	void setText(gcString Text = "");
};

#endif //OBJECTREPRESENTATION_H