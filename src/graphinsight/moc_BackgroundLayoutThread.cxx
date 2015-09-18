/****************************************************************************
** Meta object code from reading C++ file 'BackgroundLayoutThread.h'
**
** Created: Wed Apr 23 09:59:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "BackgroundLayoutThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackgroundLayoutThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BackgroundLayoutThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      42,   40,   23,   23, 0x05,
      57,   23,   23,   23, 0x05,
      72,   68,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   23,   23,   23, 0x0a,
     101,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BackgroundLayoutThread[] = {
    "BackgroundLayoutThread\0\0isRunning(bool)\0"
    "n\0stepsDone(int)\0finished()\0err\0"
    "error(QString)\0requestStop()\0process()\0"
};

void BackgroundLayoutThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BackgroundLayoutThread *_t = static_cast<BackgroundLayoutThread *>(_o);
        switch (_id) {
        case 0: _t->isRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->stepsDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->requestStop(); break;
        case 5: _t->process(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BackgroundLayoutThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BackgroundLayoutThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BackgroundLayoutThread,
      qt_meta_data_BackgroundLayoutThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BackgroundLayoutThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BackgroundLayoutThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BackgroundLayoutThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundLayoutThread))
        return static_cast<void*>(const_cast< BackgroundLayoutThread*>(this));
    return QObject::qt_metacast(_clname);
}

int BackgroundLayoutThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void BackgroundLayoutThread::isRunning(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackgroundLayoutThread::stepsDone(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackgroundLayoutThread::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void BackgroundLayoutThread::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
