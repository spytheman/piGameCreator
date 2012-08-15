#include "rsmodel.h"
#include "gameproject.h"

rsModel::rsModel()
{
}

QString rsModel::mainFolderName()
{
    return "models";
}

QString rsModel::kind()
{
    return "model";
}

bool rsModel::addToProject(gameproject *p)
{
    if(p->isResource(name))return false;
    p->mModels.append(this);
}
