#include "../sharedcode/globals.h"
#include "messageevent.h"

messageEvent::messageEvent(QString n, QVariant v, void* sender) :
    QEvent(MessageEvent), data(v), name(n), sender(sender)
{
}

