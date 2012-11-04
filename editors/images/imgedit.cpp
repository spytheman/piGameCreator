#include "../../sharedcode/globals.h"
#include "../../sharedcode/resource.h"
#include "../../sharedcode/rsimage.h"
#include "../../baseide/resourceeditor.h"
#include <QVariant>
#include <QString>
#include <QStringList>
#include "imageeditor.h"
#include <QPushButton>

#ifdef WIN32
#define DLLEXPORT extern "C" __declspec(dllexport)
#else
#define DLLEXPORT extern "C"
#endif

DLLEXPORT QString getName()
{
    return "Image editor";
}

DLLEXPORT QString getDescription()
{
    return "The default image editor for piGameCreator IDE";
}

DLLEXPORT QStringList getResourceKinds()
{
    return QStringList("image");
}

DLLEXPORT QStringList getResourceTypes()
{
    QStringList types;
    types << "image" << "*";
    return types;
}

DLLEXPORT QList<vObject> newResources()
{
    //  title   description     icon    kind    type
    QList<vObject> res;

    //New image
    vObject o;
    o["kind"]="image";
    o["type"]="image";
    o["title"]="New image";
    o["description"]="Creates a Image resource which support multiple frames, imported from files or pasted from other applications";
    o["icon"]=ffficon("image");
    res.append(o);
    return res;
}

DLLEXPORT gcresource* createResource(gameproject* project, QString kind,QString type,QString name)
{
    //gcmessage("Created");

    if(kind=="image")
    {
        rsImage* img = new rsImage;
        img->type="image";
        img->name = name;
        img->icon = ffficon("image");
        img->preview = ffficon("image").pixmap(128,128);
        img->project = project;
        return img;
    }
    return 0;
}

DLLEXPORT ResourceEditor* getGUI(QString kind, QString type, gcresource* res)
{
    return new ImageEditor();
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
