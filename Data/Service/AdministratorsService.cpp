#include "AdministratorsService.h"

bool AdministratorsService::addAdministrator(const QString& login, const QString& password) {
    try {
        _administratorsDAO->addAdministrator(login, password);
        _log.debug(__FILE__, "Administrator [" + login + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool AdministratorsService::removeAdministratorByLogin(const QString& login) {
    try {
        _administratorsDAO->removeAdministratorByLogin(login);
        _log.debug(__FILE__, "Administrator [" + login + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool AdministratorsService::changePasswordAdministratoByLogin(const QString &login, const QString &oldPassword, const QString &newPassword) {
    QString hashPassword = _administratorsDAO->hashPassword(oldPassword);
    if(!isExistAdministrator(login, hashPassword)) {
        return false;
    }
    try {
        _administratorsDAO->changePasswordAdministratorByLogin(login, oldPassword, newPassword);
        _log.debug(__FILE__, "Password of administrator [" + login + "] was changed.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool AdministratorsService::isExistAdministrator(const QString& login, const QString& password) {
    QPair<QString, QString> admin;
    try {
        admin = _administratorsDAO->findAdministratorByLogin(login);
    } catch(AdministratorNotFound& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
    if(admin.first == login && admin.second == password) {
        return true;
    } else {
        return false;
    }
}

QMap<QString, QString> AdministratorsService::getAllAdministrators() {
    return _administratorsDAO->findAllAdministrators();
}
