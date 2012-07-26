#ifndef RSIMAGE_H
#define RSIMAGE_H

#include "resource.h"

class rsImage: public gcresource
{
public:
    rsImage();
    QString mainFolderName();
    QString kind();
};

#endif // RSIMAGE_H
