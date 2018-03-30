#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include "Utils/Logger.h"

class DataBase {
public:
    static DataBase* getInstance();
    QSqlQuery execSelect(QString& strQuery);
    ~DataBase() {}
private:
    QSqlDatabase dataBase;
    Logger log;
    DataBase();
};

#endif
