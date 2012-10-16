#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "../sharedcode/globals.h"
#include "gcide.h"
#include <QtXml/qdom.h>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QColorDialog>
#include "codeeditor.h"
#include <QGraphicsDropShadowEffect>
#include "../../sharedcode/pgshighlighter.h"
#include "../../sharedcode/idesettings.h"
#include "../../sharedcode/qtwin.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    //make it persistent!
    ui->leftListWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentIndex(0);

    //QTBUGs workaround
    connect(this,SIGNAL(accepted()),this,SLOT(SettingsWindow_accepted()));
    connect(this,SIGNAL(rejected()),this,SLOT(SettingsWindow_rejected()));

    //initialize the Source
    source = new CodeEditor();
    //source->setSyntaxHighlighter(new pgsHighlighter);
    ui->codeEditorWidget->layout()->addWidget(source);
    QFile f("data/config.pgs"); QString S;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        S=f.readAll();
    }
    source->setText(S);

    connect(this, SIGNAL(codeColoringChanged()), source, SLOT(highlighterReapplyFontSettings()));

    //patch the list view
    ui->leftListWidget->item(0)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgGeneral ));
    ui->leftListWidget->item(1)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgClassEditor ));
    ui->leftListWidget->item(2)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgCodeFormatting ));
    ui->leftListWidget->item(3)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgContentServers ));
    ui->leftListWidget->item(4)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgCollaboration ));

    int ins = 2;
    gcprint("TODO: Load and insert items from ALL resource editors as well!!");

    //Get all themes for the editor:
    QStringList themes;
    QDir d("data/ace/src");
    themes = d.entryList(QStringList()<<"theme-*.js");
    themes.replaceInStrings("theme-","");
    themes.replaceInStrings(".js","");
    ui->themeComboBox->addItems(themes);

    QString currentTheme = ideSettings::getString(S_CODEEDITOR_THEME);
    for(int i=0;i<ui->themeComboBox->count();i++)
        if(ui->themeComboBox->itemText(i)==currentTheme)
            ui->themeComboBox->setCurrentIndex(i);

    source->callJS("setEditMode","haxe");

    connect(ui->leftListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(listWidget_currentItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::changeEvent(QEvent *e)
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

void SettingsWindow::SettingsWindow_accepted()
{
    //Save the settings to main settings file

    //codeEditorTheme
    ideSettings::setString("CodeEditor/Theme",ui->themeComboBox->currentText());

    //code editor font and size [override these from the theme]
    ideSettings::settings()->setValue("CodeEditor/FontFamily", ui->editorFontComboBox->currentFont().family());
    ideSettings::settings()->setValue("CodeEditor/FontSize", ui->fontSize->value());

    //Sync & flush changes
    ideSettings::settings()->sync();

    //reload them
    creatorIDE->loadSettings();

    //emit the config changed signal
    creatorIDE->emitConfigChanged();
}

void SettingsWindow::SettingsWindow_rejected()
{
    //Cancel, does not save the settings. reload them, instead ;]
    creatorIDE->loadSettings();
}

void SettingsWindow::on_editorFontComboBox_currentFontChanged(QFont f)
{
    QString family = f.family();
    int size = ui->fontSize->value();
    QString sSize = QString::number(size);
    source->callJS("setEditorFont", QStringList() << family << sSize );
}

void SettingsWindow::on_fontSize_valueChanged(int newsize)
{
    QString family = ui->editorFontComboBox->currentFont().family();
    int size = newsize;
    QString sSize = QString::number(size);
    source->callJS("setEditorFont", QStringList() << family << sSize );
}

void SettingsWindow::listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->stackedWidget->setCurrentWidget( (QWidget*)(current->data(TIDATA).value<void*>()) );
}


void SettingsWindow::on_themeComboBox_currentIndexChanged(const QString &arg1)
{
    source->callJS("setEditorTheme", QStringList()<<arg1);
}
