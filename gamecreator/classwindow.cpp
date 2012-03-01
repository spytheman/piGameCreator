#include <QPainter>
#include <QFile>
#include <QTimer>
#include <QInputDialog>
#include "gamecreator.h"
#include "classwindow.h"
#include "ui_classwindow.h"
#include "srcClass/getimageormodel.h"
#include "srcClass/editvardialog.h"
#include "srcClass/variable.h"
#include "srcClass/addeventwindow.h"
#include "srcClass/getclassresource.h"
#include "srcClass/getkeyevent.h"
#include "srcClass/getmouseevent.h"
#include "srcClass/addfunction.h"
#include <QMenu>

classwindow::classwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::classwindow)
{
    initialized=false;
    CurrentActiveItem=0;
    setProperty("editor",true);
    gcprint("classwindow.cpp:25 TODO: RIGHT CLICK to DELETE stuff!");
    ui->setupUi(this);
    fixback(this);
    ui->stackedWidget->setCurrentIndex(0);
    centralWidget()->layout()->setContentsMargins(0,0,0,0);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->PropertiesPage->layout()->setContentsMargins(3,3,0,0);
    source = new scriptwindow;
    preview = new classpreview;
    preview->window = this;
    ui->previewFrame->layout()->setContentsMargins(0,0,0,0);
    ui->previewFrame->layout()->addWidget(preview);

    ui->CodeEditPage->layout()->setContentsMargins(0,0,0,0);
    ui->CodeEditorFrame->layout()->setContentsMargins(0,0,0,0);
    ui->CodeEditorFrame->layout()->addWidget(source);

    initialized=true;
    varsDrop.window=this;
    propsDrop.window=this;
    propsDrop.allowMenus=true;
    ui->VarsList->viewport()->installEventFilter(&varsDrop);
    ui->PropList->viewport()->installEventFilter(&propsDrop);
    connect(source->source, SIGNAL(textChanged()),this,SLOT(modify()));
}

classwindow::~classwindow()
{
    delete ui;
}

void classwindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void setValueAttribs(QDomElement var,vObject v,QString type)
{
    //make as attrib if possible, depending of type
    if(type=="point2d")
    {
        //x,y
        var.setAttribute("x",v.value("x").toString());
        var.setAttribute("y",v.value("y").toString());
    }
    else if(type=="point3d")
    {
        //x,y,z
        var.setAttribute("x",v.value("x").toString());
        var.setAttribute("y",v.value("y").toString());
        var.setAttribute("z",v.value("z").toString());
    }
    else if(type=="color")
    {
        //r,g,b,a
        QColor c = v.value("color").value<QColor>();
        var.setAttribute("r",c.red());
        var.setAttribute("g",c.green());
        var.setAttribute("b",c.blue());
        var.setAttribute("a",c.alpha());
    }
    else
    {
        //the rest
        QDomText t = var.ownerDocument().createTextNode(v.value("value").toString());
        var.appendChild(t);
    }
}

