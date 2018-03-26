#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QCoreApplication>
#include <QDebug>

class DataBase {
public:
    static DataBase* getInstance();
    QSqlQuery execSelect(QString& strQuery);
    ~DataBase() {}
private:
    QSqlDatabase dataBase;
    DataBase();
};

#endif // DATABASE_H
