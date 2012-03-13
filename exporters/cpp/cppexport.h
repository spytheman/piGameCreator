#ifndef CPPEXPORTER_H
#define CPPEXPORTER_H

#include "../gcexporter.h"

class cppExporter: public gcExporter
{
public:
    bool exportResource(QString file);
};

#endif // CPPEXPORTER_H
