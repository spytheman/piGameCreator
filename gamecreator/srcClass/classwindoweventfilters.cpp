#include "classwindoweventfilters.h"
#include <QApplication>
#include "gamecreator.h"
#include "classwindow.h"

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
