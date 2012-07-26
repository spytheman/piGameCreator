#include "../../sharedcode/globals.h"
#include "../../sharedcode/resource.h"
#include "../../sharedcode/rsscene.h"
#include "../../baseide/resourceeditor.h"
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include "sceneeditor.h"
#define DLLEXPORT extern "C" __declspec(dllexport)


DLLEXPORT QString getName()
{
    return "Scene editor";
}

DLLEXPORT QString getDescription()
{
    return "The default scene editor for piGameCreator IDE";
}

DLLEXPORT QStringList getResourceKinds()
{
    QStringList L;
    L<<"scene";
    return L;
}

DLLEXPORT QStringList getResourceTypes()
{
    QStringList types;
    types << "scene" << "*";
    return types;
}

DLLEXPORT QList<vObject> newResources()
{
    //  title   description     icon    kind    type
    QList<vObject> res;

    //New image
    vObject o;
    o["kind"]="scene";
    o["type"]="scene";
    o["title"]="New scene";
    o["description"]="Creates a 2D Scene where you put game objects into layers or design interface layouts";
    o["icon"]=ffficon("application");
    res.append(o);
    return res;
}

DLLEXPORT gcresource* createResource(QString kind,QString type,QString name)
{
    //gcmessage("Created");

    if(kind=="scene")
    {
        rsScene* r = new rsScene;
        r->type="image";
        r->name = name;
        r->icon = ffficon("application");
        r->preview = ffficon("image").pixmap(128,128);
        return r;
    }
    return 0;
}

DLLEXPORT ResourceEditor* getGUI(QString kind, QString type, gcresource* res)
{
    return new SceneEditor();
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