void classwindow::save()
{
    updateCurrentActiveItem();

    //save the class definition and code:
    QDomDocument xml;
    QDomElement clas = xml.createElement("class");
    QString basename=ui->baseClassButton->text();
    if(basename=="(none)")basename="";
    clas.setAttribute("base",basename);
    clas.setAttribute("representation",preview->resname);
    QString cmode;
    if(ui->rb2d->isChecked())cmode="2d";
    else cmode="3d";
    clas.setAttribute("collision",cmode);
    //clas.setAttribute("resizable",ui->ResizableCheckBox->isChecked());
    xml.appendChild(clas);

    //vars
    QDomElement vars = xml.createElement("variables");
    for(int i=0;i<ui->VarsList->topLevelItemCount();i++)
    {
        variable v = makeVariable(ui->VarsList->topLevelItem(i)->data(0,TIDATA).toHash(),false);
        QDomElement var = xml.createElement("variable");
        var.setAttribute("name",v.name);
        var.setAttribute("type",v.type);
        var.setAttribute("array",v.isArray);
        if(v.isArray)
        {
            //all values
            for(int i=0;i<v.values.count();i++)
            {
                QDomElement value = xml.createElement("value");
                setValueAttribs(value,v.values.at(i),v.type);
                var.appendChild(value);
            }
        }
        else
        {
            //current tag
            setValueAttribs(var,v.value,v.type);
        }
        vars.appendChild(var);
    }

    //properties
    QDomElement props = xml.createElement("properties");
    for(int i=0;i<ui->PropList->topLevelItemCount();i++)
    {
        variable v = makeVariable(ui->PropList->topLevelItem(i)->data(0,TIDATA).toHash(),true);
        QDomElement prop = xml.createElement("property");
        prop.setAttribute("name",v.name);
        prop.setAttribute("type",v.type);
        prop.setAttribute("array",v.isArray);
        prop.setAttribute("menu",v.isMenu);
        if(v.isArray)
        {
            //all values
            for(int i=0;i<v.values.count();i++)
            {
                QDomElement value = xml.createElement("value");
                setValueAttribs(value,v.values.at(i),v.type);
                prop.appendChild(value);
            }
        }
        else
        {
            //current tag
            setValueAttribs(prop,v.value,v.type);
        }
        props.appendChild(prop);
    }

    //events
    QDomElement events = xml.createElement("events");
    for(int i=0;i<ui->EventsListWidget->count();i++)
    {
        QListWidgetItem* p = ui->EventsListWidget->item(i);
        //save each event, must handle the event types properly
        QDomElement e =xml.createElement("event");
        events.appendChild(e);
        QString type = p->data(TITYPE).toString();
        e.setAttribute("type",type);

        //event arguments
        if(type=="render")e.setAttribute("pass",p->data(TIDATA).toInt());
        else if(type=="timer")e.setAttribute("id",p->data(TIDATA).toInt());
        else if(type=="collision")e.setAttribute("class",p->data(TIDATA).toString());
        else if(type=="key")
        {
            vObject o = p->data(TIDATA).toHash();
            e.setAttribute("key",o["key"].toInt());
            e.setAttribute("eventtype",o["type"].toInt());
        }
        else if(type=="mouse")
        {
            vObject o = p->data(TIDATA).toHash();
            e.setAttribute("button",o["button"].toInt());
            e.setAttribute("eventtype",o["type"].toInt());
        }

        //save the code
        QString code = p->data(TICODE).toString();
        QString src(p->text().replace(":","")+".pgs");
        QString fn(project->absoluteFolder + "/classes/"+name+"/"+src);
        QFile f(fn);
        if(f.open(QIODevice::WriteOnly))
        {
            f.write(code.toUtf8());
            f.close();
        }
        e.setAttribute("src",src);
    }

    //functions
    QDomElement func = xml.createElement("functions");
    for(int i=0;i<ui->FunctionsListWidget->count();i++)
    {
        //save all functions
        QListWidgetItem* p = ui->FunctionsListWidget->item(i);

        QDomElement fx = xml.createElement("function");
        func.appendChild(fx);
        fx.setAttribute("name",p->text());
        fx.setAttribute("type",p->data(TITYPE).toString());

        vObject o = p->data(TIDATA).toHash();
        vObject::const_iterator I = o.constBegin();
        while(I!=o.constEnd())
        {
            QDomElement arg= xml.createElement("argument");
            fx.appendChild(arg);
            arg.setAttribute("name",I.key());
            arg.setAttribute("type",I.value().toString());
            I++;
        }

        QString src=p->text()+".pgs";
        QString fn=project->absoluteFolder + "/classes/"+name+"/"+src;
        QFile f(fn);
        if(f.open(QIODevice::WriteOnly))
        {
            f.write(p->data(TICODE).toString().toUtf8());
            f.close();
        }
        fx.setAttribute("src",src);
    }

    clas.appendChild(vars);
    clas.appendChild(props);
    clas.appendChild(events);
    clas.appendChild(func);
    gcSaveXml(project->absoluteFolder+"/classes/"+name+".xml",&xml);
    preview->icon.save(project->absoluteFolder+"/classes/"+name+"/icon.png","PNG");
    modified=false;
    updateTitle();
}

