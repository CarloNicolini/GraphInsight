/****************************************************************************
** Meta object code from reading C++ file 'com_trolltech_qt_gui_builtin0.h'
**
** Created: Wed Apr 23 09:58:09 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "com_trolltech_qt_gui_builtin0.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'com_trolltech_qt_gui_builtin0.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PythonQtWrapper_QBitmap[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   24,   25,   24, 0x0a,
      55,   48,   25,   24, 0x0a,
      76,   48,   25,   24, 0x0a,
     111,   95,   25,   24, 0x0a,
     153,  144,   25,   24, 0x2a,
     178,  174,   25,   24, 0x0a,
     205,  199,   25,   24, 0x0a,
     230,  226,   24,   24, 0x0a,
     272,  255,   24,   24, 0x0a,
     308,  296,  288,   24, 0x0a,
     372,  366,  288,   24, 0x2a,
     429,  405,  288,   24, 0x0a,
     483,  459,  288,   24, 0x0a,
     521,  226,  516,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QBitmap[] = {
    "PythonQtWrapper_QBitmap\0\0QBitmap*\0"
    "new_QBitmap()\0arg__1\0new_QBitmap(QPixmap)\0"
    "new_QBitmap(QSize)\0fileName,format\0"
    "new_QBitmap(QString,const char*)\0"
    "fileName\0new_QBitmap(QString)\0w,h\0"
    "new_QBitmap(int,int)\0other\0"
    "new_QBitmap(QBitmap)\0obj\0"
    "delete_QBitmap(QBitmap*)\0theWrappedObject\0"
    "clear(QBitmap*)\0QBitmap\0image,flags\0"
    "static_QBitmap_fromImage(QImage,Qt::ImageConversionFlags)\0"
    "image\0static_QBitmap_fromImage(QImage)\0"
    "theWrappedObject,arg__1\0"
    "transformed(QBitmap*,QMatrix)\0"
    "theWrappedObject,matrix\0"
    "transformed(QBitmap*,QTransform)\0bool\0"
    "__nonzero__(QBitmap*)\0"
};

void PythonQtWrapper_QBitmap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QBitmap *_t = static_cast<PythonQtWrapper_QBitmap *>(_o);
        switch (_id) {
        case 0: { QBitmap* _r = _t->new_QBitmap();
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 1: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< const QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 2: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< const QSize(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 3: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 4: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 5: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 6: { QBitmap* _r = _t->new_QBitmap((*reinterpret_cast< const QBitmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap**>(_a[0]) = _r; }  break;
        case 7: _t->delete_QBitmap((*reinterpret_cast< QBitmap*(*)>(_a[1]))); break;
        case 8: _t->clear((*reinterpret_cast< QBitmap*(*)>(_a[1]))); break;
        case 9: { QBitmap _r = _t->static_QBitmap_fromImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 10: { QBitmap _r = _t->static_QBitmap_fromImage((*reinterpret_cast< const QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 11: { QBitmap _r = _t->transformed((*reinterpret_cast< QBitmap*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 12: { QBitmap _r = _t->transformed((*reinterpret_cast< QBitmap*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->__nonzero__((*reinterpret_cast< QBitmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QBitmap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QBitmap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QBitmap,
      qt_meta_data_PythonQtWrapper_QBitmap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QBitmap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QBitmap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QBitmap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QBitmap))
        return static_cast<void*>(const_cast< PythonQtWrapper_QBitmap*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QBitmap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QBrush[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   23,   24,   23, 0x0a,
      48,   45,   24,   23, 0x0a,
      88,   75,   24,   23, 0x0a,
     130,  124,   24,   23, 0x0a,
     158,  149,   24,   23, 0x0a,
     198,  192,   24,   23, 0x2a,
     217,   75,   24,   23, 0x0a,
     253,  244,   24,   23, 0x0a,
     281,  275,   24,   23, 0x0a,
     307,  300,   24,   23, 0x0a,
     331,  327,   23,   23, 0x0a,
     385,  368,  354,   23, 0x0a,
     417,  368,  400,   23, 0x0a,
     440,  368,  435,   23, 0x0a,
     473,  368,  458,   23, 0x0a,
     508,  489,  435,   23, 0x0a,
     555,  531,   23,   23, 0x0a,
     585,  489,  435,   23, 0x0a,
     608,  531,   23,   23, 0x0a,
     662,  639,   23,   23, 0x0a,
     696,  639,   23,   23, 0x0a,
     742,  721,   23,   23, 0x0a,
     769,  531,   23,   23, 0x0a,
     826,  802,   23,   23, 0x0a,
     877,  854,   23,   23, 0x0a,
     909,  531,   23,   23, 0x0a,
     957,  368,  942,   23, 0x0a,
     980,  368,  972,   23, 0x0a,
    1004,  368,  997,   23, 0x0a,
    1037,  368, 1026,   23, 0x0a,
    1064,   23, 1056,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QBrush[] = {
    "PythonQtWrapper_QBrush\0\0QBrush*\0"
    "new_QBrush()\0bs\0new_QBrush(Qt::BrushStyle)\0"
    "color,pixmap\0new_QBrush(Qt::GlobalColor,QPixmap)\0"
    "brush\0new_QBrush(QBrush)\0color,bs\0"
    "new_QBrush(QColor,Qt::BrushStyle)\0"
    "color\0new_QBrush(QColor)\0"
    "new_QBrush(QColor,QPixmap)\0gradient\0"
    "new_QBrush(QGradient)\0image\0"
    "new_QBrush(QImage)\0pixmap\0new_QBrush(QPixmap)\0"
    "obj\0delete_QBrush(QBrush*)\0const QColor*\0"
    "theWrappedObject\0color(QBrush*)\0"
    "const QGradient*\0gradient(QBrush*)\0"
    "bool\0isOpaque(QBrush*)\0const QMatrix*\0"
    "matrix(QBrush*)\0theWrappedObject,b\0"
    "__ne__(QBrush*,QBrush)\0theWrappedObject,arg__1\0"
    "writeTo(QBrush*,QDataStream&)\0"
    "__eq__(QBrush*,QBrush)\0"
    "readFrom(QBrush*,QDataStream&)\0"
    "theWrappedObject,color\0"
    "setColor(QBrush*,Qt::GlobalColor)\0"
    "setColor(QBrush*,QColor)\0theWrappedObject,mat\0"
    "setMatrix(QBrush*,QMatrix)\0"
    "setStyle(QBrush*,Qt::BrushStyle)\0"
    "theWrappedObject,pixmap\0"
    "setTexture(QBrush*,QPixmap)\0"
    "theWrappedObject,image\0"
    "setTextureImage(QBrush*,QImage)\0"
    "setTransform(QBrush*,QTransform)\0"
    "Qt::BrushStyle\0style(QBrush*)\0QPixmap\0"
    "texture(QBrush*)\0QImage\0textureImage(QBrush*)\0"
    "QTransform\0transform(QBrush*)\0QString\0"
    "py_toString(QBrush*)\0"
};

void PythonQtWrapper_QBrush::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QBrush *_t = static_cast<PythonQtWrapper_QBrush *>(_o);
        switch (_id) {
        case 0: { QBrush* _r = _t->new_QBrush();
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 1: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< Qt::BrushStyle(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 2: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< Qt::GlobalColor(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 3: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QBrush(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 4: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< Qt::BrushStyle(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 5: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 6: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 7: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QGradient(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 8: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 9: { QBrush* _r = _t->new_QBrush((*reinterpret_cast< const QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush**>(_a[0]) = _r; }  break;
        case 10: _t->delete_QBrush((*reinterpret_cast< QBrush*(*)>(_a[1]))); break;
        case 11: { const QColor* _r = _t->color((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QColor**>(_a[0]) = _r; }  break;
        case 12: { const QGradient* _r = _t->gradient((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QGradient**>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->isOpaque((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { const QMatrix* _r = _t->matrix((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QMatrix**>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->__ne__((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: _t->writeTo((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 17: { bool _r = _t->__eq__((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: _t->readFrom((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 19: _t->setColor((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< Qt::GlobalColor(*)>(_a[2]))); break;
        case 20: _t->setColor((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 21: _t->setMatrix((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2]))); break;
        case 22: _t->setStyle((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< Qt::BrushStyle(*)>(_a[2]))); break;
        case 23: _t->setTexture((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 24: _t->setTextureImage((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 25: _t->setTransform((*reinterpret_cast< QBrush*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2]))); break;
        case 26: { Qt::BrushStyle _r = _t->style((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::BrushStyle*>(_a[0]) = _r; }  break;
        case 27: { QPixmap _r = _t->texture((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 28: { QImage _r = _t->textureImage((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 29: { QTransform _r = _t->transform((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTransform*>(_a[0]) = _r; }  break;
        case 30: { QString _r = _t->py_toString((*reinterpret_cast< QBrush*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QBrush::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QBrush::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QBrush,
      qt_meta_data_PythonQtWrapper_QBrush, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QBrush::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QBrush::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QBrush::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QBrush))
        return static_cast<void*>(const_cast< PythonQtWrapper_QBrush*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QBrush::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QColor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
     115,   14, // methods
       0,    0, // properties
       1,  589, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   23,   24,   23, 0x0a,
      51,   45,   24,   23, 0x0a,
      79,   45,   24,   23, 0x0a,
     103,   98,   24,   23, 0x0a,
     131,  123,   24,   23, 0x0a,
     165,  159,   24,   23, 0x2a,
     193,  189,   24,   23, 0x0a,
     214,  210,   23,   23, 0x0a,
     258,  241,  237,   23, 0x0a,
     279,  241,  273,   23, 0x0a,
     295,  241,  237,   23, 0x0a,
     310,  241,  273,   23, 0x0a,
     326,  241,  237,   23, 0x0a,
     340,  241,  273,   23, 0x0a,
     367,   23,  355,   23, 0x0a,
     428,  401,  394,   23, 0x0a,
     460,  241,  237,   23, 0x0a,
     474,  241,  273,   23, 0x0a,
     508,  489,  394,   23, 0x0a,
     528,  241,  394,   23, 0x2a,
     554,  544,  394,   23, 0x0a,
     606,  598,  394,   23, 0x2a,
     646,  544,  394,   23, 0x0a,
     701,  598,  394,   23, 0x2a,
     758,  750,  394,   23, 0x0a,
     803,  797,  394,   23, 0x2a,
     838,  750,  394,   23, 0x0a,
     886,  797,  394,   23, 0x2a,
     936,  928,  394,   23, 0x0a,
     981,  975,  394,   23, 0x2a,
    1016,  928,  394,   23, 0x0a,
    1064,  975,  394,   23, 0x2a,
    1106,  123,  394,   23, 0x0a,
    1145,  159,  394,   23, 0x2a,
    1180,  189,  394,   23, 0x0a,
    1208,  123,  394,   23, 0x0a,
    1256,  159,  394,   23, 0x2a,
    1303, 1298,  394,   23, 0x0a,
    1359, 1332,   23,   23, 0x0a,
    1437, 1412,   23,   23, 0x2a,
    1508, 1483,   23,   23, 0x0a,
    1567, 1544,   23,   23, 0x2a,
    1598, 1483,   23,   23, 0x0a,
    1643, 1544,   23,   23, 0x2a,
    1706, 1681,   23,   23, 0x0a,
    1774, 1751,   23,   23, 0x2a,
    1837, 1812,   23,   23, 0x0a,
    1905, 1882,   23,   23, 0x2a,
    1943,  241,  237,   23, 0x0a,
    1958,  241,  273,   23, 0x0a,
    1974,  241,  237,   23, 0x0a,
    1990,  241,  273,   23, 0x0a,
    2007,  241,  237,   23, 0x0a,
    2030,  241,  273,   23, 0x0a,
    2054,  241,  237,   23, 0x0a,
    2070,  241,  273,   23, 0x0a,
    2087,  241,  237,   23, 0x0a,
    2110,  241,  273,   23, 0x0a,
    2134,  241,  237,   23, 0x0a,
    2147,  241,  273,   23, 0x0a,
    2166,  241, 2161,   23, 0x0a,
    2183,  489,  394,   23, 0x0a,
    2204,  241,  394,   23, 0x2a,
    2221,  241,  237,   23, 0x0a,
    2240,  241,  273,   23, 0x0a,
    2260,  241,  237,   23, 0x0a,
    2277,  241,  273,   23, 0x0a,
    2303,  241, 2295,   23, 0x0a,
    2336, 2317, 2161,   23, 0x0a,
    2383, 2359,   23,   23, 0x0a,
    2413, 2317, 2161,   23, 0x0a,
    2436, 2359,   23,   23, 0x0a,
    2467,  241,  237,   23, 0x0a,
    2480,  241,  273,   23, 0x0a,
    2499,  241, 2494,   23, 0x0a,
    2512,  241, 2494,   23, 0x0a,
    2526,  241,  237,   23, 0x0a,
    2546,  241,  273,   23, 0x0a,
    2590, 2567,   23,   23, 0x0a,
    2612, 2567,   23,   23, 0x0a,
    2659, 2637,   23,   23, 0x0a,
    2680, 2637,   23,   23, 0x0a,
    2704, 1332,   23,   23, 0x0a,
    2741, 1412,   23,   23, 0x2a,
    2774, 1332,   23,   23, 0x0a,
    2822, 1412,   23,   23, 0x2a,
    2887, 2864,   23,   23, 0x0a,
    2909, 2864,   23,   23, 0x0a,
    2934, 1483,   23,   23, 0x0a,
    2966, 1544,   23,   23, 0x2a,
    2994, 1483,   23,   23, 0x0a,
    3035, 1544,   23,   23, 0x2a,
    3070, 1681,   23,   23, 0x0a,
    3102, 1751,   23,   23, 0x2a,
    3130, 1681,   23,   23, 0x0a,
    3171, 1751,   23,   23, 0x2a,
    3228, 3206,   23,   23, 0x0a,
    3280, 3259,   23,   23, 0x0a,
    3300, 3259,   23,   23, 0x0a,
    3323, 1812,   23,   23, 0x0a,
    3355, 1882,   23,   23, 0x2a,
    3404, 3383,   23,   23, 0x0a,
    3425, 1812,   23,   23, 0x0a,
    3466, 1882,   23,   23, 0x2a,
    3523, 3501,   23,   23, 0x0a,
    3558,  241, 3545,   23, 0x0a,
    3572,  241,  394,   23, 0x0a,
    3588,  241,  394,   23, 0x0a,
    3603,  241,  394,   23, 0x0a,
    3618,  241,  394,   23, 0x0a,
    3633,  241,  237,   23, 0x0a,
    3648,  241,  273,   23, 0x0a,
    3664,  241,  237,   23, 0x0a,
    3680,  241,  273,   23, 0x0a,
    3697,   23, 2295,   23, 0x0a,

 // enums: name, flags, count, data
    3718, 0x0,    5,  593,

 // enum data: key, value
    3723, uint(PythonQtWrapper_QColor::Invalid),
    3731, uint(PythonQtWrapper_QColor::Rgb),
    3735, uint(PythonQtWrapper_QColor::Hsv),
    3739, uint(PythonQtWrapper_QColor::Cmyk),
    3744, uint(PythonQtWrapper_QColor::Hsl),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QColor[] = {
    "PythonQtWrapper_QColor\0\0QColor*\0"
    "new_QColor()\0color\0new_QColor(Qt::GlobalColor)\0"
    "new_QColor(QColor)\0name\0new_QColor(QString)\0"
    "r,g,b,a\0new_QColor(int,int,int,int)\0"
    "r,g,b\0new_QColor(int,int,int)\0rgb\0"
    "new_QColor(uint)\0obj\0delete_QColor(QColor*)\0"
    "int\0theWrappedObject\0alpha(QColor*)\0"
    "qreal\0alphaF(QColor*)\0black(QColor*)\0"
    "blackF(QColor*)\0blue(QColor*)\0"
    "blueF(QColor*)\0QStringList\0"
    "static_QColor_colorNames()\0QColor\0"
    "theWrappedObject,colorSpec\0"
    "convertTo(QColor*,QColor::Spec)\0"
    "cyan(QColor*)\0cyanF(QColor*)\0"
    "theWrappedObject,f\0darker(QColor*,int)\0"
    "darker(QColor*)\0c,m,y,k,a\0"
    "static_QColor_fromCmyk(int,int,int,int,int)\0"
    "c,m,y,k\0static_QColor_fromCmyk(int,int,int,int)\0"
    "static_QColor_fromCmykF(qreal,qreal,qreal,qreal,qreal)\0"
    "static_QColor_fromCmykF(qreal,qreal,qreal,qreal)\0"
    "h,s,l,a\0static_QColor_fromHsl(int,int,int,int)\0"
    "h,s,l\0static_QColor_fromHsl(int,int,int)\0"
    "static_QColor_fromHslF(qreal,qreal,qreal,qreal)\0"
    "static_QColor_fromHslF(qreal,qreal,qreal)\0"
    "h,s,v,a\0static_QColor_fromHsv(int,int,int,int)\0"
    "h,s,v\0static_QColor_fromHsv(int,int,int)\0"
    "static_QColor_fromHsvF(qreal,qreal,qreal,qreal)\0"
    "static_QColor_fromHsvF(qreal,qreal,qreal)\0"
    "static_QColor_fromRgb(int,int,int,int)\0"
    "static_QColor_fromRgb(int,int,int)\0"
    "static_QColor_fromRgb(uint)\0"
    "static_QColor_fromRgbF(qreal,qreal,qreal,qreal)\0"
    "static_QColor_fromRgbF(qreal,qreal,qreal)\0"
    "rgba\0static_QColor_fromRgba(uint)\0"
    "theWrappedObject,c,m,y,k,a\0"
    "getCmykF(QColor*,qreal*,qreal*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,c,m,y,k\0"
    "getCmykF(QColor*,qreal*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,h,s,l,a\0"
    "getHsl(QColor*,int*,int*,int*,int*)\0"
    "theWrappedObject,h,s,l\0"
    "getHsl(QColor*,int*,int*,int*)\0"
    "getHslF(QColor*,qreal*,qreal*,qreal*,qreal*)\0"
    "getHslF(QColor*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,h,s,v,a\0"
    "getHsvF(QColor*,qreal*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,h,s,v\0"
    "getHsvF(QColor*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,r,g,b,a\0"
    "getRgbF(QColor*,qreal*,qreal*,qreal*,qreal*)\0"
    "theWrappedObject,r,g,b\0"
    "getRgbF(QColor*,qreal*,qreal*,qreal*)\0"
    "green(QColor*)\0greenF(QColor*)\0"
    "hslHue(QColor*)\0hslHueF(QColor*)\0"
    "hslSaturation(QColor*)\0hslSaturationF(QColor*)\0"
    "hsvHue(QColor*)\0hsvHueF(QColor*)\0"
    "hsvSaturation(QColor*)\0hsvSaturationF(QColor*)\0"
    "hue(QColor*)\0hueF(QColor*)\0bool\0"
    "isValid(QColor*)\0lighter(QColor*,int)\0"
    "lighter(QColor*)\0lightness(QColor*)\0"
    "lightnessF(QColor*)\0magenta(QColor*)\0"
    "magentaF(QColor*)\0QString\0name(QColor*)\0"
    "theWrappedObject,c\0__ne__(QColor*,QColor)\0"
    "theWrappedObject,arg__1\0"
    "writeTo(QColor*,QDataStream&)\0"
    "__eq__(QColor*,QColor)\0"
    "readFrom(QColor*,QDataStream&)\0"
    "red(QColor*)\0redF(QColor*)\0uint\0"
    "rgb(QColor*)\0rgba(QColor*)\0"
    "saturation(QColor*)\0saturationF(QColor*)\0"
    "theWrappedObject,alpha\0setAlpha(QColor*,int)\0"
    "setAlphaF(QColor*,qreal)\0theWrappedObject,blue\0"
    "setBlue(QColor*,int)\0setBlueF(QColor*,qreal)\0"
    "setCmyk(QColor*,int,int,int,int,int)\0"
    "setCmyk(QColor*,int,int,int,int)\0"
    "setCmykF(QColor*,qreal,qreal,qreal,qreal,qreal)\0"
    "setCmykF(QColor*,qreal,qreal,qreal,qreal)\0"
    "theWrappedObject,green\0setGreen(QColor*,int)\0"
    "setGreenF(QColor*,qreal)\0"
    "setHsl(QColor*,int,int,int,int)\0"
    "setHsl(QColor*,int,int,int)\0"
    "setHslF(QColor*,qreal,qreal,qreal,qreal)\0"
    "setHslF(QColor*,qreal,qreal,qreal)\0"
    "setHsv(QColor*,int,int,int,int)\0"
    "setHsv(QColor*,int,int,int)\0"
    "setHsvF(QColor*,qreal,qreal,qreal,qreal)\0"
    "setHsvF(QColor*,qreal,qreal,qreal)\0"
    "theWrappedObject,name\0"
    "setNamedColor(QColor*,QString)\0"
    "theWrappedObject,red\0setRed(QColor*,int)\0"
    "setRedF(QColor*,qreal)\0"
    "setRgb(QColor*,int,int,int,int)\0"
    "setRgb(QColor*,int,int,int)\0"
    "theWrappedObject,rgb\0setRgb(QColor*,uint)\0"
    "setRgbF(QColor*,qreal,qreal,qreal,qreal)\0"
    "setRgbF(QColor*,qreal,qreal,qreal)\0"
    "theWrappedObject,rgba\0setRgba(QColor*,uint)\0"
    "QColor::Spec\0spec(QColor*)\0toCmyk(QColor*)\0"
    "toHsl(QColor*)\0toHsv(QColor*)\0"
    "toRgb(QColor*)\0value(QColor*)\0"
    "valueF(QColor*)\0yellow(QColor*)\0"
    "yellowF(QColor*)\0py_toString(QColor*)\0"
    "Spec\0Invalid\0Rgb\0Hsv\0Cmyk\0Hsl\0"
};

void PythonQtWrapper_QColor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QColor *_t = static_cast<PythonQtWrapper_QColor *>(_o);
        switch (_id) {
        case 0: { QColor* _r = _t->new_QColor();
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 1: { QColor* _r = _t->new_QColor((*reinterpret_cast< Qt::GlobalColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 2: { QColor* _r = _t->new_QColor((*reinterpret_cast< const QColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 3: { QColor* _r = _t->new_QColor((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 4: { QColor* _r = _t->new_QColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 5: { QColor* _r = _t->new_QColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 6: { QColor* _r = _t->new_QColor((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor**>(_a[0]) = _r; }  break;
        case 7: _t->delete_QColor((*reinterpret_cast< QColor*(*)>(_a[1]))); break;
        case 8: { int _r = _t->alpha((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { qreal _r = _t->alphaF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->black((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { qreal _r = _t->blackF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->blue((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { qreal _r = _t->blueF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 14: { QStringList _r = _t->static_QColor_colorNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 15: { QColor _r = _t->convertTo((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< QColor::Spec(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->cyan((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: { qreal _r = _t->cyanF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 18: { QColor _r = _t->darker((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 19: { QColor _r = _t->darker((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 20: { QColor _r = _t->static_QColor_fromCmyk((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 21: { QColor _r = _t->static_QColor_fromCmyk((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 22: { QColor _r = _t->static_QColor_fromCmykF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 23: { QColor _r = _t->static_QColor_fromCmykF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 24: { QColor _r = _t->static_QColor_fromHsl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 25: { QColor _r = _t->static_QColor_fromHsl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 26: { QColor _r = _t->static_QColor_fromHslF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 27: { QColor _r = _t->static_QColor_fromHslF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 28: { QColor _r = _t->static_QColor_fromHsv((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 29: { QColor _r = _t->static_QColor_fromHsv((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 30: { QColor _r = _t->static_QColor_fromHsvF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 31: { QColor _r = _t->static_QColor_fromHsvF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 32: { QColor _r = _t->static_QColor_fromRgb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 33: { QColor _r = _t->static_QColor_fromRgb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 34: { QColor _r = _t->static_QColor_fromRgb((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 35: { QColor _r = _t->static_QColor_fromRgbF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 36: { QColor _r = _t->static_QColor_fromRgbF((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 37: { QColor _r = _t->static_QColor_fromRgba((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 38: _t->getCmykF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5])),(*reinterpret_cast< qreal*(*)>(_a[6]))); break;
        case 39: _t->getCmykF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5]))); break;
        case 40: _t->getHsl((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 41: _t->getHsl((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4]))); break;
        case 42: _t->getHslF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5]))); break;
        case 43: _t->getHslF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4]))); break;
        case 44: _t->getHsvF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5]))); break;
        case 45: _t->getHsvF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4]))); break;
        case 46: _t->getRgbF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5]))); break;
        case 47: _t->getRgbF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal*(*)>(_a[2])),(*reinterpret_cast< qreal*(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4]))); break;
        case 48: { int _r = _t->green((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 49: { qreal _r = _t->greenF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 50: { int _r = _t->hslHue((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 51: { qreal _r = _t->hslHueF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 52: { int _r = _t->hslSaturation((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 53: { qreal _r = _t->hslSaturationF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 54: { int _r = _t->hsvHue((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 55: { qreal _r = _t->hsvHueF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 56: { int _r = _t->hsvSaturation((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 57: { qreal _r = _t->hsvSaturationF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 58: { int _r = _t->hue((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 59: { qreal _r = _t->hueF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 60: { bool _r = _t->isValid((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 61: { QColor _r = _t->lighter((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 62: { QColor _r = _t->lighter((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 63: { int _r = _t->lightness((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 64: { qreal _r = _t->lightnessF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 65: { int _r = _t->magenta((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 66: { qreal _r = _t->magentaF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 67: { QString _r = _t->name((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 68: { bool _r = _t->__ne__((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 69: _t->writeTo((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 70: { bool _r = _t->__eq__((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 71: _t->readFrom((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 72: { int _r = _t->red((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 73: { qreal _r = _t->redF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 74: { uint _r = _t->rgb((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 75: { uint _r = _t->rgba((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 76: { int _r = _t->saturation((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 77: { qreal _r = _t->saturationF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 78: _t->setAlpha((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 79: _t->setAlphaF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 80: _t->setBlue((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 81: _t->setBlueF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 82: _t->setCmyk((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 83: _t->setCmyk((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 84: _t->setCmykF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 85: _t->setCmykF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 86: _t->setGreen((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 87: _t->setGreenF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 88: _t->setHsl((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 89: _t->setHsl((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 90: _t->setHslF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 91: _t->setHslF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 92: _t->setHsv((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 93: _t->setHsv((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 94: _t->setHsvF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 95: _t->setHsvF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 96: _t->setNamedColor((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 97: _t->setRed((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 98: _t->setRedF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 99: _t->setRgb((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 100: _t->setRgb((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 101: _t->setRgb((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 102: _t->setRgbF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 103: _t->setRgbF((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 104: _t->setRgba((*reinterpret_cast< QColor*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 105: { QColor::Spec _r = _t->spec((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor::Spec*>(_a[0]) = _r; }  break;
        case 106: { QColor _r = _t->toCmyk((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 107: { QColor _r = _t->toHsl((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 108: { QColor _r = _t->toHsv((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 109: { QColor _r = _t->toRgb((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 110: { int _r = _t->value((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 111: { qreal _r = _t->valueF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 112: { int _r = _t->yellow((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 113: { qreal _r = _t->yellowF((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 114: { QString _r = _t->py_toString((*reinterpret_cast< QColor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QColor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QColor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QColor,
      qt_meta_data_PythonQtWrapper_QColor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QColor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QColor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QColor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QColor))
        return static_cast<void*>(const_cast< PythonQtWrapper_QColor*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QColor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 115)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 115;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QCursor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   24,   25,   24, 0x0a,
      54,   48,   25,   24, 0x0a,
     105,   83,   25,   24, 0x0a,
     159,  142,   25,   24, 0x2a,
     204,  192,   25,   24, 0x2a,
     240,  233,   25,   24, 0x0a,
     278,  261,   25,   24, 0x0a,
     319,  307,   25,   24, 0x2a,
     351,  344,   25,   24, 0x2a,
     376,  372,   24,   24, 0x0a,
     433,  416,  401,   24, 0x0a,
     457,  416,  450,   24, 0x0a,
     475,  416,  401,   24, 0x0a,
     512,  490,   24,   24, 0x0a,
     564,  543,   24,   24, 0x0a,
     604,  416,  596,   24, 0x0a,
     621,   24,  450,   24, 0x0a,
     644,  642,   24,   24, 0x0a,
     678,  674,   24,   24, 0x0a,
     735,  709,   24,   24, 0x0a,
     786,  416,  770,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QCursor[] = {
    "PythonQtWrapper_QCursor\0\0QCursor*\0"
    "new_QCursor()\0shape\0new_QCursor(Qt::CursorShape)\0"
    "bitmap,mask,hotX,hotY\0"
    "new_QCursor(QBitmap,QBitmap,int,int)\0"
    "bitmap,mask,hotX\0new_QCursor(QBitmap,QBitmap,int)\0"
    "bitmap,mask\0new_QCursor(QBitmap,QBitmap)\0"
    "cursor\0new_QCursor(QCursor)\0"
    "pixmap,hotX,hotY\0new_QCursor(QPixmap,int,int)\0"
    "pixmap,hotX\0new_QCursor(QPixmap,int)\0"
    "pixmap\0new_QCursor(QPixmap)\0obj\0"
    "delete_QCursor(QCursor*)\0const QBitmap*\0"
    "theWrappedObject\0bitmap(QCursor*)\0"
    "QPoint\0hotSpot(QCursor*)\0mask(QCursor*)\0"
    "theWrappedObject,outS\0"
    "writeTo(QCursor*,QDataStream&)\0"
    "theWrappedObject,inS\0"
    "readFrom(QCursor*,QDataStream&)\0QPixmap\0"
    "pixmap(QCursor*)\0static_QCursor_pos()\0"
    "p\0static_QCursor_setPos(QPoint)\0x,y\0"
    "static_QCursor_setPos(int,int)\0"
    "theWrappedObject,newShape\0"
    "setShape(QCursor*,Qt::CursorShape)\0"
    "Qt::CursorShape\0shape(QCursor*)\0"
};

void PythonQtWrapper_QCursor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QCursor *_t = static_cast<PythonQtWrapper_QCursor *>(_o);
        switch (_id) {
        case 0: { QCursor* _r = _t->new_QCursor();
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 1: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< Qt::CursorShape(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 2: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QBitmap(*)>(_a[1])),(*reinterpret_cast< const QBitmap(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 3: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QBitmap(*)>(_a[1])),(*reinterpret_cast< const QBitmap(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 4: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QBitmap(*)>(_a[1])),(*reinterpret_cast< const QBitmap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 5: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QCursor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 6: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 7: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 8: { QCursor* _r = _t->new_QCursor((*reinterpret_cast< const QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QCursor**>(_a[0]) = _r; }  break;
        case 9: _t->delete_QCursor((*reinterpret_cast< QCursor*(*)>(_a[1]))); break;
        case 10: { const QBitmap* _r = _t->bitmap((*reinterpret_cast< QCursor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBitmap**>(_a[0]) = _r; }  break;
        case 11: { QPoint _r = _t->hotSpot((*reinterpret_cast< QCursor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 12: { const QBitmap* _r = _t->mask((*reinterpret_cast< QCursor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBitmap**>(_a[0]) = _r; }  break;
        case 13: _t->writeTo((*reinterpret_cast< QCursor*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 14: _t->readFrom((*reinterpret_cast< QCursor*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 15: { QPixmap _r = _t->pixmap((*reinterpret_cast< QCursor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 16: { QPoint _r = _t->static_QCursor_pos();
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 17: _t->static_QCursor_setPos((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 18: _t->static_QCursor_setPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->setShape((*reinterpret_cast< QCursor*(*)>(_a[1])),(*reinterpret_cast< Qt::CursorShape(*)>(_a[2]))); break;
        case 20: { Qt::CursorShape _r = _t->shape((*reinterpret_cast< QCursor*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::CursorShape*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QCursor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QCursor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QCursor,
      qt_meta_data_PythonQtWrapper_QCursor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QCursor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QCursor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QCursor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QCursor))
        return static_cast<void*>(const_cast< PythonQtWrapper_QCursor*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QCursor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QFont[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      79,   14, // methods
       0,    0, // properties
       7,  409, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   22,   23,   22, 0x0a,
      49,   42,   23,   22, 0x0a,
      76,   66,   23,   22, 0x0a,
     138,  107,   23,   22, 0x0a,
     194,  170,   23,   22, 0x2a,
     238,  221,   23,   22, 0x2a,
     268,  261,   23,   22, 0x2a,
     291,  287,   22,   22, 0x0a,
     334,  317,  312,   22, 0x0a,
     347,   22,   22,   22, 0x0a,
     400,  317,  378,   22, 0x0a,
     423,   22,   22,   22, 0x0a,
     454,  317,  446,   22, 0x0a,
     476,  317,  312,   22, 0x0a,
     495,  317,  446,   22, 0x0a,
     510,  317,  312,   22, 0x0a,
     553,  529,  312,   22, 0x0a,
     591,  317,  580,   22, 0x0a,
     606,   22,   22,   22, 0x0a,
     646,  632,   22,   22, 0x0a,
     695,  632,   22,   22, 0x0a,
     749,  529,  312,   22, 0x0a,
     772,  317,  312,   22, 0x0a,
     787,  317,  312,   22, 0x0a,
     803,  317,  446,   22, 0x0a,
     815,  317,  446,   22, 0x0a,
     840,  317,  446,   22, 0x0a,
     869,  317,  863,   22, 0x0a,
     910,  317,  891,   22, 0x0a,
     936,  529,  312,   22, 0x0a,
     957,  529,  312,   22, 0x0a,
     978,  529,   22,   22, 0x0a,
    1007,  529,  312,   22, 0x0a,
    1028,  529,   22,   22, 0x0a,
    1058,  317,  312,   22, 0x0a,
    1079,  317, 1075,   22, 0x0a,
    1097,  317, 1075,   22, 0x0a,
    1115,  317,  863,   22, 0x0a,
    1134,  317,  312,   22, 0x0a,
    1150,  317,  446,   22, 0x0a,
    1166,   42,   22,   22, 0x0a,
    1212,  317, 1207,   22, 0x0a,
    1234,  529, 1228,   22, 0x0a,
    1278, 1256,   22,   22, 0x0a,
    1299,  529,   22,   22, 0x0a,
    1320,  529,   22,   22, 0x0a,
    1368,  529,   22,   22, 0x0a,
    1394,  529,   22,   22, 0x0a,
    1440, 1421,   22,   22, 0x0a,
    1463,  529,   22,   22, 0x0a,
    1517, 1487,   22,   22, 0x0a,
    1567,  529,   22,   22, 0x0a,
    1592,  529,   22,   22, 0x0a,
    1617,  529,   22,   22, 0x0a,
    1642,  529,   22,   22, 0x0a,
    1670,  529,   22,   22, 0x0a,
    1694,  529,   22,   22, 0x0a,
    1721,  529,   22,   22, 0x0a,
    1744,  529,   22,   22, 0x0a,
    1793, 1770,   22,   22, 0x0a,
    1854, 1823,   22,   22, 0x0a,
    1913,  529,   22,   22, 0x2a,
    1970, 1951,   22,   22, 0x0a,
    2016,  529,   22,   22, 0x0a,
    2042,  529,   22,   22, 0x0a,
    2089, 2064,   22,   22, 0x0a,
    2118,  317, 1075,   22, 0x0a,
    2134,  317,  312,   22, 0x0a,
    2165,  317, 2152,   22, 0x0a,
    2196,  317, 2179,   22, 0x0a,
    2235,  317, 2214,   22, 0x0a,
    2257,   42,  446,   22, 0x0a,
    2302,   42, 2290,   22, 0x0a,
    2336,   22, 2290,   22, 0x0a,
    2365,  317,  446,   22, 0x0a,
    2382,  317,  312,   22, 0x0a,
    2400,  317, 1075,   22, 0x0a,
    2415,  317,  863,   22, 0x0a,
    2435,   22,  446,   22, 0x0a,

 // enums: name, flags, count, data
    2455, 0x0,   11,  437,
    2469, 0x0,    2,  459,
    2481, 0x0,   10,  463,
    2491, 0x0,    5,  483,
    2498, 0x0,    5,  493,
    2513, 0x0,    9,  503,
    2521, 0x0,    3,  521,

 // enum data: key, value
    2527, uint(PythonQtWrapper_QFont::PreferDefault),
    2541, uint(PythonQtWrapper_QFont::PreferBitmap),
    2554, uint(PythonQtWrapper_QFont::PreferDevice),
    2567, uint(PythonQtWrapper_QFont::PreferOutline),
    2581, uint(PythonQtWrapper_QFont::ForceOutline),
    2594, uint(PythonQtWrapper_QFont::PreferMatch),
    2606, uint(PythonQtWrapper_QFont::PreferQuality),
    2620, uint(PythonQtWrapper_QFont::PreferAntialias),
    2636, uint(PythonQtWrapper_QFont::NoAntialias),
    2648, uint(PythonQtWrapper_QFont::OpenGLCompatible),
    2665, uint(PythonQtWrapper_QFont::NoFontMerging),
    2679, uint(PythonQtWrapper_QFont::PercentageSpacing),
    2697, uint(PythonQtWrapper_QFont::AbsoluteSpacing),
    2713, uint(PythonQtWrapper_QFont::Helvetica),
    2723, uint(PythonQtWrapper_QFont::SansSerif),
    2733, uint(PythonQtWrapper_QFont::Times),
    2739, uint(PythonQtWrapper_QFont::Serif),
    2745, uint(PythonQtWrapper_QFont::Courier),
    2753, uint(PythonQtWrapper_QFont::TypeWriter),
    2764, uint(PythonQtWrapper_QFont::OldEnglish),
    2775, uint(PythonQtWrapper_QFont::Decorative),
    2786, uint(PythonQtWrapper_QFont::System),
    2793, uint(PythonQtWrapper_QFont::AnyStyle),
    2802, uint(PythonQtWrapper_QFont::Light),
    2808, uint(PythonQtWrapper_QFont::Normal),
    2815, uint(PythonQtWrapper_QFont::DemiBold),
    2824, uint(PythonQtWrapper_QFont::Bold),
    2829, uint(PythonQtWrapper_QFont::Black),
    2835, uint(PythonQtWrapper_QFont::MixedCase),
    2845, uint(PythonQtWrapper_QFont::AllUppercase),
    2858, uint(PythonQtWrapper_QFont::AllLowercase),
    2871, uint(PythonQtWrapper_QFont::SmallCaps),
    2881, uint(PythonQtWrapper_QFont::Capitalize),
    2892, uint(PythonQtWrapper_QFont::UltraCondensed),
    2907, uint(PythonQtWrapper_QFont::ExtraCondensed),
    2922, uint(PythonQtWrapper_QFont::Condensed),
    2932, uint(PythonQtWrapper_QFont::SemiCondensed),
    2946, uint(PythonQtWrapper_QFont::Unstretched),
    2958, uint(PythonQtWrapper_QFont::SemiExpanded),
    2971, uint(PythonQtWrapper_QFont::Expanded),
    2980, uint(PythonQtWrapper_QFont::ExtraExpanded),
    2994, uint(PythonQtWrapper_QFont::UltraExpanded),
    3008, uint(PythonQtWrapper_QFont::StyleNormal),
    3020, uint(PythonQtWrapper_QFont::StyleItalic),
    3032, uint(PythonQtWrapper_QFont::StyleOblique),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QFont[] = {
    "PythonQtWrapper_QFont\0\0QFont*\0new_QFont()\0"
    "arg__1\0new_QFont(QFont)\0arg__1,pd\0"
    "new_QFont(QFont,QPaintDevice*)\0"
    "family,pointSize,weight,italic\0"
    "new_QFont(QString,int,int,bool)\0"
    "family,pointSize,weight\0"
    "new_QFont(QString,int,int)\0family,pointSize\0"
    "new_QFont(QString,int)\0family\0"
    "new_QFont(QString)\0obj\0delete_QFont(QFont*)\0"
    "bool\0theWrappedObject\0bold(QFont*)\0"
    "static_QFont_cacheStatistics()\0"
    "QFont::Capitalization\0capitalization(QFont*)\0"
    "static_QFont_cleanup()\0QString\0"
    "defaultFamily(QFont*)\0exactMatch(QFont*)\0"
    "family(QFont*)\0fixedPitch(QFont*)\0"
    "theWrappedObject,arg__1\0"
    "fromString(QFont*,QString)\0Qt::HANDLE\0"
    "handle(QFont*)\0static_QFont_initialize()\0"
    "arg__1,arg__2\0"
    "static_QFont_insertSubstitution(QString,QString)\0"
    "static_QFont_insertSubstitutions(QString,QStringList)\0"
    "isCopyOf(QFont*,QFont)\0italic(QFont*)\0"
    "kerning(QFont*)\0key(QFont*)\0"
    "lastResortFamily(QFont*)\0"
    "lastResortFont(QFont*)\0qreal\0"
    "letterSpacing(QFont*)\0QFont::SpacingType\0"
    "letterSpacingType(QFont*)\0"
    "__ne__(QFont*,QFont)\0__lt__(QFont*,QFont)\0"
    "writeTo(QFont*,QDataStream&)\0"
    "__eq__(QFont*,QFont)\0readFrom(QFont*,QDataStream&)\0"
    "overline(QFont*)\0int\0pixelSize(QFont*)\0"
    "pointSize(QFont*)\0pointSizeF(QFont*)\0"
    "rawMode(QFont*)\0rawName(QFont*)\0"
    "static_QFont_removeSubstitution(QString)\0"
    "uint\0resolve(QFont*)\0QFont\0"
    "resolve(QFont*,QFont)\0theWrappedObject,mask\0"
    "resolve(QFont*,uint)\0setBold(QFont*,bool)\0"
    "setCapitalization(QFont*,QFont::Capitalization)\0"
    "setFamily(QFont*,QString)\0"
    "setFixedPitch(QFont*,bool)\0"
    "theWrappedObject,b\0setItalic(QFont*,bool)\0"
    "setKerning(QFont*,bool)\0"
    "theWrappedObject,type,spacing\0"
    "setLetterSpacing(QFont*,QFont::SpacingType,qreal)\0"
    "setOverline(QFont*,bool)\0"
    "setPixelSize(QFont*,int)\0"
    "setPointSize(QFont*,int)\0"
    "setPointSizeF(QFont*,qreal)\0"
    "setRawMode(QFont*,bool)\0"
    "setRawName(QFont*,QString)\0"
    "setStretch(QFont*,int)\0setStrikeOut(QFont*,bool)\0"
    "theWrappedObject,style\0"
    "setStyle(QFont*,QFont::Style)\0"
    "theWrappedObject,arg__1,arg__2\0"
    "setStyleHint(QFont*,QFont::StyleHint,QFont::StyleStrategy)\0"
    "setStyleHint(QFont*,QFont::StyleHint)\0"
    "theWrappedObject,s\0"
    "setStyleStrategy(QFont*,QFont::StyleStrategy)\0"
    "setUnderline(QFont*,bool)\0"
    "setWeight(QFont*,int)\0theWrappedObject,spacing\0"
    "setWordSpacing(QFont*,qreal)\0"
    "stretch(QFont*)\0strikeOut(QFont*)\0"
    "QFont::Style\0style(QFont*)\0QFont::StyleHint\0"
    "styleHint(QFont*)\0QFont::StyleStrategy\0"
    "styleStrategy(QFont*)\0"
    "static_QFont_substitute(QString)\0"
    "QStringList\0static_QFont_substitutes(QString)\0"
    "static_QFont_substitutions()\0"
    "toString(QFont*)\0underline(QFont*)\0"
    "weight(QFont*)\0wordSpacing(QFont*)\0"
    "py_toString(QFont*)\0StyleStrategy\0"
    "SpacingType\0StyleHint\0Weight\0"
    "Capitalization\0Stretch\0Style\0PreferDefault\0"
    "PreferBitmap\0PreferDevice\0PreferOutline\0"
    "ForceOutline\0PreferMatch\0PreferQuality\0"
    "PreferAntialias\0NoAntialias\0"
    "OpenGLCompatible\0NoFontMerging\0"
    "PercentageSpacing\0AbsoluteSpacing\0"
    "Helvetica\0SansSerif\0Times\0Serif\0Courier\0"
    "TypeWriter\0OldEnglish\0Decorative\0"
    "System\0AnyStyle\0Light\0Normal\0DemiBold\0"
    "Bold\0Black\0MixedCase\0AllUppercase\0"
    "AllLowercase\0SmallCaps\0Capitalize\0"
    "UltraCondensed\0ExtraCondensed\0Condensed\0"
    "SemiCondensed\0Unstretched\0SemiExpanded\0"
    "Expanded\0ExtraExpanded\0UltraExpanded\0"
    "StyleNormal\0StyleItalic\0StyleOblique\0"
};

void PythonQtWrapper_QFont::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QFont *_t = static_cast<PythonQtWrapper_QFont *>(_o);
        switch (_id) {
        case 0: { QFont* _r = _t->new_QFont();
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 1: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QFont(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 2: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QFont(*)>(_a[1])),(*reinterpret_cast< QPaintDevice*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 3: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 4: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 5: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 6: { QFont* _r = _t->new_QFont((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont**>(_a[0]) = _r; }  break;
        case 7: _t->delete_QFont((*reinterpret_cast< QFont*(*)>(_a[1]))); break;
        case 8: { bool _r = _t->bold((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->static_QFont_cacheStatistics(); break;
        case 10: { QFont::Capitalization _r = _t->capitalization((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont::Capitalization*>(_a[0]) = _r; }  break;
        case 11: _t->static_QFont_cleanup(); break;
        case 12: { QString _r = _t->defaultFamily((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->exactMatch((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { QString _r = _t->family((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->fixedPitch((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->fromString((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { Qt::HANDLE _r = _t->handle((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::HANDLE*>(_a[0]) = _r; }  break;
        case 18: _t->static_QFont_initialize(); break;
        case 19: _t->static_QFont_insertSubstitution((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: _t->static_QFont_insertSubstitutions((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 21: { bool _r = _t->isCopyOf((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->italic((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->kerning((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { QString _r = _t->key((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: { QString _r = _t->lastResortFamily((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 26: { QString _r = _t->lastResortFont((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: { qreal _r = _t->letterSpacing((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 28: { QFont::SpacingType _r = _t->letterSpacingType((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont::SpacingType*>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->__ne__((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: { bool _r = _t->__lt__((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->writeTo((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 32: { bool _r = _t->__eq__((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 33: _t->readFrom((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 34: { bool _r = _t->overline((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 35: { int _r = _t->pixelSize((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 36: { int _r = _t->pointSize((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 37: { qreal _r = _t->pointSizeF((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 38: { bool _r = _t->rawMode((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 39: { QString _r = _t->rawName((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 40: _t->static_QFont_removeSubstitution((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: { uint _r = _t->resolve((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 42: { QFont _r = _t->resolve((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QFont*>(_a[0]) = _r; }  break;
        case 43: _t->resolve((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 44: _t->setBold((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 45: _t->setCapitalization((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::Capitalization(*)>(_a[2]))); break;
        case 46: _t->setFamily((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 47: _t->setFixedPitch((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 48: _t->setItalic((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 49: _t->setKerning((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 50: _t->setLetterSpacing((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::SpacingType(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 51: _t->setOverline((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 52: _t->setPixelSize((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 53: _t->setPointSize((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 54: _t->setPointSizeF((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 55: _t->setRawMode((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 56: _t->setRawName((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 57: _t->setStretch((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 58: _t->setStrikeOut((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 59: _t->setStyle((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::Style(*)>(_a[2]))); break;
        case 60: _t->setStyleHint((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::StyleHint(*)>(_a[2])),(*reinterpret_cast< QFont::StyleStrategy(*)>(_a[3]))); break;
        case 61: _t->setStyleHint((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::StyleHint(*)>(_a[2]))); break;
        case 62: _t->setStyleStrategy((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< QFont::StyleStrategy(*)>(_a[2]))); break;
        case 63: _t->setUnderline((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 64: _t->setWeight((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 65: _t->setWordSpacing((*reinterpret_cast< QFont*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 66: { int _r = _t->stretch((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 67: { bool _r = _t->strikeOut((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 68: { QFont::Style _r = _t->style((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont::Style*>(_a[0]) = _r; }  break;
        case 69: { QFont::StyleHint _r = _t->styleHint((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont::StyleHint*>(_a[0]) = _r; }  break;
        case 70: { QFont::StyleStrategy _r = _t->styleStrategy((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont::StyleStrategy*>(_a[0]) = _r; }  break;
        case 71: { QString _r = _t->static_QFont_substitute((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 72: { QStringList _r = _t->static_QFont_substitutes((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 73: { QStringList _r = _t->static_QFont_substitutions();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 74: { QString _r = _t->toString((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 75: { bool _r = _t->underline((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 76: { int _r = _t->weight((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 77: { qreal _r = _t->wordSpacing((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 78: { QString _r = _t->py_toString((*reinterpret_cast< QFont*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QFont::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QFont::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QFont,
      qt_meta_data_PythonQtWrapper_QFont, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QFont::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QFont::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QFont::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QFont))
        return static_cast<void*>(const_cast< PythonQtWrapper_QFont*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QFont::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 79)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 79;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QIcon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       2,  259, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   22,   23,   22, 0x0a,
      49,   42,   23,   22, 0x0a,
      73,   42,   23,   22, 0x0a,
     105,   99,   23,   22, 0x0a,
     129,  122,   23,   22, 0x0a,
     157,  148,   23,   22, 0x0a,
     180,  176,   22,   22, 0x0a,
     240,  207,  201,   22, 0x0a,
     317,  290,  201,   22, 0x2a,
     376,  354,  201,   22, 0x2a,
     443,  401,   22,   22, 0x0a,
     534,  498,   22,   22, 0x2a,
     607,  576,   22,   22, 0x2a,
     663,  637,   22,   22, 0x2a,
     722,  687,   22,   22, 0x0a,
     802,  773,   22,   22, 0x2a,
     864,  840,   22,   22, 0x2a,
     931,  903,  890,   22, 0x0a,
    1001,  979,  890,   22, 0x2a,
    1053, 1036,  890,   22, 0x2a,
    1083, 1036, 1076,   22, 0x0a,
    1120, 1106, 1100,   22, 0x0a,
    1163, 1158, 1100,   22, 0x2a,
    1200, 1158, 1195,   22, 0x0a,
    1235, 1036, 1195,   22, 0x0a,
    1274, 1250,   22,   22, 0x0a,
    1303, 1250,   22,   22, 0x0a,
    1384, 1333,   22,   22, 0x0a,
    1498, 1453,   22,   22, 0x2a,
    1594, 1554,   22,   22, 0x2a,
    1668, 1638,   22,   22, 0x2a,
    1752, 1698,   22,   22, 0x0a,
    1879, 1831,   22,   22, 0x2a,
    1988, 1945,   22,   22, 0x2a,
    2075, 2042,   22,   22, 0x2a,
    2123,  207, 2115,   22, 0x0a,
    2169,  290, 2115,   22, 0x2a,
    2202,  354, 2115,   22, 0x2a,
    2258, 2223, 2115,   22, 0x0a,
    2331, 2302, 2115,   22, 0x2a,
    2386, 2362, 2115,   22, 0x2a,
    2437, 2405, 2115,   22, 0x0a,
    2511, 2485, 2115,   22, 0x2a,
    2567, 2546, 2115,   22, 0x2a,
    2595, 2590,   22,   22, 0x0a,
    2641, 2630,   22,   22, 0x0a,
    2695,   22, 2687,   22, 0x0a,
    2732,   22, 2720,   22, 0x0a,
    2764,  176, 1195,   22, 0x0a,

 // enums: name, flags, count, data
    2784, 0x0,    4,  267,
    2789, 0x0,    2,  275,

 // enum data: key, value
    2795, uint(PythonQtWrapper_QIcon::Normal),
    2802, uint(PythonQtWrapper_QIcon::Disabled),
    2811, uint(PythonQtWrapper_QIcon::Active),
    2818, uint(PythonQtWrapper_QIcon::Selected),
    2827, uint(PythonQtWrapper_QIcon::On),
    2830, uint(PythonQtWrapper_QIcon::Off),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QIcon[] = {
    "PythonQtWrapper_QIcon\0\0QIcon*\0new_QIcon()\0"
    "engine\0new_QIcon(QIconEngine*)\0"
    "new_QIcon(QIconEngineV2*)\0other\0"
    "new_QIcon(QIcon)\0pixmap\0new_QIcon(QPixmap)\0"
    "fileName\0new_QIcon(QString)\0obj\0"
    "delete_QIcon(QIcon*)\0QSize\0"
    "theWrappedObject,size,mode,state\0"
    "actualSize(QIcon*,QSize,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,size,mode\0"
    "actualSize(QIcon*,QSize,QIcon::Mode)\0"
    "theWrappedObject,size\0actualSize(QIcon*,QSize)\0"
    "theWrappedObject,fileName,size,mode,state\0"
    "addFile(QIcon*,QString,QSize,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,fileName,size,mode\0"
    "addFile(QIcon*,QString,QSize,QIcon::Mode)\0"
    "theWrappedObject,fileName,size\0"
    "addFile(QIcon*,QString,QSize)\0"
    "theWrappedObject,fileName\0"
    "addFile(QIcon*,QString)\0"
    "theWrappedObject,pixmap,mode,state\0"
    "addPixmap(QIcon*,QPixmap,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,pixmap,mode\0"
    "addPixmap(QIcon*,QPixmap,QIcon::Mode)\0"
    "theWrappedObject,pixmap\0"
    "addPixmap(QIcon*,QPixmap)\0QList<QSize>\0"
    "theWrappedObject,mode,state\0"
    "availableSizes(QIcon*,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,mode\0"
    "availableSizes(QIcon*,QIcon::Mode)\0"
    "theWrappedObject\0availableSizes(QIcon*)\0"
    "qint64\0cacheKey(QIcon*)\0QIcon\0"
    "name,fallback\0static_QIcon_fromTheme(QString,QIcon)\0"
    "name\0static_QIcon_fromTheme(QString)\0"
    "bool\0static_QIcon_hasThemeIcon(QString)\0"
    "isNull(QIcon*)\0theWrappedObject,arg__1\0"
    "writeTo(QIcon*,QDataStream&)\0"
    "readFrom(QIcon*,QDataStream&)\0"
    "theWrappedObject,painter,rect,alignment,mode,state\0"
    "paint(QIcon*,QPainter*,QRect,Qt::Alignment,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,painter,rect,alignment,mode\0"
    "paint(QIcon*,QPainter*,QRect,Qt::Alignment,QIcon::Mode)\0"
    "theWrappedObject,painter,rect,alignment\0"
    "paint(QIcon*,QPainter*,QRect,Qt::Alignment)\0"
    "theWrappedObject,painter,rect\0"
    "paint(QIcon*,QPainter*,QRect)\0"
    "theWrappedObject,painter,x,y,w,h,alignment,mode,state\0"
    "paint(QIcon*,QPainter*,int,int,int,int,Qt::Alignment,QIcon::Mode,QIcon"
    "::State)\0"
    "theWrappedObject,painter,x,y,w,h,alignment,mode\0"
    "paint(QIcon*,QPainter*,int,int,int,int,Qt::Alignment,QIcon::Mode)\0"
    "theWrappedObject,painter,x,y,w,h,alignment\0"
    "paint(QIcon*,QPainter*,int,int,int,int,Qt::Alignment)\0"
    "theWrappedObject,painter,x,y,w,h\0"
    "paint(QIcon*,QPainter*,int,int,int,int)\0"
    "QPixmap\0pixmap(QIcon*,QSize,QIcon::Mode,QIcon::State)\0"
    "pixmap(QIcon*,QSize,QIcon::Mode)\0"
    "pixmap(QIcon*,QSize)\0"
    "theWrappedObject,extent,mode,state\0"
    "pixmap(QIcon*,int,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,extent,mode\0"
    "pixmap(QIcon*,int,QIcon::Mode)\0"
    "theWrappedObject,extent\0pixmap(QIcon*,int)\0"
    "theWrappedObject,w,h,mode,state\0"
    "pixmap(QIcon*,int,int,QIcon::Mode,QIcon::State)\0"
    "theWrappedObject,w,h,mode\0"
    "pixmap(QIcon*,int,int,QIcon::Mode)\0"
    "theWrappedObject,w,h\0pixmap(QIcon*,int,int)\0"
    "path\0static_QIcon_setThemeName(QString)\0"
    "searchpath\0static_QIcon_setThemeSearchPaths(QStringList)\0"
    "QString\0static_QIcon_themeName()\0"
    "QStringList\0static_QIcon_themeSearchPaths()\0"
    "__nonzero__(QIcon*)\0Mode\0State\0Normal\0"
    "Disabled\0Active\0Selected\0On\0Off\0"
};

void PythonQtWrapper_QIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QIcon *_t = static_cast<PythonQtWrapper_QIcon *>(_o);
        switch (_id) {
        case 0: { QIcon* _r = _t->new_QIcon();
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 1: { QIcon* _r = _t->new_QIcon((*reinterpret_cast< QIconEngine*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 2: { QIcon* _r = _t->new_QIcon((*reinterpret_cast< QIconEngineV2*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 3: { QIcon* _r = _t->new_QIcon((*reinterpret_cast< const QIcon(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 4: { QIcon* _r = _t->new_QIcon((*reinterpret_cast< const QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 5: { QIcon* _r = _t->new_QIcon((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = _r; }  break;
        case 6: _t->delete_QIcon((*reinterpret_cast< QIcon*(*)>(_a[1]))); break;
        case 7: { QSize _r = _t->actualSize((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])),(*reinterpret_cast< QIcon::State(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 8: { QSize _r = _t->actualSize((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 9: { QSize _r = _t->actualSize((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 10: _t->addFile((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3])),(*reinterpret_cast< QIcon::Mode(*)>(_a[4])),(*reinterpret_cast< QIcon::State(*)>(_a[5]))); break;
        case 11: _t->addFile((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3])),(*reinterpret_cast< QIcon::Mode(*)>(_a[4]))); break;
        case 12: _t->addFile((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 13: _t->addFile((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: _t->addPixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])),(*reinterpret_cast< QIcon::State(*)>(_a[4]))); break;
        case 15: _t->addPixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3]))); break;
        case 16: _t->addPixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 17: { QList<QSize> _r = _t->availableSizes((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QIcon::Mode(*)>(_a[2])),(*reinterpret_cast< QIcon::State(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<QSize>*>(_a[0]) = _r; }  break;
        case 18: { QList<QSize> _r = _t->availableSizes((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QIcon::Mode(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QSize>*>(_a[0]) = _r; }  break;
        case 19: { QList<QSize> _r = _t->availableSizes((*reinterpret_cast< QIcon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QSize>*>(_a[0]) = _r; }  break;
        case 20: { qint64 _r = _t->cacheKey((*reinterpret_cast< QIcon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 21: { QIcon _r = _t->static_QIcon_fromTheme((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QIcon(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 22: { QIcon _r = _t->static_QIcon_fromTheme((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->static_QIcon_hasThemeIcon((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { bool _r = _t->isNull((*reinterpret_cast< QIcon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: _t->writeTo((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 26: _t->readFrom((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 27: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3])),(*reinterpret_cast< Qt::Alignment(*)>(_a[4])),(*reinterpret_cast< QIcon::Mode(*)>(_a[5])),(*reinterpret_cast< QIcon::State(*)>(_a[6]))); break;
        case 28: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3])),(*reinterpret_cast< Qt::Alignment(*)>(_a[4])),(*reinterpret_cast< QIcon::Mode(*)>(_a[5]))); break;
        case 29: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3])),(*reinterpret_cast< Qt::Alignment(*)>(_a[4]))); break;
        case 30: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3]))); break;
        case 31: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< Qt::Alignment(*)>(_a[7])),(*reinterpret_cast< QIcon::Mode(*)>(_a[8])),(*reinterpret_cast< QIcon::State(*)>(_a[9]))); break;
        case 32: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< Qt::Alignment(*)>(_a[7])),(*reinterpret_cast< QIcon::Mode(*)>(_a[8]))); break;
        case 33: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< Qt::Alignment(*)>(_a[7]))); break;
        case 34: _t->paint((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 35: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])),(*reinterpret_cast< QIcon::State(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 36: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 37: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 38: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])),(*reinterpret_cast< QIcon::State(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 39: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QIcon::Mode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 40: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 41: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QIcon::Mode(*)>(_a[4])),(*reinterpret_cast< QIcon::State(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 42: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QIcon::Mode(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 43: { QPixmap _r = _t->pixmap((*reinterpret_cast< QIcon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 44: _t->static_QIcon_setThemeName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->static_QIcon_setThemeSearchPaths((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 46: { QString _r = _t->static_QIcon_themeName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 47: { QStringList _r = _t->static_QIcon_themeSearchPaths();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 48: { bool _r = _t->__nonzero__((*reinterpret_cast< QIcon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QIcon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QIcon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QIcon,
      qt_meta_data_PythonQtWrapper_QIcon, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QIcon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QIcon))
        return static_cast<void*>(const_cast< PythonQtWrapper_QIcon*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QImage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
     105,   14, // methods
       0,    0, // properties
       2,  539, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   23,   24,   23, 0x0a,
      52,   45,   24,   23, 0x0a,
      83,   71,   24,   23, 0x0a,
     132,  116,   24,   23, 0x0a,
     173,  164,   24,   23, 0x2a,
     213,  193,   24,   23, 0x0a,
     252,  248,   23,   23, 0x0a,
     297,  280,  275,   23, 0x0a,
     321,  280,  314,   23, 0x0a,
     347,  280,  343,   23, 0x0a,
     366,  280,  343,   23, 0x0a,
     395,  280,  388,   23, 0x0a,
     437,  418,  413,   23, 0x0a,
     456,  280,  343,   23, 0x0a,
     490,  280,  476,   23, 0x0a,
     535,  510,  314,   23, 0x0a,
     619,  600,  314,   23, 0x2a,
     695,  659,  314,   23, 0x0a,
     804,  774,  314,   23, 0x2a,
     880,  858,  314,   23, 0x0a,
     900,  280,  314,   23, 0x2a,
     939,  914,  314,   23, 0x0a,
     992,  969,  314,   23, 0x0a,
    1042,  280,  314,   23, 0x2a,
    1094, 1067,  314,   23, 0x0a,
    1128,  280,  314,   23, 0x2a,
    1185, 1157,  314,   23, 0x0a,
    1255, 1232,  314,   23, 0x2a,
    1289,  280,  343,   23, 0x0a,
    1304,  280,  343,   23, 0x0a,
    1321,  280,  343,   23, 0x0a,
    1344,  280,  343,   23, 0x0a,
    1390, 1367,   23,   23, 0x0a,
    1424,  280, 1409,   23, 0x0a,
    1452, 1440,  314,   23, 0x0a,
    1504, 1499,  314,   23, 0x2a,
    1539,  280,  275,   23, 0x0a,
    1564,  280,  343,   23, 0x0a,
    1604, 1580,   23,   23, 0x0a,
    1645,  280,   23,   23, 0x2a,
    1667,  280,  275,   23, 0x0a,
    1688,  280,  275,   23, 0x0a,
    1735, 1704,  275,   23, 0x0a,
    1805, 1772,  275,   23, 0x0a,
    1865, 1839,  275,   23, 0x2a,
    1917, 1887,  275,   23, 0x0a,
    1984, 1962,  275,   23, 0x2a,
    2041, 2017,  343,   23, 0x0a,
    2130, 2089,  314,   23, 0x0a,
    2188, 2158,  314,   23, 0x2a,
    2211,  280,  314,   23, 0x2a,
    2229,  280,  343,   23, 0x0a,
    2247,  280,  343,   23, 0x0a,
    2273,  280, 2266,   23, 0x0a,
    2289, 1580,  275,   23, 0x0a,
    2312, 1580,   23,   23, 0x0a,
    2342, 1580,  275,   23, 0x0a,
    2365, 1580,   23,   23, 0x0a,
    2410,  280, 2396,   23, 0x0a,
    2451, 2431,  413,   23, 0x0a,
    2494, 2473,  413,   23, 0x0a,
    2517, 2431,  343,   23, 0x0a,
    2544, 2473,  343,   23, 0x0a,
    2578,  280, 2572,   23, 0x0a,
    2592,  280,  314,   23, 0x0a,
    2651, 2612,  275,   23, 0x0a,
    2692, 1704,  275,   23, 0x2a,
    2753, 2729,  275,   23, 0x2a,
    2819, 2778,  275,   23, 0x0a,
    2857, 1772,  275,   23, 0x2a,
    2891, 1839,  275,   23, 0x2a,
    2948, 2913,  314,   23, 0x0a,
    3043, 3013,  314,   23, 0x2a,
    3104, 3085,  314,   23, 0x2a,
    3163, 3126,  314,   23, 0x0a,
    3262, 3230,  314,   23, 0x2a,
    3327, 3306,  314,   23, 0x2a,
    3375, 3351,  314,   23, 0x0a,
    3445, 3426,  314,   23, 0x2a,
    3497, 3473,  314,   23, 0x0a,
    3566, 3547,  314,   23, 0x2a,
    3623, 3593,   23,   23, 0x0a,
    3676, 3655,   23,   23, 0x0a,
    3703, 1580,   23,   23, 0x0a,
    3730, 1580,   23,   23, 0x0a,
    3760, 1580,   23,   23, 0x0a,
    3790, 1580,   23,   23, 0x0a,
    3816, 1580,   23,   23, 0x0a,
    3875, 3842,   23,   23, 0x0a,
    3939, 3905,   23,   23, 0x0a,
    3997, 3970,   23,   23, 0x0a,
    4036,  280, 4030,   23, 0x0a,
    4079, 4058, 4050,   23, 0x0a,
    4101,  280, 4050,   23, 0x2a,
    4127,  280, 4115,   23, 0x0a,
    4174, 4145,  314,   23, 0x0a,
    4250, 4226,  314,   23, 0x2a,
    4279, 4145,  314,   23, 0x0a,
    4334, 4226,  314,   23, 0x2a,
    4385, 4374, 4366,   23, 0x0a,
    4438, 4374, 4427,   23, 0x0a,
    4483, 2431,  275,   23, 0x0a,
    4505, 2473,  275,   23, 0x0a,
    4528,  280,  343,   23, 0x0a,
    4543,  248,  275,   23, 0x0a,

 // enums: name, flags, count, data
    4564, 0x0,    2,  547,
    4575, 0x0,   17,  551,

 // enum data: key, value
    4582, uint(PythonQtWrapper_QImage::InvertRgb),
    4592, uint(PythonQtWrapper_QImage::InvertRgba),
    4603, uint(PythonQtWrapper_QImage::Format_Invalid),
    4618, uint(PythonQtWrapper_QImage::Format_Mono),
    4630, uint(PythonQtWrapper_QImage::Format_MonoLSB),
    4645, uint(PythonQtWrapper_QImage::Format_Indexed8),
    4661, uint(PythonQtWrapper_QImage::Format_RGB32),
    4674, uint(PythonQtWrapper_QImage::Format_ARGB32),
    4688, uint(PythonQtWrapper_QImage::Format_ARGB32_Premultiplied),
    4716, uint(PythonQtWrapper_QImage::Format_RGB16),
    4729, uint(PythonQtWrapper_QImage::Format_ARGB8565_Premultiplied),
    4759, uint(PythonQtWrapper_QImage::Format_RGB666),
    4773, uint(PythonQtWrapper_QImage::Format_ARGB6666_Premultiplied),
    4803, uint(PythonQtWrapper_QImage::Format_RGB555),
    4817, uint(PythonQtWrapper_QImage::Format_ARGB8555_Premultiplied),
    4847, uint(PythonQtWrapper_QImage::Format_RGB888),
    4861, uint(PythonQtWrapper_QImage::Format_RGB444),
    4875, uint(PythonQtWrapper_QImage::Format_ARGB4444_Premultiplied),
    4905, uint(PythonQtWrapper_QImage::NImageFormats),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QImage[] = {
    "PythonQtWrapper_QImage\0\0QImage*\0"
    "new_QImage()\0arg__1\0new_QImage(QImage)\0"
    "size,format\0new_QImage(QSize,QImage::Format)\0"
    "fileName,format\0new_QImage(QString,const char*)\0"
    "fileName\0new_QImage(QString)\0"
    "width,height,format\0"
    "new_QImage(int,int,QImage::Format)\0"
    "obj\0delete_QImage(QImage*)\0bool\0"
    "theWrappedObject\0allGray(QImage*)\0"
    "QImage\0alphaChannel(QImage*)\0int\0"
    "byteCount(QImage*)\0bytesPerLine(QImage*)\0"
    "qint64\0cacheKey(QImage*)\0uint\0"
    "theWrappedObject,i\0color(QImage*,int)\0"
    "colorCount(QImage*)\0QVector<uint>\0"
    "colorTable(QImage*)\0theWrappedObject,f,flags\0"
    "convertToFormat(QImage*,QImage::Format,Qt::ImageConversionFlags)\0"
    "theWrappedObject,f\0"
    "convertToFormat(QImage*,QImage::Format)\0"
    "theWrappedObject,f,colorTable,flags\0"
    "convertToFormat(QImage*,QImage::Format,QVector<uint>,Qt::ImageConversi"
    "onFlags)\0"
    "theWrappedObject,f,colorTable\0"
    "convertToFormat(QImage*,QImage::Format,QVector<uint>)\0"
    "theWrappedObject,rect\0copy(QImage*,QRect)\0"
    "copy(QImage*)\0theWrappedObject,x,y,w,h\0"
    "copy(QImage*,int,int,int,int)\0"
    "theWrappedObject,flags\0"
    "createAlphaMask(QImage*,Qt::ImageConversionFlags)\0"
    "createAlphaMask(QImage*)\0"
    "theWrappedObject,clipTight\0"
    "createHeuristicMask(QImage*,bool)\0"
    "createHeuristicMask(QImage*)\0"
    "theWrappedObject,color,mode\0"
    "createMaskFromColor(QImage*,uint,Qt::MaskMode)\0"
    "theWrappedObject,color\0"
    "createMaskFromColor(QImage*,uint)\0"
    "depth(QImage*)\0devType(QImage*)\0"
    "dotsPerMeterX(QImage*)\0dotsPerMeterY(QImage*)\0"
    "theWrappedObject,pixel\0fill(QImage*,uint)\0"
    "QImage::Format\0format(QImage*)\0"
    "data,format\0static_QImage_fromData(QByteArray,const char*)\0"
    "data\0static_QImage_fromData(QByteArray)\0"
    "hasAlphaChannel(QImage*)\0height(QImage*)\0"
    "theWrappedObject,arg__1\0"
    "invertPixels(QImage*,QImage::InvertMode)\0"
    "invertPixels(QImage*)\0isGrayscale(QImage*)\0"
    "isNull(QImage*)\0theWrappedObject,device,format\0"
    "load(QImage*,QIODevice*,const char*)\0"
    "theWrappedObject,fileName,format\0"
    "load(QImage*,QString,const char*)\0"
    "theWrappedObject,fileName\0"
    "load(QImage*,QString)\0"
    "theWrappedObject,data,aformat\0"
    "loadFromData(QImage*,QByteArray,const char*)\0"
    "theWrappedObject,data\0"
    "loadFromData(QImage*,QByteArray)\0"
    "theWrappedObject,metric\0"
    "metric(QImage*,QPaintDevice::PaintDeviceMetric)\0"
    "theWrappedObject,horizontally,vertically\0"
    "mirrored(QImage*,bool,bool)\0"
    "theWrappedObject,horizontally\0"
    "mirrored(QImage*,bool)\0mirrored(QImage*)\0"
    "numBytes(QImage*)\0numColors(QImage*)\0"
    "QPoint\0offset(QImage*)\0__ne__(QImage*,QImage)\0"
    "writeTo(QImage*,QDataStream&)\0"
    "__eq__(QImage*,QImage)\0"
    "readFrom(QImage*,QDataStream&)\0"
    "QPaintEngine*\0paintEngine(QImage*)\0"
    "theWrappedObject,pt\0pixel(QImage*,QPoint)\0"
    "theWrappedObject,x,y\0pixel(QImage*,int,int)\0"
    "pixelIndex(QImage*,QPoint)\0"
    "pixelIndex(QImage*,int,int)\0QRect\0"
    "rect(QImage*)\0rgbSwapped(QImage*)\0"
    "theWrappedObject,device,format,quality\0"
    "save(QImage*,QIODevice*,const char*,int)\0"
    "save(QImage*,QIODevice*,const char*)\0"
    "theWrappedObject,device\0"
    "save(QImage*,QIODevice*)\0"
    "theWrappedObject,fileName,format,quality\0"
    "save(QImage*,QString,const char*,int)\0"
    "save(QImage*,QString,const char*)\0"
    "save(QImage*,QString)\0"
    "theWrappedObject,s,aspectMode,mode\0"
    "scaled(QImage*,QSize,Qt::AspectRatioMode,Qt::TransformationMode)\0"
    "theWrappedObject,s,aspectMode\0"
    "scaled(QImage*,QSize,Qt::AspectRatioMode)\0"
    "theWrappedObject,s\0scaled(QImage*,QSize)\0"
    "theWrappedObject,w,h,aspectMode,mode\0"
    "scaled(QImage*,int,int,Qt::AspectRatioMode,Qt::TransformationMode)\0"
    "theWrappedObject,w,h,aspectMode\0"
    "scaled(QImage*,int,int,Qt::AspectRatioMode)\0"
    "theWrappedObject,w,h\0scaled(QImage*,int,int)\0"
    "theWrappedObject,h,mode\0"
    "scaledToHeight(QImage*,int,Qt::TransformationMode)\0"
    "theWrappedObject,h\0scaledToHeight(QImage*,int)\0"
    "theWrappedObject,w,mode\0"
    "scaledToWidth(QImage*,int,Qt::TransformationMode)\0"
    "theWrappedObject,w\0scaledToWidth(QImage*,int)\0"
    "theWrappedObject,alphaChannel\0"
    "setAlphaChannel(QImage*,QImage)\0"
    "theWrappedObject,i,c\0setColor(QImage*,int,uint)\0"
    "setColorCount(QImage*,int)\0"
    "setDotsPerMeterX(QImage*,int)\0"
    "setDotsPerMeterY(QImage*,int)\0"
    "setNumColors(QImage*,int)\0"
    "setOffset(QImage*,QPoint)\0"
    "theWrappedObject,pt,index_or_rgb\0"
    "setPixel(QImage*,QPoint,uint)\0"
    "theWrappedObject,x,y,index_or_rgb\0"
    "setPixel(QImage*,int,int,uint)\0"
    "theWrappedObject,key,value\0"
    "setText(QImage*,QString,QString)\0QSize\0"
    "size(QImage*)\0QString\0theWrappedObject,key\0"
    "text(QImage*,QString)\0text(QImage*)\0"
    "QStringList\0textKeys(QImage*)\0"
    "theWrappedObject,matrix,mode\0"
    "transformed(QImage*,QMatrix,Qt::TransformationMode)\0"
    "theWrappedObject,matrix\0"
    "transformed(QImage*,QMatrix)\0"
    "transformed(QImage*,QTransform,Qt::TransformationMode)\0"
    "transformed(QImage*,QTransform)\0QMatrix\0"
    "arg__1,w,h\0static_QImage_trueMatrix(QMatrix,int,int)\0"
    "QTransform\0static_QImage_trueMatrix(QTransform,int,int)\0"
    "valid(QImage*,QPoint)\0valid(QImage*,int,int)\0"
    "width(QImage*)\0__nonzero__(QImage*)\0"
    "InvertMode\0Format\0InvertRgb\0InvertRgba\0"
    "Format_Invalid\0Format_Mono\0Format_MonoLSB\0"
    "Format_Indexed8\0Format_RGB32\0Format_ARGB32\0"
    "Format_ARGB32_Premultiplied\0Format_RGB16\0"
    "Format_ARGB8565_Premultiplied\0"
    "Format_RGB666\0Format_ARGB6666_Premultiplied\0"
    "Format_RGB555\0Format_ARGB8555_Premultiplied\0"
    "Format_RGB888\0Format_RGB444\0"
    "Format_ARGB4444_Premultiplied\0"
    "NImageFormats\0"
};

void PythonQtWrapper_QImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QImage *_t = static_cast<PythonQtWrapper_QImage *>(_o);
        switch (_id) {
        case 0: { QImage* _r = _t->new_QImage();
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 1: { QImage* _r = _t->new_QImage((*reinterpret_cast< const QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 2: { QImage* _r = _t->new_QImage((*reinterpret_cast< const QSize(*)>(_a[1])),(*reinterpret_cast< QImage::Format(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 3: { QImage* _r = _t->new_QImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 4: { QImage* _r = _t->new_QImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 5: { QImage* _r = _t->new_QImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QImage::Format(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = _r; }  break;
        case 6: _t->delete_QImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 7: { bool _r = _t->allGray((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QImage _r = _t->alphaChannel((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->byteCount((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->bytesPerLine((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { qint64 _r = _t->cacheKey((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 12: { uint _r = _t->color((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->colorCount((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { QVector<uint> _r = _t->colorTable((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<uint>*>(_a[0]) = _r; }  break;
        case 15: { QImage _r = _t->convertToFormat((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QImage::Format(*)>(_a[2])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 16: { QImage _r = _t->convertToFormat((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QImage::Format(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 17: { QImage _r = _t->convertToFormat((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QImage::Format(*)>(_a[2])),(*reinterpret_cast< const QVector<uint>(*)>(_a[3])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 18: { QImage _r = _t->convertToFormat((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QImage::Format(*)>(_a[2])),(*reinterpret_cast< const QVector<uint>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 19: { QImage _r = _t->copy((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 20: { QImage _r = _t->copy((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 21: { QImage _r = _t->copy((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 22: { QImage _r = _t->createAlphaMask((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 23: { QImage _r = _t->createAlphaMask((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 24: { QImage _r = _t->createHeuristicMask((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 25: { QImage _r = _t->createHeuristicMask((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 26: { QImage _r = _t->createMaskFromColor((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< Qt::MaskMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 27: { QImage _r = _t->createMaskFromColor((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->depth((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { int _r = _t->devType((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 30: { int _r = _t->dotsPerMeterX((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 31: { int _r = _t->dotsPerMeterY((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 32: _t->fill((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 33: { QImage::Format _r = _t->format((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage::Format*>(_a[0]) = _r; }  break;
        case 34: { QImage _r = _t->static_QImage_fromData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 35: { QImage _r = _t->static_QImage_fromData((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 36: { bool _r = _t->hasAlphaChannel((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 37: { int _r = _t->height((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 38: _t->invertPixels((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QImage::InvertMode(*)>(_a[2]))); break;
        case 39: _t->invertPixels((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 40: { bool _r = _t->isGrayscale((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 41: { bool _r = _t->isNull((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 42: { bool _r = _t->load((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 43: { bool _r = _t->load((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 44: { bool _r = _t->load((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 45: { bool _r = _t->loadFromData((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 46: { bool _r = _t->loadFromData((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 47: { int _r = _t->metric((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QPaintDevice::PaintDeviceMetric(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 48: { QImage _r = _t->mirrored((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 49: { QImage _r = _t->mirrored((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 50: { QImage _r = _t->mirrored((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 51: { int _r = _t->numBytes((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 52: { int _r = _t->numColors((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 53: { QPoint _r = _t->offset((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 54: { bool _r = _t->__ne__((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 55: _t->writeTo((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 56: { bool _r = _t->__eq__((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 57: _t->readFrom((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 58: { QPaintEngine* _r = _t->paintEngine((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPaintEngine**>(_a[0]) = _r; }  break;
        case 59: { uint _r = _t->pixel((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 60: { uint _r = _t->pixel((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 61: { int _r = _t->pixelIndex((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 62: { int _r = _t->pixelIndex((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 63: { QRect _r = _t->rect((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = _r; }  break;
        case 64: { QImage _r = _t->rgbSwapped((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 65: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 66: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 67: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 68: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 69: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 70: { bool _r = _t->save((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 71: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[3])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 72: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 73: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 74: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[4])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 75: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 76: { QImage _r = _t->scaled((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 77: { QImage _r = _t->scaledToHeight((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 78: { QImage _r = _t->scaledToHeight((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 79: { QImage _r = _t->scaledToWidth((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 80: { QImage _r = _t->scaledToWidth((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 81: _t->setAlphaChannel((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 82: _t->setColor((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 83: _t->setColorCount((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 84: _t->setDotsPerMeterX((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 85: _t->setDotsPerMeterY((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 86: _t->setNumColors((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 87: _t->setOffset((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 88: _t->setPixel((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 89: _t->setPixel((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 90: _t->setText((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 91: { QSize _r = _t->size((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 92: { QString _r = _t->text((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 93: { QString _r = _t->text((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 94: { QStringList _r = _t->textKeys((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 95: { QImage _r = _t->transformed((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 96: { QImage _r = _t->transformed((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 97: { QImage _r = _t->transformed((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 98: { QImage _r = _t->transformed((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 99: { QMatrix _r = _t->static_QImage_trueMatrix((*reinterpret_cast< const QMatrix(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMatrix*>(_a[0]) = _r; }  break;
        case 100: { QTransform _r = _t->static_QImage_trueMatrix((*reinterpret_cast< const QTransform(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QTransform*>(_a[0]) = _r; }  break;
        case 101: { bool _r = _t->valid((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 102: { bool _r = _t->valid((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 103: { int _r = _t->width((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 104: { bool _r = _t->__nonzero__((*reinterpret_cast< QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QImage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QImage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QImage,
      qt_meta_data_PythonQtWrapper_QImage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QImage))
        return static_cast<void*>(const_cast< PythonQtWrapper_QImage*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 105)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 105;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QKeySequence[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       3,  159, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      44,   29,   30,   29, 0x0a,
      67,   63,   30,   29, 0x0a,
     114,  111,   30,   29, 0x0a,
     145,   63,   30,   29, 0x0a,
     183,  171,   30,   29, 0x0a,
     226,  217,   30,   29, 0x2a,
     262,  256,   30,   29, 0x2a,
     291,  288,   30,   29, 0x2a,
     317,  313,   29,   29, 0x0a,
     374,  357,  352,   29, 0x0a,
     419,  408,  395,   29, 0x0a,
     492,  488,  395,   29, 0x2a,
     537,  357,  532,   29, 0x0a,
     580,   63,  560,   29, 0x0a,
     688,  667,  639,   29, 0x0a,
     729,  724,  395,   29, 0x0a,
     771,  357,  767,   29, 0x0a,
     827,  804,  532,   29, 0x0a,
     882,  862,  532,   29, 0x0a,
     937,  917,   29,   29, 0x0a,
     973,  804,  532,   29, 0x0a,
    1008,  804,  532,   29, 0x0a,
    1043,  804,  532,   29, 0x0a,
    1078,  804,  532,   29, 0x0a,
    1134, 1113,   29,   29, 0x0a,
    1190, 1171,  767,   29, 0x0a,
    1261, 1237, 1229,   29, 0x0a,
    1314,  357, 1229,   29, 0x2a,
    1338,   29, 1229,   29, 0x0a,

 // enums: name, flags, count, data
    1365, 0x0,    2,  171,
    1380, 0x0,   66,  175,
    1392, 0x0,    3,  307,

 // enum data: key, value
    1406, uint(PythonQtWrapper_QKeySequence::NativeText),
    1417, uint(PythonQtWrapper_QKeySequence::PortableText),
    1430, uint(PythonQtWrapper_QKeySequence::UnknownKey),
    1441, uint(PythonQtWrapper_QKeySequence::HelpContents),
    1454, uint(PythonQtWrapper_QKeySequence::WhatsThis),
    1464, uint(PythonQtWrapper_QKeySequence::Open),
    1469, uint(PythonQtWrapper_QKeySequence::Close),
    1475, uint(PythonQtWrapper_QKeySequence::Save),
    1480, uint(PythonQtWrapper_QKeySequence::New),
    1484, uint(PythonQtWrapper_QKeySequence::Delete),
    1491, uint(PythonQtWrapper_QKeySequence::Cut),
    1495, uint(PythonQtWrapper_QKeySequence::Copy),
    1500, uint(PythonQtWrapper_QKeySequence::Paste),
    1506, uint(PythonQtWrapper_QKeySequence::Undo),
    1511, uint(PythonQtWrapper_QKeySequence::Redo),
    1516, uint(PythonQtWrapper_QKeySequence::Back),
    1521, uint(PythonQtWrapper_QKeySequence::Forward),
    1529, uint(PythonQtWrapper_QKeySequence::Refresh),
    1537, uint(PythonQtWrapper_QKeySequence::ZoomIn),
    1544, uint(PythonQtWrapper_QKeySequence::ZoomOut),
    1552, uint(PythonQtWrapper_QKeySequence::Print),
    1558, uint(PythonQtWrapper_QKeySequence::AddTab),
    1565, uint(PythonQtWrapper_QKeySequence::NextChild),
    1575, uint(PythonQtWrapper_QKeySequence::PreviousChild),
    1589, uint(PythonQtWrapper_QKeySequence::Find),
    1594, uint(PythonQtWrapper_QKeySequence::FindNext),
    1603, uint(PythonQtWrapper_QKeySequence::FindPrevious),
    1616, uint(PythonQtWrapper_QKeySequence::Replace),
    1624, uint(PythonQtWrapper_QKeySequence::SelectAll),
    1634, uint(PythonQtWrapper_QKeySequence::Bold),
    1639, uint(PythonQtWrapper_QKeySequence::Italic),
    1646, uint(PythonQtWrapper_QKeySequence::Underline),
    1656, uint(PythonQtWrapper_QKeySequence::MoveToNextChar),
    1671, uint(PythonQtWrapper_QKeySequence::MoveToPreviousChar),
    1690, uint(PythonQtWrapper_QKeySequence::MoveToNextWord),
    1705, uint(PythonQtWrapper_QKeySequence::MoveToPreviousWord),
    1724, uint(PythonQtWrapper_QKeySequence::MoveToNextLine),
    1739, uint(PythonQtWrapper_QKeySequence::MoveToPreviousLine),
    1758, uint(PythonQtWrapper_QKeySequence::MoveToNextPage),
    1773, uint(PythonQtWrapper_QKeySequence::MoveToPreviousPage),
    1792, uint(PythonQtWrapper_QKeySequence::MoveToStartOfLine),
    1810, uint(PythonQtWrapper_QKeySequence::MoveToEndOfLine),
    1826, uint(PythonQtWrapper_QKeySequence::MoveToStartOfBlock),
    1845, uint(PythonQtWrapper_QKeySequence::MoveToEndOfBlock),
    1862, uint(PythonQtWrapper_QKeySequence::MoveToStartOfDocument),
    1884, uint(PythonQtWrapper_QKeySequence::MoveToEndOfDocument),
    1904, uint(PythonQtWrapper_QKeySequence::SelectNextChar),
    1919, uint(PythonQtWrapper_QKeySequence::SelectPreviousChar),
    1938, uint(PythonQtWrapper_QKeySequence::SelectNextWord),
    1953, uint(PythonQtWrapper_QKeySequence::SelectPreviousWord),
    1972, uint(PythonQtWrapper_QKeySequence::SelectNextLine),
    1987, uint(PythonQtWrapper_QKeySequence::SelectPreviousLine),
    2006, uint(PythonQtWrapper_QKeySequence::SelectNextPage),
    2021, uint(PythonQtWrapper_QKeySequence::SelectPreviousPage),
    2040, uint(PythonQtWrapper_QKeySequence::SelectStartOfLine),
    2058, uint(PythonQtWrapper_QKeySequence::SelectEndOfLine),
    2074, uint(PythonQtWrapper_QKeySequence::SelectStartOfBlock),
    2093, uint(PythonQtWrapper_QKeySequence::SelectEndOfBlock),
    2110, uint(PythonQtWrapper_QKeySequence::SelectStartOfDocument),
    2132, uint(PythonQtWrapper_QKeySequence::SelectEndOfDocument),
    2152, uint(PythonQtWrapper_QKeySequence::DeleteStartOfWord),
    2170, uint(PythonQtWrapper_QKeySequence::DeleteEndOfWord),
    2186, uint(PythonQtWrapper_QKeySequence::DeleteEndOfLine),
    2202, uint(PythonQtWrapper_QKeySequence::InsertParagraphSeparator),
    2227, uint(PythonQtWrapper_QKeySequence::InsertLineSeparator),
    2247, uint(PythonQtWrapper_QKeySequence::SaveAs),
    2254, uint(PythonQtWrapper_QKeySequence::Preferences),
    2266, uint(PythonQtWrapper_QKeySequence::Quit),
    2271, uint(PythonQtWrapper_QKeySequence::NoMatch),
    2279, uint(PythonQtWrapper_QKeySequence::PartialMatch),
    2292, uint(PythonQtWrapper_QKeySequence::ExactMatch),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QKeySequence[] = {
    "PythonQtWrapper_QKeySequence\0\0"
    "QKeySequence*\0new_QKeySequence()\0key\0"
    "new_QKeySequence(QKeySequence::StandardKey)\0"
    "ks\0new_QKeySequence(QKeySequence)\0"
    "new_QKeySequence(QString)\0k1,k2,k3,k4\0"
    "new_QKeySequence(int,int,int,int)\0"
    "k1,k2,k3\0new_QKeySequence(int,int,int)\0"
    "k1,k2\0new_QKeySequence(int,int)\0k1\0"
    "new_QKeySequence(int)\0obj\0"
    "delete_QKeySequence(QKeySequence*)\0"
    "uint\0theWrappedObject\0count(QKeySequence*)\0"
    "QKeySequence\0str,format\0"
    "static_QKeySequence_fromString(QString,QKeySequence::SequenceFormat)\0"
    "str\0static_QKeySequence_fromString(QString)\0"
    "bool\0isEmpty(QKeySequence*)\0"
    "QList<QKeySequence>\0"
    "static_QKeySequence_keyBindings(QKeySequence::StandardKey)\0"
    "QKeySequence::SequenceMatch\0"
    "theWrappedObject,seq\0"
    "matches(QKeySequence*,QKeySequence)\0"
    "text\0static_QKeySequence_mnemonic(QString)\0"
    "int\0operator_cast_int(QKeySequence*)\0"
    "theWrappedObject,other\0"
    "__ne__(QKeySequence*,QKeySequence)\0"
    "theWrappedObject,ks\0"
    "__lt__(QKeySequence*,QKeySequence)\0"
    "theWrappedObject,in\0"
    "writeTo(QKeySequence*,QDataStream&)\0"
    "__le__(QKeySequence*,QKeySequence)\0"
    "__eq__(QKeySequence*,QKeySequence)\0"
    "__gt__(QKeySequence*,QKeySequence)\0"
    "__ge__(QKeySequence*,QKeySequence)\0"
    "theWrappedObject,out\0"
    "readFrom(QKeySequence*,QDataStream&)\0"
    "theWrappedObject,i\0"
    "operator_subscript(QKeySequence*,uint)\0"
    "QString\0theWrappedObject,format\0"
    "toString(QKeySequence*,QKeySequence::SequenceFormat)\0"
    "toString(QKeySequence*)\0"
    "py_toString(QKeySequence*)\0SequenceFormat\0"
    "StandardKey\0SequenceMatch\0NativeText\0"
    "PortableText\0UnknownKey\0HelpContents\0"
    "WhatsThis\0Open\0Close\0Save\0New\0Delete\0"
    "Cut\0Copy\0Paste\0Undo\0Redo\0Back\0Forward\0"
    "Refresh\0ZoomIn\0ZoomOut\0Print\0AddTab\0"
    "NextChild\0PreviousChild\0Find\0FindNext\0"
    "FindPrevious\0Replace\0SelectAll\0Bold\0"
    "Italic\0Underline\0MoveToNextChar\0"
    "MoveToPreviousChar\0MoveToNextWord\0"
    "MoveToPreviousWord\0MoveToNextLine\0"
    "MoveToPreviousLine\0MoveToNextPage\0"
    "MoveToPreviousPage\0MoveToStartOfLine\0"
    "MoveToEndOfLine\0MoveToStartOfBlock\0"
    "MoveToEndOfBlock\0MoveToStartOfDocument\0"
    "MoveToEndOfDocument\0SelectNextChar\0"
    "SelectPreviousChar\0SelectNextWord\0"
    "SelectPreviousWord\0SelectNextLine\0"
    "SelectPreviousLine\0SelectNextPage\0"
    "SelectPreviousPage\0SelectStartOfLine\0"
    "SelectEndOfLine\0SelectStartOfBlock\0"
    "SelectEndOfBlock\0SelectStartOfDocument\0"
    "SelectEndOfDocument\0DeleteStartOfWord\0"
    "DeleteEndOfWord\0DeleteEndOfLine\0"
    "InsertParagraphSeparator\0InsertLineSeparator\0"
    "SaveAs\0Preferences\0Quit\0NoMatch\0"
    "PartialMatch\0ExactMatch\0"
};

void PythonQtWrapper_QKeySequence::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QKeySequence *_t = static_cast<PythonQtWrapper_QKeySequence *>(_o);
        switch (_id) {
        case 0: { QKeySequence* _r = _t->new_QKeySequence();
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 1: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< QKeySequence::StandardKey(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 2: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< const QKeySequence(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 3: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 4: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 5: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 6: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 7: { QKeySequence* _r = _t->new_QKeySequence((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence**>(_a[0]) = _r; }  break;
        case 8: _t->delete_QKeySequence((*reinterpret_cast< QKeySequence*(*)>(_a[1]))); break;
        case 9: { uint _r = _t->count((*reinterpret_cast< QKeySequence*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 10: { QKeySequence _r = _t->static_QKeySequence_fromString((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeySequence::SequenceFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QKeySequence*>(_a[0]) = _r; }  break;
        case 11: { QKeySequence _r = _t->static_QKeySequence_fromString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->isEmpty((*reinterpret_cast< QKeySequence*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { QList<QKeySequence> _r = _t->static_QKeySequence_keyBindings((*reinterpret_cast< QKeySequence::StandardKey(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QKeySequence>*>(_a[0]) = _r; }  break;
        case 14: { QKeySequence::SequenceMatch _r = _t->matches((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QKeySequence::SequenceMatch*>(_a[0]) = _r; }  break;
        case 15: { QKeySequence _r = _t->static_QKeySequence_mnemonic((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeySequence*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->operator_cast_int((*reinterpret_cast< QKeySequence*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->__ne__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->__lt__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: _t->writeTo((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 20: { bool _r = _t->__le__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: { bool _r = _t->__eq__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->__gt__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->__ge__((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: _t->readFrom((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 25: { int _r = _t->operator_subscript((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: { QString _r = _t->toString((*reinterpret_cast< QKeySequence*(*)>(_a[1])),(*reinterpret_cast< QKeySequence::SequenceFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: { QString _r = _t->toString((*reinterpret_cast< QKeySequence*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: { QString _r = _t->py_toString((*reinterpret_cast< QKeySequence*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QKeySequence::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QKeySequence::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QKeySequence,
      qt_meta_data_PythonQtWrapper_QKeySequence, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QKeySequence::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QKeySequence::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QKeySequence::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QKeySequence))
        return static_cast<void*>(const_cast< PythonQtWrapper_QKeySequence*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QKeySequence::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QMatrix[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   24,   25,   24, 0x0a,
      55,   48,   25,   24, 0x0a,
      98,   76,   25,   24, 0x0a,
     151,  147,   24,   24, 0x0a,
     199,  182,  176,   24, 0x0a,
     213,  182,  176,   24, 0x0a,
     235,  182,  176,   24, 0x0a,
     248,  182,  176,   24, 0x0a,
     297,  269,  261,   24, 0x0a,
     322,  182,  261,   24, 0x2a,
     346,  182,  341,   24, 0x0a,
     367,  182,  341,   24, 0x0a,
     390,  182,  176,   24, 0x0a,
     404,  182,  176,   24, 0x0a,
     418,  182,  176,   24, 0x0a,
     432,  182,  176,   24, 0x0a,
     471,  452,  446,   24, 0x0a,
     498,  452,  491,   24, 0x0a,
     551,  532,  519,   24, 0x0a,
     585,  532,  578,   24, 0x0a,
     614,  532,  606,   24, 0x0a,
     664,  645,  636,   24, 0x0a,
     697,  645,  687,   24, 0x0a,
     748,  729,  721,   24, 0x0a,
     797,  770,   24,   24, 0x0a,
     867,  843,  837,   24, 0x0a,
     898,  843,  891,   24, 0x0a,
     923,  729,  636,   24, 0x0a,
     952,  843,  341,   24, 0x0a,
     996,  977,  261,   24, 0x0a,
    1022,  843,   25,   24, 0x0a,
    1049,  843,   24,   24, 0x0a,
    1080,  843,  341,   24, 0x0a,
    1105,  843,   24,   24, 0x0a,
    1137,  182,   24,   24, 0x0a,
    1153,  645,   25,   24, 0x0a,
    1199, 1176,   25,   24, 0x0a,
    1266, 1227,   24,   24, 0x0a,
    1345, 1322,   25,   24, 0x0a,
    1396, 1373,   25,   24, 0x0a,
    1436,   24, 1428,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QMatrix[] = {
    "PythonQtWrapper_QMatrix\0\0QMatrix*\0"
    "new_QMatrix()\0matrix\0new_QMatrix(QMatrix)\0"
    "m11,m12,m21,m22,dx,dy\0"
    "new_QMatrix(qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "obj\0delete_QMatrix(QMatrix*)\0qreal\0"
    "theWrappedObject\0det(QMatrix*)\0"
    "determinant(QMatrix*)\0dx(QMatrix*)\0"
    "dy(QMatrix*)\0QMatrix\0theWrappedObject,invertible\0"
    "inverted(QMatrix*,bool*)\0inverted(QMatrix*)\0"
    "bool\0isIdentity(QMatrix*)\0"
    "isInvertible(QMatrix*)\0m11(QMatrix*)\0"
    "m12(QMatrix*)\0m21(QMatrix*)\0m22(QMatrix*)\0"
    "QLine\0theWrappedObject,l\0map(QMatrix*,QLine)\0"
    "QLineF\0map(QMatrix*,QLineF)\0QPainterPath\0"
    "theWrappedObject,p\0map(QMatrix*,QPainterPath)\0"
    "QPoint\0map(QMatrix*,QPoint)\0QPointF\0"
    "map(QMatrix*,QPointF)\0QPolygon\0"
    "theWrappedObject,a\0map(QMatrix*,QPolygon)\0"
    "QPolygonF\0map(QMatrix*,QPolygonF)\0"
    "QRegion\0theWrappedObject,r\0"
    "map(QMatrix*,QRegion)\0theWrappedObject,x,y,tx,ty\0"
    "map(QMatrix*,qreal,qreal,qreal*,qreal*)\0"
    "QRect\0theWrappedObject,arg__1\0"
    "mapRect(QMatrix*,QRect)\0QRectF\0"
    "mapRect(QMatrix*,QRectF)\0"
    "mapToPolygon(QMatrix*,QRect)\0"
    "__ne__(QMatrix*,QMatrix)\0theWrappedObject,o\0"
    "__mul__(QMatrix*,QMatrix)\0"
    "__imul__(QMatrix*,QMatrix)\0"
    "writeTo(QMatrix*,QDataStream&)\0"
    "__eq__(QMatrix*,QMatrix)\0"
    "readFrom(QMatrix*,QDataStream&)\0"
    "reset(QMatrix*)\0rotate(QMatrix*,qreal)\0"
    "theWrappedObject,sx,sy\0"
    "scale(QMatrix*,qreal,qreal)\0"
    "theWrappedObject,m11,m12,m21,m22,dx,dy\0"
    "setMatrix(QMatrix*,qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "theWrappedObject,sh,sv\0"
    "shear(QMatrix*,qreal,qreal)\0"
    "theWrappedObject,dx,dy\0"
    "translate(QMatrix*,qreal,qreal)\0QString\0"
    "py_toString(QMatrix*)\0"
};

void PythonQtWrapper_QMatrix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QMatrix *_t = static_cast<PythonQtWrapper_QMatrix *>(_o);
        switch (_id) {
        case 0: { QMatrix* _r = _t->new_QMatrix();
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 1: { QMatrix* _r = _t->new_QMatrix((*reinterpret_cast< const QMatrix(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 2: { QMatrix* _r = _t->new_QMatrix((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 3: _t->delete_QMatrix((*reinterpret_cast< QMatrix*(*)>(_a[1]))); break;
        case 4: { qreal _r = _t->det((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 5: { qreal _r = _t->determinant((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 6: { qreal _r = _t->dx((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 7: { qreal _r = _t->dy((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 8: { QMatrix _r = _t->inverted((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMatrix*>(_a[0]) = _r; }  break;
        case 9: { QMatrix _r = _t->inverted((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMatrix*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->isIdentity((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->isInvertible((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { qreal _r = _t->m11((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 13: { qreal _r = _t->m12((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 14: { qreal _r = _t->m21((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 15: { qreal _r = _t->m22((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 16: { QLine _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QLine(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QLine*>(_a[0]) = _r; }  break;
        case 17: { QLineF _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QLineF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QLineF*>(_a[0]) = _r; }  break;
        case 18: { QPainterPath _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QPainterPath(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPainterPath*>(_a[0]) = _r; }  break;
        case 19: { QPoint _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 20: { QPointF _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = _r; }  break;
        case 21: { QPolygon _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QPolygon(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 22: { QPolygonF _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QPolygonF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygonF*>(_a[0]) = _r; }  break;
        case 23: { QRegion _r = _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 24: _t->map((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal*(*)>(_a[4])),(*reinterpret_cast< qreal*(*)>(_a[5]))); break;
        case 25: { QRect _r = _t->mapRect((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = _r; }  break;
        case 26: { QRectF _r = _t->mapRect((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QRectF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRectF*>(_a[0]) = _r; }  break;
        case 27: { QPolygon _r = _t->mapToPolygon((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 28: { bool _r = _t->__ne__((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: { QMatrix _r = _t->__mul__((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMatrix*>(_a[0]) = _r; }  break;
        case 30: { QMatrix* _r = _t->__imul__((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 31: _t->writeTo((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 32: { bool _r = _t->__eq__((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 33: _t->readFrom((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 34: _t->reset((*reinterpret_cast< QMatrix*(*)>(_a[1]))); break;
        case 35: { QMatrix* _r = _t->rotate((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 36: { QMatrix* _r = _t->scale((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 37: _t->setMatrix((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< qreal(*)>(_a[7]))); break;
        case 38: { QMatrix* _r = _t->shear((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 39: { QMatrix* _r = _t->translate((*reinterpret_cast< QMatrix*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMatrix**>(_a[0]) = _r; }  break;
        case 40: { QString _r = _t->py_toString((*reinterpret_cast< QMatrix*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QMatrix::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QMatrix::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QMatrix,
      qt_meta_data_PythonQtWrapper_QMatrix, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QMatrix::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QMatrix))
        return static_cast<void*>(const_cast< PythonQtWrapper_QMatrix*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QPalette[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       2,  254, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   25,   26,   25, 0x0a,
      58,   51,   26,   25, 0x0a,
     150,   88,   26,   25, 0x0a,
     227,   51,   26,   25, 0x0a,
     262,  248,   26,   25, 0x0a,
     298,  290,   26,   25, 0x0a,
     325,  321,   25,   25, 0x0a,
     383,  366,  352,   25, 0x0a,
     408,  366,  352,   25, 0x0a,
     424,  366,  352,   25, 0x0a,
     469,  446,  352,   25, 0x0a,
     547,  527,  352,   25, 0x0a,
     584,  366,  352,   25, 0x0a,
     602,  366,  352,   25, 0x0a,
     631,  366,  624,   25, 0x0a,
     665,  446,  651,   25, 0x0a,
     723,  527,  651,   25, 0x0a,
     781,  366,  760,   25, 0x0a,
     810,  366,  352,   25, 0x0a,
     826,  366,  352,   25, 0x0a,
     847,  366,  352,   25, 0x0a,
     879,  446,  874,   25, 0x0a,
     961,  942,  874,   25, 0x0a,
    1015,  990,  874,   25, 0x0a,
    1076,  366,  352,   25, 0x0a,
    1093,  366,  352,   25, 0x0a,
    1109,  366,  352,   25, 0x0a,
    1132,  366,  352,   25, 0x0a,
    1147,  366,  352,   25, 0x0a,
    1167,  942,  874,   25, 0x0a,
    1214, 1194,   25,   25, 0x0a,
    1246,  942,  874,   25, 0x0a,
    1273, 1194,   25,   25, 0x0a,
    1311,  366, 1306,   25, 0x0a,
    1363, 1339, 1330,   25, 0x0a,
    1413, 1391,   25,   25, 0x0a,
    1466, 1437,   25,   25, 0x0a,
    1560, 1534,   25,   25, 0x0a,
    1636, 1607,   25,   25, 0x0a,
    1730, 1704,   25,   25, 0x0a,
    1859, 1777,   25,   25, 0x0a,
    1988, 1968,   25,   25, 0x0a,
    2041,  366,  352,   25, 0x0a,
    2059,  366,  352,   25, 0x0a,
    2075,  366,  352,   25, 0x0a,
    2098,  366,  352,   25, 0x0a,
    2121,  366,  352,   25, 0x0a,
    2139,  366,  352,   25, 0x0a,

 // enums: name, flags, count, data
    2161, 0x0,    7,  262,
    2172, 0x0,   23,  276,

 // enum data: key, value
    2182, uint(PythonQtWrapper_QPalette::Active),
    2189, uint(PythonQtWrapper_QPalette::Disabled),
    2198, uint(PythonQtWrapper_QPalette::Inactive),
    2207, uint(PythonQtWrapper_QPalette::NColorGroups),
    2220, uint(PythonQtWrapper_QPalette::Current),
    2228, uint(PythonQtWrapper_QPalette::All),
    2232, uint(PythonQtWrapper_QPalette::Normal),
    2239, uint(PythonQtWrapper_QPalette::WindowText),
    2250, uint(PythonQtWrapper_QPalette::Button),
    2257, uint(PythonQtWrapper_QPalette::Light),
    2263, uint(PythonQtWrapper_QPalette::Midlight),
    2272, uint(PythonQtWrapper_QPalette::Dark),
    2277, uint(PythonQtWrapper_QPalette::Mid),
    2281, uint(PythonQtWrapper_QPalette::Text),
    2286, uint(PythonQtWrapper_QPalette::BrightText),
    2297, uint(PythonQtWrapper_QPalette::ButtonText),
    2308, uint(PythonQtWrapper_QPalette::Base),
    2313, uint(PythonQtWrapper_QPalette::Window),
    2320, uint(PythonQtWrapper_QPalette::Shadow),
    2327, uint(PythonQtWrapper_QPalette::Highlight),
    2337, uint(PythonQtWrapper_QPalette::HighlightedText),
    2353, uint(PythonQtWrapper_QPalette::Link),
    2358, uint(PythonQtWrapper_QPalette::LinkVisited),
    2370, uint(PythonQtWrapper_QPalette::AlternateBase),
    2384, uint(PythonQtWrapper_QPalette::NoRole),
    2391, uint(PythonQtWrapper_QPalette::ToolTipBase),
    2403, uint(PythonQtWrapper_QPalette::ToolTipText),
    2415, uint(PythonQtWrapper_QPalette::NColorRoles),
    2427, uint(PythonQtWrapper_QPalette::Foreground),
    2438, uint(PythonQtWrapper_QPalette::Background),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QPalette[] = {
    "PythonQtWrapper_QPalette\0\0QPalette*\0"
    "new_QPalette()\0button\0"
    "new_QPalette(Qt::GlobalColor)\0"
    "windowText,button,light,dark,mid,text,bright_text,base,window\0"
    "new_QPalette(QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,Q"
    "Brush)\0"
    "new_QPalette(QColor)\0button,window\0"
    "new_QPalette(QColor,QColor)\0palette\0"
    "new_QPalette(QPalette)\0obj\0"
    "delete_QPalette(QPalette*)\0const QBrush*\0"
    "theWrappedObject\0alternateBase(QPalette*)\0"
    "base(QPalette*)\0brightText(QPalette*)\0"
    "theWrappedObject,cg,cr\0"
    "brush(QPalette*,QPalette::ColorGroup,QPalette::ColorRole)\0"
    "theWrappedObject,cr\0"
    "brush(QPalette*,QPalette::ColorRole)\0"
    "button(QPalette*)\0buttonText(QPalette*)\0"
    "qint64\0cacheKey(QPalette*)\0const QColor*\0"
    "color(QPalette*,QPalette::ColorGroup,QPalette::ColorRole)\0"
    "color(QPalette*,QPalette::ColorRole)\0"
    "QPalette::ColorGroup\0currentColorGroup(QPalette*)\0"
    "dark(QPalette*)\0highlight(QPalette*)\0"
    "highlightedText(QPalette*)\0bool\0"
    "isBrushSet(QPalette*,QPalette::ColorGroup,QPalette::ColorRole)\0"
    "theWrappedObject,p\0isCopyOf(QPalette*,QPalette)\0"
    "theWrappedObject,cr1,cr2\0"
    "isEqual(QPalette*,QPalette::ColorGroup,QPalette::ColorGroup)\0"
    "light(QPalette*)\0link(QPalette*)\0"
    "linkVisited(QPalette*)\0mid(QPalette*)\0"
    "midlight(QPalette*)\0__ne__(QPalette*,QPalette)\0"
    "theWrappedObject,ds\0writeTo(QPalette*,QDataStream&)\0"
    "__eq__(QPalette*,QPalette)\0"
    "readFrom(QPalette*,QDataStream&)\0uint\0"
    "resolve(QPalette*)\0QPalette\0"
    "theWrappedObject,arg__1\0"
    "resolve(QPalette*,QPalette)\0"
    "theWrappedObject,mask\0resolve(QPalette*,uint)\0"
    "theWrappedObject,cg,cr,brush\0"
    "setBrush(QPalette*,QPalette::ColorGroup,QPalette::ColorRole,QBrush)\0"
    "theWrappedObject,cr,brush\0"
    "setBrush(QPalette*,QPalette::ColorRole,QBrush)\0"
    "theWrappedObject,cg,cr,color\0"
    "setColor(QPalette*,QPalette::ColorGroup,QPalette::ColorRole,QColor)\0"
    "theWrappedObject,cr,color\0"
    "setColor(QPalette*,QPalette::ColorRole,QColor)\0"
    "theWrappedObject,cr,windowText,button,light,dark,mid,text,bright_text,"
    "base,window\0"
    "setColorGroup(QPalette*,QPalette::ColorGroup,QBrush,QBrush,QBrush,QBru"
    "sh,QBrush,QBrush,QBrush,QBrush,QBrush)\0"
    "theWrappedObject,cg\0"
    "setCurrentColorGroup(QPalette*,QPalette::ColorGroup)\0"
    "shadow(QPalette*)\0text(QPalette*)\0"
    "toolTipBase(QPalette*)\0toolTipText(QPalette*)\0"
    "window(QPalette*)\0windowText(QPalette*)\0"
    "ColorGroup\0ColorRole\0Active\0Disabled\0"
    "Inactive\0NColorGroups\0Current\0All\0"
    "Normal\0WindowText\0Button\0Light\0Midlight\0"
    "Dark\0Mid\0Text\0BrightText\0ButtonText\0"
    "Base\0Window\0Shadow\0Highlight\0"
    "HighlightedText\0Link\0LinkVisited\0"
    "AlternateBase\0NoRole\0ToolTipBase\0"
    "ToolTipText\0NColorRoles\0Foreground\0"
    "Background\0"
};

void PythonQtWrapper_QPalette::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QPalette *_t = static_cast<PythonQtWrapper_QPalette *>(_o);
        switch (_id) {
        case 0: { QPalette* _r = _t->new_QPalette();
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 1: { QPalette* _r = _t->new_QPalette((*reinterpret_cast< Qt::GlobalColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 2: { QPalette* _r = _t->new_QPalette((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2])),(*reinterpret_cast< const QBrush(*)>(_a[3])),(*reinterpret_cast< const QBrush(*)>(_a[4])),(*reinterpret_cast< const QBrush(*)>(_a[5])),(*reinterpret_cast< const QBrush(*)>(_a[6])),(*reinterpret_cast< const QBrush(*)>(_a[7])),(*reinterpret_cast< const QBrush(*)>(_a[8])),(*reinterpret_cast< const QBrush(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 3: { QPalette* _r = _t->new_QPalette((*reinterpret_cast< const QColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 4: { QPalette* _r = _t->new_QPalette((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 5: { QPalette* _r = _t->new_QPalette((*reinterpret_cast< const QPalette(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPalette**>(_a[0]) = _r; }  break;
        case 6: _t->delete_QPalette((*reinterpret_cast< QPalette*(*)>(_a[1]))); break;
        case 7: { const QBrush* _r = _t->alternateBase((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 8: { const QBrush* _r = _t->base((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 9: { const QBrush* _r = _t->brightText((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 10: { const QBrush* _r = _t->brush((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 11: { const QBrush* _r = _t->brush((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 12: { const QBrush* _r = _t->button((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 13: { const QBrush* _r = _t->buttonText((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 14: { qint64 _r = _t->cacheKey((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 15: { const QColor* _r = _t->color((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< const QColor**>(_a[0]) = _r; }  break;
        case 16: { const QColor* _r = _t->color((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< const QColor**>(_a[0]) = _r; }  break;
        case 17: { QPalette::ColorGroup _r = _t->currentColorGroup((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPalette::ColorGroup*>(_a[0]) = _r; }  break;
        case 18: { const QBrush* _r = _t->dark((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 19: { const QBrush* _r = _t->highlight((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 20: { const QBrush* _r = _t->highlightedText((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 21: { bool _r = _t->isBrushSet((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->isCopyOf((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< const QPalette(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->isEqual((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { const QBrush* _r = _t->light((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 25: { const QBrush* _r = _t->link((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 26: { const QBrush* _r = _t->linkVisited((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 27: { const QBrush* _r = _t->mid((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 28: { const QBrush* _r = _t->midlight((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->__ne__((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< const QPalette(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: _t->writeTo((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 31: { bool _r = _t->__eq__((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< const QPalette(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: _t->readFrom((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 33: { uint _r = _t->resolve((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 34: { QPalette _r = _t->resolve((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< const QPalette(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPalette*>(_a[0]) = _r; }  break;
        case 35: _t->resolve((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 36: _t->setBrush((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[3])),(*reinterpret_cast< const QBrush(*)>(_a[4]))); break;
        case 37: _t->setBrush((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[2])),(*reinterpret_cast< const QBrush(*)>(_a[3]))); break;
        case 38: _t->setColor((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4]))); break;
        case 39: _t->setColor((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorRole(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 40: _t->setColorGroup((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2])),(*reinterpret_cast< const QBrush(*)>(_a[3])),(*reinterpret_cast< const QBrush(*)>(_a[4])),(*reinterpret_cast< const QBrush(*)>(_a[5])),(*reinterpret_cast< const QBrush(*)>(_a[6])),(*reinterpret_cast< const QBrush(*)>(_a[7])),(*reinterpret_cast< const QBrush(*)>(_a[8])),(*reinterpret_cast< const QBrush(*)>(_a[9])),(*reinterpret_cast< const QBrush(*)>(_a[10])),(*reinterpret_cast< const QBrush(*)>(_a[11]))); break;
        case 41: _t->setCurrentColorGroup((*reinterpret_cast< QPalette*(*)>(_a[1])),(*reinterpret_cast< QPalette::ColorGroup(*)>(_a[2]))); break;
        case 42: { const QBrush* _r = _t->shadow((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 43: { const QBrush* _r = _t->text((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 44: { const QBrush* _r = _t->toolTipBase((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 45: { const QBrush* _r = _t->toolTipText((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 46: { const QBrush* _r = _t->window((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        case 47: { const QBrush* _r = _t->windowText((*reinterpret_cast< QPalette*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QBrush**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QPalette::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QPalette::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QPalette,
      qt_meta_data_PythonQtWrapper_QPalette, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QPalette::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QPalette::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QPalette::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QPalette))
        return static_cast<void*>(const_cast< PythonQtWrapper_QPalette*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QPalette::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QPen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   21,   22,   21, 0x0a,
      46,   39,   22,   21, 0x0a,
      87,   69,   22,   21, 0x0a,
     172,  156,   22,   21, 0x2a,
     238,  224,   22,   21, 0x2a,
     286,  274,   22,   21, 0x2a,
     315,  309,   22,   21, 0x0a,
     336,  332,   22,   21, 0x0a,
     355,  351,   21,   21, 0x0a,
     398,  381,  374,   21, 0x0a,
     427,  381,  411,   21, 0x0a,
     450,  381,  443,   21, 0x0a,
     469,  381,  463,   21, 0x0a,
     502,  381,  487,   21, 0x0a,
     526,  381,  521,   21, 0x0a,
     544,  381,  521,   21, 0x0a,
     576,  381,  559,   21, 0x0a,
     593,  381,  463,   21, 0x0a,
     630,  611,  521,   21, 0x0a,
     673,  649,   21,   21, 0x0a,
     701,  611,  521,   21, 0x0a,
     720,  649,   21,   21, 0x0a,
     772,  749,   21,   21, 0x0a,
     816,  795,   21,   21, 0x0a,
     874,  851,   21,   21, 0x0a,
     923,  897,   21,   21, 0x0a,
     972,  947,   21,   21, 0x0a,
    1024,  999,   21,   21, 0x0a,
    1061,  795,   21,   21, 0x0a,
    1121, 1098,   21,   21, 0x0a,
    1148,  649,   21,   21, 0x0a,
    1200, 1177,   21,   21, 0x0a,
    1220, 1177,   21,   21, 0x0a,
    1256,  381, 1243,   21, 0x0a,
    1273,  381, 1269,   21, 0x0a,
    1286,  381,  463,   21, 0x0a,
    1308,   21, 1300,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QPen[] = {
    "PythonQtWrapper_QPen\0\0QPen*\0new_QPen()\0"
    "arg__1\0new_QPen(Qt::PenStyle)\0"
    "brush,width,s,c,j\0"
    "new_QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)\0"
    "brush,width,s,c\0"
    "new_QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle)\0"
    "brush,width,s\0new_QPen(QBrush,qreal,Qt::PenStyle)\0"
    "brush,width\0new_QPen(QBrush,qreal)\0"
    "color\0new_QPen(QColor)\0pen\0new_QPen(QPen)\0"
    "obj\0delete_QPen(QPen*)\0QBrush\0"
    "theWrappedObject\0brush(QPen*)\0"
    "Qt::PenCapStyle\0capStyle(QPen*)\0QColor\0"
    "color(QPen*)\0qreal\0dashOffset(QPen*)\0"
    "QVector<qreal>\0dashPattern(QPen*)\0"
    "bool\0isCosmetic(QPen*)\0isSolid(QPen*)\0"
    "Qt::PenJoinStyle\0joinStyle(QPen*)\0"
    "miterLimit(QPen*)\0theWrappedObject,p\0"
    "__ne__(QPen*,QPen)\0theWrappedObject,arg__1\0"
    "writeTo(QPen*,QDataStream&)\0"
    "__eq__(QPen*,QPen)\0readFrom(QPen*,QDataStream&)\0"
    "theWrappedObject,brush\0setBrush(QPen*,QBrush)\0"
    "theWrappedObject,pcs\0"
    "setCapStyle(QPen*,Qt::PenCapStyle)\0"
    "theWrappedObject,color\0setColor(QPen*,QColor)\0"
    "theWrappedObject,cosmetic\0"
    "setCosmetic(QPen*,bool)\0"
    "theWrappedObject,doffset\0"
    "setDashOffset(QPen*,qreal)\0"
    "theWrappedObject,pattern\0"
    "setDashPattern(QPen*,QVector<qreal>)\0"
    "setJoinStyle(QPen*,Qt::PenJoinStyle)\0"
    "theWrappedObject,limit\0"
    "setMiterLimit(QPen*,qreal)\0"
    "setStyle(QPen*,Qt::PenStyle)\0"
    "theWrappedObject,width\0setWidth(QPen*,int)\0"
    "setWidthF(QPen*,qreal)\0Qt::PenStyle\0"
    "style(QPen*)\0int\0width(QPen*)\0"
    "widthF(QPen*)\0QString\0py_toString(QPen*)\0"
};

void PythonQtWrapper_QPen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QPen *_t = static_cast<PythonQtWrapper_QPen *>(_o);
        switch (_id) {
        case 0: { QPen* _r = _t->new_QPen();
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 1: { QPen* _r = _t->new_QPen((*reinterpret_cast< Qt::PenStyle(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 2: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[3])),(*reinterpret_cast< Qt::PenCapStyle(*)>(_a[4])),(*reinterpret_cast< Qt::PenJoinStyle(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 3: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[3])),(*reinterpret_cast< Qt::PenCapStyle(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 4: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 5: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 6: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 7: { QPen* _r = _t->new_QPen((*reinterpret_cast< const QPen(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPen**>(_a[0]) = _r; }  break;
        case 8: _t->delete_QPen((*reinterpret_cast< QPen*(*)>(_a[1]))); break;
        case 9: { QBrush _r = _t->brush((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
        case 10: { Qt::PenCapStyle _r = _t->capStyle((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::PenCapStyle*>(_a[0]) = _r; }  break;
        case 11: { QColor _r = _t->color((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 12: { qreal _r = _t->dashOffset((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 13: { QVector<qreal> _r = _t->dashPattern((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<qreal>*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->isCosmetic((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->isSolid((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { Qt::PenJoinStyle _r = _t->joinStyle((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::PenJoinStyle*>(_a[0]) = _r; }  break;
        case 17: { qreal _r = _t->miterLimit((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->__ne__((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< const QPen(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: _t->writeTo((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 20: { bool _r = _t->__eq__((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< const QPen(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: _t->readFrom((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 22: _t->setBrush((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2]))); break;
        case 23: _t->setCapStyle((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< Qt::PenCapStyle(*)>(_a[2]))); break;
        case 24: _t->setColor((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 25: _t->setCosmetic((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 26: _t->setDashOffset((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 27: _t->setDashPattern((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< const QVector<qreal>(*)>(_a[2]))); break;
        case 28: _t->setJoinStyle((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< Qt::PenJoinStyle(*)>(_a[2]))); break;
        case 29: _t->setMiterLimit((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 30: _t->setStyle((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[2]))); break;
        case 31: _t->setWidth((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->setWidthF((*reinterpret_cast< QPen*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 33: { Qt::PenStyle _r = _t->style((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::PenStyle*>(_a[0]) = _r; }  break;
        case 34: { int _r = _t->width((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 35: { qreal _r = _t->widthF((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 36: { QString _r = _t->py_toString((*reinterpret_cast< QPen*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QPen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QPen::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QPen,
      qt_meta_data_PythonQtWrapper_QPen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QPen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QPen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QPen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QPen))
        return static_cast<void*>(const_cast< PythonQtWrapper_QPen*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QPen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QPixmap[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      87,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   24,   25,   24, 0x0a,
      55,   48,   25,   24, 0x0a,
      76,   48,   25,   24, 0x0a,
     117,   95,   25,   24, 0x0a,
     191,  175,   25,   24, 0x2a,
     233,  224,   25,   24, 0x2a,
     258,  254,   25,   24, 0x0a,
     288,  284,   25,   24, 0x0a,
     313,  309,   24,   24, 0x0a,
     363,  346,  338,   24, 0x0a,
     393,  346,  386,   24, 0x0a,
     434,  412,  338,   24, 0x0a,
     455,  346,  338,   24, 0x2a,
     504,  470,  338,   24, 0x0a,
     570,  543,  535,   24, 0x0a,
     605,  346,  535,   24, 0x2a,
     662,  635,  535,   24, 0x0a,
     731,  699,  535,   24, 0x0a,
     785,   24,  781,   24, 0x0a,
     815,  346,  781,   24, 0x0a,
     831,  346,  781,   24, 0x0a,
     876,  849,   24,   24, 0x0a,
     898,  346,   24,   24, 0x2a,
     941,  913,   24,   24, 0x0a,
    1012,  978,   24,   24, 0x0a,
    1062, 1050,  338,   24, 0x0a,
    1126, 1120,  338,   24, 0x2a,
    1171, 1159,  338,   24, 0x0a,
    1228, 1213,  338,   24, 0x0a,
    1293, 1280,  338,   24, 0x2a,
    1352, 1341,  338,   24, 0x2a,
    1405, 1396,  338,   24, 0x2a,
    1452, 1445,  338,   24, 0x2a,
    1503, 1488,  338,   24, 0x0a,
    1563, 1550,  338,   24, 0x2a,
    1617, 1606,  338,   24, 0x2a,
    1665, 1656,  338,   24, 0x2a,
    1700,   48,  338,   24, 0x2a,
    1736,  346, 1731,   24, 0x0a,
    1755,  346, 1731,   24, 0x0a,
    1781,  346,  781,   24, 0x0a,
    1798,  346, 1731,   24, 0x0a,
    1815,  346, 1731,   24, 0x0a,
    1874, 1835, 1731,   24, 0x0a,
    1967, 1934, 1731,   24, 0x2a,
    2028, 2002, 1731,   24, 0x2a,
    2086, 2051, 1731,   24, 0x0a,
    2186, 2157, 1731,   24, 0x2a,
    2254, 2232, 1731,   24, 0x2a,
    2288,  346,  535,   24, 0x0a,
    2327, 2303,  781,   24, 0x0a,
    2376, 2303,   24,   24, 0x0a,
    2407, 2303,   24,   24, 0x0a,
    2453,  346, 2439,   24, 0x0a,
    2481,  346, 2475,   24, 0x0a,
    2535, 2496, 1731,   24, 0x0a,
    2608, 2577, 1731,   24, 0x2a,
    2670, 2646, 1731,   24, 0x2a,
    2737, 2696, 1731,   24, 0x0a,
    2776, 1934, 1731,   24, 0x2a,
    2811, 2002, 1731,   24, 0x2a,
    2869, 2834,  338,   24, 0x0a,
    2965, 2935,  338,   24, 0x2a,
    3027, 3008,  338,   24, 0x2a,
    3087, 3050,  338,   24, 0x0a,
    3187, 3155,  338,   24, 0x2a,
    3253, 3232,  338,   24, 0x2a,
    3302, 3278,  338,   24, 0x0a,
    3373, 3354,  338,   24, 0x2a,
    3426, 3402,  338,   24, 0x0a,
    3496, 3477,  338,   24, 0x2a,
    3560, 3524,   24,   24, 0x0a,
    3628, 3600,   24,   24, 0x2a,
    3707, 3659,   24,   24, 0x0a,
    3797, 3757,   24,   24, 0x2a,
    3838, 2303,   24,   24, 0x0a,
    3872, 2303,   24,   24, 0x0a,
    3904,  346, 3898,   24, 0x0a,
    3926,  346, 3919,   24, 0x0a,
    3973, 3944,  338,   24, 0x0a,
    4026, 2303,  338,   24, 0x2a,
    4056, 3944,  338,   24, 0x0a,
    4112, 2303,  338,   24, 0x2a,
    4159, 4153, 4145,   24, 0x0a,
    4213, 4153, 4202,   24, 0x0a,
    4259,  346,  781,   24, 0x0a,
    4275,  309, 1731,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QPixmap[] = {
    "PythonQtWrapper_QPixmap\0\0QPixmap*\0"
    "new_QPixmap()\0arg__1\0new_QPixmap(QPixmap)\0"
    "new_QPixmap(QSize)\0fileName,format,flags\0"
    "new_QPixmap(QString,const char*,Qt::ImageConversionFlags)\0"
    "fileName,format\0new_QPixmap(QString,const char*)\0"
    "fileName\0new_QPixmap(QString)\0xpm\0"
    "new_QPixmap(const char**)\0w,h\0"
    "new_QPixmap(int,int)\0obj\0"
    "delete_QPixmap(QPixmap*)\0QPixmap\0"
    "theWrappedObject\0alphaChannel(QPixmap*)\0"
    "qint64\0cacheKey(QPixmap*)\0"
    "theWrappedObject,rect\0copy(QPixmap*,QRect)\0"
    "copy(QPixmap*)\0theWrappedObject,x,y,width,height\0"
    "copy(QPixmap*,int,int,int,int)\0QBitmap\0"
    "theWrappedObject,clipTight\0"
    "createHeuristicMask(QPixmap*,bool)\0"
    "createHeuristicMask(QPixmap*)\0"
    "theWrappedObject,maskColor\0"
    "createMaskFromColor(QPixmap*,QColor)\0"
    "theWrappedObject,maskColor,mode\0"
    "createMaskFromColor(QPixmap*,QColor,Qt::MaskMode)\0"
    "int\0static_QPixmap_defaultDepth()\0"
    "depth(QPixmap*)\0devType(QPixmap*)\0"
    "theWrappedObject,fillColor\0"
    "fill(QPixmap*,QColor)\0fill(QPixmap*)\0"
    "theWrappedObject,widget,ofs\0"
    "fill(QPixmap*,const QWidget*,QPoint)\0"
    "theWrappedObject,widget,xofs,yofs\0"
    "fill(QPixmap*,const QWidget*,int,int)\0"
    "image,flags\0"
    "static_QPixmap_fromImage(QImage,Qt::ImageConversionFlags)\0"
    "image\0static_QPixmap_fromImage(QImage)\0"
    "widget,rect\0static_QPixmap_grabWidget(QWidget*,QRect)\0"
    "widget,x,y,w,h\0"
    "static_QPixmap_grabWidget(QWidget*,int,int,int,int)\0"
    "widget,x,y,w\0"
    "static_QPixmap_grabWidget(QWidget*,int,int,int)\0"
    "widget,x,y\0static_QPixmap_grabWidget(QWidget*,int,int)\0"
    "widget,x\0static_QPixmap_grabWidget(QWidget*,int)\0"
    "widget\0static_QPixmap_grabWidget(QWidget*)\0"
    "arg__1,x,y,w,h\0"
    "static_QPixmap_grabWindow(WId,int,int,int,int)\0"
    "arg__1,x,y,w\0static_QPixmap_grabWindow(WId,int,int,int)\0"
    "arg__1,x,y\0static_QPixmap_grabWindow(WId,int,int)\0"
    "arg__1,x\0static_QPixmap_grabWindow(WId,int)\0"
    "static_QPixmap_grabWindow(WId)\0bool\0"
    "hasAlpha(QPixmap*)\0hasAlphaChannel(QPixmap*)\0"
    "height(QPixmap*)\0isNull(QPixmap*)\0"
    "isQBitmap(QPixmap*)\0"
    "theWrappedObject,fileName,format,flags\0"
    "load(QPixmap*,QString,const char*,Qt::ImageConversionFlags)\0"
    "theWrappedObject,fileName,format\0"
    "load(QPixmap*,QString,const char*)\0"
    "theWrappedObject,fileName\0"
    "load(QPixmap*,QString)\0"
    "theWrappedObject,data,format,flags\0"
    "loadFromData(QPixmap*,QByteArray,const char*,Qt::ImageConversionFlags)\0"
    "theWrappedObject,data,format\0"
    "loadFromData(QPixmap*,QByteArray,const char*)\0"
    "theWrappedObject,data\0"
    "loadFromData(QPixmap*,QByteArray)\0"
    "mask(QPixmap*)\0theWrappedObject,arg__1\0"
    "metric(QPixmap*,QPaintDevice::PaintDeviceMetric)\0"
    "writeTo(QPixmap*,QDataStream&)\0"
    "readFrom(QPixmap*,QDataStream&)\0"
    "QPaintEngine*\0paintEngine(QPixmap*)\0"
    "QRect\0rect(QPixmap*)\0"
    "theWrappedObject,device,format,quality\0"
    "save(QPixmap*,QIODevice*,const char*,int)\0"
    "theWrappedObject,device,format\0"
    "save(QPixmap*,QIODevice*,const char*)\0"
    "theWrappedObject,device\0"
    "save(QPixmap*,QIODevice*)\0"
    "theWrappedObject,fileName,format,quality\0"
    "save(QPixmap*,QString,const char*,int)\0"
    "save(QPixmap*,QString,const char*)\0"
    "save(QPixmap*,QString)\0"
    "theWrappedObject,s,aspectMode,mode\0"
    "scaled(QPixmap*,QSize,Qt::AspectRatioMode,Qt::TransformationMode)\0"
    "theWrappedObject,s,aspectMode\0"
    "scaled(QPixmap*,QSize,Qt::AspectRatioMode)\0"
    "theWrappedObject,s\0scaled(QPixmap*,QSize)\0"
    "theWrappedObject,w,h,aspectMode,mode\0"
    "scaled(QPixmap*,int,int,Qt::AspectRatioMode,Qt::TransformationMode)\0"
    "theWrappedObject,w,h,aspectMode\0"
    "scaled(QPixmap*,int,int,Qt::AspectRatioMode)\0"
    "theWrappedObject,w,h\0scaled(QPixmap*,int,int)\0"
    "theWrappedObject,h,mode\0"
    "scaledToHeight(QPixmap*,int,Qt::TransformationMode)\0"
    "theWrappedObject,h\0scaledToHeight(QPixmap*,int)\0"
    "theWrappedObject,w,mode\0"
    "scaledToWidth(QPixmap*,int,Qt::TransformationMode)\0"
    "theWrappedObject,w\0scaledToWidth(QPixmap*,int)\0"
    "theWrappedObject,dx,dy,rect,exposed\0"
    "scroll(QPixmap*,int,int,QRect,QRegion*)\0"
    "theWrappedObject,dx,dy,rect\0"
    "scroll(QPixmap*,int,int,QRect)\0"
    "theWrappedObject,dx,dy,x,y,width,height,exposed\0"
    "scroll(QPixmap*,int,int,int,int,int,int,QRegion*)\0"
    "theWrappedObject,dx,dy,x,y,width,height\0"
    "scroll(QPixmap*,int,int,int,int,int,int)\0"
    "setAlphaChannel(QPixmap*,QPixmap)\0"
    "setMask(QPixmap*,QBitmap)\0QSize\0"
    "size(QPixmap*)\0QImage\0toImage(QPixmap*)\0"
    "theWrappedObject,arg__1,mode\0"
    "transformed(QPixmap*,QMatrix,Qt::TransformationMode)\0"
    "transformed(QPixmap*,QMatrix)\0"
    "transformed(QPixmap*,QTransform,Qt::TransformationMode)\0"
    "transformed(QPixmap*,QTransform)\0"
    "QMatrix\0m,w,h\0static_QPixmap_trueMatrix(QMatrix,int,int)\0"
    "QTransform\0static_QPixmap_trueMatrix(QTransform,int,int)\0"
    "width(QPixmap*)\0__nonzero__(QPixmap*)\0"
};

void PythonQtWrapper_QPixmap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QPixmap *_t = static_cast<PythonQtWrapper_QPixmap *>(_o);
        switch (_id) {
        case 0: { QPixmap* _r = _t->new_QPixmap();
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 1: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 2: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const QSize(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 3: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 4: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 5: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 6: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< const char**(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 7: { QPixmap* _r = _t->new_QPixmap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap**>(_a[0]) = _r; }  break;
        case 8: _t->delete_QPixmap((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 9: { QPixmap _r = _t->alphaChannel((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 10: { qint64 _r = _t->cacheKey((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 11: { QPixmap _r = _t->copy((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 12: { QPixmap _r = _t->copy((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 13: { QPixmap _r = _t->copy((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 14: { QBitmap _r = _t->createHeuristicMask((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 15: { QBitmap _r = _t->createHeuristicMask((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 16: { QBitmap _r = _t->createMaskFromColor((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 17: { QBitmap _r = _t->createMaskFromColor((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])),(*reinterpret_cast< Qt::MaskMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 18: { int _r = _t->static_QPixmap_defaultDepth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: { int _r = _t->depth((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 20: { int _r = _t->devType((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 21: _t->fill((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 22: _t->fill((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 23: _t->fill((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QWidget*(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3]))); break;
        case 24: _t->fill((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QWidget*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 25: { QPixmap _r = _t->static_QPixmap_fromImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 26: { QPixmap _r = _t->static_QPixmap_fromImage((*reinterpret_cast< const QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 27: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 28: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 29: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 30: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 31: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 32: { QPixmap _r = _t->static_QPixmap_grabWidget((*reinterpret_cast< QWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 33: { QPixmap _r = _t->static_QPixmap_grabWindow((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 34: { QPixmap _r = _t->static_QPixmap_grabWindow((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 35: { QPixmap _r = _t->static_QPixmap_grabWindow((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 36: { QPixmap _r = _t->static_QPixmap_grabWindow((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 37: { QPixmap _r = _t->static_QPixmap_grabWindow((*reinterpret_cast< WId(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 38: { bool _r = _t->hasAlpha((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 39: { bool _r = _t->hasAlphaChannel((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 40: { int _r = _t->height((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 41: { bool _r = _t->isNull((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 42: { bool _r = _t->isQBitmap((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 43: { bool _r = _t->load((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 44: { bool _r = _t->load((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 45: { bool _r = _t->load((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 46: { bool _r = _t->loadFromData((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< Qt::ImageConversionFlags(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 47: { bool _r = _t->loadFromData((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 48: { bool _r = _t->loadFromData((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 49: { QBitmap _r = _t->mask((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBitmap*>(_a[0]) = _r; }  break;
        case 50: { int _r = _t->metric((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QPaintDevice::PaintDeviceMetric(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 51: _t->writeTo((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 52: _t->readFrom((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 53: { QPaintEngine* _r = _t->paintEngine((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPaintEngine**>(_a[0]) = _r; }  break;
        case 54: { QRect _r = _t->rect((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = _r; }  break;
        case 55: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 56: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 57: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 58: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 59: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 60: { bool _r = _t->save((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 61: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[3])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 62: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 63: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 64: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[4])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 65: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 66: { QPixmap _r = _t->scaled((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 67: { QPixmap _r = _t->scaledToHeight((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 68: { QPixmap _r = _t->scaledToHeight((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 69: { QPixmap _r = _t->scaledToWidth((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 70: { QPixmap _r = _t->scaledToWidth((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 71: _t->scroll((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QRect(*)>(_a[4])),(*reinterpret_cast< QRegion*(*)>(_a[5]))); break;
        case 72: _t->scroll((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QRect(*)>(_a[4]))); break;
        case 73: _t->scroll((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QRegion*(*)>(_a[8]))); break;
        case 74: _t->scroll((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 75: _t->setAlphaChannel((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 76: _t->setMask((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QBitmap(*)>(_a[2]))); break;
        case 77: { QSize _r = _t->size((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 78: { QImage _r = _t->toImage((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 79: { QPixmap _r = _t->transformed((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 80: { QPixmap _r = _t->transformed((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 81: { QPixmap _r = _t->transformed((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])),(*reinterpret_cast< Qt::TransformationMode(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 82: { QPixmap _r = _t->transformed((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 83: { QMatrix _r = _t->static_QPixmap_trueMatrix((*reinterpret_cast< const QMatrix(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMatrix*>(_a[0]) = _r; }  break;
        case 84: { QTransform _r = _t->static_QPixmap_trueMatrix((*reinterpret_cast< const QTransform(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QTransform*>(_a[0]) = _r; }  break;
        case 85: { int _r = _t->width((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 86: { bool _r = _t->__nonzero__((*reinterpret_cast< QPixmap*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QPixmap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QPixmap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QPixmap,
      qt_meta_data_PythonQtWrapper_QPixmap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QPixmap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QPixmap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QPixmap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QPixmap))
        return static_cast<void*>(const_cast< PythonQtWrapper_QPixmap*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QPixmap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 87)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 87;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QPolygon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   25,   26,   25, 0x0a,
      53,   51,   26,   25, 0x0a,
      85,   76,   26,   25, 0x0a,
     112,  110,   26,   25, 0x2a,
     134,  132,   26,   25, 0x0a,
     169,  164,   26,   25, 0x0a,
     191,  187,   25,   25, 0x0a,
     237,  218,   25,   25, 0x0a,
     295,  276,  262,   25, 0x0a,
     336,  319,  313,   25, 0x0a,
     364,  319,  360,   25, 0x0a,
     384,  319,   25,   25, 0x0a,
     406,  218,  401,   25, 0x0a,
     462,  433,  401,   25, 0x0a,
     507,  319,  360,   25, 0x0a,
     524,  218,  360,   25, 0x0a,
     548,  319,  401,   25, 0x0a,
     565,  218,  401,   25, 0x0a,
     633,  609,  592,   25, 0x0a,
     660,  319,  262,   25, 0x0a,
     698,  693,  677,   25, 0x0a,
     762,  738,  360,   25, 0x0a,
     820,  801,  792,   25, 0x0a,
     852,  319,  401,   25, 0x0a,
     871,  319,  262,   25, 0x0a,
     887,  738,  360,   25, 0x0a,
     949,  921,  677,   25, 0x0a,
     991,  972,  401,   25, 0x0a,
    1044, 1025,  792,   25, 0x0a,
    1071, 1025,  792,   25, 0x0a,
    1125, 1101,   25,   25, 0x0a,
    1157,  972,  401,   25, 0x0a,
    1191, 1101,   25,   25, 0x0a,
    1224,  319,   25,   25, 0x0a,
    1244,  319,   25,   25, 0x0a,
    1265,  218,   25,   25, 0x0a,
    1291,  218,   25,   25, 0x0a,
    1319,  218,   25,   25, 0x0a,
    1348,  276,   25,   25, 0x0a,
    1391, 1370,   25,   25, 0x0a,
    1438, 1417,   25,   25, 0x0a,
    1490, 1468,   25,   25, 0x0a,
    1513, 1468,   25,   25, 0x0a,
    1561, 1535,   25,   25, 0x0a,
    1589,  319,  360,   25, 0x0a,
    1605,  319,   25,   25, 0x0a,
    1624,  218,  401,   25, 0x0a,
    1653,  801,  792,   25, 0x0a,
    1698,  319, 1684,   25, 0x0a,
    1740, 1716,   25,   25, 0x0a,
    1791, 1768,   25,   25, 0x0a,
    1820, 1716,  792,   25, 0x0a,
    1849, 1768,  792,   25, 0x0a,
    1879,  801,  792,   25, 0x0a,
    1913,  276, 1906,   25, 0x0a,
    1966, 1934, 1906,   25, 0x0a,
    2002,   25, 1994,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QPolygon[] = {
    "PythonQtWrapper_QPolygon\0\0QPolygon*\0"
    "new_QPolygon()\0a\0new_QPolygon(QPolygon)\0"
    "r,closed\0new_QPolygon(QRect,bool)\0r\0"
    "new_QPolygon(QRect)\0v\0"
    "new_QPolygon(QVector<QPoint>)\0size\0"
    "new_QPolygon(int)\0obj\0delete_QPolygon(QPolygon*)\0"
    "theWrappedObject,t\0append(QPolygon*,QPoint)\0"
    "const QPoint*\0theWrappedObject,i\0"
    "at(QPolygon*,int)\0QRect\0theWrappedObject\0"
    "boundingRect(QPolygon*)\0int\0"
    "capacity(QPolygon*)\0clear(QPolygon*)\0"
    "bool\0contains(QPolygon*,QPoint)\0"
    "theWrappedObject,pt,fillRule\0"
    "containsPoint(QPolygon*,QPoint,Qt::FillRule)\0"
    "count(QPolygon*)\0count(QPolygon*,QPoint)\0"
    "empty(QPolygon*)\0endsWith(QPolygon*,QPoint)\0"
    "QVector<QPoint>*\0theWrappedObject,t,size\0"
    "fill(QPolygon*,QPoint,int)\0first(QPolygon*)\0"
    "QVector<QPoint>\0list\0"
    "static_QPolygon_fromList(QList<QPoint>)\0"
    "theWrappedObject,t,from\0"
    "indexOf(QPolygon*,QPoint,int)\0QPolygon\0"
    "theWrappedObject,r\0intersected(QPolygon*,QPolygon)\0"
    "isEmpty(QPolygon*)\0last(QPolygon*)\0"
    "lastIndexOf(QPolygon*,QPoint,int)\0"
    "theWrappedObject,pos,length\0"
    "mid(QPolygon*,int,int)\0theWrappedObject,v\0"
    "__ne__(QPolygon*,QVector<QPoint>)\0"
    "theWrappedObject,m\0__mul__(QPolygon*,QMatrix)\0"
    "__mul__(QPolygon*,QTransform)\0"
    "theWrappedObject,stream\0"
    "writeTo(QPolygon*,QDataStream&)\0"
    "__eq__(QPolygon*,QVector<QPoint>)\0"
    "readFrom(QPolygon*,QDataStream&)\0"
    "pop_back(QPolygon*)\0pop_front(QPolygon*)\0"
    "prepend(QPolygon*,QPoint)\0"
    "push_back(QPolygon*,QPoint)\0"
    "push_front(QPolygon*,QPoint)\0"
    "remove(QPolygon*,int)\0theWrappedObject,i,n\0"
    "remove(QPolygon*,int,int)\0"
    "theWrappedObject,i,t\0replace(QPolygon*,int,QPoint)\0"
    "theWrappedObject,size\0reserve(QPolygon*,int)\0"
    "resize(QPolygon*,int)\0theWrappedObject,sharable\0"
    "setSharable(QPolygon*,bool)\0size(QPolygon*)\0"
    "squeeze(QPolygon*)\0startsWith(QPolygon*,QPoint)\0"
    "subtracted(QPolygon*,QPolygon)\0"
    "QList<QPoint>\0toList(QPolygon*)\0"
    "theWrappedObject,offset\0"
    "translate(QPolygon*,QPoint)\0"
    "theWrappedObject,dx,dy\0"
    "translate(QPolygon*,int,int)\0"
    "translated(QPolygon*,QPoint)\0"
    "translated(QPolygon*,int,int)\0"
    "united(QPolygon*,QPolygon)\0QPoint\0"
    "value(QPolygon*,int)\0"
    "theWrappedObject,i,defaultValue\0"
    "value(QPolygon*,int,QPoint)\0QString\0"
    "py_toString(QPolygon*)\0"
};

void PythonQtWrapper_QPolygon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QPolygon *_t = static_cast<PythonQtWrapper_QPolygon *>(_o);
        switch (_id) {
        case 0: { QPolygon* _r = _t->new_QPolygon();
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 1: { QPolygon* _r = _t->new_QPolygon((*reinterpret_cast< const QPolygon(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 2: { QPolygon* _r = _t->new_QPolygon((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 3: { QPolygon* _r = _t->new_QPolygon((*reinterpret_cast< const QRect(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 4: { QPolygon* _r = _t->new_QPolygon((*reinterpret_cast< const QVector<QPoint>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 5: { QPolygon* _r = _t->new_QPolygon((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPolygon**>(_a[0]) = _r; }  break;
        case 6: _t->delete_QPolygon((*reinterpret_cast< QPolygon*(*)>(_a[1]))); break;
        case 7: _t->append((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 8: { const QPoint* _r = _t->at((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< const QPoint**>(_a[0]) = _r; }  break;
        case 9: { QRect _r = _t->boundingRect((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->capacity((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->clear((*reinterpret_cast< QPolygon*(*)>(_a[1]))); break;
        case 12: { bool _r = _t->contains((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->containsPoint((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< Qt::FillRule(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->count((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->count((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->empty((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->endsWith((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { QVector<QPoint>* _r = _t->fill((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVector<QPoint>**>(_a[0]) = _r; }  break;
        case 19: { const QPoint* _r = _t->first((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QPoint**>(_a[0]) = _r; }  break;
        case 20: { QVector<QPoint> _r = _t->static_QPolygon_fromList((*reinterpret_cast< const QList<QPoint>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<QPoint>*>(_a[0]) = _r; }  break;
        case 21: { int _r = _t->indexOf((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 22: { QPolygon _r = _t->intersected((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPolygon(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->isEmpty((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { const QPoint* _r = _t->last((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const QPoint**>(_a[0]) = _r; }  break;
        case 25: { int _r = _t->lastIndexOf((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: { QVector<QPoint> _r = _t->mid((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVector<QPoint>*>(_a[0]) = _r; }  break;
        case 27: { bool _r = _t->__ne__((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QVector<QPoint>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 28: { QPolygon _r = _t->__mul__((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 29: { QPolygon _r = _t->__mul__((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 30: _t->writeTo((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 31: { bool _r = _t->__eq__((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QVector<QPoint>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: _t->readFrom((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 33: _t->pop_back((*reinterpret_cast< QPolygon*(*)>(_a[1]))); break;
        case 34: _t->pop_front((*reinterpret_cast< QPolygon*(*)>(_a[1]))); break;
        case 35: _t->prepend((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 36: _t->push_back((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 37: _t->push_front((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 38: _t->remove((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->remove((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 40: _t->replace((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3]))); break;
        case 41: _t->reserve((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 42: _t->resize((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: _t->setSharable((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 44: { int _r = _t->size((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 45: _t->squeeze((*reinterpret_cast< QPolygon*(*)>(_a[1]))); break;
        case 46: { bool _r = _t->startsWith((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 47: { QPolygon _r = _t->subtracted((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPolygon(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 48: { QList<QPoint> _r = _t->toList((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QPoint>*>(_a[0]) = _r; }  break;
        case 49: _t->translate((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 50: _t->translate((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 51: { QPolygon _r = _t->translated((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 52: { QPolygon _r = _t->translated((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 53: { QPolygon _r = _t->united((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< const QPolygon(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPolygon*>(_a[0]) = _r; }  break;
        case 54: { QPoint _r = _t->value((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 55: { QPoint _r = _t->value((*reinterpret_cast< QPolygon*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = _r; }  break;
        case 56: { QString _r = _t->py_toString((*reinterpret_cast< QPolygon*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QPolygon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QPolygon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QPolygon,
      qt_meta_data_PythonQtWrapper_QPolygon, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QPolygon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QPolygon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QPolygon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QPolygon))
        return static_cast<void*>(const_cast< PythonQtWrapper_QPolygon*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QPolygon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QRegion[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       1,  219, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   24,   25,   24, 0x0a,
      55,   48,   25,   24, 0x0a,
      88,   76,   25,   24, 0x0a,
     126,  123,   25,   24, 0x2a,
     152,  148,   25,   24, 0x0a,
     193,  191,   25,   24, 0x2a,
     219,  212,   25,   24, 0x0a,
     250,  240,   25,   24, 0x0a,
     307,  299,   25,   24, 0x2a,
     340,  336,   24,   24, 0x0a,
     388,  371,  365,   24, 0x0a,
     435,  416,  411,   24, 0x0a,
     480,  461,  411,   24, 0x0a,
     513,  461,  505,   24, 0x0a,
     539,  461,  505,   24, 0x0a,
     567,  461,  505,   24, 0x0a,
     597,  461,  411,   24, 0x0a,
     624,  461,  411,   24, 0x0a,
     653,  371,  411,   24, 0x0a,
     675,  371,  671,   24, 0x0a,
     694,  461,  411,   24, 0x0a,
     719,  461,  505,   24, 0x0a,
     762,  743,  505,   24, 0x0a,
     788,  743,  505,   24, 0x0a,
     817,  461,  505,   24, 0x0a,
     865,  841,   24,   24, 0x0a,
     896,  461,  411,   24, 0x0a,
     921,  841,   24,   24, 0x0a,
     953,  371,  671,   24, 0x0a,
     988,  371,  973,   24, 0x0a,
    1030, 1004,   24,   24, 0x0a,
    1066,  461,  505,   24, 0x0a,
    1095,  416,   24,   24, 0x0a,
    1145, 1122,   24,   24, 0x0a,
    1173,  416,  505,   24, 0x0a,
    1201, 1122,  505,   24, 0x0a,
    1230,  461,  505,   24, 0x0a,
    1252,  461,  505,   24, 0x0a,
    1275,  461,  505,   24, 0x0a,
    1300,  461,  505,   24, 0x0a,
    1332,   24, 1324,   24, 0x0a,

 // enums: name, flags, count, data
    1354, 0x0,    2,  223,

 // enum data: key, value
    1365, uint(PythonQtWrapper_QRegion::Rectangle),
    1375, uint(PythonQtWrapper_QRegion::Ellipse),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QRegion[] = {
    "PythonQtWrapper_QRegion\0\0QRegion*\0"
    "new_QRegion()\0bitmap\0new_QRegion(QBitmap)\0"
    "pa,fillRule\0new_QRegion(QPolygon,Qt::FillRule)\0"
    "pa\0new_QRegion(QPolygon)\0r,t\0"
    "new_QRegion(QRect,QRegion::RegionType)\0"
    "r\0new_QRegion(QRect)\0region\0"
    "new_QRegion(QRegion)\0x,y,w,h,t\0"
    "new_QRegion(int,int,int,int,QRegion::RegionType)\0"
    "x,y,w,h\0new_QRegion(int,int,int,int)\0"
    "obj\0delete_QRegion(QRegion*)\0QRect\0"
    "theWrappedObject\0boundingRect(QRegion*)\0"
    "bool\0theWrappedObject,p\0"
    "contains(QRegion*,QPoint)\0theWrappedObject,r\0"
    "contains(QRegion*,QRect)\0QRegion\0"
    "intersect(QRegion*,QRect)\0"
    "intersected(QRegion*,QRect)\0"
    "intersected(QRegion*,QRegion)\0"
    "intersects(QRegion*,QRect)\0"
    "intersects(QRegion*,QRegion)\0"
    "isEmpty(QRegion*)\0int\0numRects(QRegion*)\0"
    "__ne__(QRegion*,QRegion)\0"
    "__and__(QRegion*,QRect)\0theWrappedObject,m\0"
    "__mul__(QRegion*,QMatrix)\0"
    "__mul__(QRegion*,QTransform)\0"
    "__add__(QRegion*,QRect)\0theWrappedObject,arg__1\0"
    "writeTo(QRegion*,QDataStream&)\0"
    "__eq__(QRegion*,QRegion)\0"
    "readFrom(QRegion*,QDataStream&)\0"
    "rectCount(QRegion*)\0QVector<QRect>\0"
    "rects(QRegion*)\0theWrappedObject,rect,num\0"
    "setRects(QRegion*,const QRect*,int)\0"
    "subtracted(QRegion*,QRegion)\0"
    "translate(QRegion*,QPoint)\0"
    "theWrappedObject,dx,dy\0"
    "translate(QRegion*,int,int)\0"
    "translated(QRegion*,QPoint)\0"
    "translated(QRegion*,int,int)\0"
    "unite(QRegion*,QRect)\0united(QRegion*,QRect)\0"
    "united(QRegion*,QRegion)\0"
    "xored(QRegion*,QRegion)\0QString\0"
    "py_toString(QRegion*)\0RegionType\0"
    "Rectangle\0Ellipse\0"
};

void PythonQtWrapper_QRegion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QRegion *_t = static_cast<PythonQtWrapper_QRegion *>(_o);
        switch (_id) {
        case 0: { QRegion* _r = _t->new_QRegion();
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 1: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QBitmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 2: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QPolygon(*)>(_a[1])),(*reinterpret_cast< Qt::FillRule(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 3: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QPolygon(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 4: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< QRegion::RegionType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 5: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QRect(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 6: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< const QRegion(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 7: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QRegion::RegionType(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 8: { QRegion* _r = _t->new_QRegion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QRegion**>(_a[0]) = _r; }  break;
        case 9: _t->delete_QRegion((*reinterpret_cast< QRegion*(*)>(_a[1]))); break;
        case 10: { QRect _r = _t->boundingRect((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->contains((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->contains((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { QRegion _r = _t->intersect((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 14: { QRegion _r = _t->intersected((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 15: { QRegion _r = _t->intersected((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->intersects((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->intersects((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->isEmpty((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { int _r = _t->numRects((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 20: { bool _r = _t->__ne__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: { QRegion _r = _t->__and__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 22: { QRegion _r = _t->__mul__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QMatrix(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 23: { QRegion _r = _t->__mul__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QTransform(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 24: { QRegion _r = _t->__add__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 25: _t->writeTo((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 26: { bool _r = _t->__eq__((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: _t->readFrom((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 28: { int _r = _t->rectCount((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { QVector<QRect> _r = _t->rects((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<QRect>*>(_a[0]) = _r; }  break;
        case 30: _t->setRects((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 31: { QRegion _r = _t->subtracted((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 32: _t->translate((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 33: _t->translate((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 34: { QRegion _r = _t->translated((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 35: { QRegion _r = _t->translated((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 36: { QRegion _r = _t->unite((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 37: { QRegion _r = _t->united((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 38: { QRegion _r = _t->united((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 39: { QRegion _r = _t->xored((*reinterpret_cast< QRegion*(*)>(_a[1])),(*reinterpret_cast< const QRegion(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QRegion*>(_a[0]) = _r; }  break;
        case 40: { QString _r = _t->py_toString((*reinterpret_cast< QRegion*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QRegion::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QRegion::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QRegion,
      qt_meta_data_PythonQtWrapper_QRegion, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QRegion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QRegion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QRegion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QRegion))
        return static_cast<void*>(const_cast< PythonQtWrapper_QRegion*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QRegion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QSizePolicy[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       4,  129, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   28,   29,   28, 0x0a,
      80,   60,   29,   28, 0x0a,
     162,  137,   29,   28, 0x0a,
     250,  244,   29,   28, 0x0a,
     283,  279,   28,   28, 0x0a,
     358,  341,  316,   28, 0x0a,
     401,  341,  384,   28, 0x0a,
     440,  341,  435,   28, 0x0a,
     492,  341,  472,   28, 0x0a,
     527,  341,  523,   28, 0x0a,
     578,  559,  435,   28, 0x0a,
     635,  611,   28,   28, 0x0a,
     670,  559,  435,   28, 0x0a,
     703,  611,   28,   28, 0x0a,
     761,  739,   28,   28, 0x0a,
     834,  815,   28,   28, 0x0a,
     890,  871,   28,   28, 0x0a,
     975,  944,   28,   28, 0x0a,
    1016,  871,   28,   28, 0x0a,
    1068,  944,   28,   28, 0x0a,
    1107,  341,   28,   28, 0x0a,
    1131,  341,  472,   28, 0x0a,
    1160,  341,  523,   28, 0x0a,

 // enums: name, flags, count, data
    1190, 0x0,   15,  145,
    1202, 0x1,   15,  175,
    1215, 0x0,    4,  205,
    1226, 0x0,    7,  213,

 // enum data: key, value
    1233, uint(PythonQtWrapper_QSizePolicy::DefaultType),
    1245, uint(PythonQtWrapper_QSizePolicy::ButtonBox),
    1255, uint(PythonQtWrapper_QSizePolicy::CheckBox),
    1264, uint(PythonQtWrapper_QSizePolicy::ComboBox),
    1273, uint(PythonQtWrapper_QSizePolicy::Frame),
    1279, uint(PythonQtWrapper_QSizePolicy::GroupBox),
    1288, uint(PythonQtWrapper_QSizePolicy::Label),
    1294, uint(PythonQtWrapper_QSizePolicy::Line),
    1299, uint(PythonQtWrapper_QSizePolicy::LineEdit),
    1308, uint(PythonQtWrapper_QSizePolicy::PushButton),
    1319, uint(PythonQtWrapper_QSizePolicy::RadioButton),
    1331, uint(PythonQtWrapper_QSizePolicy::Slider),
    1338, uint(PythonQtWrapper_QSizePolicy::SpinBox),
    1346, uint(PythonQtWrapper_QSizePolicy::TabWidget),
    1356, uint(PythonQtWrapper_QSizePolicy::ToolButton),
    1233, uint(PythonQtWrapper_QSizePolicy::DefaultType),
    1245, uint(PythonQtWrapper_QSizePolicy::ButtonBox),
    1255, uint(PythonQtWrapper_QSizePolicy::CheckBox),
    1264, uint(PythonQtWrapper_QSizePolicy::ComboBox),
    1273, uint(PythonQtWrapper_QSizePolicy::Frame),
    1279, uint(PythonQtWrapper_QSizePolicy::GroupBox),
    1288, uint(PythonQtWrapper_QSizePolicy::Label),
    1294, uint(PythonQtWrapper_QSizePolicy::Line),
    1299, uint(PythonQtWrapper_QSizePolicy::LineEdit),
    1308, uint(PythonQtWrapper_QSizePolicy::PushButton),
    1319, uint(PythonQtWrapper_QSizePolicy::RadioButton),
    1331, uint(PythonQtWrapper_QSizePolicy::Slider),
    1338, uint(PythonQtWrapper_QSizePolicy::SpinBox),
    1346, uint(PythonQtWrapper_QSizePolicy::TabWidget),
    1356, uint(PythonQtWrapper_QSizePolicy::ToolButton),
    1367, uint(PythonQtWrapper_QSizePolicy::GrowFlag),
    1376, uint(PythonQtWrapper_QSizePolicy::ExpandFlag),
    1387, uint(PythonQtWrapper_QSizePolicy::ShrinkFlag),
    1398, uint(PythonQtWrapper_QSizePolicy::IgnoreFlag),
    1409, uint(PythonQtWrapper_QSizePolicy::Fixed),
    1415, uint(PythonQtWrapper_QSizePolicy::Minimum),
    1423, uint(PythonQtWrapper_QSizePolicy::Maximum),
    1431, uint(PythonQtWrapper_QSizePolicy::Preferred),
    1441, uint(PythonQtWrapper_QSizePolicy::MinimumExpanding),
    1458, uint(PythonQtWrapper_QSizePolicy::Expanding),
    1468, uint(PythonQtWrapper_QSizePolicy::Ignored),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QSizePolicy[] = {
    "PythonQtWrapper_QSizePolicy\0\0QSizePolicy*\0"
    "new_QSizePolicy()\0horizontal,vertical\0"
    "new_QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy)\0"
    "horizontal,vertical,type\0"
    "new_QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::C"
    "ontrolType)\0"
    "other\0new_QSizePolicy(QSizePolicy)\0"
    "obj\0delete_QSizePolicy(QSizePolicy*)\0"
    "QSizePolicy::ControlType\0theWrappedObject\0"
    "controlType(QSizePolicy*)\0Qt::Orientations\0"
    "expandingDirections(QSizePolicy*)\0"
    "bool\0hasHeightForWidth(QSizePolicy*)\0"
    "QSizePolicy::Policy\0horizontalPolicy(QSizePolicy*)\0"
    "int\0horizontalStretch(QSizePolicy*)\0"
    "theWrappedObject,s\0__ne__(QSizePolicy*,QSizePolicy)\0"
    "theWrappedObject,arg__1\0"
    "writeTo(QSizePolicy*,QDataStream&)\0"
    "__eq__(QSizePolicy*,QSizePolicy)\0"
    "readFrom(QSizePolicy*,QDataStream&)\0"
    "theWrappedObject,type\0"
    "setControlType(QSizePolicy*,QSizePolicy::ControlType)\0"
    "theWrappedObject,b\0"
    "setHeightForWidth(QSizePolicy*,bool)\0"
    "theWrappedObject,d\0"
    "setHorizontalPolicy(QSizePolicy*,QSizePolicy::Policy)\0"
    "theWrappedObject,stretchFactor\0"
    "setHorizontalStretch(QSizePolicy*,uchar)\0"
    "setVerticalPolicy(QSizePolicy*,QSizePolicy::Policy)\0"
    "setVerticalStretch(QSizePolicy*,uchar)\0"
    "transpose(QSizePolicy*)\0"
    "verticalPolicy(QSizePolicy*)\0"
    "verticalStretch(QSizePolicy*)\0ControlType\0"
    "ControlTypes\0PolicyFlag\0Policy\0"
    "DefaultType\0ButtonBox\0CheckBox\0ComboBox\0"
    "Frame\0GroupBox\0Label\0Line\0LineEdit\0"
    "PushButton\0RadioButton\0Slider\0SpinBox\0"
    "TabWidget\0ToolButton\0GrowFlag\0ExpandFlag\0"
    "ShrinkFlag\0IgnoreFlag\0Fixed\0Minimum\0"
    "Maximum\0Preferred\0MinimumExpanding\0"
    "Expanding\0Ignored\0"
};

void PythonQtWrapper_QSizePolicy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QSizePolicy *_t = static_cast<PythonQtWrapper_QSizePolicy *>(_o);
        switch (_id) {
        case 0: { QSizePolicy* _r = _t->new_QSizePolicy();
            if (_a[0]) *reinterpret_cast< QSizePolicy**>(_a[0]) = _r; }  break;
        case 1: { QSizePolicy* _r = _t->new_QSizePolicy((*reinterpret_cast< QSizePolicy::Policy(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::Policy(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QSizePolicy**>(_a[0]) = _r; }  break;
        case 2: { QSizePolicy* _r = _t->new_QSizePolicy((*reinterpret_cast< QSizePolicy::Policy(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::Policy(*)>(_a[2])),(*reinterpret_cast< QSizePolicy::ControlType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QSizePolicy**>(_a[0]) = _r; }  break;
        case 3: { QSizePolicy* _r = _t->new_QSizePolicy((*reinterpret_cast< const QSizePolicy(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSizePolicy**>(_a[0]) = _r; }  break;
        case 4: _t->delete_QSizePolicy((*reinterpret_cast< QSizePolicy*(*)>(_a[1]))); break;
        case 5: { QSizePolicy::ControlType _r = _t->controlType((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSizePolicy::ControlType*>(_a[0]) = _r; }  break;
        case 6: { Qt::Orientations _r = _t->expandingDirections((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::Orientations*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->hasHeightForWidth((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QSizePolicy::Policy _r = _t->horizontalPolicy((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSizePolicy::Policy*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->horizontalStretch((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->__ne__((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< const QSizePolicy(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->writeTo((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 12: { bool _r = _t->__eq__((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< const QSizePolicy(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: _t->readFrom((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 14: _t->setControlType((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::ControlType(*)>(_a[2]))); break;
        case 15: _t->setHeightForWidth((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->setHorizontalPolicy((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::Policy(*)>(_a[2]))); break;
        case 17: _t->setHorizontalStretch((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< uchar(*)>(_a[2]))); break;
        case 18: _t->setVerticalPolicy((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::Policy(*)>(_a[2]))); break;
        case 19: _t->setVerticalStretch((*reinterpret_cast< QSizePolicy*(*)>(_a[1])),(*reinterpret_cast< uchar(*)>(_a[2]))); break;
        case 20: _t->transpose((*reinterpret_cast< QSizePolicy*(*)>(_a[1]))); break;
        case 21: { QSizePolicy::Policy _r = _t->verticalPolicy((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSizePolicy::Policy*>(_a[0]) = _r; }  break;
        case 22: { int _r = _t->verticalStretch((*reinterpret_cast< QSizePolicy*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QSizePolicy::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QSizePolicy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QSizePolicy,
      qt_meta_data_PythonQtWrapper_QSizePolicy, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QSizePolicy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QSizePolicy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QSizePolicy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QSizePolicy))
        return static_cast<void*>(const_cast< PythonQtWrapper_QSizePolicy*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QSizePolicy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QTextFormat[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       5,  279, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   28,   29,   28, 0x0a,
      64,   60,   29,   28, 0x0a,
      98,   93,   29,   28, 0x0a,
     123,  119,   28,   28, 0x0a,
     180,  163,  156,   28, 0x0a,
     238,  210,  205,   28, 0x0a,
     269,  210,  156,   28, 0x0a,
     301,  163,   28,   28, 0x0a,
     331,  163,   28,   28, 0x0a,
     361,  210,   28,   28, 0x0a,
     400,  210,  393,   28, 0x0a,
     438,  210,  432,   28, 0x0a,
     471,  163,  156,   28, 0x0a,
     496,  210,  205,   28, 0x0a,
     530,  210,  526,   28, 0x0a,
     560,  163,  205,   28, 0x0a,
     588,  163,  205,   28, 0x0a,
     615,  163,  205,   28, 0x0a,
     643,  163,  205,   28, 0x0a,
     671,  163,  205,   28, 0x0a,
     698,  163,  205,   28, 0x0a,
     730,  163,  205,   28, 0x0a,
     758,  163,  205,   28, 0x0a,
     800,  163,  780,   28, 0x0a,
     842,  210,  830,   28, 0x0a,
     896,  210,  875,   28, 0x0a,
     958,  935,   28,   28, 0x0a,
     990,  163,  526,   28, 0x0a,
    1016,  163,  526,   28, 0x0a,
    1062, 1041,  205,   28, 0x0a,
    1119, 1095,   28,   28, 0x0a,
    1154, 1041,  205,   28, 0x0a,
    1187, 1095,   28,   28, 0x0a,
    1228,  210, 1223,   28, 0x0a,
    1277,  163, 1258,   28, 0x0a,
    1311,  210, 1302,   28, 0x0a,
    1338,  163,  526,   28, 0x0a,
    1389, 1366,   28,   28, 0x0a,
    1424, 1366,   28,   28, 0x0a,
    1486, 1459,   28,   28, 0x0a,
    1563, 1539,   28,   28, 0x0a,
    1618, 1596,   28,   28, 0x0a,
    1684, 1650,   28,   28, 0x0a,
    1759, 1723,   28,   28, 0x0a,
    1818,  210, 1810,   28, 0x0a,
    1868,  163, 1851,   28, 0x0a,
    1912,  163, 1896,   28, 0x0a,
    1956,  163, 1939,   28, 0x0a,
    2001,  163, 1984,   28, 0x0a,
    2045,  163, 2029,   28, 0x0a,
    2093,  163, 2072,   28, 0x0a,
    2142,  163, 2125,   28, 0x0a,
    2170,  163,  526,   28, 0x0a,

 // enums: name, flags, count, data
    2189, 0x0,   75,  299,
    2198, 0x0,    7,  449,
    2209, 0x0,    5,  463,
    2221, 0x0,    3,  473,
    2235, 0x1,    3,  479,

 // enum data: key, value
    2250, uint(PythonQtWrapper_QTextFormat::ObjectIndex),
    2262, uint(PythonQtWrapper_QTextFormat::CssFloat),
    2271, uint(PythonQtWrapper_QTextFormat::LayoutDirection),
    2287, uint(PythonQtWrapper_QTextFormat::OutlinePen),
    2298, uint(PythonQtWrapper_QTextFormat::BackgroundBrush),
    2314, uint(PythonQtWrapper_QTextFormat::ForegroundBrush),
    2330, uint(PythonQtWrapper_QTextFormat::BackgroundImageUrl),
    2349, uint(PythonQtWrapper_QTextFormat::BlockAlignment),
    2364, uint(PythonQtWrapper_QTextFormat::BlockTopMargin),
    2379, uint(PythonQtWrapper_QTextFormat::BlockBottomMargin),
    2397, uint(PythonQtWrapper_QTextFormat::BlockLeftMargin),
    2413, uint(PythonQtWrapper_QTextFormat::BlockRightMargin),
    2430, uint(PythonQtWrapper_QTextFormat::TextIndent),
    2441, uint(PythonQtWrapper_QTextFormat::TabPositions),
    2454, uint(PythonQtWrapper_QTextFormat::BlockIndent),
    2466, uint(PythonQtWrapper_QTextFormat::BlockNonBreakableLines),
    2489, uint(PythonQtWrapper_QTextFormat::BlockTrailingHorizontalRulerWidth),
    2523, uint(PythonQtWrapper_QTextFormat::FirstFontProperty),
    2541, uint(PythonQtWrapper_QTextFormat::FontCapitalization),
    2560, uint(PythonQtWrapper_QTextFormat::FontLetterSpacing),
    2578, uint(PythonQtWrapper_QTextFormat::FontWordSpacing),
    2594, uint(PythonQtWrapper_QTextFormat::FontStyleHint),
    2608, uint(PythonQtWrapper_QTextFormat::FontStyleStrategy),
    2626, uint(PythonQtWrapper_QTextFormat::FontKerning),
    2638, uint(PythonQtWrapper_QTextFormat::FontFamily),
    2649, uint(PythonQtWrapper_QTextFormat::FontPointSize),
    2663, uint(PythonQtWrapper_QTextFormat::FontSizeAdjustment),
    2682, uint(PythonQtWrapper_QTextFormat::FontSizeIncrement),
    2700, uint(PythonQtWrapper_QTextFormat::FontWeight),
    2711, uint(PythonQtWrapper_QTextFormat::FontItalic),
    2722, uint(PythonQtWrapper_QTextFormat::FontUnderline),
    2736, uint(PythonQtWrapper_QTextFormat::FontOverline),
    2749, uint(PythonQtWrapper_QTextFormat::FontStrikeOut),
    2763, uint(PythonQtWrapper_QTextFormat::FontFixedPitch),
    2778, uint(PythonQtWrapper_QTextFormat::FontPixelSize),
    2792, uint(PythonQtWrapper_QTextFormat::LastFontProperty),
    2809, uint(PythonQtWrapper_QTextFormat::TextUnderlineColor),
    2828, uint(PythonQtWrapper_QTextFormat::TextVerticalAlignment),
    2850, uint(PythonQtWrapper_QTextFormat::TextOutline),
    2862, uint(PythonQtWrapper_QTextFormat::TextUnderlineStyle),
    2881, uint(PythonQtWrapper_QTextFormat::TextToolTip),
    2893, uint(PythonQtWrapper_QTextFormat::IsAnchor),
    2902, uint(PythonQtWrapper_QTextFormat::AnchorHref),
    2913, uint(PythonQtWrapper_QTextFormat::AnchorName),
    2924, uint(PythonQtWrapper_QTextFormat::ObjectType),
    2935, uint(PythonQtWrapper_QTextFormat::ListStyle),
    2945, uint(PythonQtWrapper_QTextFormat::ListIndent),
    2956, uint(PythonQtWrapper_QTextFormat::FrameBorder),
    2968, uint(PythonQtWrapper_QTextFormat::FrameMargin),
    2980, uint(PythonQtWrapper_QTextFormat::FramePadding),
    2993, uint(PythonQtWrapper_QTextFormat::FrameWidth),
    3004, uint(PythonQtWrapper_QTextFormat::FrameHeight),
    3016, uint(PythonQtWrapper_QTextFormat::FrameTopMargin),
    3031, uint(PythonQtWrapper_QTextFormat::FrameBottomMargin),
    3049, uint(PythonQtWrapper_QTextFormat::FrameLeftMargin),
    3065, uint(PythonQtWrapper_QTextFormat::FrameRightMargin),
    3082, uint(PythonQtWrapper_QTextFormat::FrameBorderBrush),
    3099, uint(PythonQtWrapper_QTextFormat::FrameBorderStyle),
    3116, uint(PythonQtWrapper_QTextFormat::TableColumns),
    3129, uint(PythonQtWrapper_QTextFormat::TableColumnWidthConstraints),
    3157, uint(PythonQtWrapper_QTextFormat::TableCellSpacing),
    3174, uint(PythonQtWrapper_QTextFormat::TableCellPadding),
    3191, uint(PythonQtWrapper_QTextFormat::TableHeaderRowCount),
    3211, uint(PythonQtWrapper_QTextFormat::TableCellRowSpan),
    3228, uint(PythonQtWrapper_QTextFormat::TableCellColumnSpan),
    3248, uint(PythonQtWrapper_QTextFormat::TableCellTopPadding),
    3268, uint(PythonQtWrapper_QTextFormat::TableCellBottomPadding),
    3291, uint(PythonQtWrapper_QTextFormat::TableCellLeftPadding),
    3312, uint(PythonQtWrapper_QTextFormat::TableCellRightPadding),
    3334, uint(PythonQtWrapper_QTextFormat::ImageName),
    3344, uint(PythonQtWrapper_QTextFormat::ImageWidth),
    3355, uint(PythonQtWrapper_QTextFormat::ImageHeight),
    3367, uint(PythonQtWrapper_QTextFormat::FullWidthSelection),
    3386, uint(PythonQtWrapper_QTextFormat::PageBreakPolicy),
    3402, uint(PythonQtWrapper_QTextFormat::UserProperty),
    3415, uint(PythonQtWrapper_QTextFormat::InvalidFormat),
    3429, uint(PythonQtWrapper_QTextFormat::BlockFormat),
    3441, uint(PythonQtWrapper_QTextFormat::CharFormat),
    3452, uint(PythonQtWrapper_QTextFormat::ListFormat),
    3463, uint(PythonQtWrapper_QTextFormat::TableFormat),
    3475, uint(PythonQtWrapper_QTextFormat::FrameFormat),
    3487, uint(PythonQtWrapper_QTextFormat::UserFormat),
    3498, uint(PythonQtWrapper_QTextFormat::NoObject),
    3507, uint(PythonQtWrapper_QTextFormat::ImageObject),
    3519, uint(PythonQtWrapper_QTextFormat::TableObject),
    3531, uint(PythonQtWrapper_QTextFormat::TableCellObject),
    3547, uint(PythonQtWrapper_QTextFormat::UserObject),
    3558, uint(PythonQtWrapper_QTextFormat::PageBreak_Auto),
    3573, uint(PythonQtWrapper_QTextFormat::PageBreak_AlwaysBefore),
    3596, uint(PythonQtWrapper_QTextFormat::PageBreak_AlwaysAfter),
    3558, uint(PythonQtWrapper_QTextFormat::PageBreak_Auto),
    3573, uint(PythonQtWrapper_QTextFormat::PageBreak_AlwaysBefore),
    3596, uint(PythonQtWrapper_QTextFormat::PageBreak_AlwaysAfter),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QTextFormat[] = {
    "PythonQtWrapper_QTextFormat\0\0QTextFormat*\0"
    "new_QTextFormat()\0rhs\0"
    "new_QTextFormat(QTextFormat)\0type\0"
    "new_QTextFormat(int)\0obj\0"
    "delete_QTextFormat(QTextFormat*)\0"
    "QBrush\0theWrappedObject\0"
    "background(QTextFormat*)\0bool\0"
    "theWrappedObject,propertyId\0"
    "boolProperty(QTextFormat*,int)\0"
    "brushProperty(QTextFormat*,int)\0"
    "clearBackground(QTextFormat*)\0"
    "clearForeground(QTextFormat*)\0"
    "clearProperty(QTextFormat*,int)\0QColor\0"
    "colorProperty(QTextFormat*,int)\0qreal\0"
    "doubleProperty(QTextFormat*,int)\0"
    "foreground(QTextFormat*)\0"
    "hasProperty(QTextFormat*,int)\0int\0"
    "intProperty(QTextFormat*,int)\0"
    "isBlockFormat(QTextFormat*)\0"
    "isCharFormat(QTextFormat*)\0"
    "isFrameFormat(QTextFormat*)\0"
    "isImageFormat(QTextFormat*)\0"
    "isListFormat(QTextFormat*)\0"
    "isTableCellFormat(QTextFormat*)\0"
    "isTableFormat(QTextFormat*)\0"
    "isValid(QTextFormat*)\0Qt::LayoutDirection\0"
    "layoutDirection(QTextFormat*)\0QTextLength\0"
    "lengthProperty(QTextFormat*,int)\0"
    "QVector<QTextLength>\0"
    "lengthVectorProperty(QTextFormat*,int)\0"
    "theWrappedObject,other\0"
    "merge(QTextFormat*,QTextFormat)\0"
    "objectIndex(QTextFormat*)\0"
    "objectType(QTextFormat*)\0theWrappedObject,rhs\0"
    "__ne__(QTextFormat*,QTextFormat)\0"
    "theWrappedObject,arg__1\0"
    "writeTo(QTextFormat*,QDataStream&)\0"
    "__eq__(QTextFormat*,QTextFormat)\0"
    "readFrom(QTextFormat*,QDataStream&)\0"
    "QPen\0penProperty(QTextFormat*,int)\0"
    "QMap<int,QVariant>\0properties(QTextFormat*)\0"
    "QVariant\0property(QTextFormat*,int)\0"
    "propertyCount(QTextFormat*)\0"
    "theWrappedObject,brush\0"
    "setBackground(QTextFormat*,QBrush)\0"
    "setForeground(QTextFormat*,QBrush)\0"
    "theWrappedObject,direction\0"
    "setLayoutDirection(QTextFormat*,Qt::LayoutDirection)\0"
    "theWrappedObject,object\0"
    "setObjectIndex(QTextFormat*,int)\0"
    "theWrappedObject,type\0"
    "setObjectType(QTextFormat*,int)\0"
    "theWrappedObject,propertyId,value\0"
    "setProperty(QTextFormat*,int,QVariant)\0"
    "theWrappedObject,propertyId,lengths\0"
    "setProperty(QTextFormat*,int,QVector<QTextLength>)\0"
    "QString\0stringProperty(QTextFormat*,int)\0"
    "QTextBlockFormat\0toBlockFormat(QTextFormat*)\0"
    "QTextCharFormat\0toCharFormat(QTextFormat*)\0"
    "QTextFrameFormat\0toFrameFormat(QTextFormat*)\0"
    "QTextImageFormat\0toImageFormat(QTextFormat*)\0"
    "QTextListFormat\0toListFormat(QTextFormat*)\0"
    "QTextTableCellFormat\0"
    "toTableCellFormat(QTextFormat*)\0"
    "QTextTableFormat\0toTableFormat(QTextFormat*)\0"
    "type(QTextFormat*)\0Property\0FormatType\0"
    "ObjectTypes\0PageBreakFlag\0PageBreakFlags\0"
    "ObjectIndex\0CssFloat\0LayoutDirection\0"
    "OutlinePen\0BackgroundBrush\0ForegroundBrush\0"
    "BackgroundImageUrl\0BlockAlignment\0"
    "BlockTopMargin\0BlockBottomMargin\0"
    "BlockLeftMargin\0BlockRightMargin\0"
    "TextIndent\0TabPositions\0BlockIndent\0"
    "BlockNonBreakableLines\0"
    "BlockTrailingHorizontalRulerWidth\0"
    "FirstFontProperty\0FontCapitalization\0"
    "FontLetterSpacing\0FontWordSpacing\0"
    "FontStyleHint\0FontStyleStrategy\0"
    "FontKerning\0FontFamily\0FontPointSize\0"
    "FontSizeAdjustment\0FontSizeIncrement\0"
    "FontWeight\0FontItalic\0FontUnderline\0"
    "FontOverline\0FontStrikeOut\0FontFixedPitch\0"
    "FontPixelSize\0LastFontProperty\0"
    "TextUnderlineColor\0TextVerticalAlignment\0"
    "TextOutline\0TextUnderlineStyle\0"
    "TextToolTip\0IsAnchor\0AnchorHref\0"
    "AnchorName\0ObjectType\0ListStyle\0"
    "ListIndent\0FrameBorder\0FrameMargin\0"
    "FramePadding\0FrameWidth\0FrameHeight\0"
    "FrameTopMargin\0FrameBottomMargin\0"
    "FrameLeftMargin\0FrameRightMargin\0"
    "FrameBorderBrush\0FrameBorderStyle\0"
    "TableColumns\0TableColumnWidthConstraints\0"
    "TableCellSpacing\0TableCellPadding\0"
    "TableHeaderRowCount\0TableCellRowSpan\0"
    "TableCellColumnSpan\0TableCellTopPadding\0"
    "TableCellBottomPadding\0TableCellLeftPadding\0"
    "TableCellRightPadding\0ImageName\0"
    "ImageWidth\0ImageHeight\0FullWidthSelection\0"
    "PageBreakPolicy\0UserProperty\0InvalidFormat\0"
    "BlockFormat\0CharFormat\0ListFormat\0"
    "TableFormat\0FrameFormat\0UserFormat\0"
    "NoObject\0ImageObject\0TableObject\0"
    "TableCellObject\0UserObject\0PageBreak_Auto\0"
    "PageBreak_AlwaysBefore\0PageBreak_AlwaysAfter\0"
};

void PythonQtWrapper_QTextFormat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QTextFormat *_t = static_cast<PythonQtWrapper_QTextFormat *>(_o);
        switch (_id) {
        case 0: { QTextFormat* _r = _t->new_QTextFormat();
            if (_a[0]) *reinterpret_cast< QTextFormat**>(_a[0]) = _r; }  break;
        case 1: { QTextFormat* _r = _t->new_QTextFormat((*reinterpret_cast< const QTextFormat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextFormat**>(_a[0]) = _r; }  break;
        case 2: { QTextFormat* _r = _t->new_QTextFormat((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextFormat**>(_a[0]) = _r; }  break;
        case 3: _t->delete_QTextFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1]))); break;
        case 4: { QBrush _r = _t->background((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->boolProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { QBrush _r = _t->brushProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
        case 7: _t->clearBackground((*reinterpret_cast< QTextFormat*(*)>(_a[1]))); break;
        case 8: _t->clearForeground((*reinterpret_cast< QTextFormat*(*)>(_a[1]))); break;
        case 9: _t->clearProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: { QColor _r = _t->colorProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 11: { qreal _r = _t->doubleProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 12: { QBrush _r = _t->foreground((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->hasProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->intProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->isBlockFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->isCharFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->isFrameFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->isImageFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { bool _r = _t->isListFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: { bool _r = _t->isTableCellFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: { bool _r = _t->isTableFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->isValid((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { Qt::LayoutDirection _r = _t->layoutDirection((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::LayoutDirection*>(_a[0]) = _r; }  break;
        case 24: { QTextLength _r = _t->lengthProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QTextLength*>(_a[0]) = _r; }  break;
        case 25: { QVector<QTextLength> _r = _t->lengthVectorProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<QTextLength>*>(_a[0]) = _r; }  break;
        case 26: _t->merge((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< const QTextFormat(*)>(_a[2]))); break;
        case 27: { int _r = _t->objectIndex((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->objectType((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->__ne__((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< const QTextFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: _t->writeTo((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 31: { bool _r = _t->__eq__((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< const QTextFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: _t->readFrom((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 33: { QPen _r = _t->penProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPen*>(_a[0]) = _r; }  break;
        case 34: { QMap<int,QVariant> _r = _t->properties((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<int,QVariant>*>(_a[0]) = _r; }  break;
        case 35: { QVariant _r = _t->property((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 36: { int _r = _t->propertyCount((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 37: _t->setBackground((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2]))); break;
        case 38: _t->setForeground((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< const QBrush(*)>(_a[2]))); break;
        case 39: _t->setLayoutDirection((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< Qt::LayoutDirection(*)>(_a[2]))); break;
        case 40: _t->setObjectIndex((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->setObjectType((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 42: _t->setProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 43: _t->setProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVector<QTextLength>(*)>(_a[3]))); break;
        case 44: { QString _r = _t->stringProperty((*reinterpret_cast< QTextFormat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 45: { QTextBlockFormat _r = _t->toBlockFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextBlockFormat*>(_a[0]) = _r; }  break;
        case 46: { QTextCharFormat _r = _t->toCharFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextCharFormat*>(_a[0]) = _r; }  break;
        case 47: { QTextFrameFormat _r = _t->toFrameFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextFrameFormat*>(_a[0]) = _r; }  break;
        case 48: { QTextImageFormat _r = _t->toImageFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextImageFormat*>(_a[0]) = _r; }  break;
        case 49: { QTextListFormat _r = _t->toListFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextListFormat*>(_a[0]) = _r; }  break;
        case 50: { QTextTableCellFormat _r = _t->toTableCellFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextTableCellFormat*>(_a[0]) = _r; }  break;
        case 51: { QTextTableFormat _r = _t->toTableFormat((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextTableFormat*>(_a[0]) = _r; }  break;
        case 52: { int _r = _t->type((*reinterpret_cast< QTextFormat*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QTextFormat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QTextFormat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QTextFormat,
      qt_meta_data_PythonQtWrapper_QTextFormat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QTextFormat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QTextFormat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QTextFormat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QTextFormat))
        return static_cast<void*>(const_cast< PythonQtWrapper_QTextFormat*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QTextFormat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    }
    return _id;
}
static const uint qt_meta_data_PythonQtWrapper_QTextLength[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       1,   69, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   28,   29,   28, 0x0a,
      71,   60,   29,   28, 0x0a,
     118,  112,   29,   28, 0x0a,
     151,  147,   28,   28, 0x0a,
     212,  189,  184,   28, 0x0a,
     269,  245,   28,   28, 0x0a,
     304,  189,  184,   28, 0x0a,
     337,  245,   28,   28, 0x0a,
     396,  379,  373,   28, 0x0a,
     437,  379,  419,   28, 0x0a,
     487,  456,  373,   28, 0x0a,

 // enums: name, flags, count, data
     513, 0x0,    3,   73,

 // enum data: key, value
     518, uint(PythonQtWrapper_QTextLength::VariableLength),
     533, uint(PythonQtWrapper_QTextLength::FixedLength),
     545, uint(PythonQtWrapper_QTextLength::PercentageLength),

       0        // eod
};

static const char qt_meta_stringdata_PythonQtWrapper_QTextLength[] = {
    "PythonQtWrapper_QTextLength\0\0QTextLength*\0"
    "new_QTextLength()\0type,value\0"
    "new_QTextLength(QTextLength::Type,qreal)\0"
    "other\0new_QTextLength(QTextLength)\0"
    "obj\0delete_QTextLength(QTextLength*)\0"
    "bool\0theWrappedObject,other\0"
    "__ne__(QTextLength*,QTextLength)\0"
    "theWrappedObject,arg__1\0"
    "writeTo(QTextLength*,QDataStream&)\0"
    "__eq__(QTextLength*,QTextLength)\0"
    "readFrom(QTextLength*,QDataStream&)\0"
    "qreal\0theWrappedObject\0rawValue(QTextLength*)\0"
    "QTextLength::Type\0type(QTextLength*)\0"
    "theWrappedObject,maximumLength\0"
    "value(QTextLength*,qreal)\0Type\0"
    "VariableLength\0FixedLength\0PercentageLength\0"
};

void PythonQtWrapper_QTextLength::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PythonQtWrapper_QTextLength *_t = static_cast<PythonQtWrapper_QTextLength *>(_o);
        switch (_id) {
        case 0: { QTextLength* _r = _t->new_QTextLength();
            if (_a[0]) *reinterpret_cast< QTextLength**>(_a[0]) = _r; }  break;
        case 1: { QTextLength* _r = _t->new_QTextLength((*reinterpret_cast< QTextLength::Type(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QTextLength**>(_a[0]) = _r; }  break;
        case 2: { QTextLength* _r = _t->new_QTextLength((*reinterpret_cast< const QTextLength(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextLength**>(_a[0]) = _r; }  break;
        case 3: _t->delete_QTextLength((*reinterpret_cast< QTextLength*(*)>(_a[1]))); break;
        case 4: { bool _r = _t->__ne__((*reinterpret_cast< QTextLength*(*)>(_a[1])),(*reinterpret_cast< const QTextLength(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->writeTo((*reinterpret_cast< QTextLength*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 6: { bool _r = _t->__eq__((*reinterpret_cast< QTextLength*(*)>(_a[1])),(*reinterpret_cast< const QTextLength(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->readFrom((*reinterpret_cast< QTextLength*(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 8: { qreal _r = _t->rawValue((*reinterpret_cast< QTextLength*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 9: { QTextLength::Type _r = _t->type((*reinterpret_cast< QTextLength*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTextLength::Type*>(_a[0]) = _r; }  break;
        case 10: { qreal _r = _t->value((*reinterpret_cast< QTextLength*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PythonQtWrapper_QTextLength::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PythonQtWrapper_QTextLength::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PythonQtWrapper_QTextLength,
      qt_meta_data_PythonQtWrapper_QTextLength, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PythonQtWrapper_QTextLength::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PythonQtWrapper_QTextLength::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PythonQtWrapper_QTextLength::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PythonQtWrapper_QTextLength))
        return static_cast<void*>(const_cast< PythonQtWrapper_QTextLength*>(this));
    return QObject::qt_metacast(_clname);
}

int PythonQtWrapper_QTextLength::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
