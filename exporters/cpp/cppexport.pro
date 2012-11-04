#-------------------------------------------------
#
# Project created by QtCreator 2011-03-21T04:53:56
#
#-------------------------------------------------

QT       += xml gui xmlpatterns

INCLUDEPATH += ../../gamecreator ..

TARGET = cpptarget
TEMPLATE = lib

DEFINES += CPPTARGET_LIBRARY

SOURCES += cppexport.cpp \
    config.cpp \
    ../../sharedcode/gcexporter.cpp \
    ../../sharedcode/progressdialog.cpp \
    ../../sharedcode/gameproject.cpp \
    ../../sharedcode/globals.cpp \
    ../../sharedcode/rssound.cpp \
    ../../sharedcode/rsscene.cpp \
    ../../sharedcode/rsmodel.cpp \
    ../../sharedcode/rsimage.cpp \
    ../../sharedcode/rsgraphicseffect.cpp \
    ../../sharedcode/rsclass.cpp \
    ../../sharedcode/resourcetree.cpp \
    ../../sharedcode/resource.cpp \
    ../../sharedcode/frameworkdata.cpp

HEADERS += \
    config.h \
    ../../sharedcode/gcexporter.h \
    cppexport.h \
    ../../sharedcode/progressdialog.h \
    ../../sharedcode/gameproject.h \
    ../../sharedcode/globals.h \
    ../../sharedcode/rssound.h \
    ../../sharedcode/rsscene.h \
    ../../sharedcode/rsmodel.h \
    ../../sharedcode/rsimage.h \
    ../../sharedcode/rsgraphicseffect.h \
    ../../sharedcode/rsclass.h \
    ../../sharedcode/resourcetree.h \
    ../../sharedcode/resource.h \
    ../../sharedcode/frameworkdata.h

DESTDIR = ../cpp

FORMS += \
    config.ui \
    ../../sharedcode/progressdialog.ui

win32 {
    QMAKE_POST_LINK = copy /y "cpptarget.dll" "..\..\baseide\release\targets\cpp\target.dll"
}
linux {
    QMAKE_POST_LINK = cp -a "libcpptarget.so.1.0.0" "../../baseide/release/targets/cpp/target.so"
}
QMAKE_CXXFLAGS  += -msse2 -msse

RESOURCES += \
    ../../sharedcode/resources.qrc
