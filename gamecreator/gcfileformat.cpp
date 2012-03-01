#include "gcfileformat.h"

bool gcfileformat::canImport(){return Import;}
bool gcfileformat::canExport(){return Export;}
QString gcfileformat::filter(){return Filter;}

gcfileformat::gcfileformat(gameproject *g)
{
    gp = g;
}

gcfileformat::gcfileformat()
{
    gp = 0;
}

gcfileformat* gcfileformat::getFormat(gameproject *g, QString format)
{
    return 0; //not used
}

bool gcfileformat::ExportToFile(QString s)
{
    return true;
}
