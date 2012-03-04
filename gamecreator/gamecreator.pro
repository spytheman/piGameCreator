#-------------------------------------------------
#
# piGameCreator multiplatform game development IDE
#
# GPLv3 preamble goes here for GPLd version,
# commercial for commercial version
#
#-------------------------------------------------

# Note that libzip and zlib folders' varsions are stripped
# in order to be able to do fast updates without many pain

CONFIG += ordered

INCLUDEPATH += ../glew/include ../glew/lib ../freeglut/include

LIBS += ../freeglut/lib/libfreeglut32_static.a ../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm

QT       += core gui webkit xml opengl xmlpatterns

TARGET = gamecreator
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    logwindow.cpp \
    gamecreator.cpp \
    mainpage.cpp \
    gameproject.cpp \
    projectmodel.cpp \
    imagewindow.cpp \
    saveornot.cpp \
    qtwin.cpp \
    gcfileformat.cpp \
    dllforexport.cpp \
    progressdialog.cpp \
    imgwframesmodel.cpp \
    imgwpreview.cpp \
    resourceeditor.cpp \
    platformdependent.cpp \
    scriptwindow.cpp \
    pgsparser.cpp \
    srcSettings/settingswindow.cpp \
    scripttestwindow.cpp \
    classwindow.cpp \
    srcClass/getimageormodel.cpp \
    srcClass/editvardialog.cpp \
    srcClass/variable.cpp \
    srcClass/classwindoweventfilters.cpp \
    srcClass/addeventwindow.cpp \
    srcClass/getclassresource.cpp \
    srcClass/getkeyevent.cpp \
    srcClass/getmouseevent.cpp \
    srcClass/addfunction.cpp \
    sceneeditor.cpp \
    srcScene/sceneview.cpp \
    glhelp.cpp \
    qwidgetwithclosesignal.cpp \
    buildtargets.cpp \
    extapi.cpp \
    skintestwindow.cpp \
    gameframeworkclassdef.cpp \
    ntdialog.cpp \
    overlay.cpp


HEADERS  += mainwindow.h \
    logwindow.h \
    gamecreator.h \
    mainpage.h \
    gameproject.h \
    projectmodel.h \
    imagewindow.h \
    saveornot.h \
    qtwin.h \
    gcfileformat.h \
    dllforexport.h \
    progressdialog.h \
    imgwframesmodel.h \
    imgwpreview.h \
    resourceeditor.h \
    scriptwindow.h \
    pgsparser.h \
    srcSettings/settingswindow.h \
    scripttestwindow.h \
    classwindow.h \
    srcClass/getimageormodel.h \
    srcClass/editvardialog.h \
    srcClass/variable.h \
    srcClass/classwindoweventfilters.h \
    srcClass/addeventwindow.h \
    srcClass/getclassresource.h \
    srcClass/getkeyevent.h \
    srcClass/getmouseevent.h \
    srcClass/addfunction.h \
    sceneeditor.h \
    srcScene/sceneview.h \
    glhelp.h \
    qwidgetwithclosesignal.h \
    buildtargets.h \
    extapi.h \
    skintestwindow.h \
    gameframeworkclassdef.h \
    ntdialog.h \
    overlay.h


FORMS    += mainwindow.ui \
    logwindow.ui \
    mainpage.ui \
    imagewindow.ui \
    saveornot.ui \
    progressdialog.ui \
    scriptwindow.ui \
    srcSettings/settingswindow.ui \
    scripttestwindow.ui \
    classwindow.ui \
    srcClass/getimageormodel.ui \
    srcClass/editvardialog.ui \
    srcClass/addeventwindow.ui \
    srcClass/getclassresource.ui \
    srcClass/getkeyevent.ui \
    srcClass/getmouseevent.ui \
    srcClass/addfunction.ui \
    sceneeditor.ui \
    buildtargets.ui \
    skintestwindow.ui \
    gameframeworkclassdef.ui \
    ntdialog.ui

RESOURCES += \
    resources.qrc

DEFINES += GLEW_STATIC FREEGLUT_STATIC
