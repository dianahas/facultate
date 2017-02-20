/****************************************************************************
** Meta object code from reading C++ file 'dogsqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dogsqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dogsqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DogsQT_t {
    QByteArrayData data[9];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DogsQT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DogsQT_t qt_meta_stringdata_DogsQT = {
    {
QT_MOC_LITERAL(0, 0, 6), // "DogsQT"
QT_MOC_LITERAL(1, 7, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "addNewDog"
QT_MOC_LITERAL(4, 34, 9), // "deleteDog"
QT_MOC_LITERAL(5, 44, 9), // "updateDog"
QT_MOC_LITERAL(6, 54, 22), // "moveAllDogsToWatchlist"
QT_MOC_LITERAL(7, 77, 29), // "moveAllDogsByBreedToWatchlist"
QT_MOC_LITERAL(8, 107, 17) // "openWatchlistFile"

    },
    "DogsQT\0listItemChanged\0\0addNewDog\0"
    "deleteDog\0updateDog\0moveAllDogsToWatchlist\0"
    "moveAllDogsByBreedToWatchlist\0"
    "openWatchlistFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DogsQT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DogsQT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DogsQT *_t = static_cast<DogsQT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->addNewDog(); break;
        case 2: _t->deleteDog(); break;
        case 3: _t->updateDog(); break;
        case 4: _t->moveAllDogsToWatchlist(); break;
        case 5: _t->moveAllDogsByBreedToWatchlist(); break;
        case 6: _t->openWatchlistFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DogsQT::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DogsQT.data,
      qt_meta_data_DogsQT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DogsQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DogsQT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DogsQT.stringdata0))
        return static_cast<void*>(const_cast< DogsQT*>(this));
    return QWidget::qt_metacast(_clname);
}

int DogsQT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
