#include "sceneview.h"
#include "../../sharedcode/globals.h"
#include "../../baseide/gcide.h"
#include <QApplication>
#include <QResizeEvent>

sceneview::sceneview(QWidget* parent):
    QGLWidget(parent)
{
    zoom=1.0f;
    xx=0;
    yy=0;
    ww=640;
    hh=480;
    extent = 100;
    drawDebugInfo=1;
    mousepressed=false;
    editor=0;
    setMouseTracking(true);
}

void sceneview::initializeGL()
{
    //init freeglut if not already initialized
    if(!glutGet(GLUT_INIT_STATE))
    {
        int argc = QApplication::instance()->argc();
        glutInit(&argc,QApplication::instance()->argv());
        gcprint("Initializing FreeGlut...");
    }
/*
    QGLFormat f;
    f.setAlpha(1);
    f.setDoubleBuffer(1);
    f.setOverlay(0);
    f.setSampleBuffers(1);
    f.setSamples(4);
    f.setStencil(1);
    f.setVersion(4,0);

    char* vendor_ = (char *) glGetString(GL_VENDOR);
    char* renderer_ = (char *) glGetString(GL_RENDERER);
    char* version_ = (char *) glGetString(GL_VERSION);
    char* exts_ = (char *) glGetString(GL_EXTENSIONS);
    GLExtensions = QString::fromAscii(exts_).split(" ",QString::SkipEmptyParts);

    vendor = QString::fromAscii(vendor_);
    renderer = QString::fromAscii(renderer_);
    version = QString::fromAscii(version_);
    if(vendor.toUpper().contains("NVIDIA"))
    {
       f.setVersion(4,0); //this don't work with ATI, on nVidia it returns 3.3 context if no 4 supported
    }
    f.setSwapInterval(1);
    setFormat(f);
*/

    glEnable(GL_TEXTURE_2D);

    //load the texture for the alpha mask
    //TODO: Skin support for this texture OR configuration option!
    QString checkmarkTexture = ":/resources/RES/alpha.png";
    QImage i = QGLWidget::convertToGLFormat(QImage(checkmarkTexture));
    if(i.isNull())
    {
        gcprint("Unable to load texture");
    }
    else
    {
        gcprint("Texture loaded");
        glGenTextures(1,&checkmarkT);
        glBindTexture(GL_TEXTURE_2D,checkmarkT);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,i.width(),i.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,i.bits());
    }

    //misc
    glClearColor(0.8f,0.8f,0.8f,1.0f);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //after GL initialization, layers can be rendered!
    editor->loadScene();
    gcprint(editor);
    editor->initialized = true;
    editor->restoreState( editor->creatorIDE->settings->value("SceneEditor/State").toByteArray() );
}

void sceneview::paintGL()
{

    //viewport
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0,width(),height(),0,-1000,1000);

    //clear
    glClearColor(0.8f,0.8f,0.8f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(extent-xx,extent-yy,0);
    glScalef(zoom,zoom,1);

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
        //TODO: Draw them recursively
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
        //TODO: Draw them
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
            /*
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
            /**/
        }
    }


    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(width(),height());
    glEnd();
}
void sceneview::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
}
void sceneview::mousePressEvent(QMouseEvent *e)
{

}
void sceneview::mouseReleaseEvent(QMouseEvent *e)
{

}
void sceneview::keyPressEvent(QKeyEvent *e)
{

}
void sceneview::mouseMoveEvent(QMouseEvent *e)
{

}
void sceneview::resizeEvent(QResizeEvent *e)
{
    //WHY????
    gcprint("Resising sceneview...");
    e->accept();
    resizeGL(e->size().width(), e->size().height());
}
