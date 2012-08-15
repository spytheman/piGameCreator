#ifndef RSMODEL_H
#define RSMODEL_H

#include "resource.h"

class rsModel:public gcresource
{
public:
    rsModel();
    QString mainFolderName();
    QString kind();
    bool addToProject(gameproject *p);
};

#endif // RSMODEL_H
