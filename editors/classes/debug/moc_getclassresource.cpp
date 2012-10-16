/****************************************************************************
** Meta object code from reading C++ file 'getclassresource.h'
**
** Created: Tue 16. Oct 03:24:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../getclassresource.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getclassresource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_getClassResource[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      54,   49,   17,   17, 0x08,
     104,   17,   17,   17, 0x08,
     129,   17,   17,   17, 0x08,
     155,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_getClassResource[] = {
    "getClassResource\0\0on_Filter_textChanged(QString)\0"
    "item\0on_listWidget_itemDoubleClicked(QListWidgetItem*)\0"
    "on_ClearButton_clicked()\0"
    "on_CancelButton_clicked()\0"
    "on_OKbutton_clicked()\0"
};

void getClassResource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        getClassResource *_t = static_cast<getClassResource *>(_o);
        switch (_id) {
        case 0: _t->on_Filter_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_ClearButton_clicked(); break;
        case 3: _t->on_CancelButton_clicked(); break;
        case 4: _t->on_OKbutton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData getClassResource::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject getClassResource::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_getClassResource,
      qt_meta_data_getClassResource, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &getClassResource::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *getClassResource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *getClassResource::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_getClassResource))
        return static_cast<void*>(const_cast< getClassResource*>(this));
    return QDialog::qt_metacast(_clname);
}

int getClassResource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
