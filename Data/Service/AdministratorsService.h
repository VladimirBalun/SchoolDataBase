#ifndef ADMINISTRATORSSERVICE_H
#define ADMINISTRATORSSERVICE_H

#include <memory>
#include "Utils/Logger.h"
#include "IAdministratorsService.h"
#include "Data/DAO/AdministratorsDAO.h"

class AdministratorsService : public IAdministratorsService {
    Logger log;
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
