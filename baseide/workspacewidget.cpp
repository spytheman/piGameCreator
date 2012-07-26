#include "workspacewidget.h"

WorkspaceWidget::WorkspaceWidget()
{
    widget = (QWidget*)this;
}

bool WorkspaceWidget::isResourceEditor()
{
    return false;
}

void WorkspaceWidget::setTitle(QString t)
{
    mTitle = t;
    //if tab, set the tab title,
    //if subwindow, set its title,
    //if top level window, set its title.
}

QString WorkspaceWidget::title()
{
    return mTitle;
}
