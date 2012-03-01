#ifndef GCFILEFORMAT_H
#define GCFILEFORMAT_H

//This class describes the basic file format stuff for working with game projects
//The exporter plugins should use this implementation somehow!
//The GCPX file format is a subclass of this.

class gameproject; //Circular dependency preventation

#include "gameproject.h"
#include <QString>

class gcfileformat
{
public:
    gcfileformat(gameproject* g);
    gcfileformat();

    //what this format can do?
    bool canImport();
    bool canExport();
    QString filter(); //for save/open dialogs!

    //functions
    bool ImportFromFile(QString s);
    bool ExportToFile(QString s);
    static gcfileformat* getFormat(gameproject* g, QString format);

private:
    bool Import;
    bool Export;
    QString Filter;

protected:
    gameproject* gp;
};

#endif // GCFILEFORMAT_H
