#include "codeclass.h"
#include "ui_codeclass.h"
#include "../../sharedcode/resource.h"
#include "../../baseide/codeeditor.h"
#include "../../sharedcode/idesettings.h"
#include "../../sharedcode/messageevent.h"
#include <QDir>
#include <QRegExp>
#include <QStandardItemModel>
#include <QGraphicsDropShadowEffect>
#include <QListWidgetItem>

codeClass::codeClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::codeClass)
{
    underDeletion = false;
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    ui->centralwidget->layout()->setContentsMargins(0,0,0,0);
    ui->centralwidget->layout()->setSpacing(0);

    editor = new CodeEditor;

    QFont f;
    if(ideSettings::settings()->contains(S_CODEEDITOR_FONTFAMILY))
    {
        QString ff = ideSettings::getString(S_CODEEDITOR_FONTFAMILY);
        int fsize =  ideSettings::getInt(S_CODEEDITOR_FONTSIZE);
        f.setFamily( ff );
        f.setPointSize( fsize );
        gcprint("--------------------------");
        gcprint(f.family());
        QFontInfo fi = QFontInfo(f);
        gcprint(fi.family());
        f.setFamily(fi.family());
    }
    else
    {
        f.setFamily("Courier New");
        f.setPointSize(11);
    }/**/

    //prepare font:
    editor->setFont(f);

    ui->CodeEditorFrame->layout()->setContentsMargins(0,0,0,0);
    ui->CodeEditorFrame->layout()->addWidget(editor);

    QString theme = ideSettings::getString(S_CODEEDITOR_THEME);
    editor->callJS("setEditorTheme",theme);
    editor->callJS("setEditMode","haxe");

    //some signals!
    connect(editor, SIGNAL(textModified()), this, SLOT(codeModified()));
    connect(editor, SIGNAL(completerRequested(int,QString)), this, SLOT(invokeCompleter(int,QString)));
    connect(editor, SIGNAL(jsLoaded()), this, SLOT(refreshHaxeAPIlater()));

    connect(ui->actionGo_to_line_number, SIGNAL(triggered(bool)), ui->goToLineBox, SLOT(setVisible(bool)));
    connect(ui->actionFind, SIGNAL(triggered(bool)), ui->searchBox, SLOT(setVisible(bool)));

    ui->searchBox->setVisible(0);
    ui->goToLineBox->setVisible(0);

    initResourceEditor(this);
    editor->setFocus();

    completerContainer.setLayout(new QVBoxLayout);
    completerContainer.setContentsMargins(0,0,0,0);
    //completerContainer.layout()->setContentsMargins(9,0,9,9);
    completerContainer.layout()->setContentsMargins(0,0,0,0);
    QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
    ds->setOffset(0,3);
    ds->setBlurRadius(8);
    completer.setGraphicsEffect(ds);
    completerContainer.setParent(this);
    completerContainer.setWindowFlags(Qt::Popup);
    //completerContainer.setAttribute(Qt::WA_TranslucentBackground);
    completerContainer.layout()->addWidget(&completer);
    completerContainer.hide();

    connect(&completer, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(completerItemClicked(QListWidgetItem*)));
    connect(&completer, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(completerItemSelected(QListWidgetItem*)));
}

void codeClass::codeModified()
{
    makeModified();
}

void codeClass::refreshHaxeAPIlater()
{
    //this timing here is nasty. what DOES gets it?  @SYNC
    QTimer::singleShot(1000,this,SLOT(refreshHaxeAPI()));
}

void codeClass::refreshHaxeAPI()
{
    QStringList fwClasses = FrameworkData::getAllFrameworkClassNames();
    QStringList projectClasses = project->getClasses();
    QStringList all;
    all.append(projectClasses);
    all.append(fwClasses);
    all.removeDuplicates();
    gcprint("updating highlighting");
    editor->callJS("resetTypes()");
    foreach(QString s, all) editor->callJS("addType",s);
    editor->callJS("updateHighlighting()");
}

codeClass::~codeClass()
{
    delete editor;
}

