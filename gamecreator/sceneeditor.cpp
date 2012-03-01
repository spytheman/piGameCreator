#include "sceneeditor.h"
#include "ui_sceneeditor.h"
#include "gamecreator.h"
#include <QFile>
#include <QCloseEvent>
#include <QWidgetAction>
#include <QLineEdit>
#include <QMenu>
#include <QScrollBar>
#include <QColorDialog>
#include <QFont>
#include <QEvent>
#include <QDesktopServices>

#define UGL if(initialized)ui->TheScene->updateGL();
#define SC ui->TheScene

SceneEditor::SceneEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SceneEditor)
{
    initialized=false;
    modified=false;
    setProperty("editor",true);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    fixback(this);
    ui->TheScene->window = this;
    ui->TheScene->ww = ui->WidthSB->value();
    ui->TheScene->hh = ui->HeightSB->value();
    //todo:load settings;

    //Setup the toolbar...and WHY the designer is sooo...
    ui->toolBar->insertWidget(ui->actionSelect_objects,ui->GridWidget);
    ui->toolBar->insertSeparator(ui->actionSelect_objects);
    ui->toolBar->insertWidget(ui->actionSelect_objects,ui->TBWidthHeight);
    ui->toolBar->insertSeparator(ui->actionSelect_objects);
    ui->toolBar->insertWidget(ui->actionZoomIn,ui->TBZoomWidget);
    ui->TheScene->extent=100;

    //setup the rest
    //ui->LBNoObjectSelected->hide();
    ui->GridSettingsWidget->hide();
    ui->PropertiesTW->hide();
    on_actionSelect_objects_triggered();

    ui->Matrix->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    ui->Matrix->show();

    connect(ui->m11,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m12,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m13,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m14,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m21,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m22,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m23,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m24,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m31,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m32,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m33,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m34,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m41,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m42,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m43,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));
    connect(ui->m44,SIGNAL(valueChanged(double)),ui->TheScene,SLOT(updateOpenGL()));

    //grid settings close
    connect(ui->GridSettingsWidget,SIGNAL(WindowClosed(QWidget*)),this,SLOT(gridclosed(QWidget*)));

    QMenu* m = new QMenu;
    connect(m,SIGNAL(aboutToShow()),this,SLOT(gridmenu()));
    ui->TBgridToolButton->setMenu(m);
}

void SceneEditor::gridmenu()
{
    QMenu* m = (QMenu*)sender();
    m->clear();
    m->addAction(QIcon(),QString::number(rand()%1000));
    m->addSeparator();
    m->addAction(ffficon("disk"),tr("Save grid..."));
}

void SceneEditor::gridclosed(QWidget* w)
{
    ui->toolButton_9->setChecked(0);
}

SceneEditor::~SceneEditor()
{
    delete ui;
}

void SceneEditor::changeEvent(QEvent *e)
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

void SceneEditor::savelayer(layer *l, QDomElement container)
{
    //set layer attrs
    container.setAttribute("name",l->name);
    container.setAttribute("type",l->type);

    container.setAttribute("visible",l->settings.value("visible").toString());
    container.setAttribute("locked",l->settings.value("locked").toString());

    //Layer settings are not planned!

    for(int i=0;i<l->layers.count();i++)
    {
        //save each contained layer & NOTE: Scene editor will not support this feature... probably!
        QDomElement layer =  container.ownerDocument().createElement("layer");
        savelayer(l->layers.at(i),layer);
        container.appendChild(layer);
    }

    QList<instance*>::const_iterator I;
    for (I=l->instances.constBegin();I!=l->instances.constEnd(); ++I)
    {
        instance* in = *I;
        //save EACH instance!
        QDomElement o = container.ownerDocument().createElement("object");
        o.setAttribute("class",in->className);

        o.setAttribute("x",in->x);
        o.setAttribute("y",in->y);
        o.setAttribute("z",in->z);

        o.setAttribute("lx",in->lx);
        o.setAttribute("ly",in->ly);
        o.setAttribute("lz",in->lz);

        o.setAttribute("rx",in->rz);
        o.setAttribute("ry",in->rz);
        o.setAttribute("rz",in->rz);    //rotation - DEFAULT //rotation will be rz by DEFAULT

        //The rest properties and stuff when planning completes!

        container.appendChild(o);
    }

}

