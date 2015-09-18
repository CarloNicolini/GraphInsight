/****************************************************************************
** Meta object code from reading C++ file 'SplashDialog.h'
**
** Created: Wed Apr 23 09:59:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SplashDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SplashDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplashDialog[] = {

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
      14,   13,   13,   13, 0x08,
      53,   13,   13,   13, 0x08,
      88,   13,   13,   13, 0x08,
     133,   13,   13,   13, 0x08,
     176,  168,   13,   13, 0x08,
     204,   13,   13,   13, 0x08,
     230,  168,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SplashDialog[] = {
    "SplashDialog\0\0on_commandLinkButton_Website_clicked()\0"
    "on_commandLinkButton_PPA_clicked()\0"
    "on_commandLinkButton_SocialNetwork_clicked()\0"
    "on_commandLinkButton_SAT_clicked()\0"
    "checked\0on_checkBox_3_clicked(bool)\0"
    "on_actionQuit_triggered()\0"
    "on_actionQuit_triggered(bool)\0"
};

void SplashDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SplashDialog *_t = static_cast<SplashDialog *>(_o);
        switch (_id) {
        case 0: _t->on_commandLinkButton_Website_clicked(); break;
        case 1: _t->on_commandLinkButton_PPA_clicked(); break;
        case 2: _t->on_commandLinkButton_SocialNetwork_clicked(); break;
        case 3: _t->on_commandLinkButton_SAT_clicked(); break;
        case 4: _t->on_checkBox_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_actionQuit_triggered(); break;
        case 6: _t->on_actionQuit_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SplashDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SplashDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SplashDialog,
      qt_meta_data_SplashDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplashDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplashDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplashDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplashDialog))
        return static_cast<void*>(const_cast< SplashDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SplashDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
