#include "rsclass.h"
#include "gameproject.h"

rsClass::rsClass()
{
    valid = false;
}

QString rsClass::mainFolderName()
{
    return "classes";
}

QString rsClass::kind()
{
    return "class";
}

bool rsClass::addToProject(gameproject *p)
{
    if(p->isResource(name))return false;
    p->mClasses.append(this);
}