void SceneEditor::save()
{
    gcBeginWait();
    QDomDocument xml;
    QDomProcessingInstruction xmldec = xml.createProcessingInstruction("xml","version=\"1.0\"");
    xml.appendChild(xmldec);

    QDomElement scene = xml.createElement("scene");
    QDomElement layers= xml.createElement("layers");

    for(int i=0;i<ui->TheScene->layers.count();i++)
    {
        QDomElement layer = xml.createElement("layer");
        savelayer(SC->layers.at(i),layer);
        layers.appendChild(layer);
        //a layer can contain other layers, so it's recursive!
    }
    xml.appendChild(scene);
    scene.appendChild(layers);

    gcSaveXml(project->absoluteFolder+"/scenes/"+name+".xml",&xml);
    modified=false;
    updateTitle();
    gcEndWait();
}

void SceneEditor::loadScene()
{

    if(QFile::exists(project->absoluteFolder+"/scenes/"+name+".xml"))
    {
        //default stuff:

        //Is this code needed and why crash?
        ui->LayersTW->clear();

        QTreeWidgetItem* i = new QTreeWidgetItem();
        i->setText(0,"Default");
        QFont f(i->font(0));
        f.setItalic(true);
        i->setFont(0,f);
        i->setForeground(0,QColor(0,0,0,70));
        i->setIcon(0,ffficon("shading"));
        i->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
        i->setCheckState(0,Qt::Checked);
        ui->LayersTW->addTopLevelItem(i);

        layer* l = new layer;
        l->name="Default";
        l->type=0;
        SC->layers.append(l);
        SC->currentLayer="Default";



        //load scene from the XML
        ui->LayersTW->clear();

        QDomDocument* xml = gcReadXml(project->absoluteFolder+"/scenes/"+name+".xml");
        QDomElement scene = xml->documentElement();
        if(scene.tagName()!="scene")
        {
            //error
            gcerror(tr("The scene is corrupted - the XML file is invalid"));
        }
        else
        {
            gcprint("Loading scene");
            //scene is valid
            for(int i=0;i<scene.childNodes().count();i++)
                if(scene.childNodes().at(i).isElement())
                {
                    QDomElement l = scene.childNodes().at(i).toElement();
                    gcprint("1: " + l.tagName());
                    if(l.tagName()=="layers")
                    {
                        //Create the layers
                        for(int ln=0;ln<l.childNodes().count();ln++)
                        {
                            QDomElement Layer = l.childNodes().at(ln).toElement();
                            gcprint("2: " + Layer.tagName()+ ": "+Layer.attribute("name"));
                            //add the layer
                            QString lname = Layer.attribute("name");
                            QTreeWidgetItem* item = new QTreeWidgetItem();
                            item->setText(0,lname);

                            item->setIcon(0,ffficon("shading")); //depending of the Layer Type

                            item->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);

                            if(Layer.attribute("visible")=="true")
                                item->setCheckState(0,Qt::Checked);
                            else item->setCheckState(0,Qt::Unchecked);

                            ui->LayersTW->addTopLevelItem(item);

                            layer* Lyer = new layer;
                            Lyer->name=Layer.attribute("name");
                            Lyer->type=0;
                            SC->layers.append(Lyer);/**/

                            //A layer may contain other layers OR objects.
                            gcprint("Starting to iterate...");
                            for(int nn=0;nn<Layer.childNodes().count();nn++) //for each node
                                if(Layer.childNodes().at(nn).isElement())
                                {
                                    QDomElement o = Layer.childNodes().at(nn).toElement();
                                    gcprint("3: " + o.tagName());
                                    if(o.tagName().toLower()=="layer")
                                    {
                                        //Layer inside layer: To implement
                                    }
                                    else if(o.tagName().toLower()=="object")
                                    {

                                        //prepare the instance
                                        instance* q = new instance();
                                        q->x=o.attribute("x").toInt();
                                        q->y=o.attribute("y").toInt();
                                        q->z=o.attribute("z").toInt();
                                        q->lx=o.attribute("lx").toInt();
                                        q->ly=o.attribute("ly").toInt();
                                        q->lz=o.attribute("lz").toInt();
                                        q->rx=o.attribute("ox").toInt();
                                        q->ry=o.attribute("oy").toInt();
                                        q->rz=o.attribute("oz").toInt();
                                        q->ox=o.attribute("ox").toInt();
                                        q->oy=o.attribute("oy").toInt();
                                        q->oz=o.attribute("oz").toInt();
                                        layer* LL = SC->getLayer(Layer.attribute("name"));
                                        if(LL==0){gcprint("Invalid layer");return;}
                                        //place new:

                                        classObj* c = SC->getClass(o.attribute("class"));
                                        if(c==0){gcprint("Invalid class");return;}
                                        q->className = c->name;
                                        q->texture = c->image;
                                        q->properties = c->properties;  //these must be well-loaded ;]
                                        q->alpha=1;
                                        q->selected=false;
                                        q->overed=false;

                                        //place it
                                        if(LL!=0)LL->instances.append(q);

                                        //Add loading of the rest stuff here!

                                    }
                                }
                        }
                    }
                    // else what is it? - views, vectors, graphs, ...
                }
        }
    }
    else
    {
        //default stuff:
        //only one default layer
        ui->LayersTW->clear();

        QTreeWidgetItem* i = new QTreeWidgetItem();
        i->setText(0,"Default");
        QFont f(i->font(0));
        f.setItalic(true);
        i->setFont(0,f);
        i->setForeground(0,QColor(0,0,0,70));
        i->setIcon(0,ffficon("shading"));
        i->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
        i->setCheckState(0,Qt::Checked);
        ui->LayersTW->addTopLevelItem(i);

        layer* l = new layer;
        l->name="Default";
        l->type=0;
        SC->layers.append(l);
        SC->currentLayer="Default";
    }
}

