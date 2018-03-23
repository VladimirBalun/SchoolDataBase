#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>

class DataBase
{
public:
    DataBase* getInstance();
    ~DataBase();
private:
    DataBase* instance;
    QSqlDatabase dataBase;
    DataBase() {}
    void connectWithDB();
};

#endif // DATABASE_H
