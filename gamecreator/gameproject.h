#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#include "gcfileformat.h"
#include <QtXml/qdom.h>
#include <QString>
#include <QStandardItem>
struct buildtarget;
class gameproject
{
public:
    gameproject();
    gameproject(QString s);
    ~gameproject();
    bool close();       //closes the project

    bool save();        //default save, will ask
    bool saveAs();      //ask then save
    bool save(QString, bool saveOnlyXML = false); //save to filename, does the actual save
    bool save(QString file, QString format); //saves to file using specified format
    bool saveTree();
    bool load();    //loads the resources from the XML file

    //this one returns lists with resources from given type:
    QMap<QString,QStringList> getResourcesFromTypes(QStringList types);

    //a version that returns only one list
    QStringList getResourcesFromType(QString type);
    QStringList getAllResourceNames();

    QString name;
    QString file;
    QString relativeFolder;
    QString absoluteFolder;
    bool modified;
    QString failreason;
    QString toString();

    //project stuff:

    //QList<gcimage*> images;
    //QList<wtf??*> classes;
    //QList<wtf??*> sounds;
    //QList<wtf??*> scenes2d;

    //QList<wtf??*> scripts;
    //QList<wtf??*> fonts;
    //QList<wtf??*> guilayers; //err: May not make them anyway - or make them SCENES in code

    //QList<wtf??*> shaders; //later, cppengine
    //QList<wtf??*> models; //later, cppengine
    //QList<wtf??*> scenes3d; //later, cppengine
    //QList<gcresource*> unknown; //unknown resources, RAW XML editing!

    //and a quote:
    //There are more tool/framework/etc... in the web, but GM should be good for the beginners and the pro users.

    // NOPE! If you are reading this you know: Game Maker must get competition! :]

    // List item pointer keep:
    QStandardItem* treeroot;
    QList<buildtarget*> buildTargets; //will these leak?
    buildtarget* getTarget(QString name);
    int selectedTarget;

private:
    void rec_addentry(QDomElement e, QModelIndex target = QModelIndex());
};

#endif // GAMEPROJECT_H
