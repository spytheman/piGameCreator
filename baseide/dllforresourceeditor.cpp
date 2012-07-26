#include "dllforresourceeditor.h"
#include "gcide.h"
#include <QLibrary>
#include <QFileInfo>

dllForResourceEditor::dllForResourceEditor(QString fn)
{
    pluginname = fn;
    QLibrary l("editors/"+fn);
    l.load();
    binfilename = l.fileName();
    if(l.isLoaded())
    {
        //init the functions
        pname = (QString(*)())l.resolve("getName");
        pdesc = (QString(*)())l.resolve("getDescription");
        pInit = (bool(*)())l.resolve("init");
        pLoad = (bool(*)())l.resolve("load");
        pSave = (bool(*)())l.resolve("save");
        pSaveAs = (bool(*)(QString))l.resolve("saveAs");

        pGetResourceKinds=(QStringList(*)())l.resolve("getResourceKinds");
        pGetResourceTypes=(QStringList(*)())l.resolve("getResourceTypes");
        pContextMenuItems=(QList<QAction*>(*)(QString, QString, bool, gcresource*))l.resolve("contextMenuItems");
        pGetGUI=(ResourceEditor*(*)(QString, QString, gcresource*))l.resolve("getGUI");
        pNewResources=(QList<vObject>(*)())l.resolve("newResources");
        pCreateResource=(gcresource*(*)(QString, QString, QString))l.resolve("createResource");

        valid = true;
        gcprint("----------------------------------------------------\nEditor: "+getName());
        gcprint(getDescription());
        gcprint("   Edits: "+ getResourceKinds().join(", "));
        gcprint("   Types: "+ getResourceTypes().join(", "));
        gcprint("   NEW entries: ");
        foreach(vObject o,newResources())
            gcprint("\t"+o.value("title").toString()+"\n\n\t\t"+o.value("description").toString());
    }
    else
    {
        gcprint("Failed to load editor "+fn);
        valid = false;
    }
}
bool dllForResourceEditor::isValid()
{
    return valid;
}

QString dllForResourceEditor::getName()
{
    if(pname!=0)return pname();
    else valid=false;
    return "";
}
QString dllForResourceEditor::getDescription()
{
    if(pdesc!=0)return pdesc();
    else valid=false;
    return "";
}
QStringList dllForResourceEditor::getResourceKinds()
{
    if(pGetResourceKinds)return pGetResourceKinds();
    else gcprint("The resource editor "+binaryFile()+" does not implement the getResourceKinds() API");
    return QStringList();
}
QStringList dllForResourceEditor::getResourceTypes()
{
    if(pGetResourceTypes)return pGetResourceTypes();
    else gcprint("The resource editor "+binaryFile()+" does not implement the getResourceTypes() API");
    return QStringList();
}
QList<QAction*> dllForResourceEditor::contextMenuItems(QString kind, QString type, bool folder, gcresource *res)
{
    if(pContextMenuItems)return pContextMenuItems(kind,type,folder,res);
    return QList<QAction*>();
}
ResourceEditor* dllForResourceEditor::getGUI(QString kind, QString type, gcresource *res)
{
    if(pGetGUI)return pGetGUI(kind,type,res);
    else gcmessage("The resource editor "+binaryFile()+" does not implement the getGUI() API");
    return 0;
}
QList<vObject> dllForResourceEditor::newResources()
{
    if(pNewResources)return pNewResources();
    else gcprint("The resource editor "+binaryFile()+" does not implement the newResources() API");
    return QList<vObject>();
}
gcresource* dllForResourceEditor::createResource(QString kind, QString type, QString name)
{
    if(pCreateResource)return pCreateResource(kind,type,name);
    else return 0;
}
bool dllForResourceEditor::init()
{
    if(pInit!=0)return pInit();
    else valid=false;
    return 0;
}
bool dllForResourceEditor::save()
{
    if(pSave!=0)return pSave();
    else valid=false;
    return 0;
}
bool dllForResourceEditor::load()
{
    if(pLoad!=0)return pLoad();
    else valid=false;
    return 0;
}

bool dllForResourceEditor::saveAs(QString newname)
{
    if(pSaveAs!=0)return pSaveAs(newname);
    else valid=false;
    return 0;
}
QString dllForResourceEditor::binaryFile()
{
    return binfilename;
}
