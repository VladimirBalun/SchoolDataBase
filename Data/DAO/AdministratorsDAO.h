#ifndef ADMINISTRATORS_DAO_H
#define ADMINISTRATORS_DAO_H

#include <QtSql>
#include <QCryptographicHash>
#include "Utils/DataBase.h"
#include "IAdministratorsDAO.h"
#include "Exceptions/AdministratorNotFound.h"
#include "Exceptions/NotWorkingRequest.h"

struct AdministratorsDAO : public IAdministratorsDAO {
    QPair<QString, QString> findAdministratorByLogin(const QString& login) override;
    QMap<QString, QString> findAllAdministrators() override;
    void addAdministrator(const QString& login, const QString& password) override;
    void removeAdministratorByLogin(const QString& login) override;
    virtual void changePasswordAdministratorByLogin(const QString& login, const QString& oldPassword, const QString& newPassword) override;
    QString hashPassword(const QString& password) override;
};

#endif
