#include "dllforexport.h"
#include "gamecreator.h"
#include <QLibrary>
#include <QFileInfo>

dllforexport::dllforexport(QString fn)
{
    exportername = fn;
    QLibrary l("targets/"+fn+"/target");
    l.load();
    binfilename = l.fileName();
    if(l.isLoaded())
    {
        //init the functions
        pname = (QString(*)())l.resolve("getName");
        pdesc = (QString(*)())l.resolve("getDescription");

        //build, debug and run
        prun   = (bool(*)(QString))l.resolve("run");
        pdebug = (bool(*)(QString))l.resolve("debug");
        pclean = (bool(*)(QString))l.resolve("clean");
        pbuild = (bool(*)(QString,bool))l.resolve("build");
        pconfigure = (QString(*)(QString))l.resolve("configure");
        pparameters =(QString(*)(QString))l.resolve("parameters");

        valid = true;
        gcprint("Exporter: "+getName());
        gcprint(getDescription());
    }
    else
    {
        gcprint("Failed to load exporter "+fn);
        valid = false;
    }
}

bool dllforexport::isValid()
{
    return valid;
}

QString dllforexport::getName()
{
    if(pname!=0)return pname();
}
QString dllforexport::getDescription()
{
    if(pdesc!=0)return pdesc();
}
bool dllforexport::run(QString projectfile)
{
    if(prun!=0)return prun(projectfile);
    else gcerror(QString("The exporter %1's RUN function is not implemented").arg(exportername));
}

bool dllforexport::debug(QString projectfile)
{
    if(pdebug!=0)return pdebug(projectfile);
    else gcerror(QString("The exporter %1's DEBUG function is not implemented").arg(exportername));
}

bool dllforexport::clean(QString projectfile)
{
    if(pclean!=0)return pclean(projectfile);
    else gcerror(QString("The exporter %1's CLEAN function not exists").arg(exportername));
}

bool dllforexport::build(QString projectfile, bool final)
{
    if(pbuild!=0)return pbuild(projectfile,final);
    else gcerror(QString("The exporter %1's BUILD function not exists").arg(exportername));
}
QString dllforexport::binaryFile()
{
    return binfilename;
}
QString dllforexport::exporterName()
{
    return exportername;
}

QString dllforexport::configure(QString projectfile)
{
    if(pconfigure!=0)return pconfigure(projectfile);
    else {gcerror(QString("The exporter %1's configuration function not exists").arg(exportername));return "";}
}
