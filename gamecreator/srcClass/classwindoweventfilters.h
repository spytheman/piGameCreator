#ifndef CLASSWINDOWEVENTFILTERS_H
#define CLASSWINDOWEVENTFILTERS_H

#include <QObject>

class classwindow;
class dropEventHandler: public QObject
{
    Q_OBJECT
public:
    classwindow* window;
    bool allowMenus;
    bool eventFilter(QObject *, QEvent *);
    dropEventHandler();
};

#endif // CLASSWINDOWEVENTFILTERS_H