void SceneEditor::load()
{
    QFile f(QDesktopServices::storageLocation(QDesktopServices::DataLocation)+ "/SceneEditor.wnd");//load savefile
    if(f.open(QIODevice::ReadOnly))restoreState(f.readAll());//apply it

    loadClasses();


    if(ui->LayersTW->topLevelItemCount()>0)
    ui->LayersTW->setCurrentItem(ui->LayersTW->topLevelItem(0));
    //scene MUST have at least one layer!

    //update ui stuff
    ui->TheScene->ww = ui->WidthSB->value();
    ui->TheScene->hh = ui->HeightSB->value();
    on_WidthSB_valueChanged(ui->WidthSB->value());
    on_HeightSB_valueChanged(ui->HeightSB->value());

    //update view
    SC->gridh = ui->GridHSB->value();
    SC->gridw = ui->GridWSB->value();
    SC->gridx = ui->GridXSB->value();
    SC->gridy = ui->GridYSB->value();

    setGridColor(Qt::black);
    setGridAlpha(ui->GridAlphaSlider->value()/255.0);

    SC->enableGrid=true;
    SC->snapping=ui->TBgridToolButton->isChecked();
    SC->drawGrid=ui->toolButton_8->isChecked();


    initialized=true;
}

void SceneEditor::on_actionZoomOut_triggered()  //minus
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()-25);
}

void SceneEditor::on_actionZoomIn_triggered()   //plus
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+25);
}

void SceneEditor::closeEvent(QCloseEvent *e)
{
    QFile f(QDesktopServices::storageLocation(QDesktopServices::DataLocation)+"/SceneEditor.wnd");
    if(f.open(QIODevice::WriteOnly))f.write(saveState(0));
    e->accept();
}

void SceneEditor::loadClasses()
{
    ui->AllClassesLW->clear();
    QStringList l = project->getResourcesFromType("class");
    foreach(QString s,l)
    {
        QListWidgetItem* i = new QListWidgetItem;
        i->setText(s);
        i->setIcon(gcResIcon("class",project->absoluteFolder+"/classes/"+s+"/icon.png"));
        ui->AllClassesLW->addItem(i);
    }
}

void SceneEditor::on_action100percent_triggered()
{
    ui->horizontalSlider->setValue(100);
}

