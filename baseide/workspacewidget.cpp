#include "workspacewidget.h"
#include <QWidget>
#include <QVariant>

WorkspaceWidget::WorkspaceWidget()
{
    widget = (QWidget*)this;
    shouldSetTabTitle = false;
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
