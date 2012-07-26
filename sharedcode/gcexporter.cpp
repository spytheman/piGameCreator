#include "gcexporter.h"
#include <QDebug>

#include "../sharedcode/gcexporter.h"

// This class implements the generic exporter interface for all future exporters

bool gcExporter::exportResource(QString file)
{
    return false;
}

void gcExporter::loadProject(QString gcpx)
{
    //This code loads a piGameCreator gcpx file and fills the resource arrays with corresponding data
}
