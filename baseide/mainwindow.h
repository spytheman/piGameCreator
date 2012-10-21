#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QModelIndex>
#include <QComboBox>
#include <QItemSelection>
#include <QStandardItem>

namespace Ui {
class MainWindow;
}
class OpenedProject;
class WorkspaceWidget;
class gcresource;
class ResourceTreeNode;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent *);
    void openWorkspaceWidget(WorkspaceWidget* w);
    void renameWorkspaceWidget(WorkspaceWidget* w, QString s);
    QComboBox *targetsCB;
    QMenu* SkinsMenu;
    //void updateResourceViews();
    //void updateTreeSelection();
    Ui::MainWindow *ui;
    void UpdateTargetsCB(OpenedProject* p);

    //UPDATE project views sections

    void updateProjectExplorer();
    void updateProjectTrees();
    void focusProjectExplorer();

    //void addProjectEntry(OpenedProject* p); //adds a project entry with all of its resources!
    //bool addResourceEntry(OpenedProject* p, gcresource* res, bool open=false);
    
public slots:
    void tabTextChanged(QString s);
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
    void on_action_Preferences_triggered();
    void on_actionGameScript_tester_triggered();
    void on_action_Targets_triggered();
    void on_action_Debug_triggered();
    void on_actionBuild_triggered();
    void projectTreeSelection(QItemSelection current, QItemSelection previous);
    void on_projectTree_expanded(const QModelIndex &index);
    void on_projectTree_collapsed(const QModelIndex &index);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_projectComboBox_currentIndexChanged(int index);
    void ProjectItemChanged(QStandardItem* item);
    void routeRightMenuClickToItsDLL();
    void on_pushButton_clicked();
    void on_action_Save_triggered();
    void on_actionOpen_project_triggered();
    void on_actionCreate_project_triggered();

private slots:
    void on_actionSkin_editor_triggered();

private:
    QTimer OpenWidgetTimer;
    QStandardItem* selectedWhileTreeRefresh;
    void rec_addResourceEntry(ResourceTreeNode* node, QStandardItem* target, int level, OpenedProject* project);
};

#endif // MAINWINDOW_H