void SceneEditor::on_horizontalSlider_valueChanged(int position)
{
    SC->zoom=position/100.0;
    ui->action100percent->setText(QString::number(position)+"%");
    on_WidthSB_valueChanged(ui->WidthSB->value());
    on_HeightSB_valueChanged(ui->HeightSB->value());
}

void SceneEditor::on_WidthSB_valueChanged(int i)
{
    gcprint(i);
    ui->horizontalScrollBar->setMinimum(0);
    int x = SC->extent*2 + i*SC->zoom - ui->TheScene->width(); if(x<0)x=0;
    ui->horizontalScrollBar->setMaximum(x);
    SC->ww=i;UGL
}

void SceneEditor::on_HeightSB_valueChanged(int i)
{
    ui->verticalScrollBar->setMinimum(0);
    int y = SC->extent*2 + i*SC->zoom - ui->TheScene->height(); if(y<0)y=0;
    ui->verticalScrollBar->setMaximum(y);
    SC->hh=i;UGL
}

void SceneEditor::on_actionClasses_triggered(bool checked)
{
    ui->ClassesDockWidget->setVisible(checked);
}

void SceneEditor::on_actionToolOptions_triggered(bool checked)
{
    ui->ToolOptionsDockWidget->setVisible(checked);
}

void SceneEditor::on_actionLayers_triggered(bool checked)
{
    ui->LayersDockWidget->setVisible(checked);
}

void SceneEditor::unselectTools()
{
    ui->actionSelect_objects->setChecked(0);
    ui->actionRectangle_tool->setChecked(0);
    ui->actionDraw_objects->setChecked(0);
    ui->actionPolygon_path_tool->setChecked(0);
    ui->actionGraph_tool->setChecked(0);
}

void SceneEditor::on_actionSelect_objects_triggered()
{
    unselectTools();
    ui->actionSelect_objects->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->TOp1);
    SC->toolmode=0;
}

void SceneEditor::on_actionDraw_objects_triggered()
{
    unselectTools();
    ui->actionDraw_objects->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->TOp2);
    SC->toolmode=1;
}

void SceneEditor::on_actionRectangle_tool_triggered()
{
    unselectTools();
    ui->actionRectangle_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->TOp3);
    SC->toolmode=2;
}

void SceneEditor::on_actionPolygon_path_tool_triggered()
{
    unselectTools();
    ui->actionPolygon_path_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->TOp4);
    SC->toolmode=3;
}

void SceneEditor::on_actionGraph_tool_triggered()
{
    unselectTools();
    ui->actionGraph_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->TOp5);
    SC->toolmode=4;
}

void SceneEditor::on_AllClassesLE_textChanged(QString s)
{
    if(s=="")
    {
        for(int i=0;i<ui->AllClassesLW->count();i++)
            ui->AllClassesLW->item(i)->setHidden(false);
    }
    else for(int i=0;i<ui->AllClassesLW->count();i++)
    {
        if(!ui->AllClassesLW->item(i)->text().contains(s))
            ui->AllClassesLW->item(i)->setHidden(true);
        else ui->AllClassesLW->item(i)->setHidden(false);
    }
}

void SceneEditor::on_AllClassesLW_itemClicked(QListWidgetItem* item)
{
    ui->currentClassName->setText(item->text());
    SC->currentClassName = item->text();
}

void SceneEditor::on_horizontalScrollBar_valueChanged(int value)
{
    ui->TheScene->xx=value;
    QApplication::processEvents();
    UGL
}

void SceneEditor::on_verticalScrollBar_valueChanged(int value)
{
    ui->TheScene->yy=value;
    QApplication::processEvents();
    UGL
}

void SceneEditor::on_actionGrid_settings_triggered()
{
    //ui->GridSettingsDockWidget->show();
}

void SceneEditor::on_actionHideGrid_triggered()
{
    ui->TBgridToolButton->setChecked(0);
    SC->drawGrid=false;UGL
}

void SceneEditor::on_actionShowGrid_triggered()
{
    ui->TBgridToolButton->setChecked(1);
    SC->drawGrid=true;UGL
}


void SceneEditor::on_actionPaths_triggered(bool checked)
{
    ui->PathsDockWidget->setVisible(checked);
}

void SceneEditor::on_GridWSB_valueChanged(int i)
{
    SC->gridw=i;UGL
}

