#include "Parent.h"

Parent::Builder &Parent::Builder::setName(QString &name)
{
    _name = name;
    return *this;
}

Parent::Builder &Parent::Builder::setDateBirth(QString &dateBirth)
{
    _dateBirth = dateBirth;
    return *this;
}

Parent::Builder &Parent::Builder::setAddress(QString &address)
{
    _address = address;
    return *this;
}

Parent::Builder &Parent::Builder::setPhoneNumber(QString &phoneNumber)
{
    _phoneNumber = phoneNumber;
    return *this;
}

Parent* Parent::Builder::build()
{
    return new Parent(_name, _dateBirth, _address, _phoneNumber);
}

QString Parent::getName() const
{
    return _name;
}

QString Parent::getDateBirth() const
{
    return _dateBirth;
}

QString Parent::getAddress() const
{
    return _address;
}

QString Parent::getPhoneNumber() const
{
    return _phoneNumber;
}
