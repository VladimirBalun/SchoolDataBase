#include "DataBase.h"
#include <iostream>

DataBase::DataBase()
{
    std::string str = "/home/vova/Desktop/build-SchoolDataBase-Desktop-Release/School.db";
    std::cout << "Path: " << str;
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(str.c_str());
    if(dataBase.open())
    {
        std::cout << "Connection with database was successful";
    }
    else
    {
        std::cout << "Connection with database wasn't successful";
    }
}

DataBase* DataBase::getInstance()
{
    static DataBase instance;
    return &instance;
}

QSqlQuery DataBase::execSelect(QString &strQuery)
{
    QSqlQuery query(strQuery);
    query.exec();
    return query;
}

