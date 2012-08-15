#include "../sharedcode/globals.h"
#include "../sharedcode/qtwin.h"
#include "gcide.h"
#include "buildtargets.h"
#include "dllForExport.h"
#include "openedproject.h"
#include "ui_buildtargets.h"

BuildTargets::BuildTargets(OpenedProject* p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuildTargets)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pgExporterSelect);

    project = p;
    currentTarget = 0;

    foreach(dllForExport* e, creatorIDE->exporterLibs)
    {
        ui->ExporterComboBox->addItem(QIcon(),e->getName(),qVariantFromValue((void*)e));
    }
    if(ui->ExporterComboBox->count()>0)
    {
        ui->ExporterComboBox->setCurrentIndex(0);
        dllForExport* d = (dllForExport*) ui->ExporterComboBox->itemData(0).value<void*>();
        ui->exporterDescription->setText(d->getDescription().replace("\n"," ").replace("\t"," "));
    }

    if(project->project->buildTargets().count()==0)
        ui->SettingsPart->setEnabled(false);

    ui->codeName->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9_]+"),0));

    //build targets loader
    foreach(buildtarget* T,project->project->buildTargets())
    {
        ui->SettingsPart->setEnabled(1);
        QListWidgetItem* q = new QListWidgetItem(T->name);
        vObject t;
        t["name"]=T->name;
        t["exporter"]=qVariantFromValue((void*)T->exporter);
        t["codename"]=T->codename;
        t["description"]=T->description;
        t["options"]=vObject();
        t["exportername"]=T->exportername;
        q->setData(TIDATA,qVariantFromValue(t));
        ui->TargetsLV->addItem(q);
        ui->TargetsLV->setCurrentItem(q);
        ui->DisplayName->setFocus();
    }
    if(ui->TargetsLV->count()>0)
    {
        ui->TargetsLV->setCurrentRow(p->selectedTarget);
    }
}

BuildTargets::~BuildTargets()
{
    delete ui;
}

void BuildTargets::changeEvent(QEvent *e)
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

void BuildTargets::on_helpbutton_clicked()
{

}

void BuildTargets::on_DisplayName_textChanged(const QString &arg1)
{
    QListWidgetItem* item = ui->TargetsLV->currentItem();
    if(item==0)return;
    vObject o = item->data(TIDATA).value<vObject>();
    o["name"]=arg1;
    item->setData(TIDATA,qVariantFromValue(o));
    if(arg1!="")
    item->setText(arg1);
    else item->setText(tr("Unnamed target"));
    QString t = arg1;
    QString res = t.replace(" ","_");
    res = res.replace(QRegExp("[^a-zA-Z0-9_]+"),"");
    ui->codeName->setText(res);
}

void BuildTargets::on_codeName_textChanged(const QString &arg1)
{
    QListWidgetItem* item = ui->TargetsLV->currentItem();
    if(item==0)return;
    vObject o = item->data(TIDATA).value<vObject>();
    o["codename"]=arg1;
    item->setData(TIDATA,qVariantFromValue(o));
}

void BuildTargets::on_DescText_textChanged()
{
    QListWidgetItem* item = ui->TargetsLV->currentItem();
    if(item==0)return;
    vObject o = item->data(TIDATA).value<vObject>();
    o["description"]=ui->DescText->toPlainText();
    item->setData(TIDATA,qVariantFromValue(o));
}

void BuildTargets::on_ExporterComboBox_currentIndexChanged(int index)
{
    QListWidgetItem* item = ui->TargetsLV->currentItem();
    if(item==0)return;
    dllForExport* d = (dllForExport*) ui->ExporterComboBox->itemData(index).value<void*>();
    ui->exporterDescription->setText(d->getDescription().replace("\n"," ").replace("\t"," "));
    vObject o = item->data(TIDATA).value<vObject>();
    o["exporter"]=qVariantFromValue( (void*) d);
    o["exportername"]= d->exporterName();
    item->setData(TIDATA,qVariantFromValue(o));
}

void BuildTargets::on_exporterLineEdit_textChanged(const QString &arg1)
{
    QListWidgetItem* item = ui->TargetsLV->currentItem();
    if(item==0)return;
    dllForExport* d = creatorIDE->getExporter(arg1);
    vObject o = item->data(TIDATA).value<vObject>();
    o["exporter"]=qVariantFromValue((void*)d); //can be NULL!
    o["exportername"]=arg1;
    if(d)ui->exporterDescription->setText(d->getDescription());
    else ui->exporterDescription->setText("<span style=\"color:red\">No such exporter installed!</span>");
    item->setData(TIDATA,qVariantFromValue(o));
}


