#ifndef PUPIL_H
#define PUPIL_H

#include <memory>

class Pupil
{
    QString _name;
    QString _dateBirth;
    QString _address;
    QString _nameClass;
    Pupil(QString name, QString dateBirth, QString address, QString nameClass) :
        _name(name), _dateBirth(dateBirth), _address(address), _nameClass(nameClass) {}
public:

    class Builder{
        QString _name;
        QString _dateBirth;
        QString _address;
        QString _nameClass;
    public:
        Builder& setName(QString& name);
        Builder& setDateBirth(QString& dateBirth);
        Builder& setAddress(QString& address);
        Builder& setNameClass(QString& nameClass);
        typedef std::unique_ptr<Pupil> UPtr;
        UPtr build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getNameClass() const;
};

#endif
