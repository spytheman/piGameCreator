#include "gamecreator.h"
#include "imagewindow.h"
#include "ui_imagewindow.h"
#include "imgwpreview.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QGraphicsBlurEffect>

imgwpreview::imgwpreview(WIDGETTYPE *parent)
{
    window = (imagewindow*)23949238;
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    setMouseTracking(true);
    dragoffset=false;
}

imgwpreview::~imgwpreview(){}

void imgwpreview::paintEvent(QPaintEvent * e)
{
    QPainter c(this);
    c.setRenderHint(QPainter::SmoothPixmapTransform,true);

    int selected=-1;

    if(window->frames.count()==0)
    {
        QPen p(QColor(0,0,0,255));

        c.setPen(p);
        QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
        //blur.setColor(QColor(0,0,0,200));

        //blur.draw(c);

        c.setFont(QFont("Arial",14,2,false));
        c.drawText(10,50,tr("You haven't added any frames to this image yet."));
        c.drawText(10,70,tr("To begin, click 'Add frames'"));

    }
    else
    {
        selected = window->ui->listWidget->currentIndex().row();

        if(selected>=0)
        {
            QPixmap img = window->frames.at(selected);

            if(window->scalingmode==0)
            {
                int nw=0,nh=0;
                scale_to_fit(img.width()*window->unitsize,img.height()*window->unitsize,
                             window->width*window->unitsize,window->height*window->unitsize,
                             &nw,&nh);
                double ratio = (double)img.width()/(double)img.height();
                c.drawPixmap( (window->width*window->unitsize - nw)/2 ,(window->height*window->unitsize - nh)/2,nw,nh,window->frames.at(selected));
            }
            else if(window->scalingmode==2) //stretch
            {
                c.drawPixmap(0,0,window->width*window->unitsize,window->height*window->unitsize,window->frames.at(selected));
            }
            else if(window->scalingmode==1)
            {
                //FILL mode
                //TODO
                int nw=0,nh=0;
                scale_to_fit(img.width()*window->unitsize,img.height()*window->unitsize,
                             window->width*window->unitsize,window->height*window->unitsize,
                             &nw,&nh);
                double ratio = (double)img.width()/(double)img.height();
                c.drawPixmap( (window->width*window->unitsize - nw)/2 ,(window->height*window->unitsize - nh)/2,nw,nh,window->frames.at(selected));
            }
        }

        //Draw the offset thing
        QPen p(QColor(0,0,0,255));
        c.setPen(p);
        c.drawLine(window->offsetx * window->unitsize,0,window->offsetx * window->unitsize,height());
        c.drawLine(0,window->offsety * window->unitsize,width(),window->offsety * window->unitsize);
        QBrush b(QColor(255,255,255));
        p.setColor(QColor(0,0,0));
        c.setPen(p);
        c.setBrush(b);
        c.drawEllipse(QPoint(window->offsetx*window->unitsize,window->offsety*window->unitsize),3,3);/**/

        //draw the Width/Height thing
        b.setColor(QColor(0,0,0,0));
        c.setBrush(b);
        p.setColor(QColor(255,0,255));
        c.setPen(p);
        c.drawRect(0,0,window->width*window->unitsize,window->height*window->unitsize);
    }
}

void imgwpreview::mousePressEvent(QMouseEvent *e)
{
    if(point_distance(window->offsetx,window->offsety, e->x(),e->y()) <=5)
    {
        dragoffset=true;
    }
}

void imgwpreview::mouseMoveEvent(QMouseEvent *e)
{
    if(point_distance(window->offsetx,window->offsety, e->x(),e->y()) <=5)
        setCursor(Qt::SizeAllCursor);
    else setCursor(Qt::ArrowCursor);
    int x = e->x(), y=e->y();
    if(dragoffset)
    {
        //spinboxes 7 and 10 are for offset
        if(x>window->width) x = window->width;
        if(y>window->height)y = window->height;
        window->ui->offsetX->setValue(x);
        window->ui->offsetY->setValue(y);
        repaint();
    }
}

void imgwpreview::mouseReleaseEvent(QMouseEvent *)
{
    dragoffset=false;
}
