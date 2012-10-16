/****************************************************************************
** Meta object code from reading C++ file 'editvardialog.h'
**
** Created: Tue 16. Oct 03:24:32 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editvardialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editvardialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditVarDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      44,   14,   14,   14, 0x08,
      76,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     142,   14,   14,   14, 0x08,
     168,   14,   14,   14, 0x08,
     198,   14,   14,   14, 0x08,
     220,   14,   14,   14, 0x08,
     247,   14,   14,   14, 0x08,
     278,  272,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditVarDialog[] = {
    "EditVarDialog\0\0on_menuWithChoices_clicked()\0"
    "on_NullresourceButton_clicked()\0"
    "on_SelectResourceButton_clicked()\0"
    "on_SetColorToolButton_clicked()\0"
    "on_DelFromArray_clicked()\0"
    "on_AddToArrayButton_clicked()\0"
    "on_OKbutton_clicked()\0on_radioButton_2_clicked()\0"
    "on_radioButton_clicked()\0index\0"
    "on_varType_currentIndexChanged(int)\0"
};

void EditVarDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditVarDialog *_t = static_cast<EditVarDialog *>(_o);
        switch (_id) {
        case 0: _t->on_menuWithChoices_clicked(); break;
        case 1: _t->on_NullresourceButton_clicked(); break;
        case 2: _t->on_SelectResourceButton_clicked(); break;
        case 3: _t->on_SetColorToolButton_clicked(); break;
        case 4: _t->on_DelFromArray_clicked(); break;
        case 5: _t->on_AddToArrayButton_clicked(); break;
        case 6: _t->on_OKbutton_clicked(); break;
        case 7: _t->on_radioButton_2_clicked(); break;
        case 8: _t->on_radioButton_clicked(); break;
        case 9: _t->on_varType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditVarDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditVarDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditVarDialog,
      qt_meta_data_EditVarDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditVarDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditVarDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditVarDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditVarDialog))
        return static_cast<void*>(const_cast< EditVarDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditVarDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