bool codeClass::init()
{
    refreshHaxeAPI();
    RE_INIT(SETTING_CODECLASS_WINDOW_STATE);
    setTitle(resource->name);
    if(!resource->project)gcerror("Class project is unknown!");

    //load the haxe file
    QString fn = resource->project->absoluteFolder()+"/classes/"+resource->name+".hx";
    QFile f(fn);
    if(!f.exists())
    {
        gcmessage("The file" +f.fileName()+" does not exist.\nA default file will be generated.");
        QString data =
        "class "+resource->name+"\n"
        "{\n"
        "\tpublic function new()\n"
        "\t{\n"
        "\t\t\n"
        "\t}\n"
        "}\n";
        f.open(QIODevice::WriteOnly);
        f.write(data.toUtf8());
        f.close();
    }
    if(!f.exists())gcerror("Unable to create the class file!");
    f.open(QIODevice::ReadOnly);
    QString code = f.readAll();
    editor->setText(code);

    return true;
}
void codeClass::showEvent(QShowEvent *)
{
    gcprint(QString("SHOW Init: ")+(initialized?"true":"false"));
    RE_SHOW_EVENT(SETTING_CODECLASS_WINDOW_STATE);
    ui->splitter->restoreState( ideSettings::getByteArray(SETTING_CODECLASS_SPLITTER_STATE) );

    //Update ACE classes:
    QStringList fwClasses = FrameworkData::getAllFrameworkClassNames();
    QStringList projectClasses = project->getClasses();
    refreshHaxeAPI();
}

void codeClass::hideEvent(QHideEvent *)
{
    gcprint(QString("HIDE Init: ")+(initialized?"true":"false"));
    RE_HIDE_EVENT(SETTING_CODECLASS_WINDOW_STATE);
    ideSettings::setByteArray( SETTING_CODECLASS_SPLITTER_STATE, ui->splitter->saveState() );
}
void codeClass::reloadWindowState()
{
    RE_WINDOW_STATE_LOAD(SETTING_CODECLASS_WINDOW_STATE);
    ui->splitter->restoreState( ideSettings::getByteArray(SETTING_CODECLASS_SPLITTER_STATE) );
}

bool codeClass::load()
{

}

bool codeClass::save()
{
    QString text = editor->getText();
    QString fn = resource->project->absoluteFolder()+"/classes/"+resource->name+".hx";
    QFile f(fn);
    f.open(QIODevice::WriteOnly);
    f.write(text.toUtf8());
    f.close();
    modified = false;
    updateTitle();
}

void codeClass::on_actionClass_members_triggered(bool checked)
{
    ui->classMembersDW->setVisible(checked);
}

void codeClass::on_actionFunction_library_triggered(bool checked)
{
    ui->functionLibraryDW->setVisible(checked);
}

void codeClass::on_tbGoToLineNumber_clicked()
{
    editor->setText("SomeText");
}

void codeClass::invokeCompleter(int pos, QString c)
{
    gcprint("Invoking haXe completer in mode "+c);

    //Haxe compiler completer:
    if(c=="." || c=="(")
    {
        //query for current target index
        qApp->sendEvent(mainWindow,new messageEvent("get_current_target_index",qVariantFromValue((void*)project),this));

        //it will be directly executed, so lastTargetIndex is now correct!
        buildtarget* t = project->buildTargets().at(lastTargetIndex);

        QString path = project->absoluteFolder()+"/"+t->codename+"/temp/classes";
        QDir d(path);
        d.mkpath(path);
        d.setPath(path);
        QFile f(path+"/"+resource->name+".hx");
        f.open(QIODevice::WriteOnly);
        f.write(editor->getText().toUtf8());
        f.close();

        QStringList args;
        args << "--cwd" << project->absoluteFolder()
             << "--connect" << "6000"
             << t->codename+".hxml"
             << "-cp" << FrameworkData::classPath()
             << "-cp" << t->codename+"/temp/classes"
             << "--display" << t->codename+"/temp/classes/"+resource->name+".hx@"+QString::number(pos);
        qApp->postEvent(mainWindow, new messageEvent("hx_query",args,dynamic_cast<QObject*>(this)));
    }
    else if(c==":" || c=="<" || c=="new")
    {
        bool showit=true;
        if(c=="<")
        {
            showit=false;
            //is this template argument?
            QString s = editor->evalJS("getCurrentLineText()").toString().trimmed();
            QRegExp tpl(": *\\w+<");
            if(tpl.indexIn(s)!=-1)showit=true;
        }
        if(!showit)return;

        //classes! Fill the completer with the classes
        ccOptions.clear();

        QStringList builtin;
        builtin << "Array" << "Void" << "Bool" << "Int" << "UInt" << "Float" << "Dynamic" << "String" << "List" << "Hash" << "IntHash" << "Error" << "Unknown" << "Type" << "Std";
        QStringList frameworkClasses = FrameworkData::getAllFrameworkClassNames();
        QStringList projectClasses = project->getClasses();


        qDebug() << projectClasses << frameworkClasses;
        foreach(QString s, projectClasses)
        {
            completeOption o;
            o.name = s;
            o.icon = project->icon;
            ccOptions.append(o);
        }
        foreach(QString s, frameworkClasses)
        {
            completeOption o;
            o.name = s;
            o.icon = FrameworkData::frameworkProject->icon;
            ccOptions.append(o);
        }
        foreach(QString s, builtin)
        {
            completeOption o;
            o.name = s;
            o.icon = ffficon("brick");
            ccOptions.append(o);
        }
        showCompleter();
    }
}

