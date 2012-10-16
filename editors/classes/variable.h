#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <QVariant>
#include "../../sharedcode/globals.h"

class variable  // NOT compatible with QVariant!
{
public:
    QString name;
    QString type;
    bool isArray;
    bool isProperty;
    bool isMenu;
    vObject value;
    QList<vObject> values;
    variable();
};

#endif // VARIABLE_H
