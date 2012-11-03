#ifndef PROJECTDASHBOARD_H
#define PROJECTDASHBOARD_H

#include <QTimer>
#include <QMainWindow>
#include "workspacewidget.h"

class OpenedProject;
namespace Ui {
class ProjectDashboard;
}

class ProjectDashboard : public QMainWindow, public WorkspaceWidget
{
    friend class gcide;
    friend class MainWindow;
    Q_OBJECT
    
public:
    explicit ProjectDashboard(QWidget *parent = 0);
    ~ProjectDashboard();
    void setProject(OpenedProject* project);
    void init();
    void updateWallpaper();
    bool eventFilter(QObject *, QEvent *);
    
private slots:
    void clearBottomStates();
    void saveProjectAndUpdateExplorer();
    void on_projectDescription_textChanged();
    void on_projectTitle_textChanged(const QString &arg1);
    void on_projectAuthor_textChanged(const QString &arg1);
    void on_projectAppVersion_textChanged(const QString &arg1);
    void on_buildTargetsBtn_clicked();
    void on_pbBasicInfo_clicked();
    void on_pbModules_clicked();
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_8_clicked();
    void on_toolButton_10_clicked();
    void on_toolButton_11_clicked();
    void on_toolButton_9_clicked();
    void on_projectIcon_clicked();
    void on_addModule_clicked();
    void on_actionEdit_this_module_triggered();
    void on_actionRemove_as_Main_Module_triggered();
    void refreshModules();
    void on_addModuleButtonBox_accepted();
    void on_addModuleButtonBox_rejected();
    void moduleButtonPressed();

signals:
    void titleChanged(QString);

private:
    Ui::ProjectDashboard *ui;
    OpenedProject* project;
    QTimer timer;
    QTimer refresher;
    int addModuleResult;
    QString moduleButtonClicked;
};

#endif // PROJECTDASHBOARD_H
