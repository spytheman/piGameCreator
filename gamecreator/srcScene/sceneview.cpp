#include <GL/glew.h>
#include <QMouseEvent>
#include <QApplication>
#include "sceneview.h"
#include "gamecreator.h"
#include "glhelp.h"
#include "sceneeditor.h"
#include "ui_sceneeditor.h"
#include <GL/freeglut.h>
#include <cmath>

SceneView::SceneView(QWidget *parent) :
    QGLWidget(parent)
{
    QGLFormat f;
    f.setAlpha(1);
    f.setDoubleBuffer(1);
    f.setOverlay(0);
    f.setSampleBuffers(1);
    f.setSamples(4);
    f.setStencil(1);
    f.setVersion(4,0);

    /**/
    if(vendor.toUpper().contains("NVIDIA"))
    {
        f.setVersion(4,0); //this don't work with ATI, on nVidia it returns 3.3 context if no 4 supported
    }/**/

    f.setSwapInterval(1);
    setFormat(f);
    zoom=1.0f;
    xx=0;
    yy=0;
    ww=1;
    hh=1;
    setMouseTracking(1);
    drawDebugInfo=1;
    mousepressed=false;
}

void SceneView::initializeGL()
{
    GLenum res = glewInit();
    if(res!=GLEW_OK){gcerror("Problem: glewInit failed, something is seriously wrong.");}

    char* vendor_ = (char *) glGetString(GL_VENDOR);
    char* renderer_ = (char *) glGetString(GL_RENDERER);
    char* version_ = (char *) glGetString(GL_VERSION);
    char* exts = (char *) glGetString(GL_EXTENSIONS);
    vendor = QString::fromAscii(vendor_);
    renderer = QString::fromAscii(renderer_);
    version = QString::fromAscii(version_);

    gcprint("Initializing OpenGL...");
    gcprint(QString::fromAscii(version_));
    gcprint(QString::fromAscii(vendor_));
    gcprint(QString::fromAscii(renderer_));
    gcprint("Extensions:\n");
    GLExtensions = QString::fromAscii(exts).split(" ",QString::SkipEmptyParts);
    //foreach(QString EXT,GLExtensions)gcprint("Extension: "+EXT);

    glEnable(GL_TEXTURE_2D);

    //load the texture for the alpha mask
    QImage i = QGLWidget::convertToGLFormat(QImage(":/resources/RES/alpha.png"));
    if(i.isNull())
    {
        gcprint("Unable to load texture");
    }
    else
    {
        glGenTextures(1,&checkmarkT);
        glBindTexture(GL_TEXTURE_2D,checkmarkT);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,i.width(),i.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,i.bits());
        //it must now be loaded....
    }

    //misc
    glClearColor(0.8f,0.8f,0.8f,1.0f);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    window->loadScene();
}
void SceneView::updateOpenGL()
{
    updateGL();
}
void SceneView::paintGL()
{
    //paint the scene
    glMatrixMode(GL_PROJECTION);
    GLdouble m[16];
    m[0] = window->ui->m11->value();
    m[1] = window->ui->m12->value();
    m[2] = window->ui->m13->value();
    m[3] = window->ui->m14->value();
    m[4] = window->ui->m21->value();
    m[5] = window->ui->m22->value();
    m[6] = window->ui->m23->value();
    m[7] = window->ui->m24->value();
    m[8] = window->ui->m31->value();
    m[9] = window->ui->m32->value();
    m[10]= window->ui->m33->value();
    m[11]= window->ui->m34->value();
    m[12]= window->ui->m41->value();
    m[13]= window->ui->m42->value();
    m[14]= window->ui->m43->value();
    m[15]= window->ui->m44->value();
    //glLoadMatrixf(m);
    //glFrustum(0,width(),height(),0,0,2000);
    glLoadMatrixd(m);

    //viewport
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0,width(),height(),0,-1000,1000);

    glTranslatef(extent-xx,extent-yy,0);
    glScalef(zoom,zoom,1);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //draw the border
    glColor4f(0,0,0,0.2);
    glRectf(-1,-1,ww+1,hh+1);
    //the checkmarks
    {
        glDisable(GL_DEPTH_TEST);
        glTranslatef(0,0,-100);
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,checkmarkT);
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
        glBegin(GL_QUADS);
            //UL
            glTexCoord2f(0,0);
            glVertex3i(0,0,0);
            //UR
            glTexCoord2f(0,ww/16);
            glVertex3i(ww,0,0);
            //DR
            glTexCoord2f(hh/16,ww/16);
            glVertex3i(ww,hh,0);
            //DL
            glTexCoord2f(hh/16,0);
            glVertex3i(0,hh,0);
        glEnd();
        glTranslatef(0,0,100);
        //todo: display list!
    }

    //draw the layers
    {
        QList<layer*>::const_iterator i = layers.begin();
        while(i!=layers.end())
        {
            layer* L = *i;
            L->draw(); //draw the layer
            i++;
            //each layer will draw its instances;
        }
    }

    //draw the grid
    {
        gridx = nfmod(gridx,gridw);
        gridy = nfmod(gridy,gridh);
        glDisable(GL_TEXTURE_2D);
        glLineWidth(1);
        if(enableGrid and drawGrid)
        {
            glColor4f(gridR,gridG,gridB,gridA);
            if(gridw==0)gridw=1;
            if(gridh==0)gridh=1;
            int bx = extent/gridw , by = extent/gridh ;
            glDisable(GL_MULTISAMPLE_ARB);
            glBegin(GL_LINES);
                if(gridw>1)
                for(GLfloat X = -bx*gridw +gridx; X<ww+extent;X+=gridw)
                {
                    glVertex2f(X,-extent);
                    glVertex2f(X,extent+hh);
                }
            glEnd();

            glBegin(GL_LINES);
                if(gridh>1)
                for(GLfloat Y = -by*gridh+gridy; Y<hh+extent;Y+=gridh)
                {
                    glVertex2f(-extent,Y);
                    glVertex2f(extent+ww,Y);
                }
            glEnd();
            glEnable(GL_MULTISAMPLE_ARB);
        }
    }

    //draw the layer overlays (selected items, hovered items and so on)
    {
        QList<layer*>::const_iterator i = layers.begin();
        while(i!=layers.end())
        {
            layer* L = *i;
            L->drawOverlay(); //draw the layer
            i++;
            //each layer will draw its instances;
        }
    }

    //draw the mouse hint for the object
    {

        if(toolmode==1)
        {
            glPointSize(8.0);
            glBegin(GL_POINTS);
                glColor4f(1.0f,0.0f,0.0f,1.0f);
                glVertex2i(mx,my);
            glEnd();
            classObj* c = getClass(currentClassName);
            if(c!=0)
            {
                glBegin(GL_LINE_LOOP);
                    glVertex2i(mx-c->xoff,my-c->yoff);
                    glVertex2i(mx+c->width-c->xoff,my-c->yoff);
                    glVertex2i(mx+c->width-c->xoff,my+c->height-c->yoff);
                    glVertex2i(mx-c->xoff,my+c->height-c->yoff);
                glEnd();
            }
        }
    }

    //some debug
    debug = loadedClasses.count();

    //Finally draw the debug shit
    {
        if(drawDebugInfo)
        {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glOrtho(0,width(),height(),0,-1000,1000);
            QString qs = "OpenGL "+version + "\n" + vendor + "\n"+renderer;
            char* s = qs.toAscii().data();

            glColor4f(0,0,0,0.2);
            int tl=13;
            glRasterPos2i(3,tl);
            while(*s)
            {
                if(*s=='\n'){tl+=13;glRasterPos2i(3,tl);s++;}
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*s);
                s++;
            }
        }
    }


}

