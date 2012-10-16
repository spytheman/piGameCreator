#include "gameproject.h"
#include "frameworkdata.h"
#include "../sharedcode/globals.h"
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFileInfo>
#include <QDir>
#include "rsimage.h"
#include "rsmodel.h"
#include "rsclass.h"
#include "rsscene.h"
#include "rssound.h"

void gameproject::cn_init()
{
    // @RESOURCE
    mImages = new ResourceTreeNode;
    mImages->folder=true;
    mImages->name="Images";
    mImages->kind="image";
    mModels = new ResourceTreeNode;
    mModels->folder=true;
    mModels->name="Models";
    mModels->kind="model";
    mSounds = new ResourceTreeNode;
    mSounds->folder=true;
    mSounds->name="Sounds";
    mSounds->kind="sound";
    mScenes = new ResourceTreeNode;
    mScenes->folder=true;
    mScenes->name="Scenes";
    mScenes->kind="scene";
    mClasses = new ResourceTreeNode;
    mClasses->folder=true;
    mClasses->name="Classes";
    mClasses->kind="class";
    mFonts = new ResourceTreeNode;
    mFonts->folder=true;
    mFonts->name="Fonts";
    mFonts->kind="font";
    mFilters = new ResourceTreeNode;
    mFilters->folder=true;
    mFilters->name="Filters";
    mFilters->kind="filter";
    mEffects = new ResourceTreeNode;
    mEffects->folder=true;
    mEffects->name="Effects";
    mEffects->kind="effect";
}

gameproject::gameproject()
{
    cn_init();
    mFilename = "";
}

gameproject::gameproject(QString filename)
{
    cn_init();
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
        if(project->doctype().name() != "creatorIDEProject")
        {
            gcerror("This is invalid pi|engine CREATOR project file!");
            gcprint("XML DOCTYPE was '"+project->doctype().name()+"' but must be 'creatorIDEProject'");
            return false;
        }

        // Load project settings
        QDomElement meta = project->documentElement();
        title = meta.attribute("name");
        if(title=="")title = QFileInfo(absoluteFolder()).baseName();
        description = meta.attribute("description");    // Empty for now!
        // folder??? Unneeded??? gcpx and folder name MUST be the same name! FOR NOW!
        // So folder will be IGNORED! In the future, it will be implemented.

        QDomNode res = project->documentElement().firstChild();
        if(res.toElement().tagName()=="resources")
        {
            res=res.firstChild();
            while(!res.isNull())
            {

                QDomElement e = res.toElement();
                gcprint("GROUP: "+e.tagName());
                //add the resource group
                addgroup(e);

                res=res.nextSibling();
            }
        }

        else {return false;} //Resources MUST be first defined!
        res = project->documentElement().firstChild().nextSibling();    //targets
        if(res.toElement().tagName()=="targets")
        {
            res=res.firstChild();
            while(!res.isNull())
            {
                QDomElement e = res.toElement();
                if(e.tagName()=="target")
                {
                    gcprint("TARGET: "+e.attribute("name"));
                    //add the target:
                    buildtarget* t = new buildtarget;
                    t->exportername = e.attribute("exporter");
                    t->codename = e.attribute("name");
                    t->name = e.elementsByTagName("name").at(0).toElement().text();
                    t->description = e.elementsByTagName("description").at(0).toElement().text();
                    QString defines = e.elementsByTagName("defines").at(0).toElement().text();
                    QString modules = e.elementsByTagName("modules").at(0).toElement().text();
                    t->defines = defines.split(" ", QString::SkipEmptyParts);
                    t->modules = modules.split(" ", QString::SkipEmptyParts);
                    t->exporter = NULL; //make it invalid for now!
                    t->valid = false;
                    mBuildTargets.append(t);
                }
                res=res.nextSibling();
            }
        }
        res = project->documentElement().firstChild().nextSibling().nextSibling();  //modules
        if(res.toElement().tagName()=="modules")
        {
            QStringList tempmods = res.toElement().text().split(" ",QString::SkipEmptyParts);
            foreach(QString s, tempmods)
            {
                gcprint("MODULE: "+s);
                if(s.at(0).isUpper()){modules.append(s);}
                else gcprint("Invalid module name, must start with uppercase letter (haXe requirement)");
            }
        }
        else gcprint("NO MODULES section");
    }
    return true;
}

