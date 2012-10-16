#include "codeclass.h"
#include "ui_codeclass.h"
#include "../../sharedcode/resource.h"
#include "../../baseide/codeeditor.h"
#include "../../sharedcode/idesettings.h"

codeClass::codeClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::codeClass)
{
    ui->setupUi(this);

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
    editor->callJS("setTheme",theme);
    editor->callJS("setEditMode","haxe");

    initResourceEditor(this);
}

codeClass::~codeClass()
{
    delete editor;
}

bool codeClass::init()
{
    RE_INIT(SETTING_CODECLASS_WINDOW_STATE);
    setTitle(resource->name);
    if(!resource->project)gcerror("Class project is unknown!");

    return true;
}
void codeClass::showEvent(QShowEvent *)
{
    gcprint(QString("SHOW Init: ")+(initialized?"true":"false"));
    RE_SHOW_EVENT(SETTING_CODECLASS_WINDOW_STATE);
    ui->splitter->restoreState( ideSettings::getByteArray(SETTING_CODECLASS_SPLITTER_STATE) );
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
