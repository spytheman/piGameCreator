#include "imageeditor.h"
#include "ui_imageeditor.h"
#include "../../sharedcode/resource.h"
#include "../../sharedcode/rsimage.h"

ImageEditor::ImageEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageEditor)
{
    ui->setupUi(this);
    widget=this;
    setAttribute(Qt::WA_DeleteOnClose);
    setProperty("editor",true);
}

ImageEditor::~ImageEditor()
{
    delete ui;
}

bool ImageEditor::init()
{
    setTitle(resource->name);
    return true;
}

bool ImageEditor::save()
{
    return true;
}

bool ImageEditor::saveAs(QString newname)
{
    return true;
}

bool ImageEditor::load()
{
    return true;
}

bool ImageEditor::exportResource(QString filename)
{
    return true;
}