void gameproject::rec_save_addSectionNode(QDomDocument *xml, QDomElement *target, QString sectionName, ResourceTreeNode *node)
{
    if(node->folder)
    {
        // Create a folder into the XML and add children
        QDomElement folder = xml->createElement("folder");
        folder.setAttribute("name", node->name);
        target->appendChild(folder);
        foreach(ResourceTreeNode* child, node->childs)
            rec_save_addSectionNode(xml,&folder,sectionName,child);
    }
    else
    {
        // Each resource have kind that makes the tag name,
        // its name must be stored and, eventually, its icon.
        // IN THE FUTURE @TODO
        // Other properties may get supported
        QDomElement res = xml->createElement(node->kind);
        target->appendChild(res);
        res.setAttribute("name", node->name);
    }
}

void gameproject::save_addEntry(QDomDocument* xml, QDomElement *resourcesSection, QString sectionName, ResourceTreeNode *entries)
{
    QDomElement xmlResNode = xml->createElement(sectionName);
    resourcesSection->appendChild(xmlResNode);

    //Now we must add EVERY resource into the section!
    foreach(ResourceTreeNode* res, entries->childs)
    rec_save_addSectionNode(xml,&xmlResNode,sectionName,res);
}

bool gameproject::save()
{
    save(mFilename);
}

bool gameproject::save(QString filename)
{
    gcprint("Saving "+title+"    ("+mFilename+")...");

    //save is not implemented??? must copy it from somewhere....
    QDomDocument xml("creatorIDEProject");
    QDomProcessingInstruction xmlVersion = xml.createProcessingInstruction("xml","version=\"1.0\"");
    xml.appendChild(xmlVersion);

    QDomElement project = xml.createElement("project");
    project.setAttribute("name", title);
    //project.setAttribute("folder", QFileInfo(absoluteFolder()).baseName()); // <--- Unneeded!
    project.setAttribute("description", description);
    xml.appendChild(project);

    QDomElement resources = xml.createElement("resources");
    project.appendChild(resources);

    // @RESOURCES
    save_addEntry(&xml, &resources, "images", mImages);
    save_addEntry(&xml, &resources, "models", mModels);
    save_addEntry(&xml, &resources, "sounds", mScenes);
    save_addEntry(&xml, &resources, "scenes", mScenes);
    save_addEntry(&xml, &resources, "classes", mClasses);
    save_addEntry(&xml, &resources, "fonts", mFonts);
    save_addEntry(&xml, &resources, "filters", mFilters);
    save_addEntry(&xml, &resources, "effects", mEffects);

    // Build targets:
    QDomElement targets = xml.createElement("targets");
    project.appendChild(targets);

    foreach(buildtarget* t, buildTargets())
    {
        QDomElement target = xml.createElement("target");
        target.setAttribute("exporter", t->exportername);
        target.setAttribute("name", t->codename);

        //name
        QDomElement name = xml.createElement("name");
        QDomText nametext = xml.createTextNode(t->name);
        name.appendChild(nametext);
        target.appendChild(name);

        //description
        QDomText description = xml.createTextNode(t->description);
        QDomElement descEl = xml.createElement("description");
        descEl.appendChild(description);
        target.appendChild(descEl);

        targets.appendChild(target);
    }

    gcSaveXml(mFilename, &xml);
    return false;
}



