#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <QGLWidget>
#include "sceneeditor.h"

class sceneview : public QGLWidget
{
public:
    sceneview(QWidget* parent);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void resizeEvent(QResizeEvent *);

    SceneEditor* editor;

    QStringList GLExtensions;
    QString version,vendor,renderer;

    GLdouble debug,
        //projection settings
        zoom,  extent, xx,yy /*offset*/,
        //scene settings
        ww,hh,
        //mouse
        mx,my,omx,omy, //mx,my: grid'd, omx,omy: original
        //grid settings
        gridx,gridy,gridw,gridh,
        //last placed instance for dragging
        lpx,lpy, lpw, lph,
        //Rectangle mode coords:
        rectx1,recty1,rectx2,recty2
    ;

    //grid colors
    GLfloat gridR,gridG,gridB,gridA,
            selR, selG, selB,
            overR, overG, overB;

    //textures
    GLuint checkmarkT;

    bool drawGrid, snapping, enableGrid, drawDebugInfo, mousepressed;
    GLuint GridPattern;

    void setRectGrid(GLdouble x,GLdouble y,GLdouble w,GLdouble h);
    void setIsoGrid(GLdouble x,GLdouble y,GLdouble w,GLdouble h);
    //todo: custom grids

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);

    //returns layer by name, null if not exist
    QString currentClassName, currentLayer;
    //layer* getLayer(QString name);
    //classObj* getClass(QString name);   //Load on use, null if not exists
    //void reloadClasses();

    int toolmode; //0 - select, 1 - draw, 2 - rect, 3 - poly, 4 - eyedropper

};

#endif // SCENEVIEW_H
