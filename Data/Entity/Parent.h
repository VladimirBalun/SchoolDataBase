#ifndef PARENT_H
#define PARENT_H

#include <QString>

class Parent {
    QString _name;
    QString _dateBirth;
    QString _address;
    QString _phoneNumber;
    Parent(QString name, QString dateBirth, QString address, QString phoneNumber) :
        _name(name), _dateBirth(dateBirth), _address(address), _phoneNumber(phoneNumber) {}
public:

    class Builder {
        QString _name;
        QString _dateBirth;
        QString _address;
        QString _phoneNumber;
    public:
        Builder& setName(QString& name);
        Builder& setDateBirth(QString& dateBirth);
        Builder& setAddress(QString& address);
        Builder& setPhoneNumber(QString& phoneNumber);
        Parent* build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getPhoneNumber() const;

    QString toString() const;
    friend std::ostream& operator << (std::ostream& os, Parent *parent);
};

#endif
