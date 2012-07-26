/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created: Tue 24. Jul 05:38:57 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settingswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   38,   15,   15, 0x08,
      88,   15,   15,   15, 0x08,
     114,   15,   15,   15, 0x08,
     138,   15,   15,   15, 0x08,
     164,   15,   15,   15, 0x08,
     201,  193,   15,   15, 0x08,
     238,  193,   15,   15, 0x08,
     272,  193,   15,   15, 0x08,
     315,  304,   15,   15, 0x08,
     360,   15,   15,   15, 0x08,
     386,   15,   15,   15, 0x08,
     429,  412,   15,   15, 0x08,
     502,  494,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingsWindow[] = {
    "SettingsWindow\0\0codeColoringChanged()\0"
    "f\0on_editorFontComboBox_currentFontChanged(QFont)\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_clicked()\0"
    "on_toolButton_5_clicked()\0"
    "on_TextColorButton_clicked()\0checked\0"
    "on_UnderlineTextButton_toggled(bool)\0"
    "on_ItalicTextButton_toggled(bool)\0"
    "on_BoldTextButton_toggled(bool)\0"
    "currentRow\0on_keywordsListWidget_currentRowChanged(int)\0"
    "SettingsWindow_rejected()\0"
    "SettingsWindow_accepted()\0current,previous\0"
    "listWidget_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "newsize\0on_fontSize_valueChanged(int)\0"
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsWindow *_t = static_cast<SettingsWindow *>(_o);
        switch (_id) {
        case 0: _t->codeColoringChanged(); break;
        case 1: _t->on_editorFontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 2: _t->on_toolButton_2_clicked(); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->on_toolButton_5_clicked(); break;
        case 5: _t->on_TextColorButton_clicked(); break;
        case 6: _t->on_UnderlineTextButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_ItalicTextButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_BoldTextButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_keywordsListWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SettingsWindow_rejected(); break;
        case 11: _t->SettingsWindow_accepted(); break;
        case 12: _t->listWidget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 13: _t->on_fontSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingsWindow,
      qt_meta_data_SettingsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow))
        return static_cast<void*>(const_cast< SettingsWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SettingsWindow::codeColoringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
