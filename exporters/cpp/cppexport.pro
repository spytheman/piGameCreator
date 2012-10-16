#-------------------------------------------------
#
# Project created by QtCreator 2011-03-21T04:53:56
#
#-------------------------------------------------

QT       += xml gui xmlpatterns

INCLUDEPATH += ../../gamecreator

TARGET = cpptarget
TEMPLATE = lib

DEFINES += CPPTARGET_LIBRARY

SOURCES += cppexport.cpp \
    config.cpp \
    ../../sharedcode/gcexporter.cpp

HEADERS += \
    config.h \
    ../../sharedcode/gcexporter.h \
    cppexport.h

DESTDIR = ../cpp

FORMS += \
    config.ui

QMAKE_POST_LINK = copy /y "cpptarget.dll" "..\..\baseide\release\targets\cpp\target.dll"

QMAKE_CXXFLAGS  += -msse2 -msse

RESOURCES += \
    ../../sharedcode/resources.qrc
