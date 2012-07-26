#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit testlib #qtconcurrent


TARGET = baseide
TEMPLATE = app

INCLUDEPATH += ../freeglut/include
DEFINES += FREEGLUT_STATIC GLEW_STATIC CREATOR_IDE
# LIBS += ../freeglut/lib/libfreeglut32_static.a #-lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm -lQtWebkit4

SOURCES += main.cpp\
    mainwindow.cpp \
    splashscreen.cpp \
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
    workspacewidget.cpp \
    wwmainpage.cpp \
    gcide.cpp \
    threads/initthread.cpp \
    resourceeditor.cpp \
    ../sharedcode/gamescript.cpp \
    openedproject.cpp \
    model/projecttreemodel.cpp \
    dllforexport.cpp \
    dllforresourceeditor.cpp \
    newimage.cpp \
    inputresourcename.cpp \
    ../sharedcode/pgsparser.cpp \
    gameframeworkclassdef.cpp \
    scriptwindow.cpp \
    ntdialog.cpp \
    settingswindow.cpp \
    ../sharedcode/ideobjectrepresentation.cpp \
    ../sharedcode/rsgraphicseffect.cpp \
    ../sharedcode/frameworkdata.cpp \
    scripttestwindow.cpp \
    ../sharedcode/timer.cpp \
    codeeditor.cpp


HEADERS  += mainwindow.h \
    splashscreen.h \
    gcide.h \
    threads/initthread.h \
    resourceeditor.h \
    ../sharedcode/rssound.h \
    ../sharedcode/rsscene.h \
    ../sharedcode/rsmodel.h \
    ../sharedcode/rsimage.h \
    ../sharedcode/rsclass.h \
    ../sharedcode/resource.h \
    ../sharedcode/gameproject.h \
    workspacewidget.h \
    wwmainpage.h \
    ../sharedcode/gamescript.h \
    openedproject.h \
    model/projecttreemodel.h \
    dllforexport.h \
    dllforresourceeditor.h \
    editors/imgedit.h \
    newimage.h \
    inputresourcename.h \
    gameframeworkclassdef.h \
    scriptwindow.h \
    ntdialog.h \
    settingswindow.h \
    ../sharedcode/ideobjectrepresentation.h \
    ../sharedcode/rsgraphicseffect.h \
    ../sharedcode/frameworkdata.h \
    scripttestwindow.h \
    ../sharedcode/timer.h \
    codeeditor.h

FORMS    += mainwindow.ui \
    splashscreen.ui \
    wwmainpage.ui \
    newimage.ui \
    inputresourcename.ui \
    gameframeworkclassdef.ui \
    scriptwindow.ui \
    ntdialog.ui \
    settingswindow.ui \
    scripttestwindow.ui \
    buildtargets.ui

RESOURCES += \
    ../sharedcode/resources.qrc \
    res_ide.qrc \
    resources.qrc
