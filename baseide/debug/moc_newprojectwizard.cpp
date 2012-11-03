/****************************************************************************
** Meta object code from reading C++ file 'newprojectwizard.h'
**
** Created: Fri 2. Nov 07:46:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newprojectwizard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprojectwizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_newProjectWizard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      35,   18,   17,   17, 0x08,
     103,   17,   17,   17, 0x08,
     134,  129,   17,   17, 0x08,
     179,  129,   17,   17, 0x08,
     221,  218,   17,   17, 0x08,
     260,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_newProjectWizard[] = {
    "newProjectWizard\0\0current,previous\0"
    "on_treeWidget_currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)\0"
    "on_browseButton_clicked()\0arg1\0"
    "on_projectTitleLineEdit_textChanged(QString)\0"
    "on_projectdirname_textChanged(QString)\0"
    "id\0newProjectWizard_currentIdChanged(int)\0"
    "on_toolButton_clicked()\0"
};

void newProjectWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        newProjectWizard *_t = static_cast<newProjectWizard *>(_o);
        switch (_id) {
        case 0: _t->on_treeWidget_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 1: _t->on_browseButton_clicked(); break;
        case 2: _t->on_projectTitleLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_projectdirname_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->newProjectWizard_currentIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_toolButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData newProjectWizard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject newProjectWizard::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_newProjectWizard,
      qt_meta_data_newProjectWizard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &newProjectWizard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *newProjectWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *newProjectWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_newProjectWizard))
        return static_cast<void*>(const_cast< newProjectWizard*>(this));
    return QWizard::qt_metacast(_clname);
}

int newProjectWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
