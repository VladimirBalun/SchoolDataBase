#include "Pupil.h"

Pupil::Builder &Pupil::Builder::setName(QString& name)
{
    _name = name;
    return *this;
}

Pupil::Builder &Pupil::Builder::setDateBirth(QString& dateBirth)
{
    _dateBirth = dateBirth;
    return *this;
}

Pupil::Builder &Pupil::Builder::setAddress(QString& address)
{
    _address = address;
    return *this;
}

Pupil::Builder &Pupil::Builder::setNameClass(QString& nameClass)
{
    _nameClass = nameClass;
    return *this;
}

Pupil* Pupil::Builder::build()
{
    return new Pupil(_name, _dateBirth, _address, _nameClass);
}

QString Pupil::getName() const
{
    return _name;
}

QString Pupil::getDateBirth() const
{
    return _dateBirth;
}

QString Pupil::getAddress() const
{
    return _address;
}

QString Pupil::getNameClass() const
{
    return _nameClass;
}