// @RESOURCE  add RESOURCE entry while loading the project
void gameproject::addentry(QDomElement e, QString type, ResourceTreeNode* parent)
{
    if(type=="image" && e.tagName()=="image")
    {
        ResourceTreeNode* node = new ResourceTreeNode;
        node->name = e.attribute("name");
        rsImage* res = new rsImage;
        res->project = this;
        res->name = e.attribute("name");
        res->type = e.attribute("type","image");
        res->path = e.attribute("path","");    //default path is the project root
        res->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/image.png"));
        res->preview = QPixmap( this->absoluteFolder()+"/"+res->relativeFolder()+"/preview.png" );
        node->resource = res;
        node->kind = res->kind();
        parent->childs.append(node);
    }
    else if(type=="model" && e.tagName()=="model")
    {

    }
    else if(type=="sound" && e.tagName()=="sound")
    {

    }
    else if(type=="class" && e.tagName()=="class")
    {
        ResourceTreeNode* node = new ResourceTreeNode;
        node->name = e.attribute("name");
        rsClass* res = new rsClass;
        res->project = this;
        res->name = e.attribute("name");
        res->type = e.attribute("type","codebased");
        res->path = e.attribute("path","");    //default path is the project root
        res->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/brick.png"));
        res->preview = QPixmap( this->absoluteFolder()+"/"+res->relativeFolder()+"/preview.png" );
        node->resource = res;
        node->kind = res->kind();
        parent->childs.append(node);
        //class must also be analyzed and parsed!
    }
    else if(type=="scene" && e.tagName()=="scene")
    {
        ResourceTreeNode* node = new ResourceTreeNode;
        node->name = e.attribute("name");
        rsScene* res = new rsScene;
        res->project = this;
        res->name = e.attribute("name");
        res->type = e.attribute("type","scene");
        res->path = e.attribute("path","");    //default path is the project root
        res->icon = QIcon( e.attribute("icon", ":/resources/RES/ffficons/application.png"));
        res->preview = QPixmap( this->absoluteFolder()+"/"+res->relativeFolder()+"/preview.png" );
        node->resource = res;
        node->kind = res->kind();
        parent->childs.append(node);
    }
    else if(type=="font" && e.tagName()=="font")
    {

    }
    else if(type=="filter" && e.tagName()=="filter")
    {

    }
    else if(type=="effect" && e.tagName()=="effect")
    {

    }
    else if(e.tagName()=="folder")
    {
        ResourceTreeNode* folderNode = new ResourceTreeNode;
        folderNode->name = e.attribute("name","Folder");
        folderNode->folder = true;
        folderNode->kind = type;
        // RECUSRION DETECTED!
        QDomNode dnode = e.firstChild();
        while(!dnode.isNull())
        {
            QDomElement rtne = dnode.toElement();
            addentry(rtne, type, folderNode);
            dnode = dnode.nextSiblingElement();
        }
        parent->childs.append(folderNode);
    }
    else gcprint("PROJECT LOADER: Trying to add unknown resource type: "+e.tagName());
}

void gameproject::addgroup(QDomElement e)
{
    QString type;
    gcprint(e.tagName());
    ResourceTreeNode* parent = NULL;
    // @RESOURCE
    if(e.tagName()=="images")
    {
        type="image";
        parent = mImages;
    }
    else
    if(e.tagName()=="models")
    {
        type="model";
        parent = mModels;
    }
    else
    if(e.tagName()=="sounds")
    {
        type="sound";
        parent = mSounds;
    }
    else
    if(e.tagName()=="classes")
    {
        type="class";
        parent = mClasses;
    }
    else
    if(e.tagName()=="scenes")
    {
        type="scene";
        parent = mScenes;
    }
    else
    if(e.tagName()=="fonts")
    {
        type="font";
        parent = mFonts;
    }
    else
    if(e.tagName()=="filters")
    {
        type="filter";
        parent = mFilters;
    }
    else
    if(e.tagName()=="effects")
    {
        type="effect";
        parent = mEffects;
    }
    else gcprint("PROJECT LOADER: Trying to add unknown resource group: "+e.tagName());

    QDomNode dnode = e.firstChild();
    while(!dnode.isNull())
    {
        QDomElement rtne = dnode.toElement();
        addentry(rtne, type, parent);
        dnode = dnode.nextSiblingElement();
    }
}

QString gameproject::absoluteFolder()
{
    //yeah. Folder support is unneeded!
    return QFileInfo(this->mFilename).absolutePath();
}

QString gameproject::filename()
{
    return QFileInfo(mFilename).absoluteFilePath();
}

// @RESOURCE
ResourceTreeNode* gameproject::classes(){return mClasses;}
ResourceTreeNode* gameproject::images(){return mImages;}
ResourceTreeNode* gameproject::models(){return mModels;}
ResourceTreeNode* gameproject::scenes(){return mScenes;}
ResourceTreeNode* gameproject::sounds(){return mSounds;}
ResourceTreeNode* gameproject::fonts(){return mFonts;}
ResourceTreeNode* gameproject::filters(){return mFilters;}
ResourceTreeNode* gameproject::effects(){return mEffects;}
QList<buildtarget*> gameproject::buildTargets(){return mBuildTargets;}

