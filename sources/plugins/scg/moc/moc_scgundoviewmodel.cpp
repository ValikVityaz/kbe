/****************************************************************************
** Meta object code from reading C++ file 'scgundoviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scgundoviewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgundoviewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgUndoViewModel_t {
    QByteArrayData data[11];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgUndoViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgUndoViewModel_t qt_meta_stringdata_SCgUndoViewModel = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SCgUndoViewModel"
QT_MOC_LITERAL(1, 17, 8), // "setStack"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "QUndoStack*"
QT_MOC_LITERAL(4, 39, 5), // "stack"
QT_MOC_LITERAL(5, 45, 12), // "stackChanged"
QT_MOC_LITERAL(6, 58, 14), // "stackDestroyed"
QT_MOC_LITERAL(7, 73, 3), // "obj"
QT_MOC_LITERAL(8, 77, 20), // "setStackCurrentIndex"
QT_MOC_LITERAL(9, 98, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 110, 5) // "index"

    },
    "SCgUndoViewModel\0setStack\0\0QUndoStack*\0"
    "stack\0stackChanged\0stackDestroyed\0obj\0"
    "setStackCurrentIndex\0QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgUndoViewModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x08 /* Private */,
       6,    1,   38,    2, 0x08 /* Private */,
       8,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void SCgUndoViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgUndoViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setStack((*reinterpret_cast< QUndoStack*(*)>(_a[1]))); break;
        case 1: _t->stackChanged(); break;
        case 2: _t->stackDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 3: _t->setStackCurrentIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SCgUndoViewModel::staticMetaObject = { {
    &QAbstractItemModel::staticMetaObject,
    qt_meta_stringdata_SCgUndoViewModel.data,
    qt_meta_data_SCgUndoViewModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgUndoViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgUndoViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgUndoViewModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int SCgUndoViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
