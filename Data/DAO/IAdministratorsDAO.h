#ifndef IADMINISTRATORSDAO_H
#define IADMINISTRATORSDAO_H

#include <iostream>
#include <QPair>
#include <QMap>

struct IAdministratorsDAO {
    virtual QPair<QString, QString> findAdministratorByLogin(const QString& login) = 0;
    virtual QMap<QString, QString> findAllAdministrators() = 0;
    virtual void addAdministrator(const QString& login, const QString& password) = 0;
    virtual void removeAdministratorByLogin(const QString& login) = 0;
    virtual void changePasswordAdministratorByLogin(const QString& login, const QString& oldPassword, const QString& newPassword) = 0;
    virtual QString hashPassword(const QString& password) = 0;
    virtual ~IAdministratorsDAO() {}
};

#endif
