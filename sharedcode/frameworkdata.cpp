#include <QDir>
#include <QTextStream>
#include "frameworkdata.h"
#include "gameproject.h"

bool frameworkDataIsLoaded = false;
QStringList FrameworkData::classDefFiles;
vObject FrameworkData::gameScriptData;
gameproject* FrameworkData::frameworkProject;

QString FrameworkData::classPath()
{
    QDir d("data/pi-engine/classes/");
    return d.absolutePath();
}

bool FrameworkData::loadFrameworkData()
{
    gcprint("Loading Framework data...");

    frameworkProject = new gameproject;
    frameworkProject->setFilename("data/pi-engine/pi-engine.gcpx");
    frameworkProject->load();
    //Must use haXe's compiler to load class definitions somehow!

    frameworkDataIsLoaded = true;
}
//GameScript
QList<vObject> FrameworkData::getAllFrameworkClasses()
{
    if(!frameworkDataIsLoaded)loadFrameworkData();
    QList<vObject> L;
    vObjectIterator FI;
    for(FI=gameScriptData.begin();FI!=gameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
            L << Class.value().toHash();
    }
    return L;
}
QStringList FrameworkData::getAllFrameworkClassNames()
{
    if(!frameworkDataIsLoaded)loadFrameworkData();
    return frameworkProject->getClasses();
}

vObject FrameworkData::getFrameworkClass(QString name)
{
    if(!frameworkDataIsLoaded)loadFrameworkData();
    vObjectIterator FI;
    for(FI=gameScriptData.begin();FI!=gameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
            if(Class.value().toHash().value("gcName").toString()==name)
                return Class.value().toHash();
    }
    return vObject();
}

rsClass FrameworkData::getFrameworkClassAsResource(QString name)
{
    if(!frameworkDataIsLoaded)loadFrameworkData();
    vObjectIterator FI;
    for(FI=gameScriptData.begin();FI!=gameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
            if(Class.value().toHash().value("gcName").toString()==name)
            {
                vObject o = Class.value().toHash();
                rsClass c;
                c.valid = true;
                c.name = o.value("gcName").toString();
                c.description = o.value("gcDesc").toString();
                c.baseClassName = o.value("gcBase").toString();
                c.sourceCode = "/* Native code */";

                vObjectIterator Object;
                for(Object = o.begin(); Object != o.end();++Object)
                {
                    //any frields starting with "gc" arent class functions/vars
                    if(Object.key().startsWith("gc"))continue;
                    vObject obj = Object.value().toHash();
                    QString kind = obj.value("kind").toString();
                    if(kind=="var" || kind=="prop")
                    {
                        //property or variable?
                        rsClass::variable v;
                        v.name = Object.key();
                        v.type = obj.value("type").toString();
                        v.description = obj.value("desc").toString();
                        v.isStatic = obj.value("static").toBool();
                        c.variables.append(v);
                    }
                    else if(kind=="func")
                    {
                        rsClass::function f;
                        f.name = Object.key();
                        f.type = obj.value("type").toString();
                        f.description = obj.value("desc").toString();
                        f.isStatic = obj.value("static").toBool();
                        //for each agrument:

                        //not sure?
                        vObjectIterator iArg;
                        QMap<int,QVariant> argsordered;
                        for(iArg=o.begin();iArg!=o.end();iArg++)
                        {
                            vObject oo = iArg.value().toHash();
                            if(oo.value("kind").toString()=="arg")
                            {
                                //arg is an argument!
                                QString key = iArg.key();
                                int idx = key.replace("arg","").toInt();
                                argsordered[idx]=iArg.value();
                            }
                        }
                        //now iterate andd use ordered args
                        QMap<int,QVariant>::iterator iArg2;
                        for(iArg2 = argsordered.begin();iArg2!=argsordered.end();++iArg2)
                        {
                            vObject arg = iArg2.value().toHash();
                            if(arg.value("kind").toString()=="arg")
                            {
                                //argument?
                                rsClass::variable a;
                                a.name = arg.value("name").toString();
                                a.type = arg.value("type").toString();
                                a.defaultvalue = arg.value("val").toString();
                                a.description = arg.value("desc").toString();
                                f.arguments.append(a);
                            }
                        }
                        c.functions.append(f);
                    }
                    //name,kind,type?
                }
                return c;
            }
    }

    rsClass c;
    c.valid = false;
    c.name = "[INVALID]";
    return c;
}
