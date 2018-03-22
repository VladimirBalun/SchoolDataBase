#include "database.h"

DataBase *DataBase::getInstance()
{
    if(dataBase)
    {
        return dataBase;
    }
    else
    {
        dataBase = new DataBase;
        return dataBase;
    }
}

DataBase::DataBase()
{

}

DataBase::~DataBase()
{
    delete dataBase;
}
