#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSharedPointer>

class Employe{
    QString _name;
    QString _dateBirth;
    QString _address;
    QString _profession;
    QString _phoneNumber;
    QString _personalData;
public:
    Employe(const QString& name, const QString& dateBirth, const QString& address, const QString& profession,
            const QString& phoneNumber, const QString& personalData) : _name(name), _dateBirth(dateBirth),
            _address(address), _profession(profession), _phoneNumber(phoneNumber), _personalData(personalData) {}

    class Builder{
        QString _name;
        QString _dateBirth;
        QString _address;
        QString _profession;
        QString _phoneNumber;
        QString _personalData;
    public:
        Builder& setName(const QString& name);
        Builder& setDateBirth(const QString& dateBirth);
        Builder& setAddress(const QString& address);
        Builder& setProfession(const QString& profession);
        Builder& setPhoneNumber(const QString& phoneNumber);
        Builder& setPersonalData(const QString& personalData);
        QSharedPointer<Employe> build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getProfession() const;
    QString getPhoneNumber() const;
    QString getPersonalData() const;

    QString toString() const;
    friend std::ostream& operator << (std::ostream& os, Employe *employe);
};

#endif
