/****************************************************************************
** Meta object code from reading C++ file 'protothread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../protothread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_protoThread_t {
    QByteArrayData data[14];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_protoThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_protoThread_t qt_meta_stringdata_protoThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "protoThread"
QT_MOC_LITERAL(1, 12, 7), // "sendlog"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "type"
QT_MOC_LITERAL(4, 26, 3), // "msg"
QT_MOC_LITERAL(5, 30, 10), // "sendpacket"
QT_MOC_LITERAL(6, 41, 7), // "numchan"
QT_MOC_LITERAL(7, 49, 5), // "value"
QT_MOC_LITERAL(8, 55, 12), // "setDebugMode"
QT_MOC_LITERAL(9, 68, 5), // "state"
QT_MOC_LITERAL(10, 74, 17), // "setConnectedState"
QT_MOC_LITERAL(11, 92, 7), // "setPort"
QT_MOC_LITERAL(12, 100, 12), // "QSerialPort*"
QT_MOC_LITERAL(13, 113, 4) // "port"

    },
    "protoThread\0sendlog\0\0type\0msg\0sendpacket\0"
    "numchan\0value\0setDebugMode\0state\0"
    "setConnectedState\0setPort\0QSerialPort*\0"
    "port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_protoThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   49,    2, 0x0a /* Public */,
      10,    1,   52,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::UChar, QMetaType::Double,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void protoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        protoThread *_t = static_cast<protoThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendlog((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendpacket((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->setDebugMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setConnectedState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setPort((*reinterpret_cast< QSerialPort*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (protoThread::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&protoThread::sendlog)) {
                *result = 0;
            }
        }
        {
            typedef void (protoThread::*_t)(unsigned char , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&protoThread::sendpacket)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject protoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_protoThread.data,
      qt_meta_data_protoThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *protoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *protoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_protoThread.stringdata0))
        return static_cast<void*>(const_cast< protoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int protoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void protoThread::sendlog(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void protoThread::sendpacket(unsigned char _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
