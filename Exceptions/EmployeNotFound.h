#ifndef EMPLOYENOTFOUND_H
#define EMPLOYENOTFOUND_H

#include <QString>

class EmployeNotFound {
    QString _message;
public:
    EmployeNotFound(const QString& message) : _message(message) {}
    QString what() const { return "Employe not found. Exception: " + _message; }
};

#endif
