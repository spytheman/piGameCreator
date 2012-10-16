/****************************************************************************
** Meta object code from reading C++ file 'addeventwindow.h'
**
** Created: Thu 11. Oct 18:34:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addeventwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addeventwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddEventWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   16,   15,   15, 0x08,
      82,   15,   15,   15, 0x08,
     106,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddEventWindow[] = {
    "AddEventWindow\0\0item,column\0"
    "on_treeWidget_itemDoubleClicked(QTreeWidgetItem*,int)\0"
    "on_buttonBox_rejected()\0on_buttonBox_accepted()\0"
};

void AddEventWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddEventWindow *_t = static_cast<AddEventWindow *>(_o);
        switch (_id) {
        case 0: _t->on_treeWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_buttonBox_rejected(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddEventWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddEventWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddEventWindow,
      qt_meta_data_AddEventWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddEventWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddEventWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddEventWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddEventWindow))
        return static_cast<void*>(const_cast< AddEventWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddEventWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
