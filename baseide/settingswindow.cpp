#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "../sharedcode/globals.h"
#include "gcide.h"
#include <QtXml/qdom.h>
#include <QFile>
#include <QTextStream>
#include <QColorDialog>
#include "codeeditor.h"

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
    source = new scriptwindow;
    source->codeEditor->setSyntaxHighlighter(new pgsHighlighter);
    ui->codeEditorWidget->layout()->addWidget(source);
    QFile f("data/config.pgs"); QString S;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        S=f.readAll();
    }
    source->setText(S);

    connect(this, SIGNAL(codeColoringChanged()), source->codeEditor, SLOT(highlighterReapplyFontSettings()));

    ui->TextColorFrame->setAutoFillBackground(true);
    ui->fontColorFrame->setAutoFillBackground(true);

    QPalette P = ui->fontColorFrame->palette();
    P.setColor(QPalette::Window,creatorIDE->settings->value("CodeEditor/BackgroundColor").value<QColor>());
    ui->fontColorFrame->setPalette(P);
    on_keywordsListWidget_currentRowChanged(0);/**/

    //patch the list view
    ui->leftListWidget->item(0)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgGeneral ));
    ui->leftListWidget->item(1)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgClassEditor ));
    ui->leftListWidget->item(2)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgCodeFormatting ));
    ui->leftListWidget->item(3)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgContentServers ));
    ui->leftListWidget->item(4)->setData(TIDATA,qVariantFromValue( (void*)ui->cfgCollaboration ));

    int ins = 2;
    gcprint("TODO: Load and insert items from ALL resource editors as well!!");

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

    //code editor font and size
    creatorIDE->settings->setValue("CodeEditor/FontFamily", ui->editorFontComboBox->currentFont().family());
    creatorIDE->settings->setValue("CodeEditor/FontSize", ui->fontSize->value());

    //code editor background:
    creatorIDE->settings->setValue("CodeEditor/BackgroundColor",ui->fontColorFrame->palette().color(QPalette::Window));

    //Code formats
    creatorIDE->settings->setValue("CodeEditor/format_keyword_bold",creatorIDE->codeFormats[CFkeyword].bold);
    creatorIDE->settings->setValue("CodeEditor/format_keyword_italic",creatorIDE->codeFormats[CFkeyword].italic);
    creatorIDE->settings->setValue("CodeEditor/format_keyword_underline",creatorIDE->codeFormats[CFkeyword].underline);
    creatorIDE->settings->setValue("CodeEditor/format_keyword_color",creatorIDE->codeFormats[CFkeyword].color);

    creatorIDE->settings->setValue("CodeEditor/format_function_bold",creatorIDE->codeFormats[CFfunction].bold);
    creatorIDE->settings->setValue("CodeEditor/format_function_italic",creatorIDE->codeFormats[CFfunction].italic);
    creatorIDE->settings->setValue("CodeEditor/format_function_underline",creatorIDE->codeFormats[CFfunction].underline);
    creatorIDE->settings->setValue("CodeEditor/format_function_color",creatorIDE->codeFormats[CFfunction].color);

    creatorIDE->settings->setValue("CodeEditor/format_variable_bold",creatorIDE->codeFormats[CFvariable].bold);
    creatorIDE->settings->setValue("CodeEditor/format_variable_italic",creatorIDE->codeFormats[CFvariable].italic);
    creatorIDE->settings->setValue("CodeEditor/format_variable_underline",creatorIDE->codeFormats[CFvariable].underline);
    creatorIDE->settings->setValue("CodeEditor/format_variable_color",creatorIDE->codeFormats[CFvariable].color);

    creatorIDE->settings->setValue("CodeEditor/format_resource_bold",creatorIDE->codeFormats[CFresource].bold);
    creatorIDE->settings->setValue("CodeEditor/format_resource_italic",creatorIDE->codeFormats[CFresource].italic);
    creatorIDE->settings->setValue("CodeEditor/format_resource_underline",creatorIDE->codeFormats[CFresource].underline);
    creatorIDE->settings->setValue("CodeEditor/format_resource_color",creatorIDE->codeFormats[CFresource].color);

    creatorIDE->settings->setValue("CodeEditor/format_class_bold",creatorIDE->codeFormats[CFclass].bold);
    creatorIDE->settings->setValue("CodeEditor/format_class_italic",creatorIDE->codeFormats[CFclass].italic);
    creatorIDE->settings->setValue("CodeEditor/format_class_underline",creatorIDE->codeFormats[CFclass].underline);
    creatorIDE->settings->setValue("CodeEditor/format_class_color",creatorIDE->codeFormats[CFclass].color);

    creatorIDE->settings->setValue("CodeEditor/format_number_bold",creatorIDE->codeFormats[CFnumber].bold);
    creatorIDE->settings->setValue("CodeEditor/format_number_italic",creatorIDE->codeFormats[CFnumber].italic);
    creatorIDE->settings->setValue("CodeEditor/format_number_underline",creatorIDE->codeFormats[CFnumber].underline);
    creatorIDE->settings->setValue("CodeEditor/format_number_color",creatorIDE->codeFormats[CFnumber].color);

    creatorIDE->settings->setValue("CodeEditor/format_string_bold",creatorIDE->codeFormats[CFstring].bold);
    creatorIDE->settings->setValue("CodeEditor/format_string_italic",creatorIDE->codeFormats[CFstring].italic);
    creatorIDE->settings->setValue("CodeEditor/format_string_underline",creatorIDE->codeFormats[CFstring].underline);
    creatorIDE->settings->setValue("CodeEditor/format_string_color",creatorIDE->codeFormats[CFstring].color);

    creatorIDE->settings->setValue("CodeEditor/format_operator_bold",creatorIDE->codeFormats[CFoperator].bold);
    creatorIDE->settings->setValue("CodeEditor/format_operator_italic",creatorIDE->codeFormats[CFoperator].italic);
    creatorIDE->settings->setValue("CodeEditor/format_operator_underline",creatorIDE->codeFormats[CFoperator].underline);
    creatorIDE->settings->setValue("CodeEditor/format_operator_color",creatorIDE->codeFormats[CFoperator].color);

    creatorIDE->settings->setValue("CodeEditor/format_comment_bold",creatorIDE->codeFormats[CFcomment].bold);
    creatorIDE->settings->setValue("CodeEditor/format_comment_italic",creatorIDE->codeFormats[CFcomment].italic);
    creatorIDE->settings->setValue("CodeEditor/format_comment_underline",creatorIDE->codeFormats[CFcomment].underline);
    creatorIDE->settings->setValue("CodeEditor/format_comment_color",creatorIDE->codeFormats[CFcomment].color);

    creatorIDE->settings->setValue("CodeEditor/format_preproc_bold",creatorIDE->codeFormats[CFpreproc].bold);
    creatorIDE->settings->setValue("CodeEditor/format_preproc_italic",creatorIDE->codeFormats[CFpreproc].italic);
    creatorIDE->settings->setValue("CodeEditor/format_preproc_underline",creatorIDE->codeFormats[CFpreproc].underline);
    creatorIDE->settings->setValue("CodeEditor/format_preproc_color",creatorIDE->codeFormats[CFpreproc].color);

    creatorIDE->settings->setValue("CodeEditor/format_normaltext_bold",creatorIDE->codeFormats[CFnormaltext].bold);
    creatorIDE->settings->setValue("CodeEditor/format_normaltext_italic",creatorIDE->codeFormats[CFnormaltext].italic);
    creatorIDE->settings->setValue("CodeEditor/format_normaltext_underline",creatorIDE->codeFormats[CFnormaltext].underline);
    creatorIDE->settings->setValue("CodeEditor/format_normaltext_color",creatorIDE->codeFormats[CFnormaltext].color);

    creatorIDE->settings->setValue("CodeEditor/format_error_bold",creatorIDE->codeFormats[CFerror].bold);
    creatorIDE->settings->setValue("CodeEditor/format_error_italic",creatorIDE->codeFormats[CFerror].italic);
    creatorIDE->settings->setValue("CodeEditor/format_error_underline",creatorIDE->codeFormats[CFerror].underline);
    creatorIDE->settings->setValue("CodeEditor/format_error_color",creatorIDE->codeFormats[CFerror].color);

    //Sync & flush changes
    creatorIDE->settings->sync();

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

