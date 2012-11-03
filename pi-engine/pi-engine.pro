TEMPLATE = lib
CONFIG -= qt

SOURCES += \
    interface.cpp \

QMAKE_CXXFLAGS  += -msse -msse2 -msse3

DEFINES += FREEGLUT_STATIC GLEW_STATIC CPPENGINE
LIBS += ../freeglut/lib/libfreeglut32_static.a ../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm
INCLUDEPATH += ../glew/include ../glew/lib ../freeglut/include ../baseide/release/haxe/lib/hxcpp/2,10/include
DESTDIR = .
QMAKE_POST_LINK = copy /y "debug\pi-engine.dll" "..\baseide\release\data\pi-engine\Engine_CPP\pi-engine.dll"

HEADERS +=
