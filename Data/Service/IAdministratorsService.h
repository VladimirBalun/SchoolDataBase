#ifndef IADMINISTRATORSSERVICE_H
#define IADMINISTRATORSSERVICE_H

#include <QString>
#include <QMap>

struct IAdministratorsService
{
public:
    virtual bool addAdministrator(QString& login, QString& password) = 0;
    virtual bool removeAdministratorByLogin(QString& login) = 0;
    virtual bool changePasswordAdministratoByLoginr(QString& login, QString& oldPassword, QString& newPassword) = 0;
    virtual bool isExistAdministrator(QString& login, QString& password) = 0;
    virtual QMap<QString, QString> getAllAdministrators() = 0;
    virtual ~IAdministratorsService() {}
};

#endif
