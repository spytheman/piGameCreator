#ifndef CPPEXPORTER_H
#define CPPEXPORTER_H

#include "../../sharedcode/gcexporter.h"

class cppExporter: public gcExporter
{
public:

    //@RESOURCES
    bool exportImage(QString name);
    bool exportModel(QString name);
    bool exportScene(QString name);
    bool exportSound(QString name);
    bool exportClass(QString name);
    //bool image(QString name);

    void loadProject(QString gcpx);
    bool exportResource(QString file);
};

#endif // CPPEXPORTER_H
