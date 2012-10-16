#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit

QMAKE_CXXFLAGS  += -msse2 -msse

TARGET = sceneeditor
TEMPLATE = lib
DEFINES += FREEGLUT_STATIC GLEW_STATIC
LIBS += ../../freeglut/lib/libfreeglut32_static.a ../../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm -lQtWebkit4
INCLUDEPATH += ../../glew/include ../../glew/lib ../../freeglut/include
QMAKE_POST_LINK = copy /y "..\dlls\sceneeditor.dll" "..\..\baseide\release\editors\scene-editor.dll"
DESTDIR = ../dlls

SOURCES +=  sceneedit.cpp \
            sceneeditor.cpp \
            qwidgetwithclosesignal.cpp \
            ../../sharedcode/rsscene.cpp \
            ../../sharedcode/rsimage.cpp \
            ../../sharedcode/rsclass.cpp \
            ../../sharedcode/resource.cpp \
            ../../sharedcode/globals.cpp \
            ../../sharedcode/gameproject.cpp \
            ../../sharedcode/glhelp.cpp \
            ../../baseide/resourceeditor.cpp \
            ../../baseide/workspacewidget.cpp \
            sceneview.cpp \
    ../../sharedcode/frameworkdata.cpp \
    ../../sharedcode/rssound.cpp \
    ../../sharedcode/rsmodel.cpp \
    ../../sharedcode/rsgraphicseffect.cpp \
    ../../sharedcode/resourcetree.cpp \
    ../../sharedcode/idesettings.cpp

HEADERS +=  sceneedit.h \
            sceneeditor.h \
            qwidgetwithclosesignal.h \
            ../../sharedcode/rsscene.h \
            ../../sharedcode/rsimage.h \
            ../../sharedcode/rsclass.h \
            ../../sharedcode/resource.h \
            ../../sharedcode/gameproject.h \
            ../../baseide/resourceeditor.h \
            ../../baseide/workspacewidget.h \
    sceneeditor.h \
    sceneview.h \
    ../../sharedcode/frameworkdata.h \
    ../../sharedcode/resourcetree.h \
    ../../sharedcode/idesettings.h


FORMS    += sceneeditor.ui \


RESOURCES += \
    ../../sharedcode/resources.qrc \
    ../../baseide/res_ide.qrc
