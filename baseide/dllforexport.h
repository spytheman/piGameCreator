#ifndef DLLFOREXPORT_H
#define DLLFOREXPORT_H

#include "dllforexport.h"
#include <QString>

class dllForExport
{
public:
    dllForExport(QString fn);
    bool isValid();

    //DLL funcs
    QString getName();
    QString getDescription();
    bool run(QString projectfile);
    bool debug(QString projectfile);
    bool clean(QString projectfile);
    bool build(QString projectfile, bool final);
    QString configure(QString projectfile); //filename!
    QString parameters(QString projectfile); //is this even needed or is exporter-specific?
    QString binaryFile();
    QString exporterName();

private:
    QString binfilename, exportername;
    bool valid;

    QString (*pname)();
    QString (*pdesc)();
    bool (*prun)(QString);
    bool (*pdebug)(QString);
    bool (*pclean)(QString);
    bool (*pbuild)(QString, bool);
    QString (*pconfigure)(QString);
    QString (*pparameters)(QString);

};

#endif // DLLFOREXPORT_H