void SceneView::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    window->on_HeightSB_valueChanged(hh);
    window->on_WidthSB_valueChanged(ww);
}

void SceneView::placeInstance()
{
    layer* l = getLayer(currentLayer);

    //place new:
    window->makeModified();
    instance* i = new instance();
    classObj* c = getClass(currentClassName);
    if(c==0){gcprint("Invalid class");return;}
    i->className = c->name;
    i->x = mx;
    i->y = my;
    i->z = 0;
    i->texture = c->image;
    i->properties = c->properties;  //these must be well-loaded ;]
    i->alpha=1;
    i->rx=0;i->ry=0;i->rz=0;
    i->lx=c->width;
    i->ly=c->height;
    i->lz=0;
    i->ox=c->xoff;
    i->oy=c->yoff;
    i->oz=0;
    i->selected=false;
    i->overed=false;

    //Will we delete overlapped instances?
    if(window->ui->DelUnderlying->isChecked())
    {
        QList<instance*> newinstances; bool deleted=false;
        for(QList<instance*>::iterator I = l->instances.begin(); I!=l->instances.end();I++)
        {
            instance* n = *I;
            if(rectangles_overlap(n->x,n->y,n->x+n->lx,n->y+n->ly,i->x,i->y,i->x+i->lx,i->y+i->ly))
            {
                //instance must get deleted...
                deleted=true; //if true, replace instance lists
                delete n;
            }
            else newinstances.append(n);    //only non-overlapped instances get added
        }
        if(deleted==true)l->instances = newinstances;
    }

    //place it
    if(l!=0)l->instances.append(i);
    else gcprint("Invalid layer");

    //remember last placed location for dragging events:
    lpx=mx; lpy=my; lpw=i->lx; lph=i->ly;
}
void SceneView::deleteInstance()
{
    layer* l = getLayer(currentLayer);
    QList<instance*>::iterator i = l->instances.end();i--;
    while(i>=l->instances.begin())
    {
        instance* n = *i;
        GLfloat x1,y1,x2,y2;
        x1=n->x-n->ox;
        y1=n->y-n->oy;
        x2=x1+n->lx;
        y2=y1+n->ly;
        bool in = point_in_rectangle(omx,omy,x1,y1,x2,y2);
        if(in)
        {
            //delete it:
            for(int ii=0;ii<l->instances.count();ii++)
                if(l->instances.at(ii) == n)
                {
                    l->instances.removeAt(ii);
                    delete n;
                    updateGL();
                    return;
                }
        }
        i--;
    }
}

