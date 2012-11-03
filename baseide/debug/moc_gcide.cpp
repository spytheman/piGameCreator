/****************************************************************************
** Meta object code from reading C++ file 'gcide.h'
**
** Created: Fri 2. Nov 07:46:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gcide.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gcide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gcide[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,    6,    6,    6, 0x0a,
      42,    6,    6,    6, 0x0a,
      57,    6,    6,    6, 0x0a,
      76,    6,    6,    6, 0x0a,
      94,    6,    6,    6, 0x0a,
     112,    6,    6,    6, 0x0a,
     129,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gcide[] = {
    "gcide\0\0IDEConfigChanged()\0hxStartServer()\0"
    "hxStopServer()\0hxProcessQueries()\0"
    "hxServerStarted()\0hxServerStopped()\0"
    "hxServerSTDOUT()\0hxServerSTDERR()\0"
};

void gcide::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gcide *_t = static_cast<gcide *>(_o);
        switch (_id) {
        case 0: _t->IDEConfigChanged(); break;
        case 1: _t->hxStartServer(); break;
        case 2: _t->hxStopServer(); break;
        case 3: _t->hxProcessQueries(); break;
        case 4: _t->hxServerStarted(); break;
        case 5: _t->hxServerStopped(); break;
        case 6: _t->hxServerSTDOUT(); break;
        case 7: _t->hxServerSTDERR(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData gcide::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gcide::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_gcide,
      qt_meta_data_gcide, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gcide::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gcide::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gcide::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gcide))
        return static_cast<void*>(const_cast< gcide*>(this));
    return QObject::qt_metacast(_clname);
}

int gcide::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void gcide::IDEConfigChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
