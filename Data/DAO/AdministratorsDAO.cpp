#include "AdministratorsDAO.h"
#include <iostream>

QPair<QString, QString> AdministratorsDAO::findAdministratorByLogin(QString& login)
{
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a "
                  "WHERE a.login = :login");
    query.bindValue(":login", login);
    query.exec();
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
        throw AdministratorNotFound(exceptionMessage);
    }
}

QMap<QString, QString> AdministratorsDAO::findAllAdministrators()
{
    QMap<QString, QString> administrators;
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a");
    query.exec();
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
        QString exceptionMessage = "Error in adding an administrator[" + login + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
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
        QString exceptionMessage = "Error in deleting an administrator[" + login + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
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
        QString exceptionMessage = "Error in changing administrator[" + login + "] password. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
