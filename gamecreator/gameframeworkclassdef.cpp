#include "gameframeworkclassdef.h"
#include "ui_gameframeworkclassdef.h"
#include <QDebug>
#include <QDir>
#include <qdom.h>
#include <QMenu>
#include "ntdialog.h"
#include <QTextDocumentFragment>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QPlainTextEdit>
#include "scriptwindow.h"
#include <iostream>
#define CALLTASKFUNC (this->*taskFunc)

GameFrameworkClassDef::GameFrameworkClassDef(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameFrameworkClassDef)
{
    ui->setupUi(this);
    //load framework
    gcInitClasses();
    reloadData();
    ui->treeWidget->sortByColumn(0,Qt::AscendingOrder);
    taskmode=0;
    ui->stackedWidget->setCurrentWidget(ui->pgNone);
    ui->btnEdit->setVisible(0);
}

GameFrameworkClassDef::~GameFrameworkClassDef()
{
    delete ui;
}

void GameFrameworkClassDef::reloadData()
{
    ui->treeWidget->clear();

    //for ALL files add them
    vObjectIterator
            iFiles,
            iClasses,
            iObjects;   //var / function
    for(iFiles = gcGameScriptData.constBegin(); iFiles != gcGameScriptData.constEnd(); iFiles++)
    {
        vObject oFile = iFiles.value().toHash();
        QString fn = oFile.value("gcFileName").toString();

        QTreeWidgetItem* itemFile = gcTreeWidgetItem("book",fn);

        itemFile->setBackgroundColor(0,QColor(0,0,0,20));
        QFont f(itemFile->font(0)); f.setBold(true);
        itemFile->setFont(0,f);
        itemFile->setData(0,TIICON,"book/book_open");
        itemFile->setData(0,TITYPE,"file");
        itemFile->setData(0,TIDATA,fn); //the filename
        ui->treeWidget->addTopLevelItem(itemFile);

        //for each class in this file:
        for(iClasses = oFile.constBegin(); iClasses != oFile.constEnd(); iClasses++)
        {
            QString classItemText, classIcon="brick";
            if(iClasses.key().startsWith("gc"))
                if(!(iClasses.key()=="gcObject" or iClasses.key().startsWith("gcArray")))continue;
            classItemText = iClasses.key();
            if(classItemText.isEmpty())
            {
                classItemText = "<global>";
                classIcon = "tag";
            }
            vObject oClass = iClasses.value().toHash();
            QTreeWidgetItem* itemClass = gcTreeWidgetItem(classIcon,classItemText);
            itemClass->setData(0,TITYPE,"class");
            itemClass->setData(0,TIDATA,oClass);
            itemFile->addChild(itemClass);
            //each class have objects;
            for(iObjects = oClass.begin();iObjects != oClass.end();iObjects++)
            {
                if(iObjects.key().startsWith("gc"))continue;
                vObject oObject = iObjects.value().toHash();
                QString name = iObjects.key(), kind = oObject.value("kind").toString(),
                        type = oObject.value("type").toString();
                QTreeWidgetItem* itemMember = new QTreeWidgetItem;
                itemMember->setText(0,type+" "+name);
                oObject["name"]=name;
                itemMember->setData(0,TIDATA,oObject);
                itemMember->setData(0,TITYPE,"member"); //class member
                if(kind=="prop")itemMember->setIcon(0,ffficon("tag_red"));
                else if(kind=="var")itemMember->setIcon(0,ffficon("tag_green"));
                else if(kind=="func")itemMember->setIcon(0,ffficon("sum"));
                itemClass->addChild(itemMember);
            }
        }

    }//iFiles
    if(ui->treeWidget->topLevelItemCount()>0)
        ui->treeWidget->topLevelItem(0)->setExpanded(true);
}

void GameFrameworkClassDef::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GameFrameworkClassDef::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgSelectType);
}

