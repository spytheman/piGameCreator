#ifndef GLHELP_H
#define GLHELP_H

#include <GL/gl.h>
#include <QImage>


class gcGLtexture
{

public:

    gcGLtexture(GLenum target = GL_TEXTURE_2D);
    gcGLtexture(QString filename, GLenum target = GL_TEXTURE_2D);
    bool load(QString filename, GLenum target = GL_TEXTURE_2D);
    bool bind(GLenum target = GL_TEXTURE_2D);
    GLuint texId;
    GLfloat width,height;
    ~gcGLtexture();
};


#endif // GLHELP_H
