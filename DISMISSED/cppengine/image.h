#ifndef IMAGE_H
#define IMAGE_H
#include "pgframework.h"
#include "gcArray.h"
#include "objectRepresentation.h"


class texture;

class image: public objectRepresentation
{
public:
	gcArray<texture*>* frames;
	real animationSpeed;
};

#endif //IMAGE_H