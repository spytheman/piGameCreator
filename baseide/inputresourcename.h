#ifndef INPUTRESOURCENAME_H
#define INPUTRESOURCENAME_H

#include <QDialog>
#include "../sharedcode/gameproject.h"


namespace Ui {
class InputResourceName;
}

class InputResourceName : public QDialog
{
    Q_OBJECT
    
public:
    explicit InputResourceName(QWidget *parent = 0);
    ~InputResourceName();
    QString enteredName;
    gameproject* project;
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::InputResourceName *ui;
};

#endif // INPUTRESOURCENAME_H
