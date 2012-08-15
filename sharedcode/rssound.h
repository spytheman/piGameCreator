#ifndef RSSOUND_H
#define RSSOUND_H

#include "resource.h"

class rsSound: public gcresource
{
public:
    rsSound();
    QString mainFolderName();
    QString kind();
    bool addToProject(gameproject *p);
};

#endif // RSSOUND_H
