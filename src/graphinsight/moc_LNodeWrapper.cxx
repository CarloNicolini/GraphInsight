/****************************************************************************
** Meta object code from reading C++ file 'LNodeWrapper.h'
**
** Created: Wed Apr 23 09:59:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "LNodeWrapper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LNodeWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LNodeWrapper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      76,   13,   69,   13, 0x0a,
      88,   13,   69,   13, 0x0a,
     104,   13,  100,   13, 0x0a,
     119,   13,  100,   13, 0x0a,
     132,   13,  127,   13, 0x0a,
     160,   13,  150,   13, 0x0a,
     172,   13,   69,   13, 0x0a,
     179,   13,   69,   13, 0x0a,
     186,   13,   69,   13, 0x0a,
     204,   13,  193,   13, 0x0a,
     230,  221,   13,   13, 0x0a,
     263,  257,   13,   13, 0x0a,
     298,  292,   13,   13, 0x0a,
     336,  323,   13,   13, 0x0a,
     391,  362,   13,   13, 0x0a,
     433,   13,  421,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LNodeWrapper[] = {
    "LNodeWrapper\0\0row,column,value\0"
    "nodeAttributeChanged(int,int,QString)\0"
    "double\0getDegree()\0getWeight()\0int\0"
    "getComponent()\0getId()\0uint\0"
    "getNumNeighbors()\0PyObject*\0neighbors()\0"
    "getX()\0getY()\0getZ()\0QList<int>\0"
    "getNeighborsId()\0dx,dy,dz\0"
    "move(double,double,double)\0x,y,z\0"
    "setPos(double,double,double)\0r,g,b\0"
    "setColorRGB(int,int,int)\0column,value\0"
    "setAttribute(int,QString)\0"
    "attributeName,attributeValue\0"
    "setAttribute(QString,QString)\0QStringList\0"
    "getAttributes()\0"
};

void LNodeWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LNodeWrapper *_t = static_cast<LNodeWrapper *>(_o);
        switch (_id) {
        case 0: _t->nodeAttributeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: { double _r = _t->getDegree();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: { double _r = _t->getWeight();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getComponent();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { uint _r = _t->getNumNeighbors();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 6: { PyObject* _r = _t->neighbors();
            if (_a[0]) *reinterpret_cast< PyObject**>(_a[0]) = _r; }  break;
        case 7: { double _r = _t->getX();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 8: { double _r = _t->getY();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: { double _r = _t->getZ();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 10: { QList<int> _r = _t->getNeighborsId();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        case 11: _t->move((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 12: _t->setPos((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 13: _t->setColorRGB((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->setAttribute((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->setAttribute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: { QStringList _r = _t->getAttributes();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LNodeWrapper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LNodeWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LNodeWrapper,
      qt_meta_data_LNodeWrapper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LNodeWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LNodeWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LNodeWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LNodeWrapper))
        return static_cast<void*>(const_cast< LNodeWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int LNodeWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void LNodeWrapper::nodeAttributeChanged(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
