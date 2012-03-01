#ifndef GCIMAGE_H
#define GCIMAGE_H

#include <QList>
#include <QPixmap>
#include "gcresource.h"
class imagewindow;
class gcimage: public gcresource
{
public:
    gcimage();
    void load(); //sets the image stuff from the XML

    //Image, used as sprite or texture/background

    int framecount();
    bool vector;
    QStringList frames;

    int width,height;
    int offsetX, offsetY;
    int masktype; //0 - box, 1 - circle, 2 - pixmap, 3 - as frame (per pixel)
    int scalemode; //0 - inside, 1 - fill, 2 - stretch;
    int boxleft,boxright,boxtop,boxbottom;
    int circleradius;
    bool pixmapsperframe;
    //LOD settings here when implemented!
    int unitsize;
    int previewmode; //0 - frames, 1 - both, 2 - masks only


    //these are only used if masktype=2
    //      if pixmapsperframe is true, ALL frames are used else only one
    QStringList maskframes;

    //tilesets will be different resources with its own images!

    //virtual functions:
    QDomElement savedata(QString folder, QDomDocument* xml);
    bool setName(QString newName);

    imagewindow* window;

};

#endif // GCIMAGE_H
