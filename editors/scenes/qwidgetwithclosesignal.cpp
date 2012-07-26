#include "qwidgetwithclosesignal.h"
#include <QCloseEvent>

QWidgetWithCloseSignal::QWidgetWithCloseSignal(QWidget *parent) :
    QWidget(parent)
{
}

void QWidgetWithCloseSignal::closeEvent(QCloseEvent *e)
{
    emit WindowClosed(this);
}
