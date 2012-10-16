/****************************************************************************
** Meta object code from reading C++ file 'imagepreviewer.h'
**
** Created: Mon 15. Oct 20:54:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sharedcode/imagepreviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagepreviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImagePreviewer[] = {

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
      33,   16,   15,   15, 0x08,
     101,   15,   15,   15, 0x08,
     125,   15,   15,   15, 0x08,
     149,   15,   15,   15, 0x08,
     186,  181,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImagePreviewer[] = {
    "ImagePreviewer\0\0current,previous\0"
    "on_listWidget_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "on_buttonBox_accepted()\0on_buttonBox_rejected()\0"
    "on_statusCancelButton_clicked()\0item\0"
    "on_listWidget_itemDoubleClicked(QListWidgetItem*)\0"
};

void ImagePreviewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImagePreviewer *_t = static_cast<ImagePreviewer *>(_o);
        switch (_id) {
        case 0: _t->on_listWidget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_buttonBox_rejected(); break;
        case 3: _t->on_statusCancelButton_clicked(); break;
        case 4: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImagePreviewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImagePreviewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ImagePreviewer,
      qt_meta_data_ImagePreviewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImagePreviewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImagePreviewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImagePreviewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImagePreviewer))
        return static_cast<void*>(const_cast< ImagePreviewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int ImagePreviewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