void GameFrameworkClassDef::on_OKbutton_clicked()
{
    vObject replaceHash;
    int replaceId=0;
    //Generate XML DOM from the tree
    for(int i=0;i<ui->treeWidget->topLevelItemCount();i++)
    {
        //generate files
        QTreeWidgetItem* it = ui->treeWidget->topLevelItem(i);
        QString fn = it->data(0,TIDATA).toString(); //file.gsd
        //fn+=".xml";//only debug, remove it
        QDomDocument xml;
        QDomProcessingInstruction header = xml.createProcessingInstruction("xml","version=\"1.0\"");
        xml.appendChild(header);
        QDomElement gsdata = xml.createElement("gamescriptdata");
        xml.appendChild(gsdata);
        gsdata.setAttribute("name","piGameScript"); //unused, but let it be there

        QString preamble =  //this is very, very ugly hardcoding example!

            "\n\nPGSXML framework definition file.\n  "
            "\n  "
            "DO NOT MODIFY - if you modify this, you will alter\n  "
            "the piGameCreator intellisense and code completion \n  "
            "database for the framework, that is, intellisense \n  "
            "and the code tokenizer won't recognize the Game \n  "
            "Framework functions.\n";

        QDomComment comment = xml.createComment(preamble);
        gsdata.appendChild(comment);

        //classes:
        for(int iClass=0;iClass<it->childCount();iClass++)
        {
            QTreeWidgetItem* icls = it->child(iClass);
            QString name = icls->text(0), tagname;
            bool isClass=true;
            if(name=="<global>"){tagname="global";isClass=false;name="";}
            else{tagname="class";}
            QDomElement eClass = xml.createElement(tagname);
            if(isClass)
            {
                vObject o = icls->data(0,TIDATA).toHash();
                eClass.setAttribute("name",name);
                if(o.value("gcHidden").toBool())eClass.setAttribute("hidden","true");
                if(o.value("gcDisplayName").toString()!="")eClass.setAttribute("doc",o.value("gcDisplayName").toString());
                if(o.value("gcDesc").toString()!="")eClass.setAttribute("desc",o.value("gcDesc").toString());
            }
            gsdata.appendChild(eClass);
            //add class's data
            for(int iObject=0;iObject<icls->childCount();iObject++)
            {
                QTreeWidgetItem* iobj = icls->child(iObject);
                //what type of object is it?
                vObject o = iobj->data(0,TIDATA).toHash();
                QString kind = o.value("kind").toString();
                QDomElement e=xml.createElement(kind);
                eClass.appendChild(e);
                e.setAttribute("name",o.value("name").toString());
                e.setAttribute("type",o.value("type").toString());
                QString desc = o.value("desc").toString(); //this can be XML as well!
                desc = HTMLBodyContents(desc);
                QString hash = QString(QCryptographicHash::hash(QString::number(replaceId).toLocal8Bit(),QCryptographicHash::Md5).toHex());
                replaceId++;
                QDomText xdesc = xml.createTextNode(hash);
                replaceHash[hash]=desc;
                e.appendChild(xdesc);
                if(kind=="func")
                {
                    if(o.value("static").toBool())e.setAttribute("static","true");
                    //arguments
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
                    QMap<int,QVariant>::iterator iArg2;
                    for(iArg2=argsordered.begin();iArg2!=argsordered.end();iArg2++)
                    {
                        vObject arg = iArg2.value().toHash();
                        if(arg.value("kind").toString()=="arg")
                        {
                            //arg is an argument!
                            //name and type
                            e.setAttribute("arg"+QString::number(iArg2.key()),arg.value("type").toString()+" "+arg.value("name").toString());
                            //default value
                            if(arg.value("val").toString()!="")
                                e.setAttribute("arg"+QString::number(iArg2.key())+"value",arg.value("val").toString());
                            //description
                            if(arg.value("desc").toString()!="")
                                e.setAttribute("arg"+QString::number(iArg2.key())+"desc",arg.value("desc").toString());
                        }
                    }
                }
            }
        }
        //Replace the HASHES with actual XML parts! [HACK]
        QString xmls = xml.toString(4);
        vObjectIterator i;
        for(i=replaceHash.begin();i!=replaceHash.end();i++)
        {
            xmls.replace(i.key(),i.value().toString());
        }

        //save to file
        QFile f("data/"+fn);
        if(f.open(QIODevice::WriteOnly))
        {
            QTextStream TextStream(&f);
            TextStream << xmls;
            f.close();
        }
    }
    //and...
    //close();
    ui->cancelButton->setText("Close");
}

void GameFrameworkClassDef::on_treeWidget_currentItemChanged(QTreeWidgetItem *item, QTreeWidgetItem *previous)
{
    if(taskmode){ui->stackedWidget->setCurrentWidget(ui->pgTasks);return;}
    if(item==0){ui->stackedWidget->setCurrentWidget(ui->pgNone);return;}
    QString type = item->data(0,TITYPE).toString();
    if(type=="member")
    {
        vObject o = item->data(0,TIDATA).toHash();
        QString kind = o.value("kind").toString();
        if(kind=="prop")
        {
            ui->stackedWidget->setCurrentWidget(ui->pgProperty);
            ui->propDesc->setText(o.value("desc").toString());
            ui->propType->setEditText(o.value("type").toString());
            ui->propName->setText(o.value("name").toString());
        }
        else if(kind=="var")
        {
            ui->stackedWidget->setCurrentWidget(ui->pgVariable);
            ui->varDesc->setText(o.value("desc").toString());
            ui->varType->setEditText(o.value("type").toString());
            ui->varName->setText(o.value("name").toString());
        }
        else if(kind=="func")
        {
            ui->stackedWidget->setCurrentWidget(ui->pgFunction);
            ui->fnName->setText(o.value("name").toString());
            ui->fnType->setEditText(o.value("type").toString());
            ui->fnDesc->setText(o.value("desc").toString());
            ui->staticFunction->setChecked(o.value("static").toBool());
            //show all arguments
            vObjectIterator iArg; //LOADER: UNORDERED!!! Save to MAP first!
            QMap<int,QVariant> argsordered;
            for(iArg=o.begin();iArg!=o.end();iArg++)
            {
                vObject arg = iArg.value().toHash();
                if(arg.value("kind").toString()=="arg")
                {
                    //arg is an argument!
                    QString key = iArg.key();
                    int idx = key.replace("arg","").toInt();
                    argsordered[idx]=iArg.value();
                }
            }
            QMap<int,QVariant>::iterator iArg2;
            ui->fnArgumentList->clear();
            for(iArg2=argsordered.begin();iArg2!=argsordered.end();iArg2++)
            {
                vObject arg = iArg2.value().toHash();
                if(arg.value("kind").toString()=="arg")
                {
                    //arg is an argument!
                    QTreeWidgetItem* ai = new QTreeWidgetItem();
                    ai->setIcon(0,ffficon("tag_yellow"));
                    ai->setText(0,arg.value("name").toString());
                    ai->setText(1,arg.value("type").toString());
                    ai->setText(2,arg.value("val").toString());
                    ai->setText(3,arg.value("desc").toString());
                    ui->fnArgumentList->addTopLevelItem(ai);
                }
            }
        }
        else
        {
            //is DATA ok?
            qDebug() << o;
        }
    }
    else if(type=="class")
    {
        vObject o = item->data(0,TIDATA).toHash();
        ui->classDisplayName->setText(o.value("gcDisplayName").toString());
        ui->classDescEdit->setText(o.value("gcDesc").toString());
        ui->classHidden->setChecked(o.value("gcHidden").toBool());
        ui->className->setText(item->text(0)=="<global>"?"":item->text(0));

        ui->stackedWidget->setCurrentWidget(ui->pgClassSettings);
    }
    else if(type=="file")
    {
        ui->ClassFile->setText(item->data(0,TIDATA).toString());
        ui->stackedWidget->setCurrentWidget(ui->pgClassFile);
    }
}