void BuildTargets::on_OptionsButton_clicked()
{
    dllForExport* d = (dllForExport*) ui->ExporterComboBox->itemData(ui->ExporterComboBox->currentIndex()).value<void*>();
    d->configure(project->project->filename()); //TODO: data passing for Configure ;]
}

void BuildTargets::on_AddTarget_clicked()
{
    ui->SettingsPart->setEnabled(1);
    QString s = tr("New target");
    QListWidgetItem* q = new QListWidgetItem(tr("New target"));
    vObject t;
    t["name"]="";
    t["exporter"]=qVariantFromValue((void*)ui->ExporterComboBox->itemData(ui->ExporterComboBox->currentIndex()).value<void*>());
    t["codename"]="";
    t["description"]="";
    t["options"]=vObject();
    q->setData(TIDATA,qVariantFromValue(t));
    ui->TargetsLV->addItem(q);
    ui->TargetsLV->setCurrentItem(q);
    ui->DisplayName->setFocus();
}

void BuildTargets::on_DelTarget_clicked()
{
    delete ui->TargetsLV->currentItem();
}

void BuildTargets::on_TargetsLV_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    //update ALL
    if(current==0)
    {
        if(ui->TargetsLV->count()==1)ui->SettingsPart->setDisabled(true);
        return;
    }
    vObject o = current->data(TIDATA).value<vObject>();
    ui->DisplayName->setText(o.value("name").toString());
    ui->codeName->setText(o.value("codename").toString());
    ui->DescText->setPlainText(o.value("description").toString());
    bool valid = false;
    for(int i=0;i<ui->ExporterComboBox->count();i++)
    {
        dllForExport* dll = (dllForExport*)ui->ExporterComboBox->itemData(i).value<void*>();
        if(dll==(dllForExport*)o.value("exporter").value<void*>())
        {
            ui->stackedWidget->setCurrentWidget(ui->pgExporterSelect);
            ui->ExporterComboBox->setCurrentIndex(i);
            valid=true;
        }
    }
    if(valid==false)
    {
        ui->stackedWidget->setCurrentWidget(ui->pgExporterInvalid);
        ui->exporterLineEdit->setText(o.value("exportername").toString());
        on_exporterLineEdit_textChanged(ui->exporterLineEdit->text());
    }
    else on_ExporterComboBox_currentIndexChanged(ui->ExporterComboBox->currentIndex());
}
void BuildTargets::on_OKbutton_clicked()
{
    //check for errors and rebuild the list
    bool valid=true;
    QList<buildtarget*> newlist;
    for(int i=0;i<ui->TargetsLV->count();i++)
    {
        QListWidgetItem* item = ui->TargetsLV->item(i);
        QString title, code, desc;
        vObject o =item->data(TIDATA).toHash();
        code =o.value("codename").toString();
        title=o.value("name").toString();
        if(title.isEmpty())title=tr("Unnamed target");
        desc =o.value("description").toString();
        if(code.isEmpty())valid=false;
        buildtarget* t = new buildtarget;
        t->name=title; t->codename=code; t->description=desc;
        t->exporter = (dllForExport*)o.value("exporter").value<void*>();
        t->exportername = o.value("exportername").toString();
        newlist << t;
    }
    if(valid)
    {
        project->project->setBuildTargets(newlist);
        accept();
    }
    else gcerror(tr("Every target must have code name"));

    creatorIDE->saveProject(project,true);
}

void BuildTargets::on_toolButton_clicked()
{
    if(ui->ExporterComboBox->count()>0)
        ui->ExporterComboBox->setCurrentIndex(0);
    ui->stackedWidget->setCurrentWidget(ui->pgExporterSelect);
}

void BuildTargets::on_toolButton_2_clicked()
{
    dllForExport* d =
            (dllForExport*)
                ui->ExporterComboBox->itemData(ui->ExporterComboBox->currentIndex()).value<void*>();

    ui->exporterLineEdit->setText(d->exporterName());
    ui->stackedWidget->setCurrentWidget(ui->pgExporterInvalid);
}
