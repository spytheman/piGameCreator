#include "resourceeditor.h"
#include "../sharedcode/resource.h"
#include "gcide.h"
#include <QMainWindow>

ResourceEditor::ResourceEditor()
{
    updateTimer.setSingleShot(true);
    initialized = false;
}

void ResourceEditor::initResourceEditor(QWidget* w)
{
    widget = w;
    //Resource editor specific:
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget->setProperty("editor",true);
}

void ResourceEditor::reloadWindowState()
{
    gcerror("Not intended to be called. Overload it in your class and place RE_WINDOW_STATE_LOAD macro in its body");
}

bool ResourceEditor::isResourceEditor()
{
    return true;
}
bool ResourceEditor::load()
{
    return false;
}
bool ResourceEditor::save()
{
    return false;
}
QString ResourceEditor::title()
{
    return resource->name;
}
bool ResourceEditor::init()
{
    updateTimer.setInterval(1);
    updateTimer.setSingleShot(true);
    widget->connect(&updateTimer, SIGNAL(timeout()), creatorIDE, SLOT(ResourceEditorReloadStateWrapper()));
}
bool ResourceEditor::saveAs()
{
    //ask for name and then
    QString name = "UNNAMED";
    gcerror("Implement me:  ResourceEditor::saveAs");
    //saveAs(name);
}
bool ResourceEditor::saveAs(QString newname)
{
    gcmessage("PLEASE IMPLEMENT the saveAs(newname) call to your derived DLL class");
}
bool ResourceEditor::exportResource(QString filename)
{
    gcmessage("PLEASE IMPLEMENT the exportResource(filename) call to your derived DLL class");
}
void ResourceEditor::makeModified()
{
    modified = true;
    //set the title to have a STAR
}
void ResourceEditor::updateTitle()
{
    //Updates the tab title
}
