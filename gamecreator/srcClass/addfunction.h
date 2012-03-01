#ifndef ADDFUNCTION_H
#define ADDFUNCTION_H

#include <QDialog>
#include "gamecreator.h"
#include "gameproject.h"

namespace Ui {
    class AddFunction;
}

class AddFunction : public QDialog
{
    Q_OBJECT

public:
    explicit AddFunction(QWidget *parent = 0);
    ~AddFunction();
    void argumentMode();

    gameproject* project;
    QString name;
    QString type;
    vObject args;

protected:
    void changeEvent(QEvent *e);

private:
    QString theclass;
    Ui::AddFunction *ui;
    bool argumentmode;

private slots:
    void on_removeButton_clicked();
    void on_selectClass_clicked();
    void on_okbutton_clicked();
    void on_varType_currentIndexChanged(int index);
    void on_AddButton_clicked();
};

#endif // ADDFUNCTION_H
