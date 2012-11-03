/****************************************************************************
** Meta object code from reading C++ file 'splashscreen.h'
**
** Created: Fri 2. Nov 07:46:40 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../splashscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splashscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplashScreen[] = {

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
      14,   13,   13,   13, 0x0a,
      34,   13,   13,   13, 0x0a,
      49,   13,   13,   13, 0x0a,
      65,   13,   13,   13, 0x0a,
      77,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SplashScreen[] = {
    "SplashScreen\0\0setMessage(QString)\0"
    "initcomplete()\0ShowForAWhile()\0"
    "completed()\0fadeoutStep()\0"
};

void SplashScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SplashScreen *_t = static_cast<SplashScreen *>(_o);
        switch (_id) {
        case 0: _t->setMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->initcomplete(); break;
        case 2: _t->ShowForAWhile(); break;
        case 3: _t->completed(); break;
        case 4: _t->fadeoutStep(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SplashScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SplashScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SplashScreen,
      qt_meta_data_SplashScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplashScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplashScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplashScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplashScreen))
        return static_cast<void*>(const_cast< SplashScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int SplashScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
