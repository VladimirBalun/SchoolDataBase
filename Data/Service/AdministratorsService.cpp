#include "AdministratorsService.h"
#include <iostream>

AdministratorsService::AdministratorsService()
{
    administratorsDAO = new AdministratorsDAO;
}

bool AdministratorsService::addAdministrator(QString &login, QString &password)
{
    try
    {
        administratorsDAO->addAdministrator(login, password);
        return true;
    }
    catch(NotWorkingRequest& e)
    {
        qDebug() << e.what();
        return false;
    }
}

bool AdministratorsService::removeAdministratorByLogin(QString &login)
{
    try
    {
        administratorsDAO->removeAdministratorByLogin(login);
    }
    catch(NotWorkingRequest& e)
    {
        qDebug() << e.what();
        return false;
    }
}

bool AdministratorsService::changePasswordAdministratoByLoginr(QString &login, QString &oldPassword, QString &newPassword)
{
    try
    {
        administratorsDAO->changePasswordAdministratorByLogin(login, oldPassword, newPassword);
        return true;
    }
    catch(NotWorkingRequest& e)
    {
        qDebug() << e.what();
        return false;
    }
}

bool AdministratorsService::isExistAdministrator(QString &login, QString &password)
{
    QPair<QString, QString> admin;
    qDebug() << "SERVICE\n";
    try
    {
        admin = administratorsDAO->findAdministratorByLogin(login);
    }
    catch(AdministratorNotFound& e)
    {
        qDebug() << e.what();
        return false;
    }
    QString loginAdmin = admin.first;
    QString passwordAdmin = admin.second;
    if(loginAdmin == login && passwordAdmin == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QMap<QString, QString> AdministratorsService::getAllAdministrators()
{
    return administratorsDAO->findAllAdministrators();
}

AdministratorsService::~AdministratorsService()
{
    delete administratorsDAO;
}
