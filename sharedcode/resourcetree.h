#ifndef RESOURCETREE_H
#define RESOURCETREE_H

#include "resource.h"
//This class must act as a tree containing resources and folders.

struct ResourceTreeNode
{
    QString name, kind;
    gcresource* resource;
    bool folder;

    //If root is true NO recursive destruction will occur
    bool root;

    QList<ResourceTreeNode*> childs;
    ResourceTreeNode();
    ~ResourceTreeNode();
};

#endif // RESOURCETREE_H