void GameFrameworkClassDef::ExpandOrCollapseIcon(QTreeWidgetItem* item,bool expand)
{
    QString ic = item->data(0,TIICON).toString();
    if(!ic.isEmpty())
        if(ic.indexOf("/")>0)
        {
            QStringList icons = ic.split("/");
            item->setIcon(0,ffficon(icons.at(expand)));
        }
}

void GameFrameworkClassDef::on_fnArgumentList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(item==0)return;
    NTdialog d;
    d.name = item->text(0);
    d.type = item->text(1);
    d.value= item->text(2);
    d.desc = item->text(3);
    d.exec();
    if(d.result())
    {
        item->setText(0,d.name);
        item->setText(1,d.type);
        item->setText(2,d.value);
        item->setText(3,d.desc);
    }
    arglistUpdate();
}

void GameFrameworkClassDef::on_AddButton_clicked()
{
    NTdialog d;
    d.exec();
    if(d.result())
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setIcon(0,ffficon("tag_yellow"));
        item->setText(3,d.desc);
        item->setText(2,d.value);
        item->setText(1,d.type);
        item->setText(0,d.name);
        ui->fnArgumentList->addTopLevelItem(item);
    }
    arglistUpdate();
}

void GameFrameworkClassDef::arglistUpdate()
{
    //updates the argument list object
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    vObjectIterator iArg;
    vObject oo;//new version of o without argument data
    for(iArg=o.begin();iArg!=o.end();iArg++)
    {
        vObject arg = iArg.value().toHash();
        if(arg.value("kind").toString()!="arg")
            oo[iArg.key()]=iArg.value();    //copy this value if not argument data

        //oo is now clone of o except the arguments!
        for(int i=0;i<ui->fnArgumentList->topLevelItemCount();i++)
        {
            //add the argument
            QTreeWidgetItem* it = ui->fnArgumentList->topLevelItem(i);
            vObject argdata;
            argdata["kind"] = "arg";    //required to identify [bug: not 'king' please!]
            argdata["desc"] = it->text(3);//descrption
            argdata["val"]  = it->text(2);//default value
            argdata["type"] = it->text(1);//type
            argdata["name"] = it->text(0);//name
            if(it->text(0)=="" or it->text(1)=="")
            {
                gcerror("Name and Type are required");
                goto l_end; //exit all nested loops!
            }
            else
            oo["arg"+QString::number(i+1)] = argdata;   //add to the new object
        }
    }
    //now update the object with the new object
    ui->treeWidget->currentItem()->setData(0,TIDATA,oo);

l_end:
    on_treeWidget_currentItemChanged(ui->treeWidget->currentItem(),0);
}

void GameFrameworkClassDef::on_removeButton_2_clicked()
{
    on_fnArgumentList_itemDoubleClicked(ui->fnArgumentList->currentItem(),0);
}

void GameFrameworkClassDef::on_removeButton_clicked()
{
    qDeleteAll(ui->fnArgumentList->selectedItems());
    arglistUpdate();
}

void GameFrameworkClassDef::on_btnEdit_clicked()
{
    taskmode=0;
    //which page?
    on_treeWidget_currentItemChanged(ui->treeWidget->currentItem(),0); //will set it
    ui->btnEdit->setVisible(0);
    ui->btnTasks->setVisible(1);
}

void GameFrameworkClassDef::on_btnTasks_clicked()
{
    taskmode=1;
    ui->stackedWidget->setCurrentWidget(ui->pgTasks);
    ui->btnTasks->setVisible(0);
    ui->btnEdit->setVisible(1);
}

void GameFrameworkClassDef::txBold(QTextEdit* t)
{
    QTextCursor c = t->textCursor();
    QTextCharFormat cf;
    bool wa=c.anchor()>c.position();

    if(wa)c.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,1);
    if(c.charFormat().font().bold())
        cf.setFontWeight(0);
    else
        cf.setFontWeight(QFont::Bold);
    if(wa)c.movePosition(QTextCursor::Left,QTextCursor::KeepAnchor,1);
    c.mergeCharFormat(cf);
}

void GameFrameworkClassDef::txItalic(QTextEdit* t)
{
    QTextCursor c = t->textCursor();
    QTextCharFormat cf;
    bool wa=c.anchor()>c.position();

    if(wa)c.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,1);
    if(c.charFormat().font().italic())
        cf.setFontItalic(0);
    else
        cf.setFontItalic(1);
    if(wa)c.movePosition(QTextCursor::Left,QTextCursor::KeepAnchor,1);
    c.mergeCharFormat(cf);
}

void GameFrameworkClassDef::txUnderline(QTextEdit* t)
{
    QTextCursor c = t->textCursor();
    QTextCharFormat cf;
    bool wa=c.anchor()>c.position();

    if(wa)c.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,1);
    if(c.charFormat().font().underline())
        cf.setFontUnderline(0);
    else
        cf.setFontUnderline(1);
    if(wa)c.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor,1);
    c.mergeCharFormat(cf);
}

void GameFrameworkClassDef::txFixedWidth(QTextEdit* t)
{
    QTextCursor c = t->textCursor();
    QTextCharFormat cf;
    bool wa=c.anchor()>c.position();

    if(wa)c.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,1);
    if(c.charFormat().fontStyleHint()==QFont::TypeWriter)
    {
        cf.setFontStyleHint(QFont::SansSerif);
        cf.setFontFamily("");
        cf.setFontPointSize(0);
    }
    else
    {
        cf.setFontStyleHint(QFont::TypeWriter);
        cf.setFontFamily("monospace");
        cf.setFontPointSize(10);
    }
    if(wa)c.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor,1);
    c.mergeCharFormat(cf);
}

