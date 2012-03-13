#-------------------------------------------------
#
# Project created by QtCreator 2011-03-21T04:53:56
#
#-------------------------------------------------

QT       += xml gui


INCLUDEPATH += ../../gamecreator

TARGET = cpptarget
TEMPLATE = lib

DEFINES += CPPTARGET_LIBRARY

SOURCES += cppexport.cpp \
    config.cpp \
    compilingstatus.cpp \
    ../gcexporter.cpp \
    ../../gamecreator/gameproject.cpp \
    ../../gamecreator/gcfileformat.cpp

HEADERS += \
    config.h \
    compilingstatus.h \
    ../gcexporter.h \
    cppexport.h \
    ../../gamecreator/gameproject.h \
    ../../gamecreator/gcfileformat.h

Release:DESTDIR = ../cpp

FORMS += \
    config.ui \
    compilingstatus.ui

QMAKE_POST_LINK = copy /y "cpptarget.dll" "..\..\gamecreator\release\targets\cpp\target.dll"

RESOURCES += \
    ../../gamecreator/resources.qrc
