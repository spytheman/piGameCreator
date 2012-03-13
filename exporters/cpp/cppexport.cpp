#include <QString>
#include <QDebug>
#include "config.h"
#include "compilingstatus.h"
#include "cppexport.h"

bool cppExporter::exportResource(QString file)
{
    qDebug() << "Exporting " + file;
}

/*
    All these functions are required for a plugin DLL to work.
*/

extern "C" QString getName()
{
    return "C++ / MingW";
}

extern "C" QString getDescription()
{
    return "Builds portable C++ projects based on OpenGL, Bullet Physics, AssImp and OpenAL\n"
            "The projects can run on every platform that supports these libraries\n"
            "About licensing, read the ZLIB and BSD licenses.";
}

extern "C" bool build(QString projectfile, bool final)
{
    CompilingStatus c;
    c.build();
    c.exec();
    return true;
}

extern "C" bool run(QString projectfile)
{
    CompilingStatus c;
    c.project = projectfile;
    c.run();
    c.exec();
    return true;
//    qDebug() << "RUNNING APPLICATION: \n"+projectfile;
}

extern "C" bool debug(QString projectfile)
{
    CompilingStatus c;
    c.project = projectfile;
    c.debug();
    c.exec();
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
