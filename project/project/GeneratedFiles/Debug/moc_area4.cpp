/****************************************************************************
** Meta object code from reading C++ file 'area4.h'
**
** Created: Sat Nov 29 20:47:29 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../area4.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'area4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Area4[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Area4[] = {
    "Area4\0"
};

const QMetaObject Area4::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Area4,
      qt_meta_data_Area4, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Area4::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Area4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Area4::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Area4))
        return static_cast<void*>(const_cast< Area4*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Area4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
