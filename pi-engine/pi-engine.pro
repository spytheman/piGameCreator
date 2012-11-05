TEMPLATE = lib
CONFIG -= qt

SOURCES += \
    interface.cpp \
    Window.cpp

QMAKE_CXXFLAGS  += -msse -msse2 -msse3

DEFINES += FREEGLUT_STATIC GLEW_STATIC CPPENGINE
LIBS += -lglut -lGLEW -lGL
INCLUDEPATH += ../glew/include ../glew/lib ../freeglut/include ../baseide/release/haxe/lib/hxcpp/2,10/include
DESTDIR = .
win32 {
    QMAKE_POST_LINK = copy /y "debug\pi-engine.dll" "..\baseide\release\data\pi-engine\Engine_CPP\pi-engine.dll"
}
unix {
    QMAKE_POST_LINK = cp -a  "debug/pi-engine.so.1.0.0" "../baseide/release/data/pi-engine/Engine_CPP/pi-engine.dll"
}    

HEADERS += \
    piengine.h
