#include <QString>
#include <QDebug>
#include "config.h"
#include "cppexport.h"

/*
    All these functions are required for a plugin DLL to work.
*/

extern "C" QString getName()
{
    return "Windows C++";
}

extern "C" QString getDescription()
{
    return "Builds portable C++ projects based on OpenGL, Bullet Physics, AssImp and OpenAL\n"
            "The projects can run on every platform that supports these libraries\n"
            "About licensing, read the ZLIB and BSD licenses.";
}

extern "C" bool build(QString projectfile, bool final)
{
    qDebug() << "BUILDING APPLICATION: \n"+projectfile;
    return true;
}

extern "C" bool run(QString projectfile)
{
    qDebug() << "RUNNING APPLICATION: \n"+projectfile;
    return true;
}

extern "C" bool debug(QString projectfile)
{
    qDebug() << "DEBUGGING APPLICATION: \n"+projectfile;
    return true;
}

extern "C" bool clean(QString projectfile)
{
    return true;
}

extern "C" QString configure(QString)
{
    Config c;
    c.exec();
    return QString();
}

extern "C" QString parameters(QString)
{

}

bool cppExporter::exportResource(QString name)
{
    qDebug() << "Exporting " + name;
}