void SceneEditor::on_GridHSB_valueChanged(int i)
{
    SC->gridh=i;UGL
}

void SceneEditor::on_GridXSB_valueChanged(int i)
{
    SC->gridx=i;UGL
}

void SceneEditor::on_GridYSB_valueChanged(int i)
{
    SC->gridy=i;UGL
}

void SceneEditor::on_TBgridToolButton_clicked(bool checked)
{
    SC->enableGrid=true;
    SC->drawGrid=checked;
    UGL
}

void SceneEditor::on_colorButton_clicked()
{
    QColor c;
    c = QColorDialog::getColor(gridcolor,this,tr("Select grid color"));
    if(c.isValid())
    {
        setGridColor(c);
    }
}

void SceneEditor::setGridColor(QColor c)
{
    ui->colorButton->setStyleSheet("*{background-color:"+c.name()+";border:1px outset #ccc;}");
    SC->gridR=c.red()/255.0;
    SC->gridG=c.green()/255.0;
    SC->gridB=c.blue()/255.0;
    UGL
}
void SceneEditor::setGridAlpha(float a)
{   SC->gridA=a;
    UGL;
}

void SceneEditor::on_GridAlphaSlider_valueChanged(int value)
{
    setGridAlpha(value/255.0);
}

void SceneEditor::on_GridSnapCheckbox_clicked(bool checked)
{
    SC->snapping=checked;
}

void SceneEditor::on_gridDrawCheckBox_clicked(bool checked)
{
    SC->drawGrid=checked;UGL
}

void SceneEditor::on_actionViews_triggered(bool checked)
{
    ui->ViewsDockWidget->setVisible(checked);
}

void SceneEditor::on_LayersTW_itemClicked(QTreeWidgetItem *item, int column)
{
    SC->currentLayer = item->text(0);UGL;
}

void SceneEditor::on_DefaultMatrix_clicked()
{
    ui->m11->setValue(1);
    ui->m22->setValue(1);
    ui->m33->setValue(1);
    ui->m44->setValue(1);

    ui->m12->setValue(0);
    ui->m13->setValue(0);
    ui->m14->setValue(0);

    ui->m21->setValue(0);
    ui->m23->setValue(0);
    ui->m24->setValue(0);

    ui->m31->setValue(0);
    ui->m32->setValue(0);
    ui->m34->setValue(0);

    ui->m41->setValue(0);
    ui->m42->setValue(0);
    ui->m43->setValue(0);
}

void SceneEditor::on_toolButton_8_clicked(bool checked)
{
    SC->snapping=checked;
    SC->enableGrid=true;
    UGL
}

void SceneEditor::on_toolButton_9_clicked()
{
    if(ui->toolButton_9->isChecked()==false)
    {
        ui->GridSettingsWidget->close();
        ui->toolButton_9->setChecked(0);
    }
    else
    {
        QPoint P( ui->toolButton_9->pos() );
        P.setY(P.y()+20);
        ui->toolButton_9->setChecked(1);
        ui->GridSettingsWidget->setParent(this);
        ui->GridSettingsWidget->setWindowFlags(Qt::Tool);
        ui->GridSettingsWidget->move(mapToGlobal(P));
        ui->GridSettingsWidget->adjustSize();
        ui->GridSettingsWidget->setWindowTitle(tr("Grid settings"));
        ui->GridSettingsWidget->show();
    }
}

void SceneEditor::hideEvent(QHideEvent *)
{
    ui->GridSettingsWidget->hide();

    if(initialized)
    {
        QFile f("data/SceneEditor.wnd");
        if(f.open(QIODevice::WriteOnly))f.write(saveState(0));
    }
    foreach(QObject* o, children())
    {
        if(QString(o->metaObject()->className()) == "QDockWidget") ((QWidget*)o)->hide();
    }
}

void SceneEditor::showEvent(QShowEvent *e)
{
    loadClasses();
    SC->reloadClasses();

    QFile f("data/SceneEditor.wnd");//load savefile
    if(f.open(QIODevice::ReadOnly))restoreState(f.readAll());//apply it

    if(ui->toolButton_9->isChecked())ui->GridSettingsWidget->show();
}