void GameFrameworkClassDef::txStrike(QTextEdit* t)
{
    QTextCursor c = t->textCursor();
    QTextCharFormat cf;
    bool wa=c.anchor()>c.position();

    if(wa)c.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,1);
    if(c.charFormat().font().strikeOut())
        cf.setFontStrikeOut(0);
    else
        cf.setFontStrikeOut(1);
    if(wa)c.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor,1);
    c.mergeCharFormat(cf);
}

void GameFrameworkClassDef::on_toolButton_3_clicked()
{
    txBold(ui->classDescEdit);
}


void GameFrameworkClassDef::on_toolButton_5_clicked()
{
    txFixedWidth(ui->classDescEdit);
}

void GameFrameworkClassDef::on_toolButton_clicked()
{
    txItalic(ui->classDescEdit);
}

void GameFrameworkClassDef::on_toolButton_2_clicked()
{
    txUnderline(ui->classDescEdit);
}

void GameFrameworkClassDef::on_toolButton_4_clicked()
{
    txStrike(ui->classDescEdit);
}

void GameFrameworkClassDef::on_toolButton_13_clicked()
{
    txFixedWidth(ui->varDesc);
}

void GameFrameworkClassDef::on_toolButton_14_clicked()
{
    txBold(ui->varDesc);
}

void GameFrameworkClassDef::on_toolButton_15_clicked()
{
    txItalic(ui->varDesc);
}

void GameFrameworkClassDef::on_toolButton_16_clicked()
{
    txUnderline(ui->varDesc);
}

void GameFrameworkClassDef::on_toolButton_17_clicked()
{
    txStrike(ui->varDesc);
}

void GameFrameworkClassDef::on_toolButton_23_clicked()
{
    txFixedWidth(ui->fnDesc);
}

void GameFrameworkClassDef::on_toolButton_24_clicked()
{
    txBold(ui->fnDesc);
}

void GameFrameworkClassDef::on_toolButton_25_clicked()
{
    txItalic(ui->fnDesc);
}

void GameFrameworkClassDef::on_toolButton_26_clicked()
{
    txUnderline(ui->fnDesc);
}

void GameFrameworkClassDef::on_toolButton_27_clicked()
{
    txStrike(ui->fnDesc);
}

void GameFrameworkClassDef::on_toolButton_18_clicked()
{
    txFixedWidth(ui->propDesc);
}

void GameFrameworkClassDef::on_toolButton_19_clicked()
{
    txBold(ui->propDesc);
}

void GameFrameworkClassDef::on_toolButton_20_clicked()
{
    txItalic(ui->propDesc);
}

void GameFrameworkClassDef::on_toolButton_21_clicked()
{
    txUnderline(ui->propDesc);
}

void GameFrameworkClassDef::on_toolButton_22_clicked()
{
    txStrike(ui->propDesc);
}

void GameFrameworkClassDef::on_treeWidget_itemExpanded(QTreeWidgetItem *item)
{
    ExpandOrCollapseIcon(item);
}

void GameFrameworkClassDef::on_treeWidget_itemCollapsed(QTreeWidgetItem *item)
{
    ExpandOrCollapseIcon(item,false);
}

//variables
void GameFrameworkClassDef::on_varDesc_textChanged()
{
    QString t = ui->varDesc->toHtml();
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["desc"]=t;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_varName_textChanged(const QString &arg1)
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["name"]=arg1;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
    ui->treeWidget->currentItem()->setText(0,o.value("type").toString()+" "+o.value("name").toString());
}

void GameFrameworkClassDef::on_varType_editTextChanged(const QString &arg1)
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["type"]=arg1;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
    ui->treeWidget->currentItem()->setText(0,o.value("type").toString()+" "+o.value("name").toString());
}

//functions
void GameFrameworkClassDef::on_staticFunction_clicked()
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["static"]=(ui->staticFunction->isChecked()?"true":"false");
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
    ui->treeWidget->currentItem()->setText(0,o.value("type").toString()+" "+o.value("name").toString());
}


void GameFrameworkClassDef::on_fnName_textChanged(const QString &arg1)
{
    //code is copy of on_varName_textChanged
    on_varName_textChanged(arg1);
    /*
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["name"]=arg1;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
    ui->treeWidget->currentItem()->setText(0,o.value("type").toString()+" "+o.value("name").toString()); /**/
}

void GameFrameworkClassDef::on_fnType_editTextChanged(const QString &arg1)
{
    //copy of:
    on_varType_editTextChanged(arg1);
}

