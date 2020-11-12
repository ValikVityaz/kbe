/****************************************************************************
** Meta object code from reading C++ file 'scgfindwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scgfindwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgfindwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgFindWidget_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgFindWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgFindWidget_t qt_meta_stringdata_SCgFindWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SCgFindWidget"
QT_MOC_LITERAL(1, 14, 13), // "escapePressed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "findNext"
QT_MOC_LITERAL(4, 38, 12), // "findPrevious"
QT_MOC_LITERAL(5, 51, 4), // "find"
QT_MOC_LITERAL(6, 56, 4), // "text"
QT_MOC_LITERAL(7, 61, 13), // "updateButtons"
QT_MOC_LITERAL(8, 75, 11), // "textChanged"
QT_MOC_LITERAL(9, 87, 22) // "caseSensitivityChanged"

    },
    "SCgFindWidget\0escapePressed\0\0findNext\0"
    "findPrevious\0find\0text\0updateButtons\0"
    "textChanged\0caseSensitivityChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgFindWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void SCgFindWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgFindWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->escapePressed(); break;
        case 1: _t->findNext(); break;
        case 2: _t->findPrevious(); break;
        case 3: _t->find((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->updateButtons(); break;
        case 5: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->caseSensitivityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SCgFindWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgFindWidget::escapePressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SCgFindWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgFindWidget::findNext)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SCgFindWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgFindWidget::findPrevious)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SCgFindWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgFindWidget::find)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SCgFindWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_SCgFindWidget.data,
    qt_meta_data_SCgFindWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgFindWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgFindWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgFindWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SCgFindWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SCgFindWidget::escapePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SCgFindWidget::findNext()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SCgFindWidget::findPrevious()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SCgFindWidget::find(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