void SceneView::mouseMoveEvent(QMouseEvent *e)
{
    mx = -(extent-xx)/zoom + e->x()/zoom; //Window to scene, it's CORRECT!
    my = -(extent-yy)/zoom + e->y()/zoom; //same here
    omx = mx;
    omy = my;
    GLdouble msx,msy;   //snapped
    msx = mx - nfmod(mx-gridx,gridw);
    msy = my - nfmod(my-gridy,gridh);

    //int m2x = mx,m2y = my; //me: moje ti trqqt originalnite predi snappinga
    //su: ammm. ti promenq6 fakti4eski mouse coords?
    //me: yeps...

    if(toolmode==1) //pencil
    {
        //draw/place
        if(enableGrid and snapping)
        {
            mx=msx;
            my=msy;
        }

        if(e->buttons().testFlag(Qt::LeftButton) and window->ui->FreeDrawing->isChecked())
        {
            classObj* c = getClass(currentClassName);
            if(c!=0)
            if(!rectangles_overlap(lpx,lpy,lpx+lpw,lpy+lph,mx,my,mx+c->width,my+c->height))
            {
                placeInstance();
            }
        }
        else if(e->buttons().testFlag(Qt::RightButton) and window->ui->FreeDrawing->isChecked())
        {
            deleteInstance();
        }
    }
    else if(toolmode==0)    //select
    {
        layer* l = getLayer(currentLayer);
        QList<instance*>::const_iterator i = l->instances.begin();
        while(i!=l->instances.end())
        {
            instance* n = *i;
            GLfloat x1,y1,x2,y2;
            x1=n->x-n->ox;
            y1=n->y-n->oy;
            x2=x1+n->lx;
            y2=y1+n->ly;
            n->overed=point_in_rectangle(mx,my,x1,y1,x2,y2);
            ++i;
        }
    }
    updateGL();
}



void SceneView::mousePressEvent(QMouseEvent *e)
{
    mousepressed=true;
    setFocus();
    //left button:
    if(e->buttons().testFlag(Qt::LeftButton))
    if(toolmode==1)
    {
        placeInstance();
    }
    else if(toolmode==0)
    {
        //select mode
        layer* l = getLayer(currentLayer);
        QList<instance*>::const_iterator i = l->instances.begin();
        while(i!=l->instances.end())
        {
            instance* n = *i;
            GLfloat x1,y1,x2,y2;
            x1=n->x-n->ox;
            y1=n->y-n->oy;
            x2=x1+n->lx;
            y2=y1+n->ly;
            bool in = point_in_rectangle(mx,my,x1,y1,x2,y2);
            if(QApplication::keyboardModifiers().testFlag(Qt::ControlModifier))
            {
                //ctrl is pressed - toggle selection
                if(in)n->selected=!n->selected;
            }
            else
                n->selected=in;
            ++i;
        }
    }
    else if(toolmode==2)    //rectangle
    {
        rectx1=omx;recty1=omy;
        rectx2=omx;recty2=omy;
    }

    //right button
    if(e->buttons().testFlag(Qt::RightButton))
    if(toolmode==0) //select
    {
        //show context menu
    }
    else if(toolmode==1)    //draw mode - erase clicked
    {
        //erase
        deleteInstance();
    }
    else if(toolmode==2)    //rectangle
    {

    }

    updateGL();
}

void SceneView::mouseReleaseEvent(QMouseEvent *e)
{
    mousepressed=false;
}

void SceneView::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Delete)
    {
        layer* l = getLayer(currentLayer);
        QList<instance*> nl;
        for(QList<instance*>::iterator i = l->instances.begin();i != l->instances.end();i++)
        {
            if((*i) -> selected == false)nl<<*i;
        }
        l->instances=nl;
        updateGL();
    }
}

