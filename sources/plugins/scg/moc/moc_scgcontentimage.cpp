/****************************************************************************
** Meta object code from reading C++ file 'scgcontentimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scgcontentimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgcontentimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgContentImageViewer_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgContentImageViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgContentImageViewer_t qt_meta_stringdata_SCgContentImageViewer = {
    {
QT_MOC_LITERAL(0, 0, 21) // "SCgContentImageViewer"

    },
    "SCgContentImageViewer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgContentImageViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SCgContentImageViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SCgContentImageViewer::staticMetaObject = { {
    &SCgContentViewer::staticMetaObject,
    qt_meta_stringdata_SCgContentImageViewer.data,
    qt_meta_data_SCgContentImageViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgContentImageViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgContentImageViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgContentImageViewer.stringdata0))
        return static_cast<void*>(this);
    return SCgContentViewer::qt_metacast(_clname);
}

int SCgContentImageViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SCgContentViewer::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SCgContentImageDialog_t {
    QByteArrayData data[3];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgContentImageDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgContentImageDialog_t qt_meta_stringdata_SCgContentImageDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "SCgContentImageDialog"
QT_MOC_LITERAL(1, 22, 12), // "chooseSource"
QT_MOC_LITERAL(2, 35, 0) // ""

    },
    "SCgContentImageDialog\0chooseSource\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgContentImageDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SCgContentImageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgContentImageDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chooseSource(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SCgContentImageDialog::staticMetaObject = { {
    &SCgContentDialog::staticMetaObject,
    qt_meta_stringdata_SCgContentImageDialog.data,
    qt_meta_data_SCgContentImageDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgContentImageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgContentImageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgContentImageDialog.stringdata0))
        return static_cast<void*>(this);
    return SCgContentDialog::qt_metacast(_clname);
}

int SCgContentImageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SCgContentDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
