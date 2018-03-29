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

Employe::Builder& Employe::Builder::setName(QString name) {
    _name = name;
    return *this;
}

Employe::Builder& Employe::Builder::setDateBirth(QString dateBirth) {
    _dateBirth = dateBirth;
    return *this;
}

Employe::Builder& Employe::Builder::setAddress(QString address) {
    _address = address;
    return *this;
}

Employe::Builder& Employe::Builder::setProfession(QString profession) {
    _profession = profession;
    return *this;
}

Employe::Builder& Employe::Builder::setPhoneNumber(QString phoneNumber) {
    _phoneNumber = phoneNumber;
    return *this;
}

Employe::Builder& Employe::Builder::setPersonalData(QString personalData) {
    _personalData = personalData;
    return *this;
}

Employe* Employe::Builder::build() {
    return new Employe(_name, _dateBirth, _address, _profession, _phoneNumber, _personalData);
}