void instance::draw()
{
    glPushMatrix();
    glTranslatef(x-ox,y-oy,0);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D,texture->texId); // vij sega. tuka setva6 textura. texturata 6te se izpolzva i za redner na grida!
    glTexEnvf(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
        glTexCoord2f(0,1);
        glVertex2f(0,0);
        glTexCoord2f(1,1);
        glVertex2f(lx,0);
        glTexCoord2f(1,0);
        glVertex2f(lx,ly);
        glTexCoord2f(0,0);
        glVertex2f(0,ly);
    glEnd();
/*
    glPushMatrix();
    glTranslatef(lx/2,lx/2,lx/2);
    glScalef(lx/2,lx/2,lx/2);
    //glRotatef(QCursor::pos().x(),1,0,0);
    //glRotatef(QCursor::pos().y(),0,1,0);
    glBegin(GL_QUADS);
                    // Front Face
                    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
                    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
                    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
                    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
                    // Back Face
                    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
                    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
                    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
                    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
                    // Top Face
                    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
                    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
                    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
                    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
                    // Bottom Face
                    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
                    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
                    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
                    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
                    // Right face
                    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
                    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
                    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
                    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
                    // Left Face
                    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
                    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
                    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
                    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
     glEnd();
     glDisable(GL_DEPTH_TEST);
     /**/

    glPopMatrix();
}
void instance::drawOverlay()
{

    if(selected)
    {
        glPushMatrix();
        glTranslatef(x-ox,y-oy,0);

        glColor4f(0,0,0,1);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(lx,0);
            glVertex2f(lx,ly);
            glVertex2f(0,ly);
        glEnd();
        glPointSize(10);
        glBegin(GL_POINTS);
            glVertex2f(ox,oy);
        glEnd();

        glColor4f(1,1,1,1);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(lx,0);
            glVertex2f(lx,ly);
            glVertex2f(0,ly);
        glEnd();
        glPointSize(8);
        glBegin(GL_POINTS);
            glVertex2f(ox,oy);
        glEnd();

        glPopMatrix();
    }

    if(overed)
    {
        glPushMatrix();
        glTranslatef(x-ox,y-oy,0);

        glColor4f(1,0,0,0.2);
        glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(lx,0);
            glVertex2f(lx,ly);
            glVertex2f(0,ly);
        glEnd();

        glColor4f(1,0,0,0.6);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(lx,0);
            glVertex2f(lx,ly);
            glVertex2f(0,ly);
        glEnd();
        glPointSize(8);
        glBegin(GL_POINTS);
            glVertex2f(ox,oy);
        glEnd();

        glPopMatrix();
    }
}

void layer::draw()
{
    foreach(instance* i,instances)
        i->draw();
}
void layer::drawOverlay()
{
    foreach(instance* i,instances)
        i->drawOverlay();
}

layer::~layer()
{
    foreach(instance* I,instances)delete I;
    foreach(layer* L,layers)delete L;
}

layer* SceneView::getLayer(QString name)
{
    //non-recursive!
    foreach(layer* l,layers)
    {
        if(l->name == name)return l;
    }
    return 0;
}

classObj* SceneView::getClass(QString name)
{
    foreach(classObj* c,loadedClasses)
    {
        if(c->name == name)     return c;
    }
    //not loaded: load class with this name if exists
    QStringList s = window->project->getResourcesFromType("class");
    if(s.contains(name))
    {
        //load che class
        classObj* c = new classObj;
        loadedClasses.push_back(c);
        c->name=name;
        QString repname;
        QDomDocument* xml = gcReadXml(window->project->absoluteFolder+"/classes/"+name+".xml");
        //get the image used:
        QDomElement e = xml->documentElement();
        if(e.tagName()=="class")repname = e.attribute("representation");
        QDomDocument* imgxml = gcReadXml(window->project->absoluteFolder + "/images/" +repname+".xml");
        QDomElement e2 = imgxml->documentElement();
        if(e2.tagName()=="image")
        {
            c->width = e2.attribute("width").toDouble();
            c->height = e2.attribute("height").toDouble();
            c->xoff = e2.attribute("offsetX").toDouble();
            c->yoff = e2.attribute("offsetY").toDouble();
            gcGLtexture* t = new gcGLtexture(GL_TEXTURE_2D);
            t->load(window->project->absoluteFolder + "/images/" + repname + "/frame1.png",GL_TEXTURE_2D);
            c->image = t;
        }
        return c;
    }
    else
    {
        return 0;
    }
}

void SceneView::reloadClasses()
{
    //IGNORE for now!
    /*
    foreach(classObj* o,loadedClasses)
    {
        QString n = o->name;
        o->name="";
        getClass(n);
    }
    */
    //fix: crash... TODO: GLOBAL class storage!
}
