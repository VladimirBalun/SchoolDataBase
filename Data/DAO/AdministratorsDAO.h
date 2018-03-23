#ifndef ADMINISTRATORS_DAO_H
#define ADMINISTRATORS_DAO_H

#include <QtSql>
#include "IAdministratorsDAO.h"

class AdministratorsDAO : public IAdministratorsDAO
{
public:
    AdministratorsDAO() {}
    QPair<QString, QString> findAdministratorByLogin(QString& login) override;
    QMap<QString, QString> findAllAdministrators() override;
    void addAdministrator(QString& login, QString& password) override;
    void removeAdministratorByLogin(QString& login) override;
    virtual void changePassword(QString& oldPassword, QString& newPassword) override;
    ~AdministratorsDAO() {}
};

#endif
