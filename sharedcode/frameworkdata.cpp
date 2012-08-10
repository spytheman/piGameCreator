#include <QDir>
#include <QTextStream>
#include "frameworkdata.h"

bool frameworkDataIsLoaded = false;
QStringList FrameworkData::classDefFiles;
vObject FrameworkData::gameScriptData;

bool FrameworkData::loadFrameworkData()
{
    gcprint("Loading GameScript database files...");
    //clear ALL
    classDefFiles.clear();
    gameScriptData.clear();
    //current project class data must get reloaded OR saved in gameproject*;

    //TODO: Pre-fill them!
    //get ALL files
    QDir d("data");
    QStringList files = d.entryList(QStringList("*.gsd"));
    foreach(QString fn,files)
    {
        gcprint("Reading Class database file data/"+fn+"...");
        vObject oFile;
        QDomDocument* xml = gcReadXml("data/"+fn);
        if(xml==0){gcerror("Something wrong happened with Game Script Definition file\ndata/"+fn);}
        QDomElement defs = xml->documentElement();
        if(defs.tagName()=="gamescriptdata")
        {
            for(int i=0;i<defs.childNodes().count();i++)
            {
                QDomNode defN = defs.childNodes().at(i);
                if(defN.isElement())
                {
                    vObject oClass;
                    QDomElement def = defN.toElement();
                    oClass["gcHidden"] = def.attribute("hidden");
                    oClass["gcDesc"] = def.attribute("desc");
                    oClass["gcDisplayName"] = def.attribute("doc");
                    oClass["gcName"] = def.attribute("name");
                    oClass["gcBase"] = def.attribute("base");
                    //def can only be CLASS or GLOBAL
                    QString className="";
                    if(def.tagName()=="global" or def.tagName()=="class")
                    {
                        //class name is empty string for GLOBAL scope!
                        if(def.tagName()=="class")className=def.attribute("name");
                        gcprint("\t"+className);

                        //class name is OK! now let's load its internal things
                        QDomElement e = def.firstChildElement();
                        while(!e.isNull())
                        {
                            //description
                            QString description;
                            QTextStream T(&description);
                            for(int i=0;i<e.childNodes().count();i++)e.childNodes().at(i).save(T,0);
                            description = description.trimmed();

                            //type: variable, property or function
                            if(e.tagName()=="var" or e.tagName()=="prop")
                            {
                                //variable and property
                                QString name = e.attribute("name");
                                if(name==""){gcerror(fn+"::"+className+": Unnamed variable!");}
                                //gameScriptData[fn][className][name]
                                vObject o;
                                o["kind"]=e.tagName(); //var or prop
                                o["type"]=e.attribute("type","int");
                                o["static"]= (e.attribute("static")=="true");
                                o["desc"]=description;
                                oClass[name]=o;
                            }
                            else if(e.tagName()=="func")
                            {
                                //function
                                QString name = e.attribute("name");
                                if(name==""){gcerror(fn+"::"+className+": Unnamed function!");}
                                vObject o;
                                o["kind"]=e.tagName(); //var or prop
                                o["type"]=e.attribute("type","int");
                                o["static"]= (e.attribute("static")=="true");
                                o["desc"]=description;

                                //Arguments!
                                int n=1;
                                QString ns = "arg"+QString::number(n);
                                while(e.hasAttribute(ns))
                                {
                                    QStringList nl = e.attribute(ns).split(" ");
                                    vObject arg;
                                    arg["kind"]="arg";
                                    arg["type"]=nl.at(0);
                                    arg["name"]=nl.at(1);
                                    arg["val"] =e.attribute(ns+"value");
                                    arg["desc"] =e.attribute(ns+"desc");
                                    o[ns]=arg;
                                    n++;
                                    ns = "arg"+QString::number(n);
                                }
                                oClass[name]=o;
                            }
                            e = e.nextSiblingElement();
                        }
                    }
                    oFile[className]=oClass;
                    oFile["gcFileName"]=fn;
                }
            }
        }
        else gcprint(fn + " is not a valid Game Script Definition file.");
        gameScriptData[fn] = oFile;
    }
    //qDebug()<<gameScriptData;
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
    QStringList L;
    vObjectIterator FI;
    for(FI=gameScriptData.begin();FI!=gameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
        {
            if(Class.key()!="")
            L << Class.key();
        }
    }
    return L;
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
