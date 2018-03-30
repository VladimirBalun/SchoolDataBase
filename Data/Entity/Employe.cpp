#include "Employe.h"

QString Employe::getName() const {
    return _name;
}

QString Employe::getDateBirth() const {
    return _dateBirth;
}

QString Employe::getAddress() const {
    return _address;
}

QString Employe::getProfession() const {
    return _profession;
}

QString Employe::getPhoneNumber() const {
    return _phoneNumber;
}

QString Employe::getPersonalData() const {
    return _personalData;
}

Employe::Builder& Employe::Builder::setName(const QString &name) {
    _name = name;
    return *this;
}

Employe::Builder& Employe::Builder::setDateBirth(const QString &dateBirth) {
    _dateBirth = dateBirth;
    return *this;
}

Employe::Builder& Employe::Builder::setAddress(const QString& address) {
    _address = address;
    return *this;
}

Employe::Builder& Employe::Builder::setProfession(const QString& profession) {
    _profession = profession;
    return *this;
}

Employe::Builder& Employe::Builder::setPhoneNumber(const QString& phoneNumber) {
    _phoneNumber = phoneNumber;
    return *this;
}

Employe::Builder& Employe::Builder::setPersonalData(const QString& personalData) {
    _personalData = personalData;
    return *this;
}

Employe* Employe::Builder::build() {
    return new Employe(_name, _dateBirth, _address, _profession, _phoneNumber, _personalData);
}

QString Employe::toString() const {
    return "name = " + _name + ", dateBirth = " + _dateBirth +
           ", address = "  + _address + ", profession = " + _profession +
           ", phoneNumber = " + _phoneNumber + ", perosnalData = " + _personalData;
}

std::ostream& operator << (std::ostream &os, Employe *em) {
    os << "name = " << em->getName().toStdString() << ", dateBirth = " << em->getDateBirth().toStdString()
       << ", address = "  << em->getAddress().toStdString() << ", profession = " << em->getProfession().toStdString()
       << ", phoneNumber = " << em->getPhoneNumber().toStdString() << ", perosnalData = " << em->getPersonalData().toStdString();
    return os;
}
