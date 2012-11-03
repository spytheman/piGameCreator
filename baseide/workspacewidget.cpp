// MUST NOT depend of the Creator IDE!

#include "../sharedcode/messageevent.h"
#include "workspacewidget.h"
#include <QWidget>
#include <QVariant>
#include <QApplication>

WorkspaceWidget::WorkspaceWidget()
{
    widget = (QWidget*)this;
    shouldSetTabTitle = false;
}

WorkspaceWidget::~WorkspaceWidget()
{
    //remove from the haxe command event queue
    //creatorIDE->removeHxQueryReceiver(dynamic_cast<QObject*>(this));
    QObject* obj = dynamic_cast<QObject*>(widget);
    qApp->sendEvent(mainWindow,new messageEvent("hx_del_recv",qVariantFromValue((void*)obj),obj));
}

bool WorkspaceWidget::isResourceEditor()
{
    return false;
}

void WorkspaceWidget::setTitle(QString t)
{
    mTitle = t;
    if(shouldSetTabTitle)
        for(int i=0;i<tabWidget->count();++i)
        {
            WorkspaceWidget* w =  (WorkspaceWidget*) tabWidget->widget(i)->property("WorkspaceWidget").value<void*>();
            if(w==this)
                tabWidget->setTabText(i," "+t);
        }
    //if tab, set the tab title,
    //if subwindow, set its title,
    //if top level window, set its title.
}

QString WorkspaceWidget::title()
{
    return mTitle;
}

void WorkspaceWidget::afterOpen()
{
    return;
}
