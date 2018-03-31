#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <QString>
#include <QDateTime>

class Logger {
    std::string getCurrentDateTine();
public:
    void info(const char* file, const QString& message);
    void debug(const char* file, const QString& message);
    void warning(const char* file, const QString& message);
    void error(const char* file, const QString& message);
};

#endif
