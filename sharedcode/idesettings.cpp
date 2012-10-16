#include <QCoreApplication>
#include "idesettings.h"

bool ideSettings::settingsAreInitialized = false;
QSettings* ideSettings::stngs = 0;
fontsetting ideSettings::codeFormats[CODE_FORMATS_TOTAL_COUNT];

void ideSettings::initSettings()
{
    if(!settingsAreInitialized)
    {
        QCoreApplication::setOrganizationName("Pi-Dev");
        QCoreApplication::setOrganizationDomain("http://pi-dev.com");
        QCoreApplication::setApplicationName("pi-engine");
        QSettings::setDefaultFormat(QSettings::IniFormat);
        stngs = new QSettings;

        settingsAreInitialized = true;
    }
}

QSettings* ideSettings::settings()
{
    if(!settingsAreInitialized)initSettings();
    return stngs;
}

QVariant ideSettings::get(QString name, QVariant defval)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defval);
}

void ideSettings::set(QString name, QVariant value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}

//common getters

QColor ideSettings::getColor(QString name, QColor defaultValue)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defaultValue).value<QColor>();
}

int ideSettings::getInt(QString name, int defaultValue)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defaultValue).toInt();
}

QString ideSettings::getString(QString name, QString defaultValue)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defaultValue).toString();
}

double ideSettings::getDouble(QString name, double defaultValue)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defaultValue).toDouble();
}

QByteArray ideSettings::getByteArray(QString name, QByteArray defaultValue)
{
    if(!settingsAreInitialized)initSettings();
    return stngs->value(name,defaultValue).toByteArray();
}

void ideSettings::setColor(QString name, QColor value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}

void ideSettings::setByteArray(QString name, QByteArray value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}

void ideSettings::setString(QString name, QString value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}

void ideSettings::setInt(QString name, int value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}

void ideSettings::setDouble(QString name, double value)
{
    if(!settingsAreInitialized)initSettings();
    stngs->setValue(name,value);
}
