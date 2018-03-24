#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>

class DataBase
{
public:
    static DataBase* getInstance();
    void connect();
    ~DataBase() {}
private:
    QSqlDatabase dataBase;
    DataBase() {}
};

#endif // DATABASE_H
