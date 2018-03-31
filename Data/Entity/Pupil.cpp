#include "Pupil.h"

Pupil::Builder &Pupil::Builder::setName(QString& name) {
    _name = name;
    return *this;
}

Pupil::Builder &Pupil::Builder::setDateBirth(QString& dateBirth) {
    _dateBirth = dateBirth;
    return *this;
}

Pupil::Builder &Pupil::Builder::setAddress(QString& address) {
    _address = address;
    return *this;
}

Pupil::Builder &Pupil::Builder::setNameClass(QString& nameClass) {
    _nameClass = nameClass;
    return *this;
}

QSharedPointer<Pupil> Pupil::Builder::build() {
    QSharedPointer<Pupil> pupil(new Pupil(_name, _dateBirth, _address, _nameClass));
    return pupil;
}

QString Pupil::getName() const {
    return _name;
}

QString Pupil::getDateBirth() const {
    return _dateBirth;
}

QString Pupil::getAddress() const {
    return _address;
}

QString Pupil::getNameClass() const {
    return _nameClass;
}

QString Pupil::toString() const {
    return "name = " + _name + ", dateBirth = " + _dateBirth + ", address = "  + _address + ", nameClass = " + _nameClass;
}

std::ostream& operator << (std::ostream &os, Pupil *p) {
    os << "name = " << p->getName().toStdString() << ", dateBirth = " << p->getDateBirth().toStdString()
       << ", address = "  << p->getAddress().toStdString() << ", nameClass = " << p->getNameClass().toStdString();
    return os;
}
