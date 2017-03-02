/****************************************************************************
** Meta object code from reading C++ file 'wm_waferview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Gui/wm_waferview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wm_waferview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wm__CWaferView_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wm__CWaferView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wm__CWaferView_t qt_meta_stringdata_wm__CWaferView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "wm::CWaferView"
QT_MOC_LITERAL(1, 15, 19), // "onHSliderPosChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "nNewPos"
QT_MOC_LITERAL(4, 44, 19) // "onVSliderPosChanged"

    },
    "wm::CWaferView\0onHSliderPosChanged\0\0"
    "nNewPos\0onVSliderPosChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wm__CWaferView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x09 /* Protected */,
       4,    1,   27,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void wm::CWaferView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CWaferView *_t = static_cast<CWaferView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onHSliderPosChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onVSliderPosChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject wm::CWaferView::staticMetaObject = {
    { &QAbstractScrollArea::staticMetaObject, qt_meta_stringdata_wm__CWaferView.data,
      qt_meta_data_wm__CWaferView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wm::CWaferView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wm::CWaferView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wm__CWaferView.stringdata0))
        return static_cast<void*>(const_cast< CWaferView*>(this));
    return QAbstractScrollArea::qt_metacast(_clname);
}

int wm::CWaferView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
