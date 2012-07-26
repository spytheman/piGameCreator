#ifndef RSMODEL_H
#define RSMODEL_H

#include "resource.h"

class rsModel:public gcresource
{
public:
    rsModel();
    QString mainFolderName();
    QString kind();
};

#endif // RSMODEL_H
