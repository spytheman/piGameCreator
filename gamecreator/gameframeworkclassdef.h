#ifndef GAMEFRAMEWORKCLASSDEF_H
#define GAMEFRAMEWORKCLASSDEF_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QTextEdit>
#include "gamecreator.h"

namespace Ui {
    class GameFrameworkClassDef;
}
class QModelIndex;
class GameFrameworkClassDef : public QDialog
{
    Q_OBJECT

public:
    explicit GameFrameworkClassDef(QWidget *parent = 0);
    ~GameFrameworkClassDef();
    void reloadData();
    void saveData();

    void txBold(QTextEdit* t);
    void txItalic(QTextEdit* t);
    void txUnderline(QTextEdit* t);
    void txFixedWidth(QTextEdit* t);
    void txStrike(QTextEdit* t);

    void arglistUpdate();

protected:
    void changeEvent(QEvent *e);
    void ExpandOrCollapseIcon(QTreeWidgetItem*,bool=true);

private slots:
    void on_pushButton_3_clicked();
    void on_OKbutton_clicked();
    void on_treeWidget_itemExpanded(QTreeWidgetItem *item);
    void on_treeWidget_itemCollapsed(QTreeWidgetItem *item);
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_fnArgumentList_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_removeButton_2_clicked();
    void on_removeButton_clicked();
    void on_btnEdit_clicked();
    void on_btnTasks_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_5_clicked();
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_4_clicked();
    void on_toolButton_13_clicked();
    void on_toolButton_14_clicked();
    void on_toolButton_15_clicked();
    void on_toolButton_16_clicked();
    void on_toolButton_17_clicked();
    void on_toolButton_23_clicked();
    void on_toolButton_24_clicked();
    void on_toolButton_25_clicked();
    void on_toolButton_26_clicked();
    void on_toolButton_27_clicked();
    void on_toolButton_18_clicked();
    void on_toolButton_19_clicked();
    void on_toolButton_20_clicked();
    void on_toolButton_21_clicked();
    void on_toolButton_22_clicked();
    void on_varDesc_textChanged();
    void on_varName_textChanged(const QString &arg1);
    void on_varType_editTextChanged(const QString &arg1);
    void on_staticFunction_clicked();
    void on_fnName_textChanged(const QString &arg1);
    void on_fnType_editTextChanged(const QString &arg1);
    void on_fnDesc_textChanged();
    void on_AddButton_clicked();
    void on_propName_textChanged(const QString &arg1);
    void on_propType_editTextChanged(const QString &arg1);
    void on_propDesc_textChanged();
    void on_addvarRB_clicked();
    void on_addvarRB_2_clicked();
    void on_addFunction_clicked();
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_className_textChanged(const QString &arg1);
    void on_classDisplayName_textChanged(const QString &arg1);
    void on_classDescEdit_textChanged();
    void on_classHidden_clicked(bool checked);
    void on_staticFunction_clicked(bool checked);
    void on_TaskCurrentClass_clicked();
    void on_TaskAllClasses_clicked();
    void on_TaskAllFiles_clicked();

private:

    //when: 0 - begin, 1 - for each object, 2 - after all objects!
    typedef int(GameFrameworkClassDef::*fptr)(vObject, int);
    void genCpp(vObject Class,int when);
    void genDoc(vObject Class,int when);
    void genJs (vObject Class,int when);
    fptr taskFunc;

    QString cppGetType(QString type, bool noPointer=false);
    QString cppGetName(QString name);
    void saveAndReload();
    void whichTask();

private:
    bool taskmode;
    Ui::GameFrameworkClassDef *ui;
    vObject cppMappings;
    QStringList cppBuiltInTypes,cppValueTypes, cppUsedTypes, hUsedTypes;
};

#endif // GAMEFRAMEWORKCLASSDEF_H
