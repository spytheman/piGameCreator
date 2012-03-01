#include "editvardialog.h"
#include "ui_editvardialog.h"
#include "gamecreator.h"
#include "pgsparser.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>

EditVarDialog::EditVarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditVarDialog)
{
    OKclicked=false;
    propertymode=false;
    lastindex=0;
    ui->setupUi(this);
    ui->PageWidget->setCurrentIndex(0);
    ui->ColorFrame->setAutoFillBackground(true);
    ui->menuWithChoices->hide();
    ui->AddToArrayButton->hide();
    ui->DelFromArray->hide();
    ui->ArrayList->hide();
    ui->InitValLabel->setText(tr("Initial value:"));
    QApplication::processEvents();
    resize(width(),sizeHint().height());
}

EditVarDialog::EditVarDialog(variable V, QWidget *parent):
    QDialog(parent),
    ui(new Ui::EditVarDialog)
{
    OKclicked=false;
    var=V;
    propertymode=false;
    lastindex=0;
    ui->setupUi(this);
    ui->menuWithChoices->hide();
    setWindowTitle(tr("Edit variable..."));
    setWindowIcon(ffficon("pencil"));
    ui->PageWidget->setCurrentIndex(0);
    ui->ColorFrame->setAutoFillBackground(true);
    //init from the variable
    bool m = var.isMenu;
    if(var.isArray)
    {
        ui->radioButton_2->setChecked(1);
        on_radioButton_2_clicked();
    }
    else
    {
        on_radioButton_clicked();
    }
    QApplication::processEvents();
    resize(width(),sizeHint().height());

    QVariant v; vObject vo;
    int n;
    if(V.isArray)
    {
        n=V.values.count();
    }
    else
    {
        v=var.value.value("value");
        vo=var.value;
        n=1;
    }
    //now update the UI
    ui->varName->setText(V.name);

    for(int i=0;i<n;i++)
    {
        if(V.isArray)
        {
            v= var.values.at(i).value("value");
            vo=var.values.at(i);
        }

        if(var.type=="int")
        {
                ui->varType->setCurrentIndex(0);
                ui->IntegerSpinBox->setValue(v.toInt());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="real")
        {
                ui->varType->setCurrentIndex(1);
                ui->realSpinBox->setValue(v.toDouble());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="string")
        {
                ui->varType->setCurrentIndex(2);
                ui->StringBox->setText(v.toString());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="bool")
        {
                ui->varType->setCurrentIndex(3);
                ui->BoolBox->setChecked(v.toBool());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="point2d")
        {
                ui->varType->setCurrentIndex(4);
                ui->p2x->setValue(vo.value("x").toDouble());
                ui->p2y->setValue(vo.value("y").toDouble());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="point3d")
        {
                ui->varType->setCurrentIndex(5);
                ui->p3x->setValue(vo.value("x").toDouble());
                ui->p3y->setValue(vo.value("y").toDouble());
                ui->p3z->setValue(vo.value("z").toDouble());
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="color")
        {
                ui->varType->setCurrentIndex(6);
                QPalette P(ui->ColorFrame->palette());
                P.setColor(QPalette::Window,vo.value("color").value<QColor>());
                ui->ColorFrame->setPalette(P);
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="function")
        {
                ui->varType->setCurrentIndex(7);
                //TODO: Function
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="image")
        {
                ui->varType->setCurrentIndex(8);
                //TODO: resource
                on_AddToArrayButton_clicked();
        }
        else if(var.type=="class")
        {
                ui->varType->setCurrentIndex(9);
                ui->ResName_label->setText(v.toString());
                on_AddToArrayButton_clicked();
        }
        //single values
    }
    var.isMenu=m;
}

