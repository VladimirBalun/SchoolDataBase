#include "AdministratorsDAO.h"

QPair<QString, QString> AdministratorsDAO::findAdministratorByLogin(QString& login)
{
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a "
                  "WHERE a.login = ':login'");
    query.bindValue(":login", login);
    if(query.next())
    {
//        QString login = query.value(0).toString;
//        QString password = query.value(1).toString;
//        return new QPair<QString, QString>(login, password);
    }
}

QMap<QString, QString> AdministratorsDAO::findAllAdministrators()
{
    QMap<QString, QString> administrators;
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a");
    while(query.next())
    {
//        QString login = query.value(0).toString;
//        QString password = query.value(1).toString;
//        administrators.insert(login, password);
    }
    return administrators;
}

void AdministratorsDAO::addAdministrator(QString& login, QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO administrators(login, password) "
                  "VALUES(':login', ':password')");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
}

void AdministratorsDAO::removeAdministratorByLogin(QString& login)
{
    QSqlQuery query;
    query.prepare("DELETE FROM administrators a "
                  "WHERE a.login = ':login'");
    query.bindValue(":login", login);
    query.exec();
}

void AdministratorsDAO::changePassword(QString &oldPassword, QString &newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE administrators a "
                  "SET a.password = 'newPassword' "
                  "WHERE a.password = 'oldPassword'");
    query.bindValue(":oldPassword", oldPassword);
    query.bindValue(":newPassword", newPassword);
    query.exec();
}
