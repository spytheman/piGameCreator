#include "gamecreator.h"
#include "resourceeditor.h"
#include "ui_mainwindow.h"

//Base to ALL QWidgets that can be used as resource editors or be in the main TabWidget!

void resourceeditor::save()
{
}

void resourceeditor::load()
{
}

void resourceeditor::makeModified()
{
    if(!initialized)return;
    modified=true;
    updateTitle();
}

void resourceeditor::updateTitle()
{
    for(int i=0;i<thewindow->ui->WorkSpaceTabWidget->count();i++)
    {
        QWidget* w = thewindow->ui->WorkSpaceTabWidget->widget(i);
        if(w->property("editor").value<bool>()==true)
        {
            if( dynamic_cast<resourceeditor*>(w) == this) //multiple inheritance - base pointer to derived
            {
                thewindow->ui->WorkSpaceTabWidget->setTabText(i," "+name+ (modified?" *":""));
                return;
            }
        }
    }
    gcprint("ERROR: Unable to updateTitle: Can't find the TAB to patch");
}

void resourceeditor::setName(QString s)
{
    //This must update the UI stuff.
}
