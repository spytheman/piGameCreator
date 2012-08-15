#include "rsgraphicseffect.h"
#include "gameproject.h"

rsGraphicsEffect::rsGraphicsEffect()
{
}

QString rsGraphicsEffect::mainFolderName()
{
    return "graphicseffects";
}

QString rsGraphicsEffect::kind()
{
    return "graphicseffect";
}

bool rsGraphicsEffect::addToProject(gameproject *p)
{
    if(p->isResource(name))return false;
    p->mGraphicsEffects.append(this);
}
