#ifndef NEWPROJECTWIZARD_H
#define NEWPROJECTWIZARD_H

#include <QWizard>
#include <QTreeWidgetItem>

class gameproject;
class gameprojectinformation;
class OpenedProject;
class BuildTargets;
namespace Ui {
class newProjectWizard;
}

class newProjectWizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit newProjectWizard(QWidget *parent = 0);
    ~newProjectWizard();
    OpenedProject* openedProject;
    gameproject* gameProject;
    BuildTargets* buildTargetsWidget;
    
private slots:
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_browseButton_clicked();
    void on_projectTitleLineEdit_textChanged(const QString &arg1);
    void on_projectdirname_textChanged(const QString &arg1);
    void newProjectWizard_currentIdChanged(int id);
    void on_toolButton_clicked();

private:
    Ui::newProjectWizard *ui;
    QList<gameprojectinformation*> mmGPInfos;
    void initializePage(int id);
    bool validateCurrentPage();
};

#endif // NEWPROJECTWIZARD_H
