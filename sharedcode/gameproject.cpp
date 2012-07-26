#include "gameproject.h"
#ifdef CREATOR_IDE
#include "../baseide/gcide.h"
#else
#include "frameworkdata.h"
#endif
#include "../sharedcode/globals.h"
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFileInfo>
#include "rsimage.h"
#include "rsmodel.h"
#include "rsclass.h"
#include "rsscene.h"
#include "rssound.h"

gameproject::gameproject()
{
    mFilename = "";
#ifndef CREATOR_IDE
    fd.loadFrameworkData();
#endif
}

gameproject::gameproject(QString filename)
{
    mFilename = filename;
}

bool gameproject::load()
{
    if(mFilename=="")
    {
        gcmessage("Project was created but no file set for it! Use setFileName()");
        return false;
    }
    return load(mFilename);
}

bool gameproject::load(QString filename)
{
    /*
        Loads the project data and build targets.

        Loads all resource names without loading the actual resources
        with only one exception: Classes.

        Classes are loaded and analyzed. All class members are cached
        and added to the project class hierarchy, so code completion
        can work in any class.

        About scenes, all layers in all scenes and worlds will be cached as well.
    */
    gcprint("Loading project "+filename+"...");
    QDomDocument* project = gcReadXml(filename);
    if(project)
    {
        if(project->doctype().name() != "piGameCreatorProject")
        {
            gcerror("This is invalid piGameCreator project file!");
            gcprint("XML DOCTYPE was '"+project->doctype().name()+"' but must be 'piGameCreatorProject'");
            return false;
        }
        QDomNode res = project->documentElement().firstChild();
        if(res.toElement().tagName()=="resources")
        {
            res=res.firstChild();
            while(!res.isNull())
            {
                QDomElement e = res.toElement();
                gcprint("RESOURCE: "+e.tagName());
                //add the resource
                addentry(e);
                res=res.nextSibling();
            }
        }
        else {return false;} //Resources MUST be first defined!
    }
    return true;
}

// @RESOURCE  add entry while loading the project
void gameproject::addentry(QDomElement e)
{
    if(e.tagName()=="image")
    {
        rsImage* img = new rsImage;
        img->name = e.attribute("name");
        img->type = e.attribute("type","image");
        img->path = e.attribute("path","/");    //default path is the project root
        img->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/image.png"));
        img->preview = QPixmap( this->absoluteFolder()+"/"+img->relativeFolder()+"/preview.png" );
        mImages.append(img);
    }
    else
    if(e.tagName()=="model")
    {

    }
    else
    if(e.tagName()=="sound")
    {

    }
    else
    if(e.tagName()=="class")
    {
        rsClass* res = new rsClass;
        res->name = e.attribute("name");
        res->type = e.attribute("type","codebased");
        res->path = e.attribute("path","/");    //default path is the project root
        res->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/brick.png"));
        res->preview = QPixmap( this->absoluteFolder()+"/"+res->relativeFolder()+"/preview.png" );
        mClasses.append(res);
    }
    else
    if(e.tagName()=="scene")
    {
        //Scenes and worlds are almost one thing, just different meaning:
        //scenes are optimized for 2d and layouts, worlds - for true 3d worlds
        rsScene* res = new rsScene;
        res->name = e.attribute("name");
        res->type = e.attribute("type","scene");
        res->path = e.attribute("path","/");    //default path is the project root
        res->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/application.png"));
        res->preview = QPixmap( this->absoluteFolder()+"/"+res->relativeFolder()+"/preview.png" );
        mScenes.append(res);
    }
    else gcprint("PROJECT LOADER: Trying to add unknown resource type: "+e.tagName());
}

QString gameproject::absoluteFolder()
{
    return QFileInfo(this->mFilename).absolutePath();
}

QString gameproject::filename()
{
    return QFileInfo(mFilename).absoluteFilePath();
}
QString gameproject::title()
{
    if(mTitle!="")return mTitle;
    return QFileInfo(mFilename).baseName();
}
// @RESOURCE
QList<rsClass*> gameproject::classes(){return mClasses;}
QList<rsImage*> gameproject::images(){return mImages;}
QList<rsModel*> gameproject::models(){return mModels;}
QList<rsScene*> gameproject::scenes(){return mScenes;}
QList<rsSound*> gameproject::sounds(){return mSounds;}
QList<buildtarget*> gameproject::buildTargets(){return mBuildTargets;}

bool gameproject::addResource(gcresource *r)
{
    return r->addToProject(this);
}

QStringList gameproject::getAllResourceNames()
{
    QStringList names;
    // @RESOURCE
    foreach(gcresource* r,mImages) names.append(r->name);
    foreach(gcresource* r,mModels) names.append(r->name);
    foreach(gcresource* r,mClasses)names.append(r->name);
    foreach(gcresource* r,mSounds) names.append(r->name);
    foreach(gcresource* r,mScenes) names.append(r->name);

    return names;
}

bool gameproject::isResource(QString name)
{
    //passed by value is slow but let it go that way for now
    return getAllResourceNames().contains(name);
}

QStringList gameproject::getClasses()
{
    QStringList names;
    foreach(gcresource* r,mClasses)names.append(r->name);
    return names;
}

bool gameproject::isClass(QString name)
{

}

rsClass gameproject::getClass(QString name)
{
    if(!isClass(name))
    {
        rsClass c;
        c.name="[INVALID]";
        c.valid=false;
        return c;
    }
    else
    {
        //is this project class?
        foreach(rsClass* c, mClasses)
            if(c->name == name)
            {
             return *c;
            }

        //nothing returned? Then check Framework data
        vObject o = FrameworkData::getFrameworkClass(name);
    }
}