vObject makeVObjectValueFromDOMNode(QDomElement e,QString type)
{
    vObject o;
    if(type=="point2d")
    {
        o["x"]=e.attribute("x").toDouble();
        o["y"]=e.attribute("y").toDouble();
        o["value"]="X: "+o.value("x").toString()+" Y: "+o.value("y").toString();
    }
    else if(type=="point3d")
    {
        o["x"]=e.attribute("x").toDouble();
        o["y"]=e.attribute("y").toDouble();
        o["z"]=e.attribute("z").toDouble();
        o["value"]="X: "+o.value("x").toString()+" Y: "+o.value("y").toString()+ " Z: "+o.value("z").toString();
    }
    else if(type=="color")
    {
        QColor c;
        c.setRed(e.attribute("r").toInt());
        c.setGreen(e.attribute("g").toInt());
        c.setBlue(e.attribute("b").toInt());
        c.setAlpha(e.attribute("a").toInt());
        o["color"]=c;
        o["value"]=c.name();
    }
    else if(type=="int")o["value"]=e.text().toInt();
    else if(type=="real")o["value"]=e.text().toDouble();
    else if(type=="bool")o["value"]=e.text().toInt();
    else if(type=="string")o["value"]=e.text();
    //ADD function and CLASS here
    //class:
    else o["value"]=e.text();

    return o;
}