bool codeClass::event(QEvent *e)
{
    if(e->type()==QEvent::DeferredDelete)
    {
        //Deletion is triggered! Must disable project queries!
        underDeletion = true;
    }
    if(e->type()==MessageEvent)
    {
        messageEvent* m = (messageEvent*)e;
        if(m->name=="show_error")
        {
            gcmessage("Error!!");
        }
        else if(m->name=="current_target_index")
        {
            lastTargetIndex = m->data.toInt();
        }
        else if(m->name=="hx_result")
        {
            QString out = m->data.toString();
            if(out.at(0)=='<')
                InitHaxeCompilerCompleter(out);
            else showError(out);
        }
        return true;
    }
    else return QMainWindow::event(e);
}

void codeClass::showCompleter()
{
    //do some init - reset the search string
    completerSearchString="";

    //update /reset its items
    updateCompleterQuery();

    //show the completer
    QVariant ps = editor->evalJS("getCursorPosXY()");
    qDebug() << ps;
    QPoint WindowPosition;
    QVariantMap rWindowPosition = ps.toMap();
    WindowPosition = mapToGlobal(WindowPosition);
    WindowPosition.setX(rWindowPosition.value("pageX").toInt());
    WindowPosition.setY(rWindowPosition.value("pageY").toInt()+43);
    WindowPosition += mapToGlobal( editor->pos());
    completerContainer.move(WindowPosition);
    completer.setCurrentRow(0);
    int count = 15;
    if(ccOptions.count()<=15)count=ccOptions.count();
    completerContainer.resize(largestOptionWidth, count*20 + 4);
    qDebug() << completerContainer.size();
    completerContainer.setFocusPolicy(Qt::StrongFocus);
    completerContainer.show();
    completer.setFocus();
    completer.installEventFilter(this);
}

void codeClass::InitHaxeCompilerCompleter(QString xml)
{
    if(!xml.startsWith("<list"))return;
    largestOptionWidth=40;
    editor->callJS("markCompleterBeginPoint()", QStringList());
    //it must be list or type
    // <i n="fullscreen"><t>Bool</t><d></d></i>

    QRegExp rx("<i n=\"(\\w+)\"><t>(.*)</t><d>(.*)</d></i>");
    rx.setMinimal(true);
    rx.setPatternSyntax(QRegExp::RegExp2);
    QStringList opts;
    int pos=0;
    ccOptions.clear();
    while ((pos = rx.indexIn(xml, pos)) != -1)
    {
        opts << rx.cap(0);
        //qDebug() << rx.cap(1);

        QString name,type,desc;
        name=rx.cap(1);
        type=rx.cap(2);
        desc=rx.cap(3);
        completeOption o;
        o.name = name;
        o.description = desc;
        o.type = type;
        if(o.type.contains("->"))o.icon=ffficon("sum");
        else o.icon = ffficon("tag_green");
        ccOptions.append(o);

        pos += rx.matchedLength();
    }
    //update the list
    updateCompleterQuery();

    showCompleter();

    return;

}

void codeClass::completerItemSelected(QListWidgetItem *item)
{
    for(int i=0;i<completerSearchString.length();i++)editor->callJS("keyBackspace()");
    //editor->callJS("selectFromCompleterPointToCursor()",QStringList());
    hideCompleter();
    completerSearchString="";
    editor->insertTextAtCursor(item->data(TIDATA).toString());

    //Is this function? If so, we must add()
    gcprint(item->data(TIDATA+1).toString());
    if(item->data(TIDATA+1).toString().contains("-&gt;"))
    {
        editor->insertTextAtCursor("()");
        //editor->callJS("keyLeft()");
    }
}

