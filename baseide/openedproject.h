#ifndef OPENEDPROJECT_H
#define OPENEDPROJECT_H

#include <QProcess>
#include <QtNetwork/QTcpSocket>
#include "../sharedcode/globals.h"
#include "../sharedcode/resourcetree.h"

class gameproject;
class gcresource;
class OpenedProject: public QObject
{
    friend class MainWindow;
    Q_OBJECT

public:
    OpenedProject();
    ~OpenedProject();
    gameproject* project;
    int selectedTarget;
    ResourceTreeNode* selectedResource;

    // Tree states
    bool isProjectExpanded, isDashboardSelected;
    QList<ResourceTreeNode*> expandedResources;


};

#endif // OPENEDPROJECT_H
