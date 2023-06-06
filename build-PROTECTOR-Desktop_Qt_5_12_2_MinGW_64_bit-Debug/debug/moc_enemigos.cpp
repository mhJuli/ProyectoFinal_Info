/****************************************************************************
** Meta object code from reading C++ file 'enemigos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PROTECTOR_PROJECT/enemigos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemigos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Enemigos_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enemigos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enemigos_t qt_meta_stringdata_Enemigos = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Enemigos"
QT_MOC_LITERAL(1, 9, 7), // "cambioE"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "disparo"
QT_MOC_LITERAL(4, 26, 6) // "muerte"

    },
    "Enemigos\0cambioE\0\0disparo\0muerte"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemigos[] = {

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
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enemigos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemigos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cambioE(); break;
        case 1: _t->disparo(); break;
        case 2: _t->muerte(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Enemigos::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Enemigos.data,
    qt_meta_data_Enemigos,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enemigos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemigos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemigos.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "base"))
        return static_cast< base*>(this);
    return QObject::qt_metacast(_clname);
}

int Enemigos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Enemigo1_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enemigo1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enemigo1_t qt_meta_stringdata_Enemigo1 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Enemigo1"
QT_MOC_LITERAL(1, 9, 7), // "cambioE"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "disparo"
QT_MOC_LITERAL(4, 26, 6) // "muerte"

    },
    "Enemigo1\0cambioE\0\0disparo\0muerte"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemigo1[] = {

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
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enemigo1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemigo1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cambioE(); break;
        case 1: _t->disparo(); break;
        case 2: _t->muerte(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Enemigo1::staticMetaObject = { {
    &Enemigos::staticMetaObject,
    qt_meta_stringdata_Enemigo1.data,
    qt_meta_data_Enemigo1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enemigo1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemigo1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemigo1.stringdata0))
        return static_cast<void*>(this);
    return Enemigos::qt_metacast(_clname);
}

int Enemigo1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Enemigos::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Enemigo2_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enemigo2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enemigo2_t qt_meta_stringdata_Enemigo2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Enemigo2"
QT_MOC_LITERAL(1, 9, 7), // "cambioE"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "disparo"
QT_MOC_LITERAL(4, 26, 6) // "muerte"

    },
    "Enemigo2\0cambioE\0\0disparo\0muerte"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemigo2[] = {

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
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enemigo2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemigo2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cambioE(); break;
        case 1: _t->disparo(); break;
        case 2: _t->muerte(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Enemigo2::staticMetaObject = { {
    &Enemigos::staticMetaObject,
    qt_meta_stringdata_Enemigo2.data,
    qt_meta_data_Enemigo2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enemigo2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemigo2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemigo2.stringdata0))
        return static_cast<void*>(this);
    return Enemigos::qt_metacast(_clname);
}

int Enemigo2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Enemigos::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Enemigo3_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enemigo3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enemigo3_t qt_meta_stringdata_Enemigo3 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Enemigo3"
QT_MOC_LITERAL(1, 9, 7), // "cambioE"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "disparo"
QT_MOC_LITERAL(4, 26, 6) // "muerte"

    },
    "Enemigo3\0cambioE\0\0disparo\0muerte"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemigo3[] = {

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
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enemigo3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemigo3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cambioE(); break;
        case 1: _t->disparo(); break;
        case 2: _t->muerte(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Enemigo3::staticMetaObject = { {
    &Enemigos::staticMetaObject,
    qt_meta_stringdata_Enemigo3.data,
    qt_meta_data_Enemigo3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enemigo3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemigo3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemigo3.stringdata0))
        return static_cast<void*>(this);
    return Enemigos::qt_metacast(_clname);
}

int Enemigo3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Enemigos::qt_metacall(_c, _id, _a);
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
