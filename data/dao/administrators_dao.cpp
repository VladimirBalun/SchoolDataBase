#include "administrators_dao.h"

IAdministratorsDAO::LoginAndPassword AdministratorsDAO::findAdministratorByLogin(String& login)
{
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a "
                  "WHERE a.login = ':login'");
    query.bindValue(":login", login);
    if(query.next())
    {
        String login = query.value(0).toString;
        String password = query.value(1).toString;
        return new LoginAndPassword(login, password);
    }
}

IAdministratorsDAO::Map AdministratorsDAO::findAllAdministrators()
{
    Map administrators;
    QSqlQuery query;
    query.prepare("SELECT a.login, a.password "
                  "FROM administrators a");
    while(query.next())
    {
        String login = query.value(0).toString;
        String password = query.value(1).toString;
        administrators.insert(login, password);
    }
    return administrators;
}

void AdministratorsDAO::addAdministrator(String& login, String& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO administrators(login, password) "
                  "VALUES(':login', ':password')");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
}

void AdministratorsDAO::removeAdministratorByLogin(String& login)
{
    QSqlQuery query;
    query.prepare("DELETE FROM administrators a "
                  "WHERE a.login = ':login'");
    query.bindValue(":login", login);
    query.exec();
}
