/****************************************************************************
** Meta object code from reading C++ file 'sceneeditor.h'
**
** Created: Thu 18. Oct 05:01:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sceneeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sceneeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SceneEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      45,   12,   12,   12, 0x0a,
      84,   12,   12,   12, 0x0a,
     120,   12,   12,   12, 0x0a,
     154,   12,   12,   12, 0x0a,
     190,   12,   12,   12, 0x0a,
     220,   12,   12,   12, 0x0a,
     257,  249,   12,   12, 0x0a,
     289,  249,   12,   12, 0x0a,
     326,  249,   12,   12, 0x0a,
     357,   12,   12,   12, 0x0a,
     377,   12,   12,   12, 0x08,
     409,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SceneEditor[] = {
    "SceneEditor\0\0on_actionGraph_tool_triggered()\0"
    "on_actionPolygon_path_tool_triggered()\0"
    "on_actionRectangle_tool_triggered()\0"
    "on_actionDraw_objects_triggered()\0"
    "on_actionSelect_objects_triggered()\0"
    "on_HeightSB_valueChanged(int)\0"
    "on_WidthSB_valueChanged(int)\0checked\0"
    "on_actionLayers_triggered(bool)\0"
    "on_actionToolOptions_triggered(bool)\0"
    "on_actionViews_triggered(bool)\0"
    "reloadWindowState()\0on_action100percent_triggered()\0"
    "on_actionTerrain_tool_triggered()\0"
};

void SceneEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SceneEditor *_t = static_cast<SceneEditor *>(_o);
        switch (_id) {
        case 0: _t->on_actionGraph_tool_triggered(); break;
        case 1: _t->on_actionPolygon_path_tool_triggered(); break;
        case 2: _t->on_actionRectangle_tool_triggered(); break;
        case 3: _t->on_actionDraw_objects_triggered(); break;
        case 4: _t->on_actionSelect_objects_triggered(); break;
        case 5: _t->on_HeightSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_WidthSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_actionLayers_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_actionToolOptions_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionViews_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->reloadWindowState(); break;
        case 11: _t->on_action100percent_triggered(); break;
        case 12: _t->on_actionTerrain_tool_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SceneEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SceneEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SceneEditor,
      qt_meta_data_SceneEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SceneEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SceneEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SceneEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SceneEditor))
        return static_cast<void*>(const_cast< SceneEditor*>(this));
    if (!strcmp(_clname, "ResourceEditor"))
        return static_cast< ResourceEditor*>(const_cast< SceneEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SceneEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
