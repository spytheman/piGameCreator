#ifndef SAVEORNOT_H
#define SAVEORNOT_H

#include <QDialog>
#include "gameproject.h"
#include "resourceeditor.h"

namespace Ui {
    class saveornot;
}

class saveornot : public QDialog
{
    Q_OBJECT

public:
    explicit saveornot(gameproject* gp);
    saveornot(QString what);
    static int resource(QString what);
    static int project(QString what);
    ~saveornot();

protected:
    void changeEvent(QEvent *e);

private:
    explicit saveornot(QWidget *parent = 0); //will force crash
    Ui::saveornot *ui;


private slots:
    void on_commandLinkButton_3_clicked();
};

#endif // SAVEORNOT_H
