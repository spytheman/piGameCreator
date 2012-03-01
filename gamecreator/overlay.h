#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QPainter>

typedef void(*OverlayPainterFP)(QPainter*,QWidget*);
class overlay : public QWidget
{
    Q_OBJECT
public:
    explicit overlay(QWidget *parent = 0, OverlayPainterFP=0);
    OverlayPainterFP PainterFunc;
    QWidget* parentWidget;

private:
    void paintEvent(QPaintEvent *e);
};

#endif // OVERLAY_H