void codeClass::showError(QString out)
{
    gcprint(out);
}

void codeClass::completerItemClicked(QListWidgetItem *item)
{

}

bool codeClass::eventFilter(QObject *o, QEvent *e)
{
    if(e->type()==QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*)e;

        //user can press up/down, enter and esc now!
        if(k->key()==Qt::Key_Up
                || k->key()==Qt::Key_Down
                || k->key()==Qt::Key_Escape
                || k->key()==Qt::Key_Return
                || k->key()==Qt::Key_Enter
                || k->key()==Qt::Key_PageDown
                || k->key()==Qt::Key_PageUp
                || k->key()==Qt::Key_Shift
        )
            return false;

        if(k->key()==Qt::Key_Home || k->key()==Qt::Key_End)
        {
            hideCompleter();
            editor->setFocusOnAce();
            return false;
        }

        //else try to type it? Well, not that way!
        if(k->key()==Qt::Key_Backspace)
        {
            if(completerSearchString.length()==0)
            {
                editor->callJS("keyBackspace()",QStringList());
                hideCompleter();
                return true;
            }
            completerSearchString.remove( completerSearchString.length()-1,1 );
            //backspace and re-search
            editor->callJS("keyBackspace()",QStringList());
            updateCompleterQuery();
        }
        else if(k->key()==Qt::Key_Tab)
        {
            hideCompleter();
        }
        else if(k->key()==Qt::Key_Delete)
        {
            editor->callJS("keyDelete()",QStringList());
            hideCompleter();
        }
        else if(k->text().length()>0)
        {
            //try to type this!
            QString letter = k->text();
            completerSearchString+=letter;
            //search for it as well!
            editor->callJS("editor.insert",letter);
            updateCompleterQuery();
            //Space hides it
            if(!k->text().at(0).isLetterOrNumber() && k->text().at(0)!='_') hideCompleter();
        }
        else
        {
            //hide it!
            hideCompleter();
        }

        return true;
    }
    return false;
}

void codeClass::hideCompleter()
{
    completerContainer.hide();
    completerSearchString="";
    completer.removeEventFilter(this);
}

void codeClass::updateCompleterQuery()
{
    largestOptionWidth=40;
    completer.clear();
    for(int i=0;i<ccOptions.count();i++)
    {
        completeOption o = ccOptions.at(i);
        if(!o.name.contains(completerSearchString, Qt::CaseInsensitive))continue;

        //surely this will be shown! but let's show the matched part
        QListWidgetItem* item = new QListWidgetItem;
        completer.addItem(item);
        item->setData(TIDATA, o.name);
        item->setData(TIDATA+1, o.type);
        item->setData(TIDATA+2, o.description);
        item->setSizeHint(QSize(0,20));

        QWidget* lw = new QWidget;
        QHBoxLayout* hb = new QHBoxLayout;
        lw->setLayout(hb);
        hb->setContentsMargins(0,0,0,0);
        QLabel* icon = new QLabel;
        icon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        icon->setPixmap(o.icon.pixmap(16,16));
        /*
        if(o.type.contains("->"))
            icon->setPixmap(ffficon("sum").pixmap(16,16));
        else
            icon->setPixmap(ffficon("tag_green").pixmap(16,16));
        /**/

        QLabel* l = new QLabel;
        QString origString = o.name.mid( o.name.indexOf(completerSearchString,Qt::CaseInsensitive), completerSearchString.length());
        QString newname = o.name.replace(completerSearchString, "<span style='background: #FF0'>"+origString+"</span>");
        l->setText("<b>"+o.name+"</b> <i>"+o.type+"</i>");

        QString tooltip = "<b>"+o.name+"</b> <i>"+o.type+"</i>";
        if(!o.description.isEmpty()) tooltip.append("<hr />"+ o.description);
        l->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        lw->setToolTip(tooltip);

        int cw = l->minimumSizeHint().width()+50;
        if(largestOptionWidth<cw) largestOptionWidth=cw;

        lw->layout()->addWidget(icon);
        lw->layout()->addWidget(l);

        completer.setItemWidget(item,lw);
    }
    completer.setCurrentRow(0);
    if(completer.count()==1)
    {
        //try to commit it?
        int tl = completer.item(0)->data(TIDATA).toString().length();
        if(tl==completerSearchString.length())
        {
            completerItemSelected(completer.item(0));
        }
    }

}