void GameFrameworkClassDef::on_fnDesc_textChanged()
{
    QString t = ui->fnDesc->toHtml();
    //maintain: Copy of on_varDesc_textChanged();
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["desc"]=t;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_propName_textChanged(const QString &arg1)
{
    on_varName_textChanged(arg1);
}

void GameFrameworkClassDef::on_propType_editTextChanged(const QString &arg1)
{
    on_varType_editTextChanged(arg1);
}

void GameFrameworkClassDef::on_propDesc_textChanged()
{
    QString t = ui->propDesc->toHtml();
    //maintain: Copy of on_varDesc_textChanged();
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["desc"]=t;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_addvarRB_clicked()
{
    QTreeWidgetItem* it = ui->treeWidget->currentItem(), *target=it;
    QString type = it->data(0,TITYPE).toString(); //file, class, member
    if(type=="file"){gcerror("Only classes can be added to files!");return;}
    else if(type=="member")target=it->parent();

    //now add the variable to the tree
    QTreeWidgetItem* n = new QTreeWidgetItem;
    n->setIcon(0,ffficon("tag_green"));
    n->setData(0,TITYPE,"member");
    vObject o;
    o["kind"]="var";
    o["type"]="int";
    o["desc"]="";
    o["name"]=""; //not sure about this
    n->setData(0,TIDATA,qVariantFromValue(o));
    ui->treeWidget->expandItem(target);
    target->addChild(n);
    ui->treeWidget->setCurrentItem(n);
}

void GameFrameworkClassDef::on_addvarRB_2_clicked()
{
    //maintain: TODO: Avoid that being copypasted all over again!
    QTreeWidgetItem* it = ui->treeWidget->currentItem(), *target=it;
    QString type = it->data(0,TITYPE).toString(); //file, class, member
    if(type=="file"){gcerror("Only classes can be added to files!");return;}
    else if(type=="member")target=it->parent();

    //now add the variable to the tree
    QTreeWidgetItem* n = new QTreeWidgetItem;
    n->setIcon(0,ffficon("tag_red"));
    n->setData(0,TITYPE,"member");
    vObject o;
    o["kind"]="prop";
    o["type"]="int";
    o["desc"]="";
    o["name"]=""; //not sure about this
    n->setData(0,TIDATA,o); //data is EMPTY? WTF?
    ui->treeWidget->expandItem(target);
    target->addChild(n);
    ui->treeWidget->setCurrentItem(n);
}

void GameFrameworkClassDef::on_addFunction_clicked()
{
    //maintain: TODO: Avoid that being copypasted all over again!
    QTreeWidgetItem* it = ui->treeWidget->currentItem(), *target=it;
    QString type = it->data(0,TITYPE).toString(); //file, class, member
    if(type=="file"){gcerror("Only classes can be added to files!");return;}
    else if(type=="member")target=it->parent();

    //now add the variable to the tree
    QTreeWidgetItem* n = new QTreeWidgetItem;
    n->setIcon(0,ffficon("sum"));
    n->setData(0,TITYPE,QString("member"));
    vObject o;
    o["kind"]="func";
    o["type"]="void";
    o["desc"]="";
    o["name"]=""; //not sure about this
    n->setData(0,TIDATA,o);
    ui->treeWidget->expandItem(target);
    target->addChild(n);
    ui->treeWidget->setCurrentItem(n);
}

void GameFrameworkClassDef::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu m;
    QAction ins(&m),del(&m),insvar(&m),insfunc(&m),insprop(&m),copy(&m);
    ins.setIcon(ffficon("add"));
    del.setIcon(ffficon("cancel"));
    ins.setText("Insert other...");
    del.setText("Delete");
    insvar.setText("Insert variable");
    insvar.setIcon(ffficon("tag_green"));
    insprop.setText("Insert property");
    insprop.setIcon(ffficon("tag_red"));
    insfunc.setText("Insert function");
    insfunc.setIcon(ffficon("sum"));
    copy.setText("Duplicate this");
    copy.setIcon(ffficon("page_copy"));

    m.addAction(&copy);
    m.addSeparator();
    m.addAction(&insvar);
    m.addAction(&insfunc);
    m.addAction(&insprop);
    m.addAction(&ins);
    m.addSeparator();
    m.addAction(&del);
    QAction* res = m.exec(QCursor::pos());
    if(res==&ins)
    {
        //insert other
        on_pushButton_3_clicked();
    }
    else if(res==&del)
    {
        //delete selected
        QTreeWidgetItem* item = ui->treeWidget->currentItem(), *target=item;
        QString kind = item->data(0,TITYPE).toString(); //file,class,member
        if(kind=="member")target=item->parent();
        if(kind=="class")target=item->parent();
        if(kind=="file"){gcerror("Cannot delete piGameScript definition files from here!\n"
                                 "Please, remove them from the operating system");return;}
        //crash if serious data corruption occur!
        ui->treeWidget->setCurrentItem(target);
        delete item; //must be unused
    }
    else if(res==&insvar)
    {
        on_addvarRB_clicked();
        ui->stackedWidget->setFocus();
    }
    else if(res==&insprop)
    {
        on_addvarRB_2_clicked();
        ui->stackedWidget->setFocus();
    }
    else if(res==&insfunc)
    {
        on_addFunction_clicked();
        ui->stackedWidget->setFocus();
    }
    else if(res==&copy)
    {
        QTreeWidgetItem* current = ui->treeWidget->currentItem(),
                *dupl = current->clone();
        current->parent()->addChild(dupl);
    }
}

void GameFrameworkClassDef::on_radioButton_clicked()
{
    //maintain: TODO: Avoid that being copypasted all over again!
    QTreeWidgetItem* it = ui->treeWidget->currentItem(), *target=it;
    QString type = it->data(0,TITYPE).toString(); //file, class, member
    if(type=="class")target=it->parent();
    else if(type=="member")target=it->parent()->parent();

    //now add the variable to the tree
    QTreeWidgetItem* n = new QTreeWidgetItem;
    n->setIcon(0,ffficon("brick"));
    n->setData(0,TITYPE,"class");
    n->setData(0,TIDATA,vObject());
    ui->treeWidget->expandItem(target);
    target->addChild(n);
    ui->treeWidget->setCurrentItem(n);
}

void GameFrameworkClassDef::on_radioButton_2_clicked()
{
    gcerror("To add new file:\n • Save and close this dialog\n • create a new file into the Data folder with .GSD extension");
}


/*
    else if(type=="class")
    {
        vObject o = item->data(0,TIDATA).toHash();
        ui->classDisplayName->setText(o.value("gcDisplayName").toString());
        ui->classDescEdit->setText(o.value("gcDesc").toString());
        ui->classHidden->setChecked(o.value("gcHidden").toBool());
        ui->className->setText(item->text(0));
        ui->stackedWidget->setCurrentWidget(ui->pgClassSettings);
    }
    /**/

void GameFrameworkClassDef::on_className_textChanged(const QString &arg1)
{
    QString text = arg1;
    if(arg1=="")
    {
        text="<global>";
        ui->treeWidget->currentItem()->setIcon(0,ffficon("tag"));
    }
    else ui->treeWidget->currentItem()->setIcon(0,ffficon("brick"));
    ui->treeWidget->currentItem()->setText(0,text);
}

void GameFrameworkClassDef::on_classDisplayName_textChanged(const QString &arg1)
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["gcDisplayName"]=arg1;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_classDescEdit_textChanged()
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["gcDesc"]=HTMLBodyContents(ui->classDescEdit->toHtml());
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_classHidden_clicked(bool checked)
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["gcHidden"]=checked;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::on_staticFunction_clicked(bool checked)
{
    vObject o = ui->treeWidget->currentItem()->data(0,TIDATA).toHash();
    o["static"]=checked;
    ui->treeWidget->currentItem()->setData(0,TIDATA,o);
}

void GameFrameworkClassDef::saveAndReload()
{
    on_OKbutton_clicked();
    gcInitClasses();
    reloadData();
}
void GameFrameworkClassDef::whichTask()
{
    if(ui->genCpp->isChecked())taskFunc = (fptr)&GameFrameworkClassDef::genCpp;
    else if(ui->genDoc->isChecked())taskFunc = (fptr)&GameFrameworkClassDef::genDoc;
    else if(ui->genJs->isChecked())taskFunc = (fptr)&GameFrameworkClassDef::genJs;
}

void GameFrameworkClassDef::on_TaskCurrentClass_clicked()
{
    //which class?
    QTreeWidgetItem* item = ui->treeWidget->currentItem(), *target=item;
    if(item==0)return; //Crash protection
    QString kind = item->data(0,TITYPE).toString(); //file,class,member
    if(kind=="member")target=item->parent(); //we need the class here
    if(kind=="file"){gcerror("A class must be selected!");return;}
    vObject Class = target->data(0,TIDATA).toHash();
    QString className = Class.value("gcName").toString(); //name
    saveAndReload();
    whichTask();
    Class = gcClass(className);
    CALLTASKFUNC(Class,0);
    CALLTASKFUNC(Class,1);
    CALLTASKFUNC(Class,2);
}

void GameFrameworkClassDef::on_TaskAllClasses_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem(), *target=item;
    if(item==0)return; //Crash protection
    QString kind = item->data(0,TITYPE).toString(); //file,class,member
    if(kind=="member")target=item->parent()->parent(); //we need the file here
    if(kind=="class")target=item->parent(); //we need the file here
    //now get the file:
    QString file=target->text(0);
    saveAndReload();
    whichTask();

    QList<vObject> L;
    vObjectIterator FI;
    for(FI=gcGameScriptData.begin();FI!=gcGameScriptData.end();++FI)
        if(FI.key()==file)
        {
            vObject File = FI.value().toHash();
            vObjectIterator Class;
            for(Class=File.begin();Class!=File.end();++Class)
                L << Class.value().toHash();
        }

    vObject Class;
    CALLTASKFUNC(Class,0);
    for(int i=0;i<L.count();i++)
        CALLTASKFUNC(L.at(i),1);
    CALLTASKFUNC(Class,2); //don't read it. just complete it!
}

