/****************************************************************************
** Meta object code from reading C++ file 'CQMandelbrotTest.h'
**
** Created: Wed Aug 21 21:34:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CQMandelbrotTest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQMandelbrotTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CQMandelbrotTest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      25,   17,   17,   17, 0x08,
      38,   17,   17,   17, 0x08,
      55,   17,   17,   17, 0x08,
      73,   17,   17,   17, 0x08,
      91,   17,   17,   17, 0x08,
     109,   17,   17,   17, 0x08,
     128,   17,   17,   17, 0x08,
     147,   17,   17,   17, 0x08,
     166,   17,   17,   17, 0x08,
     186,   17,   17,   17, 0x08,
     206,   17,   17,   17, 0x08,
     225,   17,   17,   17, 0x08,
     241,   17,   17,   17, 0x08,
     258,   17,   17,   17, 0x08,
     272,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CQMandelbrotTest[] = {
    "CQMandelbrotTest\0\0quit()\0resetRange()\0"
    "setIterations8()\0setIterations16()\0"
    "setIterations32()\0setIterations64()\0"
    "setIterations128()\0setIterations256()\0"
    "setIterations512()\0setIterations1024()\0"
    "setIterations2048()\0toggleShowVector()\0"
    "toggleAnimate()\0toggleThreaded()\0"
    "animateSlot()\0help()\0"
};

void CQMandelbrotTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CQMandelbrotTest *_t = static_cast<CQMandelbrotTest *>(_o);
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->resetRange(); break;
        case 2: _t->setIterations8(); break;
        case 3: _t->setIterations16(); break;
        case 4: _t->setIterations32(); break;
        case 5: _t->setIterations64(); break;
        case 6: _t->setIterations128(); break;
        case 7: _t->setIterations256(); break;
        case 8: _t->setIterations512(); break;
        case 9: _t->setIterations1024(); break;
        case 10: _t->setIterations2048(); break;
        case 11: _t->toggleShowVector(); break;
        case 12: _t->toggleAnimate(); break;
        case 13: _t->toggleThreaded(); break;
        case 14: _t->animateSlot(); break;
        case 15: _t->help(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CQMandelbrotTest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CQMandelbrotTest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CQMandelbrotTest,
      qt_meta_data_CQMandelbrotTest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CQMandelbrotTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CQMandelbrotTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CQMandelbrotTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQMandelbrotTest))
        return static_cast<void*>(const_cast< CQMandelbrotTest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CQMandelbrotTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
