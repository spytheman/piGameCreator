#ifndef OPENEDPROJECT_H
#define OPENEDPROJECT_H

#include "../sharedcode/globals.h"
class gameproject;
class gcresource;
class OpenedProject
{
public:
    OpenedProject();
    gameproject* project;
    int selectedTarget;
    // selectedResource
};

#endif // OPENEDPROJECT_H
