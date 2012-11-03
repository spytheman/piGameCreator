#ifndef MESSAGEEVENT_H
#define MESSAGEEVENT_H

#include <QEvent>
#include <QVariant>

class messageEvent : public QEvent
{
public:
    messageEvent(QString name, QVariant data=QVariant(), void* sender=0);
    QVariant data;
    QString name;
    void* sender;
};

#endif // MESSAGEEVENT_H
