/****************************************************************************
** Meta object code from reading C++ file 'codeeditor.h'
**
** Created: Sun 12. Aug 05:52:09 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../codeeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodeEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x08,
      44,   42,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditor[] = {
    "CodeEditor\0\0y\0verticalScrollBarMoved(int)\0"
    "x\0horizontalScrollBarMoved(int)\0"
    "toggleCursorVisible()\0gswCompleted()\0"
    "gswProgressChanged(int)\0"
    "highlighterReapplyFontSettings()\0"
    "onIDESettingsChanged()\0"
};

void CodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CodeEditor *_t = static_cast<CodeEditor *>(_o);
        switch (_id) {
        case 0: _t->verticalScrollBarMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->horizontalScrollBarMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toggleCursorVisible(); break;
        case 3: _t->gswCompleted(); break;
        case 4: _t->gswProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->highlighterReapplyFontSettings(); break;
        case 6: _t->onIDESettingsChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CodeEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CodeEditor::staticMetaObject = {
    { &QAbstractScrollArea::staticMetaObject, qt_meta_stringdata_CodeEditor,
      qt_meta_data_CodeEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditor))
        return static_cast<void*>(const_cast< CodeEditor*>(this));
    return QAbstractScrollArea::qt_metacast(_clname);
}

int CodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