bool gameproject::addResource(gcresource *r)
{
    return r->addToProject(this);
}

//This only removes resources!
void rec_delNodeIfNeeded(ResourceTreeNode* trash, ResourceTreeNode* node, ResourceTreeNode* parent)
{
    if(node == trash)
    {
        //must delete this node and remove it from its parent
        if(parent)
            for(int i=0; i < parent->childs.count(); ++i)
                if(parent->childs.at(i) == node)
                {
                    parent->childs.removeAt(i);
                    gcprint("\n--------------------------\nDELETING FOLDER NODE: ");
                    //delete node;
                    gcprint("FOLDER NODE DELETED!");
                }
    }

    if(node->folder)
        foreach(ResourceTreeNode* child, node->childs)
            rec_delNodeIfNeeded(trash,child,node);
}

//This only removes resources!
void rec_delIfNeeded(gcresource* trash, ResourceTreeNode* node, ResourceTreeNode* parent)
{
    gcprint("rec_delIfNeeded: "+node->name);
    if(node->folder)
    {
        foreach(ResourceTreeNode* child, node->childs)
            rec_delIfNeeded(trash,child,node);
    }
    else
    {
        if(node->resource == trash)
        {
            //must delete this node and remove it from its parent
            if(parent)
                for(int i=0; i < parent->childs.count(); ++i)
                    if(parent->childs.at(i) == node)
                    {
                        parent->childs.removeAt(i);
                        delete node;
                    }
        }
    }
}

ResourceTreeNode gameproject::getRootNode()
{
    ResourceTreeNode r;
    r.folder = true;
    r.root = true;
    // @RESOURCE
    r.childs.append(mImages);
    r.childs.append(mModels);
    r.childs.append(mSounds);
    r.childs.append(mClasses);
    r.childs.append(mScenes);
    r.childs.append(mFonts);
    r.childs.append(mFilters);
    r.childs.append(mEffects);
    return r;
}

bool gameproject::removeResource(gcresource *resource)
{
    ResourceTreeNode root = getRootNode();
    rec_delIfNeeded(resource, &root, NULL);
    return true;
}

bool gameproject::removeTreeNode(ResourceTreeNode *node)
{
    ResourceTreeNode root = getRootNode();
    rec_delNodeIfNeeded(node, &root, NULL);
    return true;
}

void rec_getNodeNames(QStringList* output, ResourceTreeNode* node, bool folders = false, int level=0)
{
    if(node->folder)
    {
        if(folders)output->append(node->name);
        foreach(ResourceTreeNode* r,node->childs)
            rec_getNodeNames(output,r,folders,++level);
    }
    else
    {
        QString out;
        for(int i=0;i<level;i++)out+="    ";
        out+=node->name;
        gcprint(out);
        output->append(node->name);
    }
}

QStringList gameproject::getAllResourceNames()
{
    QStringList names;
    ResourceTreeNode root = getRootNode();
    rec_getNodeNames(&names, &root, false);
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
    ResourceTreeNode* root; root->childs.append(mClasses);
    rec_getNodeNames(&names,root);
    return names;
}

bool gameproject::isClass(QString name)
{
    return getClasses().contains(name);
}

void rec_getResourceFromKind(QList<gcresource*>* out, ResourceTreeNode* node, QString kind)
{
    if(node->folder)
        foreach(ResourceTreeNode* r,node->childs)
            rec_getResourceFromKind(out,r,kind);

    else if(node->resource->kind()==kind)
        out->append( node->resource );
}

QList<gcresource*> gameproject::getResourcesFromKind(QString kind)
{
    QList<gcresource*> R;
    ResourceTreeNode root = getRootNode();
    rec_getResourceFromKind(&R, &root, kind);
    return R;
}

