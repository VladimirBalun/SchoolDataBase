#include "DataBase.h"

DataBase* DataBase::getInstance()
{
    static DataBase instance;
    return &instance;
}

void DataBase::connect()
{
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");
    dataBase.setDatabaseName("shool");
    dataBase.setUserName("root");
    dataBase.setPassword("admin");
    if(dataBase.isOpen())
    {
        qDebug() << "Connection with database was successful";
    }
    else
    {
        qDebug() << "Connection with database wasn' successful";
    }
}