void classwindow::load()
{
    initialized=false;
    QDomDocument* xml = gcReadXml(project->absoluteFolder+"/classes/"+name+".xml");
    if(xml!=0)
    {
        gcprint("Loading class...");
        //parse the xml and do the init stuff
        QDomElement clas = xml->documentElement();
        ui->baseClassButton->setText(clas.attribute("base","(none)"));
        if(ui->baseClassButton->text()=="")ui->baseClassButton->setText("(none)");
        preview->resname = clas.attribute("representation","");
        preview->icon = QPixmap(project->absoluteFolder+"/classes/"+name+"/icon.png");
        treeitem->setIcon(preview->icon);
        //ui->ResizableCheckBox->setChecked(clas.attribute("resizable").toInt());
        if(clas.attribute("collision")=="3d")ui->rb3d->setChecked(1);
        else ui->rb2d->setChecked(1);

        //variables
        QDomElement varroot = xml->documentElement().firstChildElement("variables");
        QDomNodeList L = varroot.childNodes();
        for(int _=0;_<=L.count();_++)
            if(L.at(_).isElement())
                if(L.at(_).toElement().tagName()=="variable")
                {
                    QDomElement ve = L.at(_).toElement();
                    variable v;
                    v.isArray=ve.attribute("array","0").toInt();
                    v.type=ve.attribute("type","int");
                    v.name=ve.attribute("name");
                    //add the menu case for properties here
                    if(v.name!="")
                    {
                        QDomElement val;
                        //valid only if named
                        if(v.isArray)
                        {
                            //parse the values
                            for(int i=0;i<ve.childNodes().count();i++)
                            {
                                QDomElement value = ve.childNodes().at(i).toElement();
                                if(!value.isNull())
                                if(value.tagName()=="value")
                                {
                                    //all value elements;
                                    val=value;
                                    vObject o = makeVObjectValueFromDOMNode(val,v.type);
                                    gcprint(o.value("text").toString());
                                    v.values.push_back(o);
                                }
                            }
                            //vObject is created...
                        }
                        else
                        {
                            //one element
                            val=ve;
                            vObject o = makeVObjectValueFromDOMNode(val,v.type);
                            gcprint(o.value("text").toString());
                            v.value=o;
                        }
                    } //v.name
                    // variable v is ready
                    QTreeWidgetItem* item = new QTreeWidgetItem;
                    makeTreeItem(item,v);
                    ui->VarsList->insertTopLevelItem(ui->VarsList->topLevelItemCount(),item);
                }

        //properties
        QDomElement proproot = xml->documentElement().firstChildElement("properties");
        L = proproot.childNodes();
        for(int _=0;_<=L.count();_++)
            if(L.at(_).isElement())
                if(L.at(_).toElement().tagName()=="property")
                {
                    QDomElement ve = L.at(_).toElement();
                    variable v;
                    v.isArray=ve.attribute("array","0").toInt();
                    v.isProperty=true;
                    v.type=ve.attribute("type","int");
                    v.name=ve.attribute("name");
                    v.isMenu=ve.attribute("menu","0").toInt();
                    //add the menu case for properties here
                    if(v.name!="")
                    {
                        QDomElement val;
                        //valid only if named
                        if(v.isArray)
                        {
                            //parse the values
                            for(int i=0;i<ve.childNodes().count();i++)
                            {
                                QDomElement value = ve.childNodes().at(i).toElement();
                                if(!value.isNull())
                                if(value.tagName()=="value")
                                {
                                    //all value elements;
                                    val=value;
                                    vObject o = makeVObjectValueFromDOMNode(val,v.type);
                                    gcprint(o.value("text").toString());
                                    v.values.push_back(o);
                                }
                            }
                            //vObject is created...
                        }
                        else
                        {
                            //one element
                            val=ve;
                            vObject o = makeVObjectValueFromDOMNode(val,v.type);
                            gcprint(o.value("text").toString());
                            v.value=o;
                        }
                    } //v.name
                    // variable v is ready
                    QTreeWidgetItem* item = new QTreeWidgetItem;
                    makeTreeItem(item,v);
                    ui->PropList->insertTopLevelItem(ui->PropList->topLevelItemCount(),item);
                }


        //events
        QDomElement events = xml->documentElement().firstChildElement("events");
        L = events.childNodes();
        for(int _=0;_<L.count();_++)
            if(L.at(_).isElement())
                if(L.at(_).toElement().tagName()=="event")
                {
                    //load events
                    QDomElement e = L.at(_).toElement();
                    QVariant data;
                    QString type = e.attribute("type"), src = e.attribute("src"), name;
                    QIcon icon;
                    if(type=="create")
                    {
                        name=tr("Create");
                        icon=ffficon("new");
                    }
                    else if(type=="init")
                    {
                        name=tr("Initialize");
                        icon=ffficon("tick");
                    }
                    else if(type=="delete")
                    {
                        name=tr("Destroy");
                        icon=ffficon("bin");
                    }
                    else if(type=="step")
                    {
                        name=tr("Game tick");
                        icon=QIcon(":/resources/RES/tango/actions/media-playback-start.png");
                    }
                    else if(type=="render")
                    {
                        data=e.attribute("pass").toInt();
                        name = tr("Render pass %1").arg(data.toString());
                        icon=ffficon("pencil");
                    }
                    else if(type=="timer")
                    {
                        data=e.attribute("id").toInt();
                        name=tr("Timer %1").arg(data.toString());
                        icon=ffficon("clock");
                    }
                    else if(type=="collision")
                    {
                        data=e.attribute("class");
                        name="Collision: "+data.toString();
                        icon=ffficon("shape_move_backwards");
                    }
                    else if(type=="key")
                    {
                        vObject o;
                        o["key"]=e.attribute("key").toInt();
                        o["type"]=e.attribute("eventtype").toInt();
                        data=o;
                        QString s;int t=o.value("type").toInt();
                        if(t==0)s="Down: ";
                        else if(t==1)s="Press: ";
                        else if(t==2)s="Release: ";
                        s+=QString::fromStdString( getKeyEvent::getKeyName(e.attribute("key").toInt()));
                        name=s;
                        icon=ffficon("keyboard");
                    }
                    else if(type=="mouse")
                    {
                        vObject o;
                        int b = e.attribute("button").toInt();
                        int t = e.attribute("eventtype").toInt();
                        o["button"]=b;
                        o["type"]=t;
                        data=o;
                        QString s,bs;
                        if(b==0)bs="Left";
                        else if(b==1)bs="Right";
                        else if(b==2)bs="Middle";
                        if(t==0)s=tr("%1 clicked me").arg(bs);
                        else if(t==1)s=tr("%1 released me").arg(bs);
                        else if(t==2)s=tr("%1 pressed").arg(bs);
                        else if(t==3)s=tr("%1 released").arg(bs);
                        else if(t==4)s=tr("%1 is down").arg(bs);
                        else if(t==5)s=tr("Wheel up");
                        else if(t==6)s=tr("Wheel down");
                        name=s;
                        icon=ffficon("mouse");
                    }
                    QListWidgetItem* i = new QListWidgetItem;
                    i->setData(TITYPE,type);
                    i->setData(TIDATA,data);
                    //load the code
                    QString fn = project->absoluteFolder+"/classes/"+this->name+"/"+src, code;
                    QFile f(fn);if(f.open(QIODevice::ReadOnly))
                    {
                        code = QString::fromUtf8(f.readAll());
                        f.close();
                    }
                    i->setData(TICODE,code);
                    i->setText(name);
                    i->setIcon(icon);
                    ui->EventsListWidget->addItem(i);
                }

        //functions
        QDomElement functions = xml->documentElement().firstChildElement("functions");
        L = functions.childNodes();
        for(int _=0;_<L.count();_++)
            if(L.at(_).isElement())
                if(L.at(_).toElement().tagName()=="function")
                {
                    QDomElement e = L.at(_).toElement();
                    QString type=e.attribute("type","void"), name=e.attribute("name"), src=e.attribute("src");
                    //are they valid
                    if(name!="" and src!="")
                    {
                        //function is valid,load it
                        QListWidgetItem *i = new QListWidgetItem;
                        i->setIcon(ffficon("sum"));
                        i->setText(name);
                        i->setData(TITYPE,type);
                        QString code;
                        QFile f(project->absoluteFolder+"/classes/"+this->name+"/"+src);
                        if(f.open(QIODevice::ReadOnly))
                        {
                            code = QString::fromUtf8(f.readAll());
                            f.close();
                        }
                        i->setData(TICODE,code);
                        //arguments
                        vObject o;
                        for(int ii=0;ii<=e.childNodes().count();ii++)
                        {
                            if(e.childNodes().at(ii).toElement().tagName()=="argument")
                            {
                                QDomElement arg=e.childNodes().at(ii).toElement();
                                QString argtype=arg.attribute("type");
                                QString argname=arg.attribute("name");
                                o[argname]=argtype;
                            }
                        }
                        i->setData(TIDATA,o);

                        ui->FunctionsListWidget->addItem(i);
                    }
                }


        delete xml;
    }
    initialized=true;
    QApplication::processEvents();
    modified=false;
    updateTitle();
}

void classwindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void classwindow::on_pushButton_clicked()
{
    updateCurrentActiveItem();
    CurrentActiveItem=0;    //settings aren't item
    ui->pushButton->setChecked(1);
    ui->stackedWidget->setCurrentIndex(0);
    ui->EventsListWidget->setCurrentIndex(QModelIndex());
    ui->FunctionsListWidget->setCurrentIndex(QModelIndex());
}

void classpreview::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    if(icon.isNull())
    {
        p.fillRect(0,0,width(),height(),QApplication::palette().background());
        p.drawText(0,0,width(),height(),Qt::AlignCenter,tr("PREVIEW\nClick to select"));

    }
    else
    {
        p.drawPixmap(0,0,icon);
    }
}

void classpreview::mousePressEvent(QMouseEvent *e)
{

}

void classpreview::mouseReleaseEvent(QMouseEvent *e)
{
    //pop a window to select image OR model
    getImageOrModel* w = new getImageOrModel(window->project,this);
    w->exec();
    resname = w->selectedName;
    QString fn = window->project->absoluteFolder + "/images/" + resname + "/frame1.png";
    icon = QPixmap(fn).scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    repaint();
    QIcon I = QIcon(icon); if(I.isNull()) I = gcResIcon("class","");
    window->treeitem->setIcon(I);
    window->makeModified();
    delete w;
}

classpreview::classpreview(QWidget *parent) : QWidget(parent)
{

}

classpreview::~classpreview()
{

}

