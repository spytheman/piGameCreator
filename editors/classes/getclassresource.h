#ifndef GETCLASSRESOURCE_H
#define GETCLASSRESOURCE_H

#include <QDialog>
#include <QListWidgetItem>
#include "../../sharedcode/gameproject.h"

namespace Ui {
    class getClassResource;
}

class getClassResource : public QDialog
{
    Q_OBJECT

public:
    explicit getClassResource(QWidget *parent = 0);
    getClassResource(gameproject* gp, QWidget*p=0);
    ~getClassResource();
    QString resname;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::getClassResource *ui;
    gameproject* project;

private slots:
    void on_Filter_textChanged(QString );
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
    void on_ClearButton_clicked();
    void on_CancelButton_clicked();
    void on_OKbutton_clicked();
};

#endif // GETCLASSRESOURCE_H
