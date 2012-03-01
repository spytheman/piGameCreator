#ifndef SCRIPTTESTWINDOW_H
#define SCRIPTTESTWINDOW_H

#include <QMainWindow>
#include "scriptwindow.h"

namespace Ui {
    class scripttestwindow;
}

class scripttestwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit scripttestwindow(QWidget *parent = 0);
    ~scripttestwindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::scripttestwindow *ui;
    scriptwindow* source;

private slots:
    void on_actionSettings_triggered();
    void codeChanged();
};

#endif // SCRIPTTESTWINDOW_H
