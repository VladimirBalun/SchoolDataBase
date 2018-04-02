#ifndef PARENTNOTFOUND_H
#define PARENTNOTFOUND_H

#include <QString>

class ParentNotFound {
    QString _message;
public:
    ParentNotFound(const QString& message) : _message(message) {}
    QString what() const { return "Parent not found. Exception: " + _message; }
};

#endif
