/****************************************************************************
** Meta object code from reading C++ file 'getmouseevent.h'
**
** Created: Fri 2. Nov 07:49:20 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../getmouseevent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getmouseevent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GetMouseEvent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      45,   39,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GetMouseEvent[] = {
    "GetMouseEvent\0\0on_buttonBox_accepted()\0"
    "index\0on_EventType_currentIndexChanged(int)\0"
};

void GetMouseEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GetMouseEvent *_t = static_cast<GetMouseEvent *>(_o);
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_EventType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GetMouseEvent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GetMouseEvent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GetMouseEvent,
      qt_meta_data_GetMouseEvent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GetMouseEvent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GetMouseEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GetMouseEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GetMouseEvent))
        return static_cast<void*>(const_cast< GetMouseEvent*>(this));
    return QDialog::qt_metacast(_clname);
}

int GetMouseEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
