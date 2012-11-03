/****************************************************************************
** Meta object code from reading C++ file 'buildtargets.h'
**
** Created: Fri 2. Nov 07:46:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../buildtargets.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buildtargets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BuildTargets[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      43,   38,   13,   13, 0x08,
      79,   38,   13,   13, 0x08,
     112,   13,   13,   13, 0x08,
     144,  138,   13,   13, 0x08,
     189,   13,   13,   13, 0x08,
     216,   13,   13,   13, 0x08,
     239,   13,   13,   13, 0x08,
     279,  262,   13,   13, 0x08,
     346,   13,   13,   13, 0x08,
     368,   13,   13,   13, 0x08,
     392,   38,   13,   13, 0x08,
     433,   13,   13,   13, 0x08,
     459,   13,   13,   13, 0x08,
     486,   38,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BuildTargets[] = {
    "BuildTargets\0\0on_helpbutton_clicked()\0"
    "arg1\0on_DisplayName_textChanged(QString)\0"
    "on_codeName_textChanged(QString)\0"
    "on_DescText_textChanged()\0index\0"
    "on_ExporterComboBox_currentIndexChanged(int)\0"
    "on_OptionsButton_clicked()\0"
    "on_AddTarget_clicked()\0on_DelTarget_clicked()\0"
    "current,previous\0"
    "on_TargetsLV_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "on_OKbutton_clicked()\0on_toolButton_clicked()\0"
    "on_exporterLineEdit_textChanged(QString)\0"
    "on_toolButton_2_clicked()\0"
    "on_selectModules_clicked()\0"
    "on_defines_textChanged(QString)\0"
};

void BuildTargets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BuildTargets *_t = static_cast<BuildTargets *>(_o);
        switch (_id) {
        case 0: _t->on_helpbutton_clicked(); break;
        case 1: _t->on_DisplayName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_codeName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_DescText_textChanged(); break;
        case 4: _t->on_ExporterComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_OptionsButton_clicked(); break;
        case 6: _t->on_AddTarget_clicked(); break;
        case 7: _t->on_DelTarget_clicked(); break;
        case 8: _t->on_TargetsLV_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 9: _t->on_OKbutton_clicked(); break;
        case 10: _t->on_toolButton_clicked(); break;
        case 11: _t->on_exporterLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_toolButton_2_clicked(); break;
        case 13: _t->on_selectModules_clicked(); break;
        case 14: _t->on_defines_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BuildTargets::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BuildTargets::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BuildTargets,
      qt_meta_data_BuildTargets, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BuildTargets::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BuildTargets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BuildTargets::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BuildTargets))
        return static_cast<void*>(const_cast< BuildTargets*>(this));
    return QDialog::qt_metacast(_clname);
}

int BuildTargets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
