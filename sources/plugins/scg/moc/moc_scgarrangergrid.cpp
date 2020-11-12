/****************************************************************************
** Meta object code from reading C++ file 'scgarrangergrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../arrangers/scgarrangergrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgarrangergrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgGridArranger_t {
    QByteArrayData data[7];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgGridArranger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgGridArranger_t qt_meta_stringdata_SCgGridArranger = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SCgGridArranger"
QT_MOC_LITERAL(1, 16, 13), // "xValueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "newSpacing"
QT_MOC_LITERAL(4, 42, 13), // "yValueChanged"
QT_MOC_LITERAL(5, 56, 26), // "symmetricalCheckBoxClicked"
QT_MOC_LITERAL(6, 83, 7) // "checked"

    },
    "SCgGridArranger\0xValueChanged\0\0"
    "newSpacing\0yValueChanged\0"
    "symmetricalCheckBoxClicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgGridArranger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x09 /* Protected */,
       4,    1,   32,    2, 0x09 /* Protected */,
       5,    1,   35,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void SCgGridArranger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgGridArranger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->symmetricalCheckBoxClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SCgGridArranger::staticMetaObject = { {
    &SCgArranger::staticMetaObject,
    qt_meta_stringdata_SCgGridArranger.data,
    qt_meta_data_SCgGridArranger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgGridArranger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgGridArranger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgGridArranger.stringdata0))
        return static_cast<void*>(this);
    return SCgArranger::qt_metacast(_clname);
}

int SCgGridArranger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SCgArranger::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
