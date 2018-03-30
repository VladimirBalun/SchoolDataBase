#include "Logger.h"

void Logger::info(const char *file, const QString &message) {
    std::cout << "[INFO]  " << getCurrentDateTine() << "  " << file << "  "<< message.toStdString() << std::endl;
}

void Logger::debug(const char *file, const QString &message) {
    std::cout << "[DEBUG]  " << getCurrentDateTine() << "  " << file << "  "<< message.toStdString() << std::endl;
}

void Logger::warning(const char *file, const QString &message) {
    std::cerr << "[WARNING]  " << getCurrentDateTine() << "  " << file << "  "<< message.toStdString() << std::endl;
}

void Logger::error(const char *file, const QString &message) {
    std::cerr << "[ERROR]  " << getCurrentDateTine() << "  " << file << "  "<< message.toStdString() << std::endl;
}

std::string Logger::getCurrentDateTine() {
    return QDateTime::currentDateTime().toString("dd.MM.yy HH:mm:ss").toStdString();
}
