#ifndef ADMINISTRATORSSERVICE_H
#define ADMINISTRATORSSERVICE_H

#include <QScopedPointer>
#include "Utils/Logger.h"
#include "IAdministratorsService.h"
#include "Data/DAO/AdministratorsDAO.h"

class AdministratorsService : public IAdministratorsService {
    Logger _log;
    QScopedPointer<IAdministratorsDAO> _administratorsDAO;
public:
    AdministratorsService() : _administratorsDAO(new AdministratorsDAO) {}
    bool addAdministrator(const QString& login, const  QString& password) override;
    bool removeAdministratorByLogin(const QString& login) override;
    bool changePasswordAdministratoByLogin(const QString& login, const QString& oldPassword, const QString& newPassword) override;
    bool isExistAdministrator(const QString& login, const QString& password) override;
    QMap<QString, QString> getAllAdministrators() override;
};

#endif
