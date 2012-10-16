#ifndef PATH_H
#define PATH_H

#include "pgframework.h"
#include "gcArray.h"


class point;
class path
{
public:		bool isClosed;
gcArray<point*>* points;

};

#endif //PATH_H