void EditVarDialog::propertyMode(bool edit)
{
    propertymode=true;
    if(edit)
    {
        //edit
        setWindowIcon(ffficon("pencil"));
        setWindowTitle(tr("Edit design-time property..."));
    }
    else
    {
        //add
        setWindowIcon(ffficon("add"));
        setWindowTitle(tr("Add design-time property..."));
    }
    ui->menuWithChoices->show();
    ui->varNameLabel->setText(tr("Property name:"));
    ui->varTypeLabel->setText(tr("Property type:"));
    ui->PropertyTypeGB->setTitle(tr("Property kind"));
    if(var.isArray)
    if(var.isMenu)
    {
        ui->menuWithChoices->setChecked(1);
        on_menuWithChoices_clicked();
    }
    else
    {
        ui->radioButton_2->setChecked(1);
        on_radioButton_2_clicked();
    }
}

EditVarDialog::~EditVarDialog()
{
    delete ui;
}

void EditVarDialog::changeEvent(QEvent *e)
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

void EditVarDialog::on_varType_currentIndexChanged(int i)
{
    if(var.isArray)
    {
        int willdel=QMessageBox::Yes;
        if(ui->ArrayList->count()>0)
        {
            willdel=QMessageBox::question(this,tr("Clear values?"),tr("The value list is not empty.\nChanging the data type will make values invalid!\nDo you want to continue?"),QMessageBox::Yes, QMessageBox::No);
        }
        if(willdel==QMessageBox::No)
        {
            ui->varType->blockSignals(true);
            ui->varType->setCurrentIndex(lastindex);
            ui->varType->blockSignals(false);
            return;
        }
        ui->ArrayList->clear();
    }
    if(i>7) ui->PageWidget->setCurrentIndex(8);
    else ui->PageWidget->setCurrentIndex(i);
    lastindex=i;
    if(i==6)
    {
        //color, make arraylist alpha-preview-enabled
        ui->ArrayList->setStyleSheet("background-image: url(:/resources/RES/alpha.png);");
    }
    else
    {
        //reset it;
        ui->ArrayList->setStyleSheet("");
    }
}

void EditVarDialog::on_radioButton_clicked()
{
    var.isArray=false;
    var.isMenu=false;
    ui->AddToArrayButton->hide();
    ui->DelFromArray->hide();
    ui->ArrayList->hide();
    ui->InitValLabel->setText(tr("Initial value:"));
    QApplication::processEvents();
    resize(width(),sizeHint().height());
}

void EditVarDialog::on_radioButton_2_clicked()
{
    var.isArray=true;
    ui->AddToArrayButton->show();
    ui->DelFromArray->show();
    ui->ArrayList->show();
    ui->InitValLabel->setText(tr("Initial values:"));
    resize(width(),sizeHint().height());
    var.isMenu=false;
}
void EditVarDialog::on_menuWithChoices_clicked()
{
    on_radioButton_2_clicked();
    var.isMenu=true;
}

void EditVarDialog::updateVar()
{
    int type = ui->varType->currentIndex();
    switch(type)
    {
    case 0://int
        var.type="int";
        break;
    case 1://real
        var.type="real";
        break;
    case 2://string
        var.type="string";
        break;
    case 3://bool
        var.type = "bool";
        break;
    case 4://point2d
        var.type="point2d";
        break;
    case 5://point3d
        var.type="point3d";
        break;
    case 6://color
        var.type="color";
        break;
    case 7://function
        var.type="function";
        break;
    case 8://image
        var.type="image";
        break;
    case 9://class
        var.type="class";
        break;
        //to complete!
    }
}

