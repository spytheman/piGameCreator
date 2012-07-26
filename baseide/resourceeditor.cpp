#include "resourceeditor.h"
#include "../sharedcode/resource.h"

ResourceEditor::ResourceEditor()
{
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
    gcmessage("PLEASE IMPLEMENT the INIT() call to your DLL class");
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
