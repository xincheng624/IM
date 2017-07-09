/****************************************************************************
** Meta object code from reading C++ file 'clientSocket.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientSocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_clientSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      55,   46,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   14,   13,   13, 0x0a,
     108,   13,   13,   13, 0x0a,
     125,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_clientSocket[] = {
    "clientSocket\0\0Info\0sendSignals(TranssionInfo)\0"
    "clientId\0disconnectClient(QString)\0"
    "sendMessage(TranssionInfo)\0receiveMessage()\0"
    "deleteClientSocket()\0"
};

void clientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        clientSocket *_t = static_cast<clientSocket *>(_o);
        switch (_id) {
        case 0: _t->sendSignals((*reinterpret_cast< const TranssionInfo(*)>(_a[1]))); break;
        case 1: _t->disconnectClient((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sendMessage((*reinterpret_cast< const TranssionInfo(*)>(_a[1]))); break;
        case 3: _t->receiveMessage(); break;
        case 4: _t->deleteClientSocket(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData clientSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject clientSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_clientSocket,
      qt_meta_data_clientSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &clientSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *clientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *clientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clientSocket))
        return static_cast<void*>(const_cast< clientSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int clientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void clientSocket::sendSignals(const TranssionInfo & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void clientSocket::disconnectClient(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
