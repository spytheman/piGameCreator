#ifndef ADDEVENTWINDOW_H
#define ADDEVENTWINDOW_H

#include <QDialog>
#include "classwindow.h"

namespace Ui {
    class AddEventWindow;
}

class AddEventWindow : public QDialog
{
    Q_OBJECT
    friend class classwindow;

public:
    explicit AddEventWindow(QWidget *parent = 0);
    AddEventWindow(classwindow* w, QWidget* parent = 0);
    ~AddEventWindow();
    bool OKclicked;
    QTreeWidgetItem* selectedEvent;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddEventWindow *ui;
    classwindow* window;

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // ADDEVENTWINDOW_H