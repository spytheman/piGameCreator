/****************************************************************************
** Meta object code from reading C++ file 'codeclass.h'
**
** Created: Thu 18. Oct 05:02:09 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../codeclass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_codeClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x0a,
      58,   11,   10,   10, 0x0a,
     100,   10,   10,   10, 0x0a,
     120,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_codeClass[] = {
    "codeClass\0\0checked\0"
    "on_actionClass_members_triggered(bool)\0"
    "on_actionFunction_library_triggered(bool)\0"
    "reloadWindowState()\0on_tbGoToLineNumber_clicked()\0"
};

void codeClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        codeClass *_t = static_cast<codeClass *>(_o);
        switch (_id) {
        case 0: _t->on_actionClass_members_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_actionFunction_library_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->reloadWindowState(); break;
        case 3: _t->on_tbGoToLineNumber_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData codeClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject codeClass::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_codeClass,
      qt_meta_data_codeClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &codeClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *codeClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *codeClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_codeClass))
        return static_cast<void*>(const_cast< codeClass*>(this));
    if (!strcmp(_clname, "ResourceEditor"))
        return static_cast< ResourceEditor*>(const_cast< codeClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int codeClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
