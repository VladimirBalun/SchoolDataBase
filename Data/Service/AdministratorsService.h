#ifndef ADMINISTRATORSSERVICE_H
#define ADMINISTRATORSSERVICE_H

#include <iostream>
#include <memory>
#include <QPair>
#include "Data/DAO/IAdministratorsDAO.h"
#include "Data/DAO/AdministratorsDAO.h"
#include "IAdministratorsService.h"

class AdministratorsService : public IAdministratorsService {
    std::unique_ptr<IAdministratorsDAO> administratorsDAO;
public:
    AdministratorsService();
    bool addAdministrator(QString& login, QString& password) override;
    bool removeAdministratorByLogin(QString& login) override;
    bool changePasswordAdministratoByLogin(QString& login, QString& oldPassword, QString& newPassword) override;
    bool isExistAdministrator(QString& login, QString& password) override;
    QMap<QString, QString> getAllAdministrators() override;
    ~AdministratorsService() {}
};

#endif
