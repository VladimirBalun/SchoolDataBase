#include "DataBase.h"

DataBase::DataBase() {
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("/home/vova/Desktop/build-SchoolDataBase-Desktop-Release/School.db");
    if(dataBase.open()) {
        qDebug() << "Connection with database was successful\n";
    } else {
        qDebug() << "Connection with database wasn't successful\n";
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