void SettingsWindow::on_keywordsListWidget_currentRowChanged(int r)
{
    QPalette P = ui->TextColorFrame->palette();
    P.setColor(QPalette::Window,creatorIDE->codeFormats[r].color);
    ui->TextColorFrame->setPalette(P);

    ui->BoldTextButton->setChecked(creatorIDE->codeFormats[r].bold);
    ui->ItalicTextButton->setChecked(creatorIDE->codeFormats[r].italic);
    ui->UnderlineTextButton->setChecked(creatorIDE->codeFormats[r].underline);

    ui->TokenGroupBox->setTitle(ui->keywordsListWidget->currentItem()->text());
}

void SettingsWindow::on_BoldTextButton_toggled(bool checked)
{
    creatorIDE->codeFormats[ui->keywordsListWidget->currentRow()].bold=checked;
    emit codeColoringChanged();
}

void SettingsWindow::on_ItalicTextButton_toggled(bool checked)
{
    creatorIDE->codeFormats[ui->keywordsListWidget->currentRow()].italic=checked;
    emit codeColoringChanged();
}

void SettingsWindow::on_UnderlineTextButton_toggled(bool checked)
{
    creatorIDE->codeFormats[ui->keywordsListWidget->currentRow()].underline=checked;
    emit codeColoringChanged();
}

