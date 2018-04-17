#include "Parent.h"

Parent::Builder &Parent::Builder::setName(const QString &name) {
    _name = name;
    return *this;
}

Parent::Builder &Parent::Builder::setDateBirth(const QString &dateBirth) {
    _dateBirth = dateBirth;
    return *this;
}

Parent::Builder &Parent::Builder::setAddress(const QString &address) {
    _address = address;
    return *this;
}

Parent::Builder &Parent::Builder::setChild(const QString &child) {
    _child = child;
    return *this;
}

QSharedPointer<Parent> Parent::Builder::build() {
    QSharedPointer<Parent> parent(new Parent(_name, _dateBirth, _address, _child));
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

QString Parent::getChild() const{
    return _child;
}

QString Parent::toString() const {
    return  "name = " + _name + ", dateBirth = " + _dateBirth + ", address = "  + _address;
}

std::ostream& operator << (std::ostream &os, Parent *p) {
    os << "name = " << p->getName().toStdString() << ", dateBirth = " << p->getDateBirth().toStdString()
       << ", address = "  << p->getAddress().toStdString();
    return os;
}
