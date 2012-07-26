#include "newimage.h"
#include "ui_newimage.h"
#include "gcide.h"
#include "dllforresourceeditor.h"
#include "../sharedcode/globals.h"
#include <QIcon>

newImage::newImage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newImage)
{
    ui->setupUi(this);

    //get ALL images from ALL resources
    foreach(dllForResourceEditor* re, creatorIDE->resourceEditorLibs)
    {
        QList<vObject> list = re->newResources();
        foreach(vObject o,list)
            if(o.value("kind")=="image")
            {
                QCommandLinkButton* button = new QCommandLinkButton(o.value("title").toString(),o.value("description").toString());
                button->setIcon(o.value("icon").value<QIcon>());
                //add plugin instance pointer
                o["pluginlibpointer"]=qVariantFromValue( (void*)re );
                button->setProperty("data",o);
                connect(button,SIGNAL(clicked()),this,SLOT(setDialogData()));
                ui->buttonsLayout->addWidget(button);
            }
    }
}

newImage::~newImage()
{
    delete ui;
}

void newImage::setDialogData()
{
    QCommandLinkButton* cb = qobject_cast<QCommandLinkButton*>(sender());
    //set as qDialog's property
    setProperty("data", cb->property("data") );
    close();
}
