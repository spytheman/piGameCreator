#include "openedproject.h"
#include "gcide.h"
#include <QTimer>
#include <QHostAddress>

OpenedProject::OpenedProject()
{
    selectedTarget = 0;
    project = 0;
}

OpenedProject::~OpenedProject()
{
    if(project) delete project;
}