void classwindow::on_addEvent_clicked()
{
    AddEventWindow* w = new AddEventWindow(this,this);
    bool fail=false;
    w->exec();
    if(w->OKclicked)
    {
        //add the event
        QListWidgetItem* i = new QListWidgetItem;
        QString etype = w->selectedEvent->toolTip(0), ename;
        i->setIcon(w->selectedEvent->icon(0));

        //check if the event have parameters and ask for them
        if(etype=="create")ename=tr("Create");
        else if(etype=="init")ename=tr("Initialize");
        else if(etype=="delete")ename=tr("Destroy");
        else if(etype=="step")ename=tr("Game tick");
        else if(etype=="render")
        {
            //get render pass
            bool ok;
            int pass = QInputDialog::getInteger(this,tr("Render pass"),tr("Enter the rendering pass, leave 0 if only one.\nMore passes may slow the game but allow for more cool effects."),0,0,1000,1,&ok);
            if(ok)
            {
                ename = tr("Render pass %1").arg(pass);
                i->setData(TIDATA,pass);
            }
            else fail=true;
        }
        else if(etype=="timer")
        {
            //get timer id
            bool ok;
            int n = QInputDialog::getInteger(this,tr("Timer #"),tr("Enter the timer number"),0,0,1000,1,&ok);
            if(ok)
            {
                ename = tr("Timer %1").arg(n);
                i->setData(TIDATA,n);
            }
            else fail=true;
        }
        else if(etype=="collision")
        {
            //get class
            getClassResource* w = new getClassResource(project,this);
            if(w->exec()==QDialog::Accepted)
            {
                ename = tr("Collision: ")+w->resname;
                i->setData(TIDATA,w->resname);
            }
            else fail=true;

        }
        else if(etype=="key")
        {
            //get key event
            getKeyEvent w(this);
            if(w.exec()==QDialog::Accepted)
            {
                int k = w.keyCode, t = w.etype; QString s;
                if(t==0)s="Down: ";
                else if(t==1)s="Press: ";
                else if(t==2)s="Release: ";
                s+=w.keyName;
                ename=s;
                vObject o;o["key"]=k;o["type"]=t;
                i->setData(TIDATA,o);
            }
            else fail=true;
        }
        else if(etype=="mouse")
        {
            //get mouse event
            GetMouseEvent w(this);
            if(w.exec()==QDialog::Accepted)
            {
                int b = w.button;
                int t = w.etype;
                QString s,bs;
                if(b==0)bs="Left";
                else if(b==1)bs="Right";
                else if(b==2)bs="Middle";
                if(t==0)s=tr("%1 clicked me").arg(bs);
                else if(t==1)s=tr("%1 released me").arg(bs);
                else if(t==2)s=tr("%1 pressed").arg(bs);
                else if(t==3)s=tr("%1 released").arg(bs);
                else if(t==4)s=tr("%1 is down").arg(bs);
                else if(t==5)s=tr("Wheel up");
                else if(t==6)s=tr("Wheel down");
                ename=s;
                vObject o; o["button"]=b; o["type"]=t;
                i->setData(TIDATA,o);
            }
            else fail=true;
        }
        //add the rest here

        //because the Designer MISSES option to set CUSTOM properties on items...
        if(!fail)
        {
            //add the event if not duplicate                
            i->setData(TITYPE,etype);
            i->setText(ename);

            QStringList L;
            for(int i=0;i<ui->EventsListWidget->count();i++)
                L << ui->EventsListWidget->item(i)->text();

            if(!L.contains(ename))
            {
                ui->EventsListWidget->addItem(i);
                ui->EventsListWidget->setCurrentItem(i);
                on_EventsListWidget_itemClicked(i);
                makeModified();
            }
            else delete i;
        }
    }
}

void classwindow::on_addFunction_clicked()
{
    AddFunction w(this);
    w.project = project;
    if(w.exec()==QDialog::Accepted)
    {
        QString s;  //provide good default code for events!
        s+="// "+w.type+" "+w.name+"(";
        QListWidgetItem* i = new QListWidgetItem;
        vObject o = w.args;

        vObject::const_iterator I = o.constBegin();
        bool cb=false;
        while(I!=o.constEnd())
        {
            s.append( I.value().toString() + " " + I.key() +",");
            cb=true;
            I++;
        }
        if(cb)
        s[s.length()-1]=')';
        else s+=")";

        i->setText(w.name);
        i->setData(TIDATA,w.args);
        i->setData(TITYPE,w.type);
        i->setData(TICODE,s);
        i->setIcon(ffficon("sum"));
        ui->FunctionsListWidget->addItem(i);
        on_FunctionsListWidget_itemClicked(i);
        makeModified();
    }
}

void classwindow::makeTreeItem(QTreeWidgetItem* n, variable v)
{
    n->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    n->setText(0,v.name);
    n->setText(1,v.type);
    QFont f(n->font(1));f.setBold(1);
    n->setFont(1,f);

    if(v.isArray){n->setText(2,"Array");n->setText(1,n->text(1)+"[]");}
    else n->setText(2, v.value.value("value").toString());
    if(v.isMenu)n->setText(2,"Menu");

    if(v.value.value("color",QColor()).value<QColor>()!=QColor())
    {
        n->setBackgroundColor(2,v.value.value("color").value<QColor>());
    }
    // the variable class itself CANNOT be stored as QVariant, but vObject can)
    vObject o = makeVObject(v);
    n->setData(0,TIDATA,o); //yes. vObject is OK with QVariant
}

