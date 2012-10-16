#ifndef CLASSWINDOWEVENTFILTERS_H
#define CLASSWINDOWEVENTFILTERS_H

#include <QObject>
class eventClass;

class classwindow;
class dropEventHandler: public QObject
{
    Q_OBJECT
public:
    eventClass* window;
    bool allowMenus;
    bool eventFilter(QObject *, QEvent *);
    dropEventHandler();
};

#endif // CLASSWINDOWEVENTFILTERS_H
