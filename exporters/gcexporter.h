#ifndef GCEXPORTER_H
#define GCEXPORTER_H

#include <QList>

class gcExporter
{
public:
    QList<QString> resourceFiles;
    virtual void loadProject(QString gcpx);
    virtual bool exportResource(QString file);

};

#endif // GCEXPORTER_H
