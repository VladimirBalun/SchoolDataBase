#include "DataBase.h"

DataBase::DataBase() {
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("/home/vova/Desktop/build-SchoolDataBase-Desktop-Debug/School.db");
    if (dataBase.open()) {
        std::cout << "Connection with database was successful" << std::endl;
    } else {
        std::cerr << "Connection with database wasn't successful" << std::endl;
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

