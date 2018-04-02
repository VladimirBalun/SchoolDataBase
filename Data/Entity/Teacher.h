#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QVector>
#include <QSharedPointer>

class Teacher {
    QString _name;
    QString _nameClass;
    QVector<QString> _predmets;
    Teacher(const QString& name, const QString& nameClass, const QVector<QString>& predmets) :
        _name(name), _nameClass(nameClass), _predmets(predmets) {}
public:

    class Builder {
        QString _name;
        QString _nameClass;
        QVector<QString> _predmets;
    public:
        Builder& setName(const QString& name);
        Builder& setNameClass(const QString& nameClass);
        Builder& setPredmets(const QVector<QString>& predmets);
        QSharedPointer<Teacher> build();
    };

    QString getName() const;
    QString getNameClass() const;
    QVector<QString> getPredmets() const;

    QString toString() const;
    friend std::ostream& operator << (std::ostream& os, Teacher *teacher);
};

#endif
