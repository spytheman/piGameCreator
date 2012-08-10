#ifndef RSCLASS_H
#define RSCLASS_H

#include "resource.h"

class rsClass: public gcresource
{
public:
    struct variable
    {
        QString name,type,defaultvalue,description;
        bool isStatic;
    };
    struct function
    {
        QString name,type,description;
        QList<variable> arguments;
        QString sourceCode;
        bool isStatic;
    };


    rsClass();
    QString mainFolderName();
    QString kind();
    bool addToProject(gameproject *p);

    //what does each class have?

    //The generic case:
    QString sourceCode;     //minimum requirement!
    QString description;
    QString baseClassName;
    QList<variable> variables, properties;
    QList<function> functions, events;

    bool valid;
};

#endif // RSCLASS_H