void rec_getNodeResources(QList<gcresource*>* out, ResourceTreeNode* node)
{
    if(node->folder)
    {
        foreach(ResourceTreeNode* r,node->childs)
            rec_getNodeResources(out,r);
    }
    else out->append( node->resource );
}
QList<gcresource*> gameproject::getAllResources()
{
    QList<gcresource*> R;
    ResourceTreeNode root = getRootNode();
    rec_getNodeResources(&R, &root);
    return R;
}
QList<gcresource*> gameproject::getResourcesUnderNode(ResourceTreeNode *node)
{
    QList<gcresource*> R;
    rec_getNodeResources(&R, node);
    return R;
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
        QList<gcresource*> classes = getResourcesFromKind("class");
        foreach(gcresource* r, classes)
        {
            rsClass* c = (rsClass*)r;
            if(c->name == name)
            {
                return *c;
            }
        }
        //TODO: Framework Data? haXe STDLib + pi|engine classes

        //nothing returned? Then check Framework data
        //vObject o = FrameworkData::getFrameworkClass(name);
    }
}

void rec_deleteAllNodes(ResourceTreeNode* node)
{
    node->root = false;
    /*
    if(node->folder)
    {
        foreach(ResourceTreeNode* r,node->childs)
            rec_deleteAllNodes(r);
    }
    delete node;*/
}

gameproject::~gameproject()
{
    ResourceTreeNode root = getRootNode();
    rec_deleteAllNodes(&root);
}

ResourceTreeNode* gameproject::getKindFolder(QString kind)
{
    // @RESOURCE
         if(kind=="images")return mImages;
    else if(kind=="models")return mModels;
    else if(kind=="sounds")return mSounds;
    else if(kind=="classes")return mClasses;
    else if(kind=="scenes")return mScenes;
    else if(kind=="fonts")return mFonts;
    else if(kind=="filters")return mFilters;
    else if(kind=="effects")return mEffects;
    else
    {
        gcprint("INVALID KIND! Cannot retrieve folder for: "+kind);
    }
}

void gameproject::setBuildTargets(QList<buildtarget *> targets)
{
    qDeleteAll(mBuildTargets);
    mBuildTargets.clear();
    mBuildTargets = targets;
}

void gameproject::setFilename(QString fileName)
{
    mFilename = fileName;
}

gameprojectinformation* gameproject::getProjectInformation(QString file)
{
    if(QFile::exists(file))
    {
        gameprojectinformation* p = new gameprojectinformation;

        //Load just the meta data from the project
        gcprint("Loading Metadata for project "+file+"...");
        QDomDocument* project = gcReadXml(file);
        if(project)
        {
            if(project->doctype().name() != "creatorIDEProject")
            {
                //gcerror("This is invalid pi|engine CREATOR project file!");
                gcprint("XML DOCTYPE was '"+project->doctype().name()+"' but must be 'creatorIDEProject'");
                return NULL;
            }

            // Load project settings
            QDomElement meta = project->documentElement();
            p->title = meta.attribute("name");
            if(p->title=="")p->title = QFileInfo(file).baseName();
            p->description = meta.attribute("description");
            QIcon icon(meta.attribute("icon",""));
            if(icon.isNull())icon = ffficon("page_white");
            p->icon = icon;
            p->valid = true;
            //Resources must not be loaded

            QDomNode res = project->documentElement().firstChild().nextSibling();
            if(res.toElement().tagName()=="targets")
            {
                res=res.firstChild();
                while(!res.isNull())
                {
                    QDomElement e = res.toElement();
                    if(e.tagName()=="target")
                    {
                        gcprint("TARGET: "+e.attribute("name"));
                        //add the target:
                        buildtarget* t = new buildtarget;
                        t->exportername = e.attribute("exporter");
                        t->codename = e.attribute("name");
                        t->name = e.elementsByTagName("name").at(0).toElement().text();
                        t->description = e.elementsByTagName("description").at(0).toElement().text();
                        t->exporter = NULL; //make it invalid for now!
                        t->valid = false;
                        p->targets.append(t);
                    }
                    res=res.nextSibling();
                }
            }
        }
        else return NULL;
        return p;
    }
    else
    {
        gcprint("The file "+file+" does not exist!");
        return NULL;
    }
}

gameprojectinformation::gameprojectinformation()
{
    valid = false;
}

gameprojectinformation::gameprojectinformation(QString folder)
{
    gameprojectinformation* p = gameproject::getProjectInformation(folder);
    valid = p->valid;
    title = p->title;
    description = p->description;
    icon = p->icon;
    delete p;
}
