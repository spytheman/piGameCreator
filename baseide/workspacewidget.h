#ifndef WORKSPACEWIDGET_H
#define WORKSPACEWIDGET_H

#include <QString>
#include <QTabWidget>
#include <QMainWindow>
/*
    Workspace widgets can be inserted into the main window Workspace.
    They can also be an resource editors
*/
enum wwWidgetType {WT_TAB, WT_SUBWINDOW, WT_TOPLEVEL, WT_FULLSCREEN};
class QWidget;
class WorkspaceWidget
{
    friend class MainWindow;
public:
    WorkspaceWidget();
    ~WorkspaceWidget();
    virtual bool isResourceEditor();    //false, do not overload
    virtual void afterOpen();
    void setTitle(QString);
    QString title();
    wwWidgetType WidgetType;
    QWidget* widget;
    QTabWidget* tabWidget;
    QMainWindow* mainWindow;
private:
    QString mTitle;
    bool shouldSetTabTitle;
};

#endif // WORKSPACEWIDGET_H
