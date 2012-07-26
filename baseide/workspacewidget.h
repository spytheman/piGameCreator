#ifndef WORKSPACEWIDGET_H
#define WORKSPACEWIDGET_H

#include <QString>
/*
    Workspace widgets can be inserted into the main window Workspace.
    They can also be an resource editors
*/
enum wwWidgetType {WT_TAB, WT_SUBWINDOW, WT_TOPLEVEL, WT_FULLSCREEN};
class QWidget;
class WorkspaceWidget
{
public:
    WorkspaceWidget();
    virtual bool isResourceEditor();    //false, do not overload
    void setTitle(QString);
    QString title();
    wwWidgetType WidgetType;
    QWidget* widget;
private:
    QString mTitle;
};

#endif // WORKSPACEWIDGET_H
