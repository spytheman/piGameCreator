#include <GL/glew.h>
#include <QFile>
#include <QGLWidget>
#include "glhelp.h"
#include "../../sharedcode/globals.h"


gcGLtexture::gcGLtexture(GLenum target)
{
    glGenTextures(1,&texId);
    GLuint i = glGetError();
    if(glGetError()!=GL_NO_ERROR)
        gcprint( (char*)gluErrorString(i) );

}
gcGLtexture::gcGLtexture(QString filename, GLenum target)
{
    glGenTextures(1,&texId);
    GLuint i = glGetError();
    if(glGetError()!=GL_NO_ERROR)
        gcprint( (char*)gluErrorString(i) );

    load(filename);

}

bool gcGLtexture::bind(GLenum target)
{
    glBindTexture(target,texId);
    return true;
}

bool gcGLtexture::load(QString fn, GLenum target)
{
    if(!QFile::exists(fn))
    {
        gcprint("Unable to load "+fn);
        return false;
    }
    gcprint(texId);
    bind(target);
    QImage i = QGLWidget::convertToGLFormat(QImage(fn));
    width = i.width();
    height = i.height();
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGBA,i.width(),i.height(),GL_RGBA,GL_UNSIGNED_BYTE,i.bits());
}

gcGLtexture::~gcGLtexture()
{
    gcprint("Deleting texid "+QString::number(texId));
    glDeleteTextures(1,&texId);
}
