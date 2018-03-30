#include "DataBase.h"

DataBase::DataBase() {
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/home/vova/Desktop/build-SchoolDataBase-Desktop-Debug/School.db";
    dataBase.setDatabaseName(path);
    if (dataBase.open()) {
        log.info(__FILE__, "Connection with database was successful");
    } else {
        log.error(__FILE__, "Connection with database wasn't successful. Path to DB: " + path);
    }
}

DataBase* DataBase::getInstance() {
    static DataBase instance;
    return &instance;
}

QSqlQuery DataBase::execSelect(QString &strQuery) {
    QSqlQuery query(strQuery);
    query.exec();
    return query;
}

