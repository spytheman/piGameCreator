#include "resourcetree.h"

ResourceTreeNode::ResourceTreeNode()
{
    resource = NULL;
    folder = false;
    root = false;
}

ResourceTreeNode::~ResourceTreeNode()
{
    if(resource)
        gcprint("Deleting " + resource->kind() + ": " +resource->name + "\n");
    else gcprint("Deleting NULL tree node");
    if(folder && !root)
        qDeleteAll(childs);
}
