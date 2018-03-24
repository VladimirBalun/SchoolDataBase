#ifndef IADMINISTRATORSDAO_H
#define IADMINISTRATORSDAO_H

#include <iostream>
#include <QPair>
#include <QMap>

struct IAdministratorsDAO{
    virtual QPair<QString, QString> findAdministratorByLogin(QString& login) = 0;
    virtual QMap<QString, QString> findAllAdministrators() = 0;
    virtual void addAdministrator(QString& login, QString& password) = 0;
    virtual void removeAdministratorByLogin(QString& login) = 0;
    virtual void changePasswordAdministratorByLogin(QString& login, QString& oldPassword, QString& newPassword) = 0;
    virtual ~IAdministratorsDAO() {}
};

#endif
