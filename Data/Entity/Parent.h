#ifndef PARENT_H
#define PARENT_H

#include <QString>
#include <QSharedPointer>

class Parent {
    QString _name;
    QString _dateBirth;
    QString _address;
    QString _child;
    Parent(QString name, QString dateBirth, QString address, QString child) :
        _name(name), _dateBirth(dateBirth), _address(address), _child(child) {}
public:

    class Builder {
        QString _name;
        QString _dateBirth;
        QString _address;
        QString _child;
    public:
        Builder& setName(const QString& name);
        Builder& setDateBirth(const QString& dateBirth);
        Builder& setAddress(const QString& address);
        Builder& setChild(const QString& child);
        QSharedPointer<Parent> build();
    };

    QString getName() const;
    QString getDateBirth() const;
    QString getAddress() const;
    QString getChild() const;

    QString toString() const;
    friend std::ostream& operator << (std::ostream& os, Parent *parent);
};

#endif
