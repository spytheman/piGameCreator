#include "openedproject.h"

OpenedProject::OpenedProject()
{
    selectedTarget = 0;
    project = 0;
}

OpenedProject::~OpenedProject()
{
    if(project) delete project;
}