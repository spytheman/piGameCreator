#ifndef IMGWPREVIEW_H
#define IMGWPREVIEW_H

#define WIDGETTYPE QWidget
#include <QWidget>

class imagewindow;

class imgwpreview : public WIDGETTYPE
{
    friend class imagewindow;
    Q_OBJECT
public:
    imgwpreview(WIDGETTYPE *parent = 0);
    ~imgwpreview();
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:

public slots:

private:
    imagewindow* window;
    bool dragoffset;

};

#endif // IMGWPREVIEW_H
