#ifndef RSSCENE_H
#define RSSCENE_H

#include "resource.h"
#include "ideobjectrepresentation.h"
#include "rsgraphicseffect.h"
#include <QList>

class rsScene:public gcresource
{
public:   
    class layer;
    class instance;
    rsScene();
    QString mainFolderName();
    QString kind();
    QList<layer> layers;

    //some classes used for scenes
    class instance
    {
        QString classname;

        //main game object properties:
        QString objectName;
        double x,y,z, xrot,yrot,zrot, xscale,yscale,zscale;
        ideObjectRepresentation representation;
        QList<rsGraphicsEffect> graphicsEffects;

        //design time properties
        vObject properties;


        //used in the scene editors:
        bool selected;
    };

    class layer
    {
        QString name;   //layer name
        QList<instance> instances;  //instances
        QList<layer> layers;        //child layers
        bool
            visible,        //layer is visible
            designonly,     //layer is not used runtime
            limited,        //have limited area
            grid,           //is grid layer
            selected        //if selected in the scene editor
        ;
        QColor layerColor;  //used for coloring selections and instances during design
        double
            x,y,z,      //layer position
            ox,oy,oz,   //layer origin shifts  [may get unused]
            //only if layer is grid based:
            gx,gy,gz,  // grid width/height/length [Z will not be used at all for now]
            cx,cy,cz,  // grid item counts

            //if limited but NOT gridbased:
            xlength,ylength,zlength, //layer dimensions - layer is box by nature

            //else there are no dimensions about the layer!
        ;
    };
};

#endif // RSSCENE_H
