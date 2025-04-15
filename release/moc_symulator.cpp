/****************************************************************************
** Meta object code from reading C++ file 'symulator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../symulator.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSymulatorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSymulatorENDCLASS = QtMocHelpers::stringData(
    "Symulator",
    "nextStep",
    "",
    "on_list_WartoscZadana_currentRowChanged",
    "currentRow",
    "on_button_zapisz_clicked",
    "on_button_wczytaj_clicked",
    "on_button_reset_clicked",
    "on_button_start_clicked",
    "on_button_stop_clicked",
    "on_spinbox_interval_valueChanged",
    "arg1",
    "on_spinbox_maksimumY_valueChanged",
    "on_checkBox_stateChanged",
    "on_lineEdit_A_editingFinished",
    "on_lineEdit_B_editingFinished",
    "on_button_reset_pid_clicked",
    "on_comboBox_mode_currentIndexChanged",
    "index",
    "on_arxModify_clicked",
    "on_button_online_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymulatorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    1,  111,    2, 0x08,    2 /* Private */,
       5,    0,  114,    2, 0x08,    4 /* Private */,
       6,    0,  115,    2, 0x08,    5 /* Private */,
       7,    0,  116,    2, 0x08,    6 /* Private */,
       8,    0,  117,    2, 0x08,    7 /* Private */,
       9,    0,  118,    2, 0x08,    8 /* Private */,
      10,    1,  119,    2, 0x08,    9 /* Private */,
      12,    1,  122,    2, 0x08,   11 /* Private */,
      13,    1,  125,    2, 0x08,   13 /* Private */,
      14,    0,  128,    2, 0x08,   15 /* Private */,
      15,    0,  129,    2, 0x08,   16 /* Private */,
      16,    0,  130,    2, 0x08,   17 /* Private */,
      17,    1,  131,    2, 0x08,   18 /* Private */,
      19,    0,  134,    2, 0x08,   20 /* Private */,
      20,    0,  135,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Symulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSymulatorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSymulatorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSymulatorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Symulator, std::true_type>,
        // method 'nextStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_list_WartoscZadana_currentRowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_zapisz_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_wczytaj_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_reset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_start_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinbox_interval_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_spinbox_maksimumY_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_lineEdit_A_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_B_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_reset_pid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_mode_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_arxModify_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_online_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Symulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Symulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nextStep(); break;
        case 1: _t->on_list_WartoscZadana_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_button_zapisz_clicked(); break;
        case 3: _t->on_button_wczytaj_clicked(); break;
        case 4: _t->on_button_reset_clicked(); break;
        case 5: _t->on_button_start_clicked(); break;
        case 6: _t->on_button_stop_clicked(); break;
        case 7: _t->on_spinbox_interval_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->on_spinbox_maksimumY_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_lineEdit_A_editingFinished(); break;
        case 11: _t->on_lineEdit_B_editingFinished(); break;
        case 12: _t->on_button_reset_pid_clicked(); break;
        case 13: _t->on_comboBox_mode_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_arxModify_clicked(); break;
        case 15: _t->on_button_online_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Symulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Symulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSymulatorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Symulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
