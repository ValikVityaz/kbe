/****************************************************************************
** Meta object code from reading C++ file 'scgcontentnumeric.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scgcontentnumeric.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgcontentnumeric.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgContentNumericDialog_t {
    QByteArrayData data[5];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgContentNumericDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgContentNumericDialog_t qt_meta_stringdata_SCgContentNumericDialog = {
    {
QT_MOC_LITERAL(0, 0, 23), // "SCgContentNumericDialog"
QT_MOC_LITERAL(1, 24, 17), // "enableApplyButton"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 17), // "QValidator::State"
QT_MOC_LITERAL(4, 61, 21) // "slotEnableApplyButton"

    },
    "SCgContentNumericDialog\0enableApplyButton\0"
    "\0QValidator::State\0slotEnableApplyButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgContentNumericDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void SCgContentNumericDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgContentNumericDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableApplyButton((*reinterpret_cast< QValidator::State(*)>(_a[1]))); break;
        case 1: _t->slotEnableApplyButton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SCgContentNumericDialog::*)(QValidator::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgContentNumericDialog::enableApplyButton)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SCgContentNumericDialog::staticMetaObject = { {
    &SCgContentDialog::staticMetaObject,
    qt_meta_stringdata_SCgContentNumericDialog.data,
    qt_meta_data_SCgContentNumericDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgContentNumericDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgContentNumericDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgContentNumericDialog.stringdata0))
        return static_cast<void*>(this);
    return SCgContentDialog::qt_metacast(_clname);
}

int SCgContentNumericDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SCgContentDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SCgContentNumericDialog::enableApplyButton(QValidator::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
