/****************************************************************************
** Meta object code from reading C++ file 'PyExampleObject.h'
**
** Created: Wed Apr 23 09:59:04 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PyExampleObject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PyExampleObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PyExampleObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   16,   17,   16, 0x0a,
      47,   43,   16,   16, 0x0a,
      88,   84,   72,   16, 0x0a,
     124,   16,  111,   16, 0x0a,
     155,  148,  139,   16, 0x0a,
     195,   16,  183,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PyExampleObject[] = {
    "PyExampleObject\0\0PyObject*\0getMainModule()\0"
    "str\0showInformation(QString)\0QStringList\0"
    "dir\0readDirectory(QString)\0QMainWindow*\0"
    "createWindow()\0QObject*\0o,name\0"
    "findChild(QObject*,QString)\0QVariantMap\0"
    "testMap()\0"
};

void PyExampleObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PyExampleObject *_t = static_cast<PyExampleObject *>(_o);
        switch (_id) {
        case 0: { PyObject* _r = _t->getMainModule();
            if (_a[0]) *reinterpret_cast< PyObject**>(_a[0]) = _r; }  break;
        case 1: _t->showInformation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { QStringList _r = _t->readDirectory((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 3: { QMainWindow* _r = _t->createWindow();
            if (_a[0]) *reinterpret_cast< QMainWindow**>(_a[0]) = _r; }  break;
        case 4: { QObject* _r = _t->findChild((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 5: { QVariantMap _r = _t->testMap();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PyExampleObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PyExampleObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PyExampleObject,
      qt_meta_data_PyExampleObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PyExampleObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PyExampleObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PyExampleObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PyExampleObject))
        return static_cast<void*>(const_cast< PyExampleObject*>(this));
    return QObject::qt_metacast(_clname);
}

int PyExampleObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
