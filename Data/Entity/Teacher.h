#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QVector>
#include <QSharedPointer>

class Teacher {
    QString _name;
    QString _nameClass;
    QVector<QString> _predmets;
public:
    Teacher(const QString& name, const QString& nameClass) : _name(name), _nameClass(nameClass) {}

    QString getName() const;
    QString getNameClass() const;
    QVector<QString> getPredmets() const;
    void addPredmet(const QString& namePredmet);

    QString toString() const;
    friend std::ostream& operator << (std::ostream& os, Teacher *teacher);
};

#endif
