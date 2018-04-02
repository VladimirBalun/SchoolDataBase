#include "Teacher.h"

QString Teacher::getName() const {
    return _name;
}

QString Teacher::getNameClass() const {
    return _nameClass;
}

QVector<QString> Teacher::getPredmets() const {
    return _predmets;
}

Teacher::Builder& Teacher::Builder::setName(const QString &name) {
    _name = name;
    return *this;
}

Teacher::Builder& Teacher::Builder::setNameClass(const QString &nameClass) {
    _nameClass = nameClass;
    return *this;
}

Teacher::Builder& Teacher::Builder::setPredmets(const QVector<QString> &predmets) {
    _predmets = predmets;
    return *this;
}

QSharedPointer<Teacher> Teacher::Builder::build() {
    QSharedPointer<Teacher> teacher(new Teacher(_name, _nameClass, _predmets));
    return teacher;
}


QString Teacher::toString() const {
    return "name = " + _name + " nameClass = " + _nameClass;
}

std::ostream& operator <<(std::ostream &os, Teacher *t) {
    os << "name = " << t->getName().toStdString() << ", nameClass = " << t->getNameClass().toStdString();
    return os;
}
