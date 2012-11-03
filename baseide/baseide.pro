#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit testlib network #qtconcurrent


TARGET = baseide
TEMPLATE = app

INCLUDEPATH += ../freeglut/include
DEFINES += FREEGLUT_STATIC GLEW_STATIC CREATOR_IDE
# LIBS += ../freeglut/lib/libfreeglut32_static.a #-lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm -lQtWebkit4

SOURCES += main.cpp \
    mainwindow.cpp \
    splashscreen.cpp \
    ../sharedcode/pgshighlighter.cpp \
    ../sharedcode/qtwin.cpp \
    ../sharedcode/globals.cpp \
    ../sharedcode/gcexporter.cpp \
    ../sharedcode/rssound.cpp \
    ../sharedcode/rsscene.cpp \
    ../sharedcode/rsmodel.cpp \
    ../sharedcode/rsimage.cpp \
    ../sharedcode/rsclass.cpp \
    ../sharedcode/resource.cpp \
    ../sharedcode/gameproject.cpp \
    ../sharedcode/gamescript.cpp \
    ../sharedcode/pgsparser.cpp \
    ../sharedcode/ideobjectrepresentation.cpp \
    ../sharedcode/rsgraphicseffect.cpp \
    ../sharedcode/frameworkdata.cpp \
    ../sharedcode/idesettings.cpp \
    ../sharedcode/timer.cpp \
    workspacewidget.cpp \
    wwmainpage.cpp \
    gcide.cpp \
    threads/initthread.cpp \
    resourceeditor.cpp \  
    openedproject.cpp \
    model/projecttreemodel.cpp \
    dllforexport.cpp \
    dllforresourceeditor.cpp \
    newimage.cpp \
    inputresourcename.cpp \
    ntdialog.cpp \
    settingswindow.cpp \
    scripttestwindow.cpp \
    codeeditor.cpp \
    buildtargets.cpp \
    ../sharedcode/resourcetree.cpp \
    ../sharedcode/imageio.cpp \
    newresource.cpp \
    newprojectwizard.cpp \
    ../sharedcode/selecticon.cpp \
    ../sharedcode/imagepreviewer.cpp \
    ../sharedcode/filereference.cpp \
    ../sharedcode/progressdialog.cpp \
    projectdashboard.cpp \
    skintestwindow.cpp \
    ../sharedcode/messageevent.cpp



HEADERS  += mainwindow.h \
    splashscreen.h \
    ../sharedcode/rssound.h \
    ../sharedcode/rsscene.h \
    ../sharedcode/rsmodel.h \
    ../sharedcode/rsimage.h \
    ../sharedcode/rsclass.h \
    ../sharedcode/resource.h \
    ../sharedcode/gameproject.h \
    ../sharedcode/ideobjectrepresentation.h \
    ../sharedcode/rsgraphicseffect.h \
    ../sharedcode/frameworkdata.h \
    ../sharedcode/timer.h \
    ../sharedcode/idesettings.h \
    ../sharedcode/gamescript.h \
    gcide.h \
    threads/initthread.h \
    resourceeditor.h \
    workspacewidget.h \
    wwmainpage.h \
    openedproject.h \
    model/projecttreemodel.h \
    dllforexport.h \
    dllforresourceeditor.h \
    editors/imgedit.h \
    newimage.h \
    inputresourcename.h \
    ntdialog.h \
    settingswindow.h \
    scripttestwindow.h \
    codeeditor.h \
    buildtargets.h \
    pgshighlighter.h \
    ../sharedcode/resourcetree.h \
    ../sharedcode/imageio.h \
    newresource.h \
    newprojectwizard.h \
    ../sharedcode/selecticon.h \
    ../sharedcode/imagepreviewer.h \
    ../sharedcode/filereference.h \
    ../sharedcode/progressdialog.h \
    projectdashboard.h \
    skintestwindow.h \
    ../sharedcode/messageevent.h


FORMS    += mainwindow.ui \
    splashscreen.ui \
    wwmainpage.ui \
    newimage.ui \
    inputresourcename.ui \
    ntdialog.ui \
    settingswindow.ui \
    scripttestwindow.ui \
    buildtargets.ui \
    newresource.ui \
    newprojectwizard.ui \
    ../sharedcode/selecticon.ui \
    ../sharedcode/imagepreviewer.ui \
    ../sharedcode/progressdialog.ui \
    projectdashboard.ui \
    skintestwindow.ui

RESOURCES += \
    ../sharedcode/resources.qrc \
    res_ide.qrc
