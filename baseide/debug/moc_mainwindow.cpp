/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 19. Oct 02:47:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      64,   60,   11,   11, 0x0a,
      88,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x0a,
     140,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     177,  171,   11,   11, 0x0a,
     222,  171,   11,   11, 0x0a,
     264,  171,   11,   11, 0x0a,
     304,  300,   11,   11, 0x0a,
     354,   11,   11,   11, 0x0a,
     388,   11,   11,   11, 0x0a,
     427,   11,   11,   11, 0x0a,
     457,   11,   11,   11, 0x0a,
     485,   11,   11,   11, 0x0a,
     529,  512,   11,   11, 0x0a,
     581,  171,   11,   11, 0x0a,
     618,  171,   11,   11, 0x0a,
     656,   11,   11,   11, 0x0a,
     680,   11,   11,   11, 0x0a,
     706,  171,   11,   11, 0x0a,
     755,  750,   11,   11, 0x0a,
     790,   11,   11,   11, 0x0a,
     820,   11,   11,   11, 0x0a,
     844,   11,   11,   11, 0x0a,
     871,   11,   11,   11, 0x0a,
     905,   11,   11,   11, 0x0a,
     941,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0s\0tabTextChanged(QString)\0"
    "ShowSkins()\0setSkin()\0row\0"
    "BuildTargetChanged(int)\0"
    "on_actionExit_triggered()\0"
    "on_action_Run_triggered()\0LastWWClosed()\0"
    "ResViewChange()\0index\0"
    "on_WorkSpaceTabWidget_tabCloseRequested(int)\0"
    "on_projectTree_doubleClicked(QModelIndex)\0"
    "on_projectTree_clicked(QModelIndex)\0"
    "pos\0on_projectTree_customContextMenuRequested(QPoint)\0"
    "on_action_Preferences_triggered()\0"
    "on_actionGameScript_tester_triggered()\0"
    "on_action_Targets_triggered()\0"
    "on_action_Debug_triggered()\0"
    "on_actionBuild_triggered()\0current,previous\0"
    "projectTreeSelection(QItemSelection,QItemSelection)\0"
    "on_projectTree_expanded(QModelIndex)\0"
    "on_projectTree_collapsed(QModelIndex)\0"
    "on_toolButton_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_projectComboBox_currentIndexChanged(int)\0"
    "item\0ProjectItemChanged(QStandardItem*)\0"
    "routeRightMenuClickToItsDLL()\0"
    "on_pushButton_clicked()\0"
    "on_action_Save_triggered()\0"
    "on_actionOpen_project_triggered()\0"
    "on_actionCreate_project_triggered()\0"
    "on_actionSkin_editor_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->tabTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ShowSkins(); break;
        case 2: _t->setSkin(); break;
        case 3: _t->BuildTargetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_actionExit_triggered(); break;
        case 5: _t->on_action_Run_triggered(); break;
        case 6: _t->LastWWClosed(); break;
        case 7: _t->ResViewChange(); break;
        case 8: _t->on_WorkSpaceTabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_projectTree_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_projectTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_projectTree_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->on_action_Preferences_triggered(); break;
        case 13: _t->on_actionGameScript_tester_triggered(); break;
        case 14: _t->on_action_Targets_triggered(); break;
        case 15: _t->on_action_Debug_triggered(); break;
        case 16: _t->on_actionBuild_triggered(); break;
        case 17: _t->projectTreeSelection((*reinterpret_cast< QItemSelection(*)>(_a[1])),(*reinterpret_cast< QItemSelection(*)>(_a[2]))); break;
        case 18: _t->on_projectTree_expanded((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 19: _t->on_projectTree_collapsed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 20: _t->on_toolButton_clicked(); break;
        case 21: _t->on_toolButton_2_clicked(); break;
        case 22: _t->on_projectComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->ProjectItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 24: _t->routeRightMenuClickToItsDLL(); break;
        case 25: _t->on_pushButton_clicked(); break;
        case 26: _t->on_action_Save_triggered(); break;
        case 27: _t->on_actionOpen_project_triggered(); break;
        case 28: _t->on_actionCreate_project_triggered(); break;
        case 29: _t->on_actionSkin_editor_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
