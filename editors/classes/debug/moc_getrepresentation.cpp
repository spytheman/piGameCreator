/****************************************************************************
** Meta object code from reading C++ file 'getrepresentation.h'
**
** Created: Thu 11. Oct 18:34:03 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../getrepresentation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getrepresentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_getRepresentation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x08,
      68,   19,   18,   18, 0x08,
     118,   18,   18,   18, 0x08,
     144,   18,   18,   18, 0x08,
     171,   18,   18,   18, 0x08,
     198,   18,   18,   18, 0x08,
     225,   18,   18,   18, 0x08,
     250,   18,   18,   18, 0x08,
     277,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_getRepresentation[] = {
    "getRepresentation\0\0item\0"
    "on_listWidget_itemClicked(QListWidgetItem*)\0"
    "on_listWidget_itemDoubleClicked(QListWidgetItem*)\0"
    "on_pushButton_2_clicked()\0"
    "on_radioButton_4_clicked()\0"
    "on_radioButton_5_clicked()\0"
    "on_radioButton_6_clicked()\0"
    "on_radioButton_clicked()\0"
    "on_radioButton_2_clicked()\0"
    "on_radioButton_3_clicked()\0"
};

void getRepresentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        getRepresentation *_t = static_cast<getRepresentation *>(_o);
        switch (_id) {
        case 0: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_radioButton_4_clicked(); break;
        case 4: _t->on_radioButton_5_clicked(); break;
        case 5: _t->on_radioButton_6_clicked(); break;
        case 6: _t->on_radioButton_clicked(); break;
        case 7: _t->on_radioButton_2_clicked(); break;
        case 8: _t->on_radioButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData getRepresentation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject getRepresentation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_getRepresentation,
      qt_meta_data_getRepresentation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &getRepresentation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *getRepresentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *getRepresentation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_getRepresentation))
        return static_cast<void*>(const_cast< getRepresentation*>(this));
    return QDialog::qt_metacast(_clname);
}

int getRepresentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
