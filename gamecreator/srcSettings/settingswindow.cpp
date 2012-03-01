#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "gamecreator.h"
#include <QtXml/qdom.h>
#include <QFile>
#include <QTextStream>
#include <QColorDialog>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    //QTBUGs workaround
    connect(this,SIGNAL(accepted()),this,SLOT(SettingsWindow_accepted()));
    connect(this,SIGNAL(rejected()),this,SLOT(SettingsWindow_rejected()));

    //initialize the Source
    source = new scriptwindow;
    ui->codeEditorWidget->layout()->addWidget(source);
    QFile f("data/config.pgs"); QString S;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        S=f.readAll();
    }
    source->setText(S);

    ui->TextColorFrame->setAutoFillBackground(true);
    ui->fontColorFrame->setAutoFillBackground(true);

    QPalette P = ui->fontColorFrame->palette();
    P.setColor(QPalette::Window,codeBackground);
    ui->fontColorFrame->setPalette(P);
    on_keywordsListWidget_currentRowChanged(0);/**/
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
    //save the settings here and apply them
    QDomDocument xml;
    QDomElement root = xml.createElement("settings");
    QDomElement e,e1,e2,e3,c;
    QString s;
    //for each page: create elements

    //code formatting
    {
        int n;
        e=xml.createElement("codeformat");

        c=xml.createElement("font");
        c.setAttribute("size",ui->fontSize->value());
        c.setAttribute("color",codeBackground.name());
        c.setAttribute("face",ui->editorFontComboBox->currentFont().family());
        e.appendChild(c);

        s="keyword";n=0;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="function";n=1;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="variable";n=2;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="resource";n=3;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="class";n=4;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="number";n=5;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="string";n=6;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="operator";n=7;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="comment";n=8;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="preprocessor";n=9;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="normaltext";n=10;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

        s="error";n=11;
        c=xml.createElement(s);
        c.setAttribute("color",CodeFormats[n].color.name());
        c.setAttribute("bold",CodeFormats[n].bold);
        c.setAttribute("italic",CodeFormats[n].italic);
        c.setAttribute("underline",CodeFormats[n].underline);
        e.appendChild(c);

    root.appendChild(e);
    }

    //done
    xml.appendChild(root);
    //save it
    gcSaveXml("config.xml",&xml);
    gcloadsettings();
}

void SettingsWindow::SettingsWindow_rejected()
{
    //Cancel, does not save the settings
    gcloadsettings();
}

void SettingsWindow::on_keywordsListWidget_currentRowChanged(int r)
{
    QPalette P = ui->TextColorFrame->palette();
    P.setColor(QPalette::Window,CodeFormats[r].color);
    ui->TextColorFrame->setPalette(P);

    ui->BoldTextButton->setChecked(CodeFormats[r].bold);
    ui->ItalicTextButton->setChecked(CodeFormats[r].italic);
    ui->UnderlineTextButton->setChecked(CodeFormats[r].underline);

    ui->TokenGroupBox->setTitle(ui->keywordsListWidget->currentItem()->text());
}

void SettingsWindow::on_BoldTextButton_toggled(bool checked)
{
    CodeFormats[ui->keywordsListWidget->currentRow()].bold=checked;
    source->recolorize();
}

void SettingsWindow::on_ItalicTextButton_toggled(bool checked)
{
    CodeFormats[ui->keywordsListWidget->currentRow()].italic=checked;
    source->recolorize();
}

void SettingsWindow::on_UnderlineTextButton_toggled(bool checked)
{
    CodeFormats[ui->keywordsListWidget->currentRow()].underline=checked;
    source->recolorize();
}

void SettingsWindow::on_TextColorButton_clicked()
{
    QColor c = QColorDialog::getColor(CodeFormats[ui->keywordsListWidget->currentRow()].color,this);
    if(c.isValid())
    {
        CodeFormats[ui->keywordsListWidget->currentRow()].color = c;
        on_keywordsListWidget_currentRowChanged(ui->keywordsListWidget->currentRow());
        source->recolorize();
    }
}

void SettingsWindow::on_toolButton_5_clicked()
{
    //gcmessage("Not implemented");
    //return;
    QColor c = QColorDialog::getColor(codeBackground,this);
    if(c.isValid())
    {
        codeBackground=c;
        QPalette p(ui->TextColorFrame->palette());
        p.setColor(QPalette::Window,codeBackground);
        ui->fontColorFrame->setPalette(p);
        source->setBackgroundColor(c);
    }
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
    gcmessage("Not Implemented");
}
