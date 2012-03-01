#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
//#include "projectmodel.h"
#include "logwindow.h"
#include <QComboBox>
#include <QTimer>
class overlay;
class ProjectModel;
class gameproject;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    QDockWidget* tutorials;

    //projects
    int gcOpenProject(QString s);
    void gcCloseProject(int p);
    int gcNewProjectWizard();

    //ui
    void uiUpdateTree();
    static ProjectModel* projectModel();
    void RebuildTargetsCB(gameproject*);
    bool rec_drawOverlay;
    Ui::MainWindow* ui;
    QPixmap* LastIdeFrame;
    bool mustUpdate;
    int frame;
private:
    static ProjectModel* pmodel;
    QComboBox *targetsCB;
    QMenu* SkinsMenu;
    void paintEvent(QPaintEvent *e);
    void update();
    overlay* Overlay;
    QTimer overlayTimer;

private slots:
    void on_actionCreate_2D_scene_triggered();
    void on_actionAdd_class_triggered();
    void on_action_Preferences_triggered();
    void on_actionCreate_image_triggered();
    void on_actionBuild_triggered();
    void on_action_Debug_triggered();
    void on_actionSave_as_triggered();
    void on_action_Save_triggered();
    void on_actionOpen_project_triggered();
    void on_actionShow_Main_page_triggered();
    void openRecentFile();
    void on_actionClose_active_tab_triggered();
    void on_WorkSpaceTabWidget_tabCloseRequested(int index);
    void on_actionTEST_triggered();
    void on_actionTutorials_triggered(bool checked);
    void on_actionShowLog_triggered();
    void on_actionExit_triggered();
    void TutorialsVisible(bool);
    void TreeContextMenu();
    void ItemClicked(QModelIndex);
    void on_action_Run_triggered();
    void on_treeView_clicked(const QModelIndex &index);
    void on_action_Targets_triggered();
    void BuildTargetChanged(int row);
    void ShowSkins();
    void on_actionSkin_editor_triggered();
    void settheme();
    void on_actionClass_editor_triggered();
    void updateOverlay();
};

#endif // MAINWINDOW_H
