#ifndef ADMINISTRATORS_DAO_H
#define ADMINISTRATORS_DAO_H

#include <QtSql>
#include <QCryptographicHash>
#include "Utils/DataBase.h"
#include "IAdministratorsDAO.h"
#include "Exceptions/AdministratorNotFound.h"
#include "Exceptions/NotWorkingRequest.h"

class AdministratorsDAO : public IAdministratorsDAO {
    DataBase* dataBase = DataBase::getInstance();
public:
    AdministratorsDAO() {}
    QPair<QString, QString> findAdministratorByLogin(QString& login) override;
    QMap<QString, QString> findAllAdministrators() override;
    void addAdministrator(QString& login, QString& password) override;
    void removeAdministratorByLogin(QString& login) override;
    virtual void changePasswordAdministratorByLogin(QString& login, QString& oldPassword, QString& newPassword) override;
    QString hashPassword(QString& password) override;
    ~AdministratorsDAO() {}
};

#endif
