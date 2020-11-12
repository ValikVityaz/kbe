/****************************************************************************
** Meta object code from reading C++ file 'scgview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scgview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scgview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCgView_t {
    QByteArrayData data[30];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCgView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCgView_t qt_meta_stringdata_SCgView = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SCgView"
QT_MOC_LITERAL(1, 8, 12), // "scaleChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "newScaleFactor"
QT_MOC_LITERAL(4, 37, 16), // "sceneRectChanged"
QT_MOC_LITERAL(5, 54, 7), // "newRect"
QT_MOC_LITERAL(6, 62, 18), // "updateActionsState"
QT_MOC_LITERAL(7, 81, 3), // "idx"
QT_MOC_LITERAL(8, 85, 16), // "selectAllCommand"
QT_MOC_LITERAL(9, 102, 8), // "setScale"
QT_MOC_LITERAL(10, 111, 2), // "sc"
QT_MOC_LITERAL(11, 114, 11), // "scaleFactor"
QT_MOC_LITERAL(12, 126, 8), // "setScene"
QT_MOC_LITERAL(13, 135, 9), // "SCgScene*"
QT_MOC_LITERAL(14, 145, 5), // "scene"
QT_MOC_LITERAL(15, 151, 14), // "deleteSelected"
QT_MOC_LITERAL(16, 166, 17), // "deleteJustContour"
QT_MOC_LITERAL(17, 184, 14), // "swapPairOrient"
QT_MOC_LITERAL(18, 199, 16), // "changeIdentifier"
QT_MOC_LITERAL(19, 216, 14), // "showTypeDialog"
QT_MOC_LITERAL(20, 231, 10), // "changeType"
QT_MOC_LITERAL(21, 242, 7), // "newType"
QT_MOC_LITERAL(22, 250, 13), // "changeContent"
QT_MOC_LITERAL(23, 264, 17), // "setContentVisible"
QT_MOC_LITERAL(24, 282, 10), // "visibility"
QT_MOC_LITERAL(25, 293, 13), // "deleteContent"
QT_MOC_LITERAL(26, 307, 15), // "updateSceneRect"
QT_MOC_LITERAL(27, 323, 4), // "rect"
QT_MOC_LITERAL(28, 328, 15), // "editModeChanged"
QT_MOC_LITERAL(29, 344, 4) // "mode"

    },
    "SCgView\0scaleChanged\0\0newScaleFactor\0"
    "sceneRectChanged\0newRect\0updateActionsState\0"
    "idx\0selectAllCommand\0setScale\0sc\0"
    "scaleFactor\0setScene\0SCgScene*\0scene\0"
    "deleteSelected\0deleteJustContour\0"
    "swapPairOrient\0changeIdentifier\0"
    "showTypeDialog\0changeType\0newType\0"
    "changeContent\0setContentVisible\0"
    "visibility\0deleteContent\0updateSceneRect\0"
    "rect\0editModeChanged\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCgView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  115,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x28 /* Private | MethodCloned */,
       8,    0,  119,    2, 0x08 /* Private */,
       9,    1,  120,    2, 0x0a /* Public */,
       9,    1,  123,    2, 0x0a /* Public */,
      12,    1,  126,    2, 0x0a /* Public */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    0,  130,    2, 0x08 /* Private */,
      17,    0,  131,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    1,  134,    2, 0x08 /* Private */,
      22,    0,  137,    2, 0x08 /* Private */,
      23,    1,  138,    2, 0x08 /* Private */,
      25,    0,  141,    2, 0x08 /* Private */,
      26,    1,  142,    2, 0x08 /* Private */,
      28,    1,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QRectF,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF,   27,
    QMetaType::Void, QMetaType::Int,   29,

       0        // eod
};

void SCgView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCgView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scaleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->sceneRectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: _t->updateActionsState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateActionsState(); break;
        case 4: _t->selectAllCommand(); break;
        case 5: _t->setScale((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setScale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->setScene((*reinterpret_cast< SCgScene*(*)>(_a[1]))); break;
        case 8: _t->deleteSelected(); break;
        case 9: _t->deleteJustContour(); break;
        case 10: _t->swapPairOrient(); break;
        case 11: _t->changeIdentifier(); break;
        case 12: _t->showTypeDialog(); break;
        case 13: _t->changeType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->changeContent(); break;
        case 15: _t->setContentVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->deleteContent(); break;
        case 17: _t->updateSceneRect((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 18: _t->editModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SCgView::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgView::scaleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SCgView::*)(const QRectF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCgView::sceneRectChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SCgView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_SCgView.data,
    qt_meta_data_SCgView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SCgView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCgView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCgView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int SCgView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void SCgView::scaleChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SCgView::sceneRectChanged(const QRectF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
