#ifndef DLLFORRESOURCEEDITOR_H
#define DLLFORRESOURCEEDITOR_H

#include "../sharedcode/resource.h"
#include "resourceeditor.h"
#include <QString>
#include <QWidget>

class dllForResourceEditor
{
public:
    dllForResourceEditor(QString fn);
    bool isValid(); //returns true is specified plugin DLL was found and loaded successfully

    // DLL functions
    QString getName();          // Resource editor name
    QString getDescription();   // Resource editor description
    QString binaryFile();       // Path to the plugin DLL/SO

    /*
        Resource kind is: images, models, classes, sounds and so on.
        No new resource kinds can be added by plugins like these,
        (because exporters use unified API), but plugins like these
        can create or edit resources from these kinds
    */
    QStringList getResourceKinds(); // Resource kind this editor edits - usually only one unless editor is too generic!
    QStringList getResourceTypes(); // Resource types this editor will edit

    /*
        Returns list of QActions that will be added to the context menu
        from the specified resource kind and type.
        The plugin can also add options to the menu of folders or other resource kinds and types
        On right click, ALL resource editors will be queried for their items, and then the menu will be displayed
    */
    QList<QAction*> contextMenuItems(QString kind, QString type, bool folder, gcresource* res);

    /*
        When the user selecta an option from the right menu that was created by this exporter,
        following function will be called on it to do its job.
    */
    bool contextMenuItemClicked(QAction* action);

    /*
        This function is normally called when user opens a resource in the IDE's Project views.
        The DLL instance being used is determined by the following algorithm:
        • It must support the proper resource kind AND type.
        • If NO DLL supports both KIND and TYPE, TYPE will be set to * (asterisk) string
        • And piGameCreator's DEFAULT resource editor for that type will be used
          (because ALL default editors implement the type * as well as default type, OR maybe...)
        • If for some reason, there is NOT a DLL that supports this kind with * TYPE,
        ERROR will occur! [for example invalid resource kind was specified in the project XML]
    */
    ResourceEditor* getGUI(QString kind, QString type, gcresource* res);

    /* These APIs are used for creation of new resource from this type

      Clicking 'Add' to any reource kind makes the following:
      1. Queries ALL resource editors to check which support addding this resource kind
      IF results are more than one, displays a list to select ehich one to use.
      If there is only one of these, uses it directly.
      So if there is only one sound editor, it will be used.
      If there are three class editors, developer should choose which one to use.
    */

    /*
      This function returns a list with vObjects representing resources this editor can CREATE
      These entries will be shown into the NEW / Add dialog for requested kind
      Properties of these vObjects are following:

        title   description     icon    kind    type    pluginlibpointer* = this

      The pluginlibpointer* field is filled by the loader, NOT by the DLL itself!
    */
    QList<vObject> newResources();

    /*
        This function creates a default new resource from specified type and kind.
        It can also ask the user to fill in some information about newly created object.
        It is called if the user was selected option that points to this plugin's DLL,
        when the user completes this wizard. The name is filled into the resource editor itself.
    */
    gcresource* createResource(gameproject* project, QString kind, QString type, QString name);

    //Management and initialization
    bool init();
    bool load();
    bool save();
    bool saveAs(QString newname);
    bool exportResource(QString filename);

private:
    QString pluginname, binfilename;
    bool valid;

    QString (*pname)();
    QString (*pdesc)();
    QStringList (*pGetResourceKinds)();
    QStringList (*pGetResourceTypes)();
    QList<QAction*> (*pContextMenuItems)(QString, QString, bool, gcresource*);
    ResourceEditor* (*pGetGUI)(QString, QString, gcresource*);
    QList<vObject> (*pNewResources)();
    gcresource* (*pCreateResource)(gameproject* project, QString kind, QString type, QString name);
    bool (*pContextMenuItemClicked)(QAction* action);
    bool (*pInit)();
    bool (*pLoad)();
    bool (*pSave)();
    bool (*pSaveAs)(QString newname);
    bool (*pExportResource)(QString filename);
};

#endif // DLLFORRESOURCEEDITOR_H
