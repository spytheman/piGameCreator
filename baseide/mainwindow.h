#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QModelIndex>
#include <QComboBox>

namespace Ui {
class MainWindow;
}
class OpenedProject;
class WorkspaceWidget;
class gcresource;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent *);
    void openWorkspaceWidget(WorkspaceWidget* w);
    QComboBox *targetsCB;
    QMenu* SkinsMenu;
    //void updateResourceViews();
    //void updateTreeSelection();
    Ui::MainWindow *ui;
    void RebuildTargetsCB(OpenedProject* p);

    //UPDATE project views sections
    void addProjectEntry(OpenedProject* p); //adds a project entry with all of its resources!
    bool addResourceEntry(OpenedProject* p, gcresource* res, bool open=false);
    
private slots:
    void ShowSkins();
    void setSkin();
    void BuildTargetChanged(int row);
    void on_actionExit_triggered();
    void on_action_Run_triggered();
    void LastWWClosed();
    void ResViewChange();
    void on_WorkSpaceTabWidget_tabCloseRequested(int index);
    void on_projectTree_doubleClicked(const QModelIndex &index);
    void on_projectTree_clicked(const QModelIndex &index);
    void on_projectTree_customContextMenuRequested(const QPoint &pos);

    void on_actionFramework_editor_triggered();

    void on_action_Preferences_triggered();

    void on_actionGameScript_tester_triggered();

private:
    QTimer OpenWidgetTimer;
};

#endif // MAINWINDOW_H
