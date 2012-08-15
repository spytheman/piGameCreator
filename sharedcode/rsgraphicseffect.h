#ifndef RSGRAPHICSEFFECT_H
#define RSGRAPHICSEFFECT_H

#include "resource.h"

class rsGraphicsEffect: public gcresource
{
public:
    rsGraphicsEffect();
    QString mainFolderName();
    QString kind();
    bool addToProject(gameproject *p);
};

#endif // RSGRAPHICSEFFECT_H
