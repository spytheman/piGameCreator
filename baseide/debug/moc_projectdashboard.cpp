/****************************************************************************
** Meta object code from reading C++ file 'projectdashboard.h'
**
** Created: Fri 19. Oct 01:33:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projectdashboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projectdashboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProjectDashboard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   17,   17,   17, 0x08,
      60,   17,   17,   17, 0x08,
      91,   17,   17,   17, 0x08,
     132,  127,   17,   17, 0x08,
     169,  127,   17,   17, 0x08,
     207,  127,   17,   17, 0x08,
     249,   17,   17,   17, 0x08,
     278,   17,   17,   17, 0x08,
     303,   17,   17,   17, 0x08,
     326,   17,   17,   17, 0x08,
     350,   17,   17,   17, 0x08,
     376,   17,   17,   17, 0x08,
     402,   17,   17,   17, 0x08,
     429,   17,   17,   17, 0x08,
     456,   17,   17,   17, 0x08,
     482,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProjectDashboard[] = {
    "ProjectDashboard\0\0titleChanged(QString)\0"
    "clearBottomStates()\0saveProjectAndUpdateExplorer()\0"
    "on_projectDescription_textChanged()\0"
    "arg1\0on_projectTitle_textChanged(QString)\0"
    "on_projectAuthor_textChanged(QString)\0"
    "on_projectAppVersion_textChanged(QString)\0"
    "on_buildTargetsBtn_clicked()\0"
    "on_pbBasicInfo_clicked()\0"
    "on_pbModules_clicked()\0on_toolButton_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_8_clicked()\0"
    "on_toolButton_10_clicked()\0"
    "on_toolButton_11_clicked()\0"
    "on_toolButton_9_clicked()\0"
    "on_projectIcon_clicked()\0"
};

void ProjectDashboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProjectDashboard *_t = static_cast<ProjectDashboard *>(_o);
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->clearBottomStates(); break;
        case 2: _t->saveProjectAndUpdateExplorer(); break;
        case 3: _t->on_projectDescription_textChanged(); break;
        case 4: _t->on_projectTitle_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_projectAuthor_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_projectAppVersion_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_buildTargetsBtn_clicked(); break;
        case 8: _t->on_pbBasicInfo_clicked(); break;
        case 9: _t->on_pbModules_clicked(); break;
        case 10: _t->on_toolButton_clicked(); break;
        case 11: _t->on_toolButton_2_clicked(); break;
        case 12: _t->on_toolButton_8_clicked(); break;
        case 13: _t->on_toolButton_10_clicked(); break;
        case 14: _t->on_toolButton_11_clicked(); break;
        case 15: _t->on_toolButton_9_clicked(); break;
        case 16: _t->on_projectIcon_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProjectDashboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProjectDashboard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProjectDashboard,
      qt_meta_data_ProjectDashboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProjectDashboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProjectDashboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProjectDashboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectDashboard))
        return static_cast<void*>(const_cast< ProjectDashboard*>(this));
    if (!strcmp(_clname, "WorkspaceWidget"))
        return static_cast< WorkspaceWidget*>(const_cast< ProjectDashboard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProjectDashboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ProjectDashboard::titleChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
