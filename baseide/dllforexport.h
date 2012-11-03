#ifndef DLLFOREXPORT_H
#define DLLFOREXPORT_H

#include "../sharedcode/globals.h"
#include <QString>


class dllForExport
{
public:
    dllForExport(QString fn);
    bool isValid();

    //DLL funcs
    QString getName();
    QString getDescription();
    bool run(QString projectfile, QString target);
    bool debug(QString projectfile, QString target);
    bool clean(QString projectfile, QString target);
    bool build(QString projectfile, QString target, bool final);
    QString configure(QString projectfile); //filename!
    QString parameters(QString projectfile); //is this even needed or is exporter-specific?
    QString binaryFile();
    QString exporterName();
    QList<compileerror> getCompileErrors();
    void clearCompileErrors();

private:
    QString binfilename, exportername;
    bool valid;

    QString (*pname)();
    QString (*pdesc)();
    bool (*prun)(QString,QString);
    bool (*pdebug)(QString,QString);
    bool (*pclean)(QString,QString);
    bool (*pbuild)(QString,QString, bool);
    QString (*pconfigure)(QString);
    QString (*pparameters)(QString);
    QList<compileerror> (*pgetcompileerrors)();
    void (*pclearcompileerrors)();

};

#endif // DLLFOREXPORT_H