vObject EditVarDialog::makeValue()
{
    vObject o;
    int type = ui->varType->currentIndex();
    switch(type)
    {
    case 0://int
        o["value"] = ui->IntegerSpinBox->value();
        break;
    case 1://real
        o["value"] = ui->realSpinBox->value();
        break;
    case 2://string
        o["value"] = ui->StringBox->text();
        break;
    case 3://bool
        o["value"] = ui->BoolBox->isChecked();
        break;
    case 4://point2d
        o["value"] = "X: "+QString::number(ui->p2x->value()) +
                      "  Y: "+QString::number(ui->p2y->value());
        o["x"] = ui->p2x->value();
        o["y"] = "y",ui->p2y->value();
        break;
    case 5://point3d
        o["value"] = "X: "+QString::number(ui->p3x->value()) +
                      "  Y: "+QString::number(ui->p3y->value())+
                      "  Z: "+QString::number(ui->p3z->value());
        o["x"]= ui->p3x->value();
        o["y"]= ui->p3y->value();
        o["z"]= ui->p3z->value();
        break;
    case 6://color
        o["color"]=ui->ColorFrame->palette().background().color();
        o["value"]=o.value("color").value<QColor>().name();
        break;
    case 7://function
        o["value"]=ui->FunctionLabel->text();
        //to plan!
        break;
    default:    //image, class, so on - only NAME
        o["value"] = ui->ResName_label->text();
    }
    return o;
}

void EditVarDialog::on_OKbutton_clicked()
{
    QString error = "Not set";
    //int type = ui->varType->currentIndex();
    bool valid=true;
    QString name = ui->varName->text();
    QStringList l = project->getAllResourceNames();
    pgsParser p;
    QList<pgsParser::token> t = p.tokenize(name);
    if(name.trimmed()=="")
    {
        valid=false;
        error=tr("You must specify a variable name");
    }
    else if(l.contains(name))
    {
        valid=false;
        error=tr("You cannot use this name, because it conflicts with a resource");
    }
    else if(t.count()>1)
    {
        valid=false;
        error=tr("Specified name is invalid");
    }
    else if(t.at(0).kind != pgsParser::nameId)
    {
        valid=false;
        error=tr("You cannot use this name because it conflicts with a GameScript entity");
    }
    if(valid)name = t.at(0).text;

    if(ui->radioButton->isChecked()) //single
        var.isArray=false;
    if(ui->radioButton_2->isChecked())
        var.isArray=true;

    //set up the VAR object if all right
    if(valid)
    {
        updateVar();
        if(!var.isArray)
        {
            var.value = makeValue();
            var.values.clear();
        }
        else
        {
            //fill values from the ArrayList
            var.value = vObject();
            var.values.clear();
            for(int i=0;i<ui->ArrayList->count();i++)
            {
                var.values.append(ui->ArrayList->item(i)->data(TIDATA).value<vObject>());
            }
        }
        var.name = name;
        OKclicked=true;
        accept();
    }
    else gcerror(error);
}

void EditVarDialog::on_AddToArrayButton_clicked()
{
    vObject o = makeValue();
    if(var.isArray)
    {
        QListWidgetItem* w = new QListWidgetItem;
        w->setText(o.value("value").toString());
        w->setData(TIDATA,o);
        if(o.value("color",QColor()).value<QColor>() != QColor())
        {
            //color exists
            w->setBackgroundColor(o.value("color").value<QColor>());
        }
        ui->ArrayList->addItem(w);
    }
    ui->IntegerSpinBox->selectAll();
    ui->realSpinBox->selectAll();
    ui->StringBox->selectAll();
}

void EditVarDialog::on_DelFromArray_clicked()
{
    QList<QListWidgetItem*> l = ui->ArrayList->selectedItems();
    foreach(QListWidgetItem* L,l)delete L;
}

void EditVarDialog::on_SetColorToolButton_clicked()
{
    QColorDialog C(this);
    C.setOption(QColorDialog::ShowAlphaChannel,true);
    C.setOption(QColorDialog::DontUseNativeDialog,true);
    C.setCurrentColor(ui->ColorFrame->palette().background().color());
    C.exec();
    QColor c = C.currentColor();
    if(c.isValid())
    {
        QPalette p(ui->ColorFrame->palette());
        p.setColor(QPalette::Window,c);
        ui->ColorFrame->setPalette(p);
    }
}

void EditVarDialog::on_SelectResourceButton_clicked()
{

}

void EditVarDialog::on_NullresourceButton_clicked()
{

}
