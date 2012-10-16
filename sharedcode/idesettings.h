#ifndef IDESETTINGS_H
#define IDESETTINGS_H

#include <QSettings>
#include <QVariant>
#include <QColor>
#include "globals.h"

#define CODE_FORMATS_TOTAL_COUNT 12

#define S_MAINWINDOW_GEOMETRY "MainWindow/Geometry"
#define S_MAINWINDOW_STATE "MainWindow/State"

#define S_SCENEEDITOR_STATE "SceneEditor/State"

#define S_CREATORIDE_RECENTFILES "creatorIDE/RecentFiles"
#define S_CREATORIDE_SKIN "creatorIDE/Skin"
#define S_CREATORIDE_PROJECTDIR "creatorIDE/ProjectDirectory"
#define S_IMAGEPREVIEW_GEOMETRY "imagePreviewer/Geometry"

#define S_CODEEDITOR_FONTFAMILY "CodeEditor/FontFamily"
#define S_CODEEDITOR_FONTSIZE "CodeEditor/FontSize"
#define S_CODEEDITOR_THEME "CodeEditor/Theme"

class ideSettings
{
public:
    static void initSettings();

    static QSettings* settings();
    static QVariant get(QString name, QVariant defaultValue = QVariant());
    static void set(QString name, QVariant value);

    //common
    static QColor getColor(QString name, QColor defaultValue = QColor::fromRgba(qRgba(0,0,0,0)));
    static int getInt(QString name, int defaultValue = 0);
    static QString getString(QString name, QString defaultValue = "");
    static QByteArray getByteArray(QString name, QByteArray defaultValue = QByteArray());
    static double getDouble(QString name, double defaultValue = 0.0);

    static void setInt(QString name, int value);
    static void setString(QString name, QString value);
    static void setByteArray(QString name, QByteArray value);
    static void setColor(QString name, QColor value);
    static void setDouble(QString name, double value);

    static fontsetting codeFormats[CODE_FORMATS_TOTAL_COUNT];

private:
    static QSettings* stngs;
    static bool settingsAreInitialized;
};

#endif // IDESETTINGS_H
