#include "classwindoweventfilters.h"
#include <QApplication>
#include "../../sharedcode/globals.h"
#include "eventclass.h"

dropEventHandler::dropEventHandler()
{
    allowMenus=false;
}

bool dropEventHandler::eventFilter(QObject *o, QEvent *e)
{
    if(e->type() == QEvent::Drop)
    {
        window->checkVars();
    }
    return false;
}
