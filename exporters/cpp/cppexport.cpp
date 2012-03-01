#include <QString>
#include <QDebug>

//gamecreator includes
#include "extapi.h"
#include "gameproject.h"

//now all the DLL exported functions come

extern "C" QString getName()
{
    return "C++ / MingW";
}

extern "C" QString getDescription()
{
    return "Builds portable C++ projects based on OpenGL, Bullet Physics, AssImp and OpenAL\n"
            "The projects can run on every platform that supports these libraries\n"
            "About licensing, read the ZLIB and BSD licenses."
            "If you use Qt, you must comply with LGPL as well.";
}

extern "C" bool build(QString projectfile, bool final)
{

}

extern "C" bool run(QString projectfile)
{
    qDebug() << "RUNNING APPLICATION: \n"+projectfile;
}

extern "C" bool debug(QString projectfile)
{

}

extern "C" bool clean(QString projectfile)
{

}

extern "C" QString configure(QString)
{
    return QString();
}

extern "C" QString parameters(QString)
{

}
