#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit network

QMAKE_CXXFLAGS  += -msse2 -msse

TARGET = classeditor
TEMPLATE = lib
DEFINES += FREEGLUT_STATIC
# LIBS += ../../freeglut/lib/libfreeglut32_static.a ../../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm -lQtWebkit4
INCLUDEPATH += ../../glew/include ../../glew/lib ../../freeglut/include
QMAKE_POST_LINK = copy /y "..\dlls\classeditor.dll" "..\..\baseide\release\editors\class-editor.dll"
DESTDIR = ../dlls

SOURCES +=  classedit.cpp \
        ../../sharedcode/globals.cpp \
    eventclass.cpp \
    codeclass.cpp \
    getrepresentation.cpp \
    getmouseevent.cpp \
    getkeyevent.cpp \
    getclassresource.cpp \
    editvardialog.cpp \
    classwindoweventfilters.cpp \
    addfunction.cpp \
    addeventwindow.cpp \
    variable.cpp \
    ../../sharedcode/rsclass.cpp \
    ../../baseide/workspacewidget.cpp \
    ../../baseide/resourceeditor.cpp \
    ../../sharedcode/gameproject.cpp \
    ../../sharedcode/pgsparser.cpp \
    ../../sharedcode/resource.cpp \
    ../../sharedcode/rssound.cpp \
    ../../sharedcode/rsscene.cpp \
    ../../sharedcode/rsmodel.cpp \
    ../../sharedcode/rsimage.cpp \
    ../../sharedcode/rsgraphicseffect.cpp \
    ../../sharedcode/frameworkdata.cpp \
    ../../baseide/codeeditor.cpp \
    ../../sharedcode/idesettings.cpp \
    ../../sharedcode/pgshighlighter.cpp \
    ../../sharedcode/resourcetree.cpp \
    ../../sharedcode/progressdialog.cpp \
    ../../sharedcode/messageevent.cpp

HEADERS += \
    variable.h \
    getmouseevent.h \
    getkeyevent.h \
    getrepresentation.h \
    getclassresource.h \
    eventclass.h \
    editvardialog.h \
    codeclass.h \
    classwindoweventfilters.h \
    addfunction.h \
    addeventwindow.h \
    ../../sharedcode/rsclass.h \
    ../../baseide/workspacewidget.h \
    ../../baseide/resourceeditor.h \
    ../../sharedcode/gameproject.h \
    ../../sharedcode/pgsparser.h \
    ../../sharedcode/resource.h \
    ../../sharedcode/rssound.h \
    ../../sharedcode/rsscene.h \
    ../../sharedcode/rsmodel.h \
    ../../sharedcode/rsimage.h \
    ../../sharedcode/rsgraphicseffect.h \
    ../../sharedcode/frameworkdata.h \
    ../../baseide/codeeditor.h \
    ../../sharedcode/idesettings.h \
    ../../sharedcode/pgshighlighter.h \
    ../../sharedcode/resourcetree.h \
    ../../sharedcode/progressdialog.h \
    ../../sharedcode/messageevent.h

FORMS    += eventclass.ui \
    codeclass.ui \
    getmouseevent.ui \
    getkeyevent.ui \
    getclassresource.ui \
    editvardialog.ui \
    addfunction.ui \
    addeventwindow.ui \
    getrepresentation.ui \
    ../../sharedcode/progressdialog.ui

RESOURCES += \
    ../../sharedcode/resources.qrc \
    ../../baseide/res_ide.qrc \

OTHER_FILES +=
