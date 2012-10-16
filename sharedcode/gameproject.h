#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#include <QString>
#include <QList>
#include <QDomElement>
#include "globals.h"
#include "frameworkdata.h"
#include "resourcetree.h"

//This class represents a game project.

class gcresource;
class rsImage;
class rsModel;
class rsScene;
class rsClass;
class rsSound;
class rsGraphicsEffect;
class gameprojectinformation;
class gameproject
{
    // @RESOURCES
    friend class rsImage;
    friend class rsModel;
    friend class rsScene;
    friend class rsClass;
    friend class rsSound;
    friend class rsGraphicsEffect;
public:

    //construct the game project
    gameproject();
    //with file set
    gameproject(QString filename);
    inline void cn_init();
    ~gameproject();

    //Resources:

    //All project resources, used by the Project tree / may even not be used!
    QList<gcresource*> resources;

    //TODO: @RESOURCE Add all possible resource types in here - so they can be taken directly
    ResourceTreeNode* classes();
    ResourceTreeNode* images();
    ResourceTreeNode* models();
    ResourceTreeNode* scenes();
    ResourceTreeNode* sounds();
    ResourceTreeNode* fonts();
    ResourceTreeNode* filters();
    ResourceTreeNode* effects();

    //Project settings:
    QList<buildtarget*> buildTargets();
    QString title, description;
    QStringList modules; // Only Main by default


    //Loads project from given file
    bool load(QString filename);
    //Loads the project with the current file
    //will return false and echo an error if no file set!
    bool load();

    bool save();
    bool save(QString filename);
    void save_addEntry(QDomDocument *xml, QDomElement *resourcesSection, QString scetionName, ResourceTreeNode *entries);
    void rec_save_addSectionNode(QDomDocument* xml, QDomElement* target, QString sectionName, ResourceTreeNode* source);

    void setFilename(QString);
    void setBuildTargets(QList<buildtarget*> targets);
    QString filename();
    QString absoluteFolder();
    void setTitle(QString title);



    // A project should also contain other items!

    //Convenience string lists and checks [may get slow!]:
    QStringList getClasses();
    QStringList getAllResourceNames();
    QString getKindFromName(QString name);  //returns KIND for given resource name, "" otherwise
    bool areNamesUnique();  //must seriously use this when validating
    bool isResource(QString name);
    // @RESOURCE
    bool isImage(QString name);
    bool isClass(QString name);
    bool isModel(QString name);
    bool isScene(QString name);
    bool isSound(QString name);
    bool isWorld(QString name);
    bool isGraphicsEffect(QString name);

    bool isKind(QString name, QString kind);
    bool isType(QString name, QString type);

    //gettters for a resource type
    QList<gcresource*> getResourcesFromKind(QString kind);
    QList<gcresource*> getResourcesUnderNode(ResourceTreeNode* node);
    QList<gcresource*> getAllResources();
    rsClass getClass(QString name);

    bool addResource(gcresource* resource);
    //removes from the project trees, but doesnt delete any files into its folder!
    bool removeResource(gcresource* resource);
    bool removeTreeNode(ResourceTreeNode* node);

    ResourceTreeNode* getKindFolder(QString kind);

    //The root node is protected from deletion!
    ResourceTreeNode getRootNode();

    static gameprojectinformation* getProjectInformation(QString folder);

private:
    QString mFilename;

    //containers @RESOURCE
    ResourceTreeNode* mImages;
    ResourceTreeNode* mModels;
    ResourceTreeNode* mSounds;
    ResourceTreeNode* mScenes;
    ResourceTreeNode* mClasses;
    ResourceTreeNode* mFonts;
    ResourceTreeNode* mFilters;
    ResourceTreeNode* mEffects;

    QList<buildtarget*> mBuildTargets;
    void addentry(QDomElement e, QString type, ResourceTreeNode* parent);
    void addgroup(QDomElement e);

};

//and small helper class
class gameprojectinformation
{
public:
    QString title, description;
    QIcon icon;
    QString filename;
    bool valid;
    QList<buildtarget*> targets;
    gameprojectinformation();
    gameprojectinformation(QString file);
};

#endif // GAMEPROJECT_H
