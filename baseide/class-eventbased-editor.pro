#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T19:29:11
#
#-------------------------------------------------

QT       += core gui xml opengl xmlpatterns webkit


TARGET = baseide
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    splashscreen.cpp \
    ../sharedcode/qtwin.cpp \
    ../sharedcode/globals.cpp \
    ../sharedcode/gcexporter.cpp \
    gcide.cpp \
    threads/initthread.cpp \
    resourceeditor.cpp \
    ../sharedcode/rssound.cpp \
    ../sharedcode/rsscene.cpp \
    ../sharedcode/rsmodel.cpp \
    ../sharedcode/rsimage.cpp \
    ../sharedcode/rsclass.cpp \
    ../sharedcode/resource.cpp \
    ../sharedcode/gameproject.cpp \
    workspacewidget.cpp \
    wwmainpage.cpp \
    ../sharedcode/gamescript.cpp \
    openedproject.cpp \
    ../sharedcode/rsworld.cpp \
    model/projecttreemodel.cpp

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
    model/projecttreemodel.h

FORMS    += mainwindow.ui \
    splashscreen.ui \
    wwmainpage.ui

RESOURCES += \
    ../sharedcode/resources.qrc \
    res_ide.qrc
