#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include "Utils/Logger.h"

class DataBase {
public:
    static DataBase* getInstance();
    void connect();
private:
    QSqlDatabase _dataBase;
    Logger _log;
    DataBase() {}
};

#endif
