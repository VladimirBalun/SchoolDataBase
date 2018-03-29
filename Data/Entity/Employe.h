#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>

class Employe{
    QString _name;
    QString _dateBirth;
    QString _address;
    QString _profession;
    QString _phoneNumber;
    QString _personalData;
    Employe(QString name, QString dateBirth, QString address, QString profession, QString phoneNumber, QString personalData) :
        _name(name), _dateBirth(dateBirth), _address(address), _profession(profession), _phoneNumber(phoneNumber), _personalData(personalData) {}
public:

    class Builder{
        QString _name;
        QString _dateBirth;
        QString _address;
        QString _profession;
        QString _phoneNumber;
        QString _personalData;
    public:
        Builder& setName(QString name);
        Builder& setDateBirth(QString dateBirth);
        Builder& setAddress(QString address);
        Builder& setProfession(QString profession);
        Builder& setPhoneNumber(QString phoneNumber);
        Builder& setPersonalData(QString personalData);
        Employe* build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getProfession() const;
    QString getPhoneNumber() const;
    QString getPersonalData() const;
};

#endif
