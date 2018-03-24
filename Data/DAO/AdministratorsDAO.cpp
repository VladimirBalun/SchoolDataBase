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
        QPair<QString, QString> admin;
        admin.first = QString(query.value(0).toString()); //login
        admin.second = QString(query.value(1).toString()); //password
        return admin;
    }
    else
    {
        QString exceptionMessage = "Administrator [" + login + "] isn't exist.";
        throw new AdministratorNotFound(exceptionMessage);
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
        QString login = QString(query.value(0).toString());
        QString password = QString(query.value(0).toString());
        administrators.insert(login, password);
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
    if(!query.exec())
    {
        QString exceptionMessage = "Administrator [" + login + "] was'n added. Query: " + query.lastQuery();
        throw new NotWorkingRequest(QString(exceptionMessage));
    }
}

void AdministratorsDAO::removeAdministratorByLogin(QString& login)
{
    QSqlQuery query;
    query.prepare("DELETE FROM administrators a "
                  "WHERE a.login = ':login'");
    query.bindValue(":login", login);
    if(!query.exec())
    {
        QString exceptionMessage = "Administrator [" + login + "] was'n deleted. Query: " + query.lastQuery();
        throw new NotWorkingRequest(QString(exceptionMessage));
    }
}

void AdministratorsDAO::changePasswordAdministratorByLogin(QString& login, QString &oldPassword, QString &newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE administrators a "
                  "SET a.password = 'newPassword' "
                  "WHERE a.password = 'oldPassword'");
    query.bindValue(":oldPassword", oldPassword);
    query.bindValue(":newPassword", newPassword);
    if(!query.exec())
    {
        QString exceptionMessage = "Password of administrator [" + login + "] was'n changed. Query: " + query.lastQuery();
        throw new NotWorkingRequest(QString(exceptionMessage));
    }
}
