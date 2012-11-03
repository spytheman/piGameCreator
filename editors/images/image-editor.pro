#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit

QMAKE_CXXFLAGS  += -msse2 -msse

TARGET = imageeditor
TEMPLATE = lib
DEFINES += FREEGLUT_STATIC
# LIBS += ../../freeglut/lib/libfreeglut32_static.a ../../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm -lQtWebkit4
INCLUDEPATH += ../../glew/include ../../glew/lib ../../freeglut/include
QMAKE_POST_LINK = copy /y "..\dlls\imageeditor.dll" "..\..\baseide\release\editors\image-editor.dll"
DESTDIR = ../dlls

SOURCES +=  imgedit.cpp \
            imageeditor.cpp \
            ../../sharedcode/rsimage.cpp \
            ../../sharedcode/resource.cpp \
            ../../sharedcode/globals.cpp \
            ../../sharedcode/glhelp.cpp \
            ../../baseide/resourceeditor.cpp \
            ../../baseide/workspacewidget.cpp \
    ../../sharedcode/messageevent.cpp

HEADERS +=  imgedit.h \
            imageeditor.h \
            ../../sharedcode/rsimage.h \
            ../../sharedcode/resource.h \
            ../../sharedcode/glhelp.h \
            ../../baseide/resourceeditor.h \
            ../../baseide/workspacewidget.h \
    ../../sharedcode/messageevent.h


FORMS    += imageeditor.ui

RESOURCES += \
    ../../sharedcode/resources.qrc \
    ../../baseide/res_ide.qrc
