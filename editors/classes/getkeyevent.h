#ifndef GETKEYEVENT_H
#define GETKEYEVENT_H

#include <QDialog>
#include <string>

namespace Ui {
    class getKeyEvent;
}
class GetGlobalKeyEventFilter;
class getKeyEvent : public QDialog
{
    Q_OBJECT

public:
    explicit getKeyEvent(QWidget *parent = 0);
    ~getKeyEvent();
    void setKey(int);
    QString keyName;
    int keyCode;
    int etype;
    static std::string getKeyName(int key);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::getKeyEvent *ui;
    GetGlobalKeyEventFilter* EF;
};

std::string getKeyName(int key);

class GetGlobalKeyEventFilter:public QObject
{
    Q_OBJECT
    GetGlobalKeyEventFilter();
    getKeyEvent* window;
public:
    GetGlobalKeyEventFilter(getKeyEvent* w);
    bool eventFilter(QObject *, QEvent *);
};

#endif // GETKEYEVENT_H
