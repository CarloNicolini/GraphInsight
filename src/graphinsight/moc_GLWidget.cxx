/****************************************************************************
** Meta object code from reading C++ file 'GLWidget.h'
**
** Created: Wed Apr 23 09:59:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GLWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      74,   26,    9,    9, 0x05,
     119,    9,    9,    9, 0x05,
     132,    9,    9,    9, 0x05,
     156,  150,    9,    9, 0x05,
     184,    9,    9,    9, 0x05,
     205,  201,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     227,    9,    9,    9, 0x0a,
     279,  247,  242,    9, 0x0a,
     314,  305,  242,    9, 0x0a,
     332,    9,  242,    9, 0x2a,
     343,  305,  242,    9, 0x0a,
     362,    9,  242,    9, 0x2a,
     374,    9,    9,    9, 0x0a,
     386,    9,    9,    9, 0x0a,
     432,  409,    9,    9, 0x0a,
     448,    9,    9,    9, 0x0a,
     463,  461,    9,    9, 0x0a,
     482,  461,    9,    9, 0x0a,
     501,  461,    9,    9, 0x0a,
     523,  461,    9,    9, 0x0a,
     550,  461,    9,    9, 0x0a,
     589,  461,    9,    9, 0x0a,
     620,  461,    9,    9, 0x0a,
     643,  639,    9,    9, 0x0a,
     674,    9,    9,    9, 0x0a,
     681,  461,    9,    9, 0x0a,
     718,  716,    9,    9, 0x0a,
     737,  716,    9,    9, 0x0a,
     755,  716,    9,    9, 0x0a,
     777,  461,    9,    9, 0x0a,
     793,  461,    9,    9, 0x0a,
     806,    9,    9,    9, 0x0a,
     826,    9,    9,    9, 0x0a,
     847,    9,    9,    9, 0x0a,
     872,    9,    9,    9, 0x0a,
     896,  887,    9,    9, 0x0a,
     920,  887,    9,    9, 0x0a,
     947,  944,    9,    9, 0x0a,
     968,  461,    9,    9, 0x0a,
     980,  461,    9,    9, 0x0a,
     999,  461,    9,    9, 0x0a,
    1015,  461,    9,    9, 0x0a,
    1033,  461,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0dataSetLoaded()\0"
    "nodes,edges,stepsCount,elapsedTime,layoutStatus\0"
    "graphStatsChanged(int,int,int,ulong,QString)\0"
    "hasAborted()\0layoutCompleted()\0lnode\0"
    "selectedNodeChanged(LNode*)\0"
    "nodeUnselected()\0fps\0paintFinished(double)\0"
    "updateColors()\0bool\0pathname,methodType,nDimensions\0"
    "openFile(QString,int,int)\0pathname\0"
    "saveFile(QString)\0saveFile()\0"
    "saveImage(QString)\0saveImage()\0"
    "initEmpty()\0randomizeCoordinates()\0"
    "methodType,nDimensions\0reload(int,int)\0"
    "resetScene()\0v\0setEdgeRadius(int)\0"
    "setGLEnabled(bool)\0setLabelFontSize(int)\0"
    "setLabelMinNodeDegree(int)\0"
    "setLabelShowSelectedItemAdjacent(bool)\0"
    "setLabelShowSelectedItem(bool)\0"
    "setNodeRadius(int)\0val\0"
    "setNonIntersectingLabels(bool)\0stop()\0"
    "visualizationFilterNodeDegree(int)\0b\0"
    "setShowEdges(bool)\0setFastMode(bool)\0"
    "setAutoRotation(bool)\0setSpacing(int)\0"
    "setZoom(int)\0contextMenu(QPoint)\0"
    "selectedNodeAction()\0selectedNodeAttrAction()\0"
    "unselectNode()\0methodId\0setNodeColorMethod(int)\0"
    "setEdgeColorMethod(int)\0id\0"
    "setSelectedNode(int)\0setFog(int)\0"
    "setNightMode(bool)\0setQuality(int)\0"
    "setShowGrid(bool)\0setEdgeType(int)\0"
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLWidget *_t = static_cast<GLWidget *>(_o);
        switch (_id) {
        case 0: _t->dataSetLoaded(); break;
        case 1: _t->graphStatsChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< ulong(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->hasAborted(); break;
        case 3: _t->layoutCompleted(); break;
        case 4: _t->selectedNodeChanged((*reinterpret_cast< LNode*(*)>(_a[1]))); break;
        case 5: _t->nodeUnselected(); break;
        case 6: _t->paintFinished((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->updateColors(); break;
        case 8: { bool _r = _t->openFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->saveImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->saveImage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: _t->initEmpty(); break;
        case 14: _t->randomizeCoordinates(); break;
        case 15: _t->reload((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->resetScene(); break;
        case 17: _t->setEdgeRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->setGLEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setLabelFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setLabelMinNodeDegree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setLabelShowSelectedItemAdjacent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->setLabelShowSelectedItem((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setNodeRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setNonIntersectingLabels((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->stop(); break;
        case 26: _t->visualizationFilterNodeDegree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->setShowEdges((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->setFastMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->setAutoRotation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->setSpacing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->contextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 33: _t->selectedNodeAction(); break;
        case 34: _t->selectedNodeAttrAction(); break;
        case 35: _t->unselectNode(); break;
        case 36: _t->setNodeColorMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->setEdgeColorMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->setSelectedNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->setFog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->setNightMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->setQuality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->setShowGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->setEdgeType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::dataSetLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GLWidget::graphStatsChanged(int _t1, int _t2, int _t3, unsigned long _t4, QString _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWidget::hasAborted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GLWidget::layoutCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GLWidget::selectedNodeChanged(LNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLWidget::nodeUnselected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GLWidget::paintFinished(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
