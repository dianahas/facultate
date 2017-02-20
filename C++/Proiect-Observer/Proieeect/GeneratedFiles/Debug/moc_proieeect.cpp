/****************************************************************************
** Meta object code from reading C++ file 'proieeect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../proieeect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proieeect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Proieeect_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Proieeect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Proieeect_t qt_meta_stringdata_Proieeect = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Proieeect"
QT_MOC_LITERAL(1, 10, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "addIssue"
QT_MOC_LITERAL(4, 36, 11), // "removeIssue"
QT_MOC_LITERAL(5, 48, 11) // "updateIssue"

    },
    "Proieeect\0listItemChanged\0\0addIssue\0"
    "removeIssue\0updateIssue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Proieeect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Proieeect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Proieeect *_t = static_cast<Proieeect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->addIssue(); break;
        case 2: _t->removeIssue(); break;
        case 3: _t->updateIssue(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Proieeect::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Proieeect.data,
      qt_meta_data_Proieeect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Proieeect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Proieeect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Proieeect.stringdata0))
        return static_cast<void*>(const_cast< Proieeect*>(this));
    if (!strcmp(_clname, "Observer"))
        return static_cast< Observer*>(const_cast< Proieeect*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Proieeect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
