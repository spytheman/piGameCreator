#ifndef CPPEXPORTER_H
#define CPPEXPORTER_H

#include "../../sharedcode/gcexporter.h"

class cppExporter: public gcExporter
{
public:
    bool exportResource(QString file);
};

#endif // CPPEXPORTER_H
