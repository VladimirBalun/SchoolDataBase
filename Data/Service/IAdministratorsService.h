#ifndef IADMINISTRATORSSERVICE_H
#define IADMINISTRATORSSERVICE_H

#include <QString>
#include <QMap>

struct IAdministratorsService {
    virtual bool addAdministrator(const QString& login, const QString& password) = 0;
    virtual bool removeAdministratorByLogin(const QString& login) = 0;
    virtual bool changePasswordAdministratoByLogin(const QString& login, const QString& oldPassword, const QString& newPassword) = 0;
    virtual bool isExistAdministrator(const QString& login, const QString& password) = 0;
    virtual QMap<QString, QString> getAllAdministrators() = 0;
    virtual ~IAdministratorsService() {}
};

#endif
