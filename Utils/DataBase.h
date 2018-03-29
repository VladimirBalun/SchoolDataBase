#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <QtSql>
#include <QtSql/QSqlDatabase>

class DataBase {
public:
    static DataBase* getInstance();
    QSqlQuery execSelect(QString& strQuery);
    ~DataBase() {}
private:
    QSqlDatabase dataBase;
    DataBase();
};

#endif