void GameFrameworkClassDef::on_TaskAllFiles_clicked()
{
    saveAndReload();
    whichTask();
    vObject Class;
    CALLTASKFUNC(Class,0);
    QList<vObject> L = gcClasses();
    for(int i=0;i<L.count();++i)CALLTASKFUNC(L.at(i),1);
    CALLTASKFUNC(Class,2);
}

QString GameFrameworkClassDef::cppGetType(QString type, bool noPointer)
{
    //qDebug() << type;
    int isArray = type.indexOf("[]");

    if(isArray!=-1)
    {
        type.replace("[]","");
        if(!hUsedTypes.contains("gcArray"))hUsedTypes.append("gcArray");   //must use this as well! well, C++...
    }
    QString t = cppMappings.value(type).toString()!=""?cppMappings.value(type).toString():type;

    //Don't #include builtin types, please!
    QString rawtype = t;
    if(!cppBuiltInTypes.contains(rawtype))
        if(!hUsedTypes.contains(rawtype))
            hUsedTypes.append(rawtype);

    //is t an pointer type?
    if(!noPointer)if(!cppValueTypes.contains(t))t.append("*");

    if(isArray!=-1)t = "gcArray<"+t+">*";

    return t;
}

QString GameFrameworkClassDef::cppGetName(QString name)
{
    return cppMappings.value(name).toString()=="" ? name :cppMappings.value(name).toString();
}

