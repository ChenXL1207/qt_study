/****************************************************************************
** Meta object code from reading C++ file 'ui_page1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sample_3_1/ui_page1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui_page1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ui_page1_t {
    QByteArrayData data[6];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ui_page1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ui_page1_t qt_meta_stringdata_ui_page1 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ui_page1"
QT_MOC_LITERAL(1, 9, 19), // "slots_onGrowClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "sexNum"
QT_MOC_LITERAL(4, 37, 27), // "slots_onShowMetaInfoClicked"
QT_MOC_LITERAL(5, 65, 20) // "slots_onClearClicked"

    },
    "ui_page1\0slots_onGrowClicked\0\0sexNum\0"
    "slots_onShowMetaInfoClicked\0"
    "slots_onClearClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ui_page1[] = {

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
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ui_page1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ui_page1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slots_onGrowClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slots_onShowMetaInfoClicked(); break;
        case 2: _t->slots_onClearClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ui_page1::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ui_page1.data,
    qt_meta_data_ui_page1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ui_page1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ui_page1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ui_page1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ui_page1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
