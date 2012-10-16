#include "eventclass.h"
#include "codeclass.h"
#include "../../sharedcode/globals.h"
#include "../../sharedcode/resource.h"
#include "../../sharedcode/rsclass.h"
#include "../../baseide/resourceeditor.h"
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QPushButton>
#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT QString getName()
{
    return "Class editor";
}

DLLEXPORT QString getDescription()
{
    return "The default class editor for pi|engine CREATOR IDE";
}

DLLEXPORT QStringList getResourceKinds()
{
    return QStringList("class");
}

DLLEXPORT QStringList getResourceTypes()
{
    QStringList types;
    types << "codebased" << "eventbased" << "*";
    return types;
}

DLLEXPORT QList<vObject> newResources()
{
    //  title   description     icon    kind    type
    QList<vObject> res;

    //New image
    vObject o;
    o["kind"]="class";
    o["type"]="eventbased";
    o["title"]="New event-based class";
    o["description"]="Create a class by defining events";
    o["icon"]=ffficon("brick");
    res.append(o);
    o["kind"]="class";
    o["type"]="codebased";
    o["title"]="New code-based class";
    o["description"]="Write your class definition by hand";
    o["icon"]=ffficon("brick");
    res.append(o);
    return res;
}

DLLEXPORT QList<QAction*> contextMenuItems(QString kind, QString type, bool folder, gcresource* resource)
{
    QList<QAction*> res;
    if(kind=="class" && type=="eventbased" )
    {
        QAction* a = new QAction(ffficon("page_white_text"), "Convert to code class",NULL);
        vObject o;
        o["option"]="converttocode";
        o["resource"]= qVariantFromValue( (void*)resource );
        a->setData(o);
        res.append(a);
    }
    return res;
}

DLLEXPORT bool contextMenuItemClicked(QAction* action)
{
    vObject o = action->data().toHash();
    gcresource* res = (gcresource*) o.value("resource").value<void*>();
    gcmessage(res->name + " will be converted to code class. But, must not be opened... \n\nTODO: Replan this API!");
}

DLLEXPORT gcresource* createResource(gameproject* project, QString kind,QString type,QString name)
{
    //gcmessage("Created");
    if(kind=="class")
    {
        rsClass* res = new rsClass;
        res->type = type;   //either class or code
        res->name = name;
        res->icon = ffficon("brick");
        res->preview = ffficon("brick").pixmap(128,128);
        res->project = project;
        return res;
    }
    return 0;
}

DLLEXPORT ResourceEditor* getGUI(QString kind, QString type, gcresource* res)
{
    if(kind=="class")
    {
        //default is codebased...
        if(type=="*" || type=="codebased")
        {
            codeClass* c = new codeClass;
            return c;
        }
        else
        if(type=="eventbased")
        {
            eventClass* c = new eventClass;
            return c;
        }
    }
    else
    {
        gcerror("Invalid kind...");
        return 0;
    }
}
DLLEXPORT bool save()
{
    return true;
}
DLLEXPORT bool saveAs(QString newname)
{
    return true;
}
DLLEXPORT bool load()
{
    return true;
}
