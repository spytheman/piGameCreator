#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#include <QString>
#include <QList>
#include <QDomElement>
#include "../sharedcode/globals.h"
#include "frameworkdata.h"

//This class represents a game project.

class gcresource;
class rsImage;
class rsModel;
class rsScene;
class rsClass;
class rsSound;

class gameproject
{
    friend class rsImage;
    friend class rsModel;
    friend class rsScene;
    friend class rsClass;
    friend class rsSound;
public:
    //construct the game project
    gameproject();
    //with file set
    gameproject(QString filename);

    //Loads project from given file
    bool load(QString filename);
    //Loads the project with the current file
    //will return false and echo an error if no file set!
    bool load();

    void setFilename(QString);
    QString filename();
    QString absoluteFolder();
    QString title();
    void setTitle(QString title);

    //Resources:

    //All project resources, used by the Project tree / may even not be used!
    QList<gcresource*> resources;

    //TODO: @RESOURCE Add all possible resource types in here - so they can be taken directly
    QList<rsClass*> classes();
    QList<rsImage*> images();
    QList<rsModel*> models();
    QList<rsScene*> scenes();
    QList<rsSound*> sounds();

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
    bool isKind(QString name, QString kind);
    bool isType(QString name, QString type);
    rsClass getClass(QString name);

    //Project settings:
    QList<buildtarget*> buildTargets();

    bool addResource(gcresource* resource);

private:
    QString mFilename, mTitle;

    //containers
    QList<rsClass*> mClasses;
    QList<rsImage*> mImages;
    QList<rsModel*> mModels;
    QList<rsScene*> mScenes;
    QList<rsSound*> mSounds;
    QList<buildtarget*> mBuildTargets;
    void addentry(QDomElement e);

#ifndef CREATOR_IDE
    FrameworkData fd;
#endif
};

#endif // GAMEPROJECT_H
