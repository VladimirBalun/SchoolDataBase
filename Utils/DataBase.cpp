#include "DataBase.h"

DataBase* DataBase::getInstance() {
    static DataBase instance;
    return &instance;
}

void DataBase::connect() {
    _dataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/home/vova/Desktop/build-SchoolDataBase-Desktop-Debug/School.db";
    _dataBase.setDatabaseName(path);
    if (_dataBase.open()) {
        _log.info(__FILE__, "Connection with database was successful");
    } else {
        _log.error(__FILE__, "Connection with database wasn't successful. Path to DB: " + path);
        exit(EXIT_FAILURE);
    }
}
