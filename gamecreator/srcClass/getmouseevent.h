#ifndef GETMOUSEEVENT_H
#define GETMOUSEEVENT_H

#include <QDialog>

namespace Ui {
    class GetMouseEvent;
}

class GetMouseEvent : public QDialog
{
    Q_OBJECT

public:
    explicit GetMouseEvent(QWidget *parent = 0);
    ~GetMouseEvent();
    int etype,button;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GetMouseEvent *ui;

private slots:
    void on_buttonBox_accepted();
    void on_EventType_currentIndexChanged(int index);
};

#endif // GETMOUSEEVENT_H