void classwindow::on_addVariable_clicked()
{
    EditVarDialog* d = new EditVarDialog(this);
    d->project = project;
    d->exec();
    if(d->var.name==""){delete d;return;}
    QTreeWidgetItem* w = new QTreeWidgetItem;
    makeTreeItem(w,d->var);
    ui->VarsList->insertTopLevelItem(ui->VarsList->model()->rowCount(),w);
    delete d;
    checkVars();
    makeModified();
}

void classwindow::on_addProperty_clicked()
{
    EditVarDialog* d = new EditVarDialog(this);
    d->propertyMode(false);
    d->project = project;
    d->exec();
    if(d->var.name==""){delete d;return;}
    QTreeWidgetItem* w = new QTreeWidgetItem;
    makeTreeItem(w,d->var);
    ui->PropList->insertTopLevelItem(ui->PropList->model()->rowCount(),w);
    delete d;
    checkVars();
    makeModified();
}

vObject classwindow::makeVObject(variable v)
{
    vObject o;
    o["name"] = v.name;
    o["type"] = v.type;
    o["array"]= v.isArray;
    o["menu"] = v.isMenu;
    if(v.isArray)
    {
        QList<vObject> l = v.values;
        QList<QVariant> t;
        for(int i=0;i<l.count();i++)
            t.push_back(l.at(i));
        o["values"] = t;
    }
    else o["value"] = v.value;
    return o;
}

variable classwindow::makeVariable(vObject o, bool property)
{
    variable v;
    v.name = o.value("name").toString();
    v.type = o.value("type").toString();
    v.isArray = o.value("array").toBool();
    v.isMenu = o.value("menu").toBool();
    v.isProperty = property;
    if(v.isArray)
    {
        QList<QVariant> l = o.value("values").toList();
        for(int i=0;i<l.count();i++)
        {
            vObject t = l.at(i).toHash();
            v.values.push_back(t);
        }
    }
    else v.value = o.value("value").toHash();
    return v;
}

void classwindow::on_VarsList_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    vObject o = item->data(0,TIDATA).toHash();
    if(o.value("name","")!="")
    {
        variable v = makeVariable(o,false);
        EditVarDialog w(v,this);
        w.project=project;
        if(w.exec()==1);
        makeTreeItem(item,w.var);
    }
    else delete item;
}
void classwindow::on_PropList_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    vObject o = item->data(0,TIDATA).toHash();
    if(o.value("name","")!="")
    {
        variable v = makeVariable(o,false);
        EditVarDialog w(v,this);
        w.propertyMode(true);
        w.project=project;
        if(w.exec()==1);
        makeTreeItem(item,w.var);
    }
    else delete item;
}

void classwindow::on_VarsList_itemSelectionChanged()
{
    for(int i=0;i<ui->VarsList->topLevelItemCount();i++)
    {
        ui->VarsList->topLevelItem(i)->
                setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    }
    for(int i=0;i<ui->PropList->topLevelItemCount();i++)
    {
        ui->PropList->topLevelItem(i)->
                setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    }
}

void classwindow::on_PropList_itemSelectionChanged()
{
    on_VarsList_itemSelectionChanged();
}

void classwindow::keyPressEvent(QKeyEvent *e)
{
    if(e->type() == QKeyEvent::KeyPress and e->key()==Qt::Key_Delete)
    {
        if(ui->VarsList->hasFocus())on_DelVars_clicked();
        else if(ui->PropList->hasFocus())on_DelProperties_clicked();
    }
}

void classwindow::on_DelVars_clicked()
{
    QList<QTreeWidgetItem*> l = ui->VarsList->selectedItems();
    foreach(QTreeWidgetItem* i,l)delete i;
    makeModified();
}

void classwindow::on_DelProperties_clicked()
{
    QList<QTreeWidgetItem*> l = ui->PropList->selectedItems();
    foreach(QTreeWidgetItem* i,l)delete i;
    makeModified();
}

void classwindow::checkVars()
{
    QTimer* t = new QTimer();
    t->setSingleShot(true);
    t->setInterval(10);
    connect(t,SIGNAL(timeout()),this,SLOT(timeout()));
    t->start();
}

