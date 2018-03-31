#include "Parent.h"

Parent::Builder &Parent::Builder::setName(QString &name) {
    _name = name;
    return *this;
}

Parent::Builder &Parent::Builder::setDateBirth(QString &dateBirth) {
    _dateBirth = dateBirth;
    return *this;
}

Parent::Builder &Parent::Builder::setAddress(QString &address) {
    _address = address;
    return *this;
}

Parent::Builder &Parent::Builder::setPhoneNumber(QString &phoneNumber) {
    _phoneNumber = phoneNumber;
    return *this;
}

QSharedPointer<Parent> Parent::Builder::build() {
    QSharedPointer<Parent> parent(new Parent(_name, _dateBirth, _address, _phoneNumber));
    return parent;
}

QString Parent::getName() const {
    return _name;
}

QString Parent::getDateBirth() const {
    return _dateBirth;
}

QString Parent::getAddress() const {
    return _address;
}

QString Parent::getPhoneNumber() const {
    return _phoneNumber;
}

QString Parent::toString() const {
    return  "name = " + _name + ", dateBirth = " + _dateBirth + ", address = "  + _address + ", phoneNumber = " + _phoneNumber;
}

std::ostream& operator << (std::ostream &os, Parent *p) {
    os << "name = " << p->getName().toStdString() << ", dateBirth = " << p->getDateBirth().toStdString()
       << ", address = "  << p->getAddress().toStdString() << ", phoneNumber = " << p->getPhoneNumber().toStdString();
    return os;
}
