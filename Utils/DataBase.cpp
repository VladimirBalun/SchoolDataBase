#include "DataBase.h"

DataBase *DataBase::getInstance()
{
    if(instance)
    {
        return instance;
    }
    else
    {
        connectWithDB();
        instance = new DataBase;
        return instance;
    }
}

void DataBase::connectWithDB()
{
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    if(dataBase.isOpen())
    {
        qDebug() << "Connection with database was successful";
    }
    else
    {
        qDebug() << "Connection with database wasn' successful";
    }
}

DataBase::~DataBase()
{
    delete instance;
}