void GameFrameworkClassDef::genCpp(vObject Class,int when)
{
    switch(when)
    {
    case 0:
        //clear all mappings
        cppBuiltInTypes.clear();
        cppMappings.clear();
        cppValueTypes.clear();

        //map GameScript types to C++
        //real is assumed C++ type but it will be actually TYPEDEF'd in 'pgframework.h'
        cppBuiltInTypes<<"int"<<"real"<<"void"<<"double"<<"bool";
        cppMappings["string"]="gcString"; //making a string class will override std::string

        //map functions
        cppMappings["at"]="gcAt";
        cppMappings["isEqual"]="gcIsEqual";
        cppMappings["fromString"]="gcFromString";
        cppMappings["toString"]="gcToString";
        cppMappings["fromInt"]="gcFromInt";
        cppMappings["toInt"]="gcToInt";
        cppMappings["fromReal"]="gcFromReal";
        cppMappings["toReal"]="gcToReal";
        cppMappings["throw"]="gcThrow";
        //cppMappings[""]="gc";


        //about pointers: ALL TYPES are pointers EXCEPT these added here:
        cppValueTypes.append(cppBuiltInTypes);
        cppValueTypes<<"gcString"; //<<"point2D"<<"point3D"<<"color";

        //arrays nees special treatment

        //all rest types will be as they are :}

        break;
    case 1:
    {
        hUsedTypes.clear();
        QString header,source, fnh, fncpp, target="../../cppengine",
                hforwards,inclh,inclcpp,classmember, className, classNameNoPointer;
        QStringList classmembers;
        QList<vObject> functions; //vObject contains: sig, code  [CPP entries]
        QTextEdit textedit;  //used only for HTML2TEXT
        className=cppGetType(Class.value("gcName").toString());
        classNameNoPointer=cppGetType(Class.value("gcName").toString(),true);

        //includes:
        inclh = "#include \"pgframework.h\"";

        //For each item in the class:
        vObjectIterator iClass;
        for(iClass=Class.begin();iClass!=Class.end();iClass++)
        {
            vObject o = iClass.value().toHash();
            QString kind = o.value("kind").toString();
            textedit.setText(o.value("desc").toString());
            //QApplication::processEvents();
            QString desc = textedit.toPlainText();
            o["name"]=iClass.key();
            if(o.value("type").toString()=="")continue;

            //DAMN the f***ing COMMENTS!
            if(desc!="")
                classmember = "\n/*\n\t" + desc.replace("\n","\n\t") + "\n*/\n\t/*COMMENTS END*/";
            else
                classmember = "/*COMMENTS END*/"; //Used in UPDATE to separate COMMENTS from MEMBER

            if(kind=="func")
            {
                //vObject func;
                QString sig, code;

                classmember += o.value("static").toBool()?"static ":"";
                classmember += cppGetType(o.value("type").toString());
                classmember += " ";
                classmember += cppGetName(o.value("name").toString());
                classmember += "("; //arglist opening bracket

                sig += cppGetType(o.value("type").toString());
                sig += " "+classNameNoPointer+(classNameNoPointer!=""?"::":"")+cppGetName(o.value("name").toString());
                sig += "("; //arglist opening bracket
                //arguments
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
                QMap<int,QVariant>::iterator iArg2;
                for(iArg2=argsordered.begin();iArg2!=argsordered.end();iArg2++)
                {
                    vObject arg = iArg2.value().toHash();
                    if(arg.value("kind").toString()=="arg")
                    {
                        //arg is an argument!
                        //name and type
                        classmember += cppGetType(arg.value("type").toString())+" "+arg.value("name").toString();
                        sig += cppGetType(arg.value("type").toString())+" "+arg.value("name").toString();
                        if(arg.value("val").toString()!="")
                        {
                            classmember+=" = "+arg.value("val").toString(); //not optimized
                            //sig+=" = "+arg.value("val").toString(); //even worse
                        }
                        //NOTE: ^ String literals may differ in piGameScript and C++

                        if(iArg2 != argsordered.end()-1)
                        {
                            classmember+=", ";
                            sig+=", ";
                        }
                    }
                }
                //Note: may add some comment in here
                classmember += ");"; //closing arglist and entry

                classmembers.append(classmember);   //must be the correct function

                sig += ");\n"; //closing arglist

                code+="{\n\t::gcThrow(\"Feature not implemented: \\n"+
                        cppGetType(o.value("type").toString())+" "+Class.value("gcName").toString()+(classNameNoPointer!=""?"::":"")+o.value("name").toString()
                        +"\",\"NOT_IMPLEMENTED\");\n}\n\n";

                vObject func;
                func["sig"]=sig.replace("\n","");
                func["code"]=code;
                functions.push_back(func);
            }
            else
            {
                //not a function |    type name;
                if(o.value("type").toString()!="")
                classmember += cppGetType(o.value("type").toString())+" "+ cppGetName(o.value("name").toString())+";";
                classmembers.append(classmember);
            }
        }

        /*
          TODO: Write the Special Functions generation
            some functions are special:
            toInt, toString, toBool, toReal, isEqual, at
            they may need some fixed treatment: they always MUST exist
            and default to unimplemented / Exception!
        */

        //in case you aren't running in the source tree
        //generate in application folder instead
        if(!QFile::exists(target))
        {
            QMessageBox::information(this,"Information",
                                     "The files will be generated in the application folder\n"
                                     "Note that on Windows Vista and 7 this may FAIL!");
            target="generatedCPP";
        }

        QFile fh,fcpp;
        if(classNameNoPointer=="")
        {
            className="globals";
            classNameNoPointer="globals";
        }
        fnh  =target+"/"+classNameNoPointer+".h";
        fncpp=target+"/"+classNameNoPointer+".cpp";
        fh.setFileName(fnh);
        fcpp.setFileName(fncpp);
        QString fTitle, sTitle;

        if(fh.exists())
        {
            fTitle="//UPDATED\n";
            //update the header
            QString oh;      //original header
            if(fh.open(QIODevice::ReadOnly))
            {
                oh=fh.readAll();
                fh.close();
            }

            //update the #include and forward declaration lists:
            // UPDATION will NOT touch these. It's developer's responsibility to update them.
            /*
            foreach(QString s,hUsedTypes)
            {
                //must NOT #include itself!
                if(s!=classNameNoPointer)
                {
                    //this file is included by ALL files in the project:
                    QString occ = "#include \"pgframework.h\"";
                    int pos=oh.indexOf(occ);
                    if(pos!=-1)pos+=occ.length()+1;
                    else pos=0;
                    QString include = "#include \""+s+".h\"\n";
                    if(!oh.contains(include))
                        oh.insert(pos,include);
                }
            }/**/

            //update the class members list:
            //Add after the public: declaration
            int pos = oh.indexOf("public:"); //end of THE class?
            if(pos!=-1)
            {
                //go to the end of public declaration
                pos+=8;
            }
            else pos=oh.indexOf("};");

            //pos should now point to good place to add new class members - not perfect but good enough!
            //add the classmembers
            foreach(QString member, classmembers)
            {
                QString marker = "/*COMMENTS END*/";
                int pos2 = member.indexOf(marker);
                if(pos2!=-1)pos2+=marker.length();
                QString fm = member.mid(pos2);
                if(!fm.isEmpty())
                if(!oh.contains(fm))
                    oh.insert(pos,"\t"+member.replace(marker,"")+"\n");
            }

            //header file is now updated.
            header = oh;
        }
        else
        {
            QString marker = "/*COMMENTS END*/";
            fTitle = "//CREATED";
            //Generate the header:

            //First, generate the forward declarations and #include s
            foreach(QString s,hUsedTypes)
            {
                //must NOT #include itself!
                if(s!=classNameNoPointer)
                {
                    //Decide when to generate #INCLUDE or when to generate FORWARD
                    if(cppValueTypes.contains(s) || s.contains("gcArray"))
                    inclh += "\n#include \""+s+".h\"";
                    else
                    hforwards += "\nclass "+s+";";  //FORWARD
                }
            }
            qDebug() << hUsedTypes;

            inclh += "\n";
            QString uppername = classNameNoPointer.toUpper() + "_H",
            guards = "#ifndef " +uppername + "\n#define "+uppername;
            header = guards + "\n" + inclh + "\n" + hforwards + "\n\nclass " + classNameNoPointer + "\n{\npublic:\n";
            foreach(QString member,classmembers)
                if(!member.isEmpty())header+="\t"+member.replace(marker,"")+"\n";
            header += "};\n\n#endif //"+uppername;
        }

        if(fcpp.exists())
        {
            sTitle = "//UPDATED";
            //update the source
            QString os;      //original source
            if(fcpp.open(QIODevice::ReadOnly))
            {
                os=fcpp.readAll();
                fcpp.close();
            }

            //now add THESE functions that AREN'T THERE ALREADY!
            //DO NOT EVEN CONSIDER touching something other as it may be very stable code!
            foreach(vObject ff,functions)
            {
                QString what = ff.value("sig").toString().replace(");",")");
                gcprint(what);
                if(!os.contains(what))
                {
                    os += "\n"+ what + "\n" + ff.value("code").toString();
                }
            }
            source = os;
        }
        else
        {
            sTitle = "//CREATED";
            //Generate the source:
            //TODO: Must seriously check the original file and only add to it if segment is not already there!
            source = "#include \""+classNameNoPointer+".h\"\n";
            source += "#include \"globals.h\"\n";   //for gcThrow   [damn, hardcoding stuff...]
            foreach(vObject ff,functions)
            {
                source += ff.value("sig").toString().replace(");",")")+ "\n" +ff.value("code").toString();
            }
        }

        //header AND source are now generated!

        //if this was the GLOBALS file, patch it to be correct
        if(classNameNoPointer=="")
        {
            fh.setFileName(fh.fileName().replace("/.h","/globals.h"));
            fcpp.setFileName(fcpp.fileName().replace("/.cpp","/globals.cpp"));

            header.replace("#ifndef _H","#ifndef GLOBALS_H");
            header.replace("#define _H","#define GLOBALS_H");
            header.replace("#endif //_H","#endif //GLOBALS_H");
            header.replace("class \n{\npublic:\n","");
            header.replace("};\n\n","");

            source.replace("#include \".h\"", "#include \"globals.h\"");
        }


        //now save them to the disk [or whatever]
        if(fh.open(QIODevice::WriteOnly))
        {
            fh.write(header.toUtf8());
            fh.close();
        }
        if(fcpp.open(QIODevice::WriteOnly))
        {
            fcpp.write(source.toUtf8());
            fcpp.close();
        }
        /**/


        //dump to windows instead of the actual SAVE:
        scriptwindow
                *H = new scriptwindow,
                *CPP=new scriptwindow;
        H->setText(header);
        CPP->setText(source);
        H->setWindowTitle(fh.fileName());
        CPP->setWindowTitle(fcpp.fileName());
        H->setAttribute(Qt::WA_DeleteOnClose);
        CPP->setAttribute(Qt::WA_DeleteOnClose);
        H->setParent(this);
        CPP->setParent(this);
        H->setWindowFlags(Qt::Window);
        CPP->setWindowFlags(Qt::Window);
        H->show();
        CPP->show();        
        /**/
        break;
    }
    case 2:
        //we generated all the code, sure!
        //Update the makefiles AND the PRO file for qmake

        QFile f("../../cppengine/qmake.cppengine.pro.template");
        QString Template;
        if(f.exists())
        {
            if(f.open(QIODevice::ReadOnly))
            {
                Template = f.readAll();
                f.close();
            }
            QFile outf("../../cppengine/cppengine.pro");
            if(outf.open(QIODevice::WriteOnly))
            {
                //patch the template:
                QDir d("../../cppengine");
                QStringList sources = d.entryList(QStringList("*.cpp"));
                QString cppstrings = sources.join(" \\\n\t");
                QStringList headers = d.entryList(QStringList("*.h"));
                QString hstrings = headers.join(" \\\n\t");
                Template.replace("{{SOURCES}}","\t"+cppstrings);
                Template.replace("{{HEADERS}}","\t"+hstrings);
                outf.write(Template.toUtf8());

                scriptwindow *PRO = new scriptwindow;
                PRO->setText(Template);
                PRO->setWindowTitle("QMAKE makefile");
                PRO->setAttribute(Qt::WA_DeleteOnClose);
                PRO->setParent(this);
                PRO->setWindowFlags(Qt::Window);
                PRO->show();
            }
        }
        break;
    }

}

void GameFrameworkClassDef::genJs(vObject Class,int when)
{
    //too much classes? Each in a file
    gcprint("JavaScript is not implemented!");
}

void GameFrameworkClassDef::genDoc(vObject Class,int when)
{
    //each class in its doc
}
