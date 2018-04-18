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

void Teacher::addPredmet(const QString &namePredmet) {
    _predmets.append(namePredmet);
}

QString Teacher::toString() const {
    return "name = " + _name + " nameClass = " + _nameClass;
}

std::ostream& operator <<(std::ostream &os, Teacher *t) {
    os << "name = " << t->getName().toStdString() << ", nameClass = " << t->getNameClass().toStdString();
    return os;
}
