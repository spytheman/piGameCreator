#include <QString>
#include <QDebug>
#include "config.h"
#include "compilingstatus.h"
#include "cppexport.h"
#include <xmmintrin.h>

bool cppExporter::exportResource(QString file)
{
    qDebug() << "Exporting " + file;
}

/*
    All these functions are required for a plugin DLL to work.
*/

extern "C" QString getName()
{
    __m128 a, b;
    a = _mm_set_ps(1.0f,2.0f,-1.0f,0.0f);
    b = _mm_set_ps1(3.0f);
    __m128 result = _mm_mul_ps(a,b);

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
