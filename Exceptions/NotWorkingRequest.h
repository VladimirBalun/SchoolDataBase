#ifndef NOTWORKINGREQUEST_H
#define NOTWORKINGREQUEST_H

#include <QString>

class NotWorkingRequest
{
    QString _message;
public:
    NotWorkingRequest(QString message) : _message(message) {}
    QString what() const { return "Not working request. Exception: " + _message; }
};

#endif
