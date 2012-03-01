#ifndef EDITVARDIALOG_H
#define EDITVARDIALOG_H

#include <QDialog>
#include "srcClass/variable.h"
#include "gameproject.h"

namespace Ui {
    class EditVarDialog;
}

class EditVarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditVarDialog(QWidget *parent = 0);
    EditVarDialog(variable var, QWidget *parent = 0);
    ~EditVarDialog();
    void propertyMode(bool edit=false);
    variable var;
    gameproject* project;
    bool OKclicked;

protected:
    void changeEvent(QEvent *e);

private:
    int lastindex;
    Ui::EditVarDialog *ui;
    void updateVar();
    bool propertymode;
    vObject makeValue();

private slots:
    void on_menuWithChoices_clicked();
    void on_NullresourceButton_clicked();
    void on_SelectResourceButton_clicked();
    void on_SetColorToolButton_clicked();
    void on_DelFromArray_clicked();
    void on_AddToArrayButton_clicked();
    void on_OKbutton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_varType_currentIndexChanged(int index);
};

#endif // EDITVARDIALOG_H
