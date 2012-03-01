#include "overlay.h"
#include "QDebug"

overlay::overlay(QWidget *parent, OverlayPainterFP PaintFunction) :
    QWidget(parent)
{
    if(parent==0)qDebug() << "NULL parent widget!";
    setPalette(Qt::transparent);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAutoFillBackground(false);
    parentWidget=parent;
    PainterFunc=PaintFunction;
}

void overlay::paintEvent(QPaintEvent *e)
{
    setGeometry(0,0,parentWidget->width(),parentWidget->height());
    QPainter p(this);
    if(PainterFunc==0)qDebug() << "NULL paint function pointer!";
    PainterFunc(&p,parentWidget);
}
