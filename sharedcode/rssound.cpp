#include "rssound.h"
#include "gameproject.h"

rsSound::rsSound()
{
}

QString rsSound::mainFolderName()
{
    return "sounds";
}

QString rsSound::kind()
{
    return "sound";
}

bool rsSound::addToProject(gameproject *p)
{
    //if(p->isResource(name))return false;
    //p->mSounds->childs.append( (gcresource*)this);
}
