#include "resource.h"

gcresource::gcresource()
{
    //does nothing for now
    project = 0;
}
gcresource::~gcresource()
{
    gcprint("DELETING RESOURCE: "+name);
}

QString gcresource::relativeFolder()
{
    return mainFolderName() + "/" + name;
}

QString gcresource::fileName()
{
    return mainFolderName() + "/" + name + ".xml";
}

QString gcresource::mainFolderName()
{
    return "resources";
}

QString gcresource::kind()
{
    return "unknown";
}

bool gcresource::checkSourceFiles()
{
    gcprint("Checking source files of default Resource base...");
    return true;
}

bool gcresource::addToProject(gameproject *p)
{
    gcerror("AddToProject is not implemented for this raw class gcresource!");
}