void fixconflict(QTreeWidgetItem* i, bool property, QStringList* L)
{
    gcprint("CONFLICT DETECTED: "+i->text(0));
    int n=2;QString s,t;
    t=i->text(0);
    do
    {
        s=t+"_"+QString::number(n);
        n++;
    }
    while(L->contains(s));

    //now s os OKAY
    gcprint("setting text to: "+s);
    i->setText(0,s);
    gcprint("done");
    vObject v = i->data(0,TIDATA).toHash();
    v["name"]=s;
    i->setData(0,TIDATA,v);
}
void menu2array(QTreeWidgetItem* i)
{
    vObject v = i->data(0,TIDATA).toHash();
    if(v.value("menu").toBool()==true)
    {
        //it's a menu
        i->setText(2,"Array");
    }
}

void array2menu(QTreeWidgetItem* i)
{
    vObject v = i->data(0,TIDATA).toHash();
    if(v.value("menu").toBool()==true)
    {
        //it's a menu
        i->setText(2,"Menu");
    }
}

void classwindow::timeout() //actual checking of vars here
{
    //vars:
    QStringList l; QString s; int i;
    for(i=0;i<ui->VarsList->topLevelItemCount();i++)
    {
        menu2array(ui->VarsList->topLevelItem(i));
        s = ui->VarsList->topLevelItem(i)->text(0);
        if(!l.contains(s))l<<s;
        else
        {
            //conflict
            fixconflict(ui->VarsList->topLevelItem(i),false,&l);
        }
    }
    for(i=0;i<ui->PropList->topLevelItemCount();i++)
    {
        array2menu(ui->PropList->topLevelItem(i));
        s = ui->PropList->topLevelItem(i)->text(0);
        if(!l.contains(s))l<<s;
        else
        {
            //conflict
            fixconflict(ui->PropList->topLevelItem(i),true,&l);
        }
    }
    gcprint(l.join("; "));
}

void classwindow::on_EventsListWidget_itemClicked(QListWidgetItem* item)
{
    updateCurrentActiveItem();
    CurrentActiveItem=item;
    ui->pushButton->setChecked(0);
    ui->stackedWidget->setCurrentIndex(1);
    ui->FunctionsListWidget->setCurrentIndex(QModelIndex());
    source->source->blockSignals(true);
    source->setText(item->data(TICODE).toString());
    source->source->blockSignals(false);
}

void classwindow::on_FunctionsListWidget_itemClicked(QListWidgetItem* item)
{
    updateCurrentActiveItem();
    CurrentActiveItem=item;
    ui->pushButton->setChecked(0);
    ui->stackedWidget->setCurrentIndex(1);
    ui->EventsListWidget->setCurrentIndex(QModelIndex());
    source->source->blockSignals(true);
    source->setText(item->data(TICODE).toString());
    source->source->blockSignals(false);
    ui->FunctionsListWidget->setCurrentItem(item);
}

void classwindow::updateCurrentActiveItem()
{
    if(CurrentActiveItem!=0)
    {
        gcprint("Setting " +CurrentActiveItem->text()+"'s code");
        CurrentActiveItem->setData(TICODE,source->source->toPlainText());
    }
}

void classwindow::modify()
{
    if(initialized==true)
    makeModified();
}

void classwindow::on_baseClassButton_clicked()
{
    getClassResource w(project,this);
    if(w.exec()==QDialog::Accepted)
    {
        if(w.resname!="")
        ui->baseClassButton->setText(w.resname);
        else ui->baseClassButton->setText("(none)");
        makeModified();
    }
}

void classwindow::on_EventsListWidget_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* i = ui->EventsListWidget->currentItem();
    if(i!=0)
    {
        QMenu m;
        QAction del(&m);del.setIcon(ffficon("delete"));
        del.setText(tr("Delete")+" \""+i->text()+"\"");
        QAction chg(&m);
        chg.setText(tr("Change event"));
        m.addAction(&del);m.addAction(&chg);
        QAction *res;
        res = m.exec( QCursor::pos() );
        if(res==&del)
        {
            updateCurrentActiveItem();
            on_pushButton_clicked();
            delete i;
            makeModified();
        }
    }
}

void classwindow::on_FunctionsListWidget_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* i = ui->FunctionsListWidget->currentItem();
    if(i!=0)
    {
        QMenu m;
        QAction del(&m);del.setIcon(ffficon("delete"));
        del.setText(tr("Delete")+" \""+i->text()+"\"");
        m.addAction(&del);

        QAction *res;
        res = m.exec( QCursor::pos() );
        if(res==&del)
        {
            updateCurrentActiveItem();
            on_pushButton_clicked();
            delete i;
            makeModified();
        }
    }
}
