#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QGLWidget>
#include "glhelp.h"
#include "gamecreator.h"

class SceneEditor;
class instance;
class layer;
class classObj;
class SceneView : public QGLWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = 0);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    SceneEditor* window;

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

    GLfloat gridR,gridG,gridB,gridA,
            selR, selG, selB,
            overR, overG, overB;

    //textures
    GLuint checkmarkT;
    QList<layer*> layers;

    bool drawGrid, snapping, enableGrid, drawDebugInfo;
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
    layer* getLayer(QString name);
    classObj* getClass(QString name);   //Load on use, null if not exists
    void reloadClasses();

    int toolmode; //0 - select, 1 - draw, 2 - rect, 3 - poly, 4 - eyedropper

private:
    QList<classObj*> loadedClasses;
    bool mousepressed;
    void placeInstance();
    void deleteInstance();

signals:

public slots:
    void updateOpenGL();
};

class instance
{
public:
    gcGLtexture* texture;
    //later: models...
    double
        x,y,z,      //coords
        rx,ry,rz,   //rotation
        lx,ly,lz,   //length
        ox,oy,oz;   //offset
    char alpha;
    vObject properties; //must do some previewing function
    QString className;
    bool selected,overed;
    void draw(), drawOverlay();
};

class layer
{
public:
    QList<instance*> instances;
    QList<layer*> layers;    //recursive won't get added soon.. to the editor, let's code it
    QString name;
    int type;
    vObject settings;   //unplanned except: visible and locked && unimplemented TODO: savelayer() in sceneeditor.cpp
    void draw();
    void drawOverlay();
    ~layer();
};

class classObj
{
public:
    gcGLtexture* image;
    GLdouble width,height,xoff,yoff;  //default w/h [only 2d cares for scenes]
    vObject properties;     //for the property pane
    QString name;
};

#endif // SCENEVIEW_H