void SettingsWindow::on_TextColorButton_clicked()
{
    QColor c = QColorDialog::getColor(creatorIDE->codeFormats[ui->keywordsListWidget->currentRow()].color,this);
    if(c.isValid())
    {
        creatorIDE->codeFormats[ui->keywordsListWidget->currentRow()].color = c;
        on_keywordsListWidget_currentRowChanged(ui->keywordsListWidget->currentRow());
        emit codeColoringChanged();
    }
}

void SettingsWindow::on_toolButton_5_clicked()
{
    //gcmessage("Not implemented");
    //return;
    QColor c = QColorDialog::getColor( ui->fontColorFrame->palette().color(QPalette::Window) ,this);
    if(c.isValid())
    {
        QPalette p(ui->TextColorFrame->palette());
        p.setColor(QPalette::Window,c);
        ui->fontColorFrame->setPalette(p);
        source->setBackgroundColor(c);
    }
    emit codeColoringChanged();
}

void SettingsWindow::on_toolButton_clicked()
{
    gcmessage("Save: Not implemented");
}

void SettingsWindow::on_toolButton_2_clicked()
{
    gcmessage("Load: Not implemented");
}

void SettingsWindow::on_editorFontComboBox_currentFontChanged(QFont f)
{
    f.setPointSize( ui->fontSize->value() );
    source->codeEditor->setFont(f);
    source->codeEditor->updateLineSize();
    source->codeEditor->viewport()->repaint();
}

void SettingsWindow::on_fontSize_valueChanged(int newsize)
{
    QFont f( ui->editorFontComboBox->currentFont() );
    f.setPointSize(newsize);
    source->codeEditor->setFont(f);
    source->codeEditor->updateLineSize();
    source->codeEditor->viewport()->repaint();
}


void SettingsWindow::listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->stackedWidget->setCurrentWidget( (QWidget*)(current->data(TIDATA).value<void*>()) );
}

