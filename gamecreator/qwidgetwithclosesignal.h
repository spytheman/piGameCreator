#ifndef QWIDGETWITHCLOSESIGNAL_H
#define QWIDGETWITHCLOSESIGNAL_H

#include <QWidget>

class QWidgetWithCloseSignal : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetWithCloseSignal(QWidget *parent = 0);
    void closeEvent(QCloseEvent* e);

signals:
    bool WindowClosed(QWidget*);

};

#endif // QWIDGETWITHCLOSESIGNAL_H
