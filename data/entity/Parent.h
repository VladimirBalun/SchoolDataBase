#ifndef PARENT_H
#define PARENT_H

#include <memory>

class Parent
{
    QString _name;
    QString _dateBirth;
    QString _address;
    Qstring _phoneNumber;
    Parent(QString name, QString dateBirth, QString address, QString phoneNumber) :
        _name(name), _dateBirth(dateBirth), _address(address), _phoneNumber(phoneNumber) {}
public:

    class Builder{
        QString _name;
        QString _dateBirth;
        QString _address;
        Qstring _phoneNumber;
    public:
        Builder& setName(QString& name);
        Builder& setDateBirth(QString& dateBirth);
        Builder& setAddress(QString& address);
        Builder& setPhoneNumber(QString& phoneNumber);
        typedef std::unique_ptr<Parent> UPtr;
        UPtr build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getPhoneNumber() const;
};

#endif // PARENT_H
