#include "AdministratorsService.h"

AdministratorsService::AdministratorsService() {
    administratorsDAO = std::make_unique<AdministratorsDAO>();
}

bool AdministratorsService::addAdministrator(QString &login, QString &password) {
    try {
        administratorsDAO->addAdministrator(login, password);
        return true;
    } catch(NotWorkingRequest& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
}

bool AdministratorsService::removeAdministratorByLogin(QString &login) {
    try {
        administratorsDAO->removeAdministratorByLogin(login);
        return true;
    } catch(NotWorkingRequest& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
}

bool AdministratorsService::changePasswordAdministratoByLogin(QString &login, QString &oldPassword, QString &newPassword) {
    QString hashPassword = administratorsDAO->hashPassword(oldPassword);
    if(!isExistAdministrator(login, hashPassword)) {
        return false;
    }
    try {
        administratorsDAO->changePasswordAdministratorByLogin(login, oldPassword, newPassword);
        return true;
    } catch(NotWorkingRequest& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
}

bool AdministratorsService::isExistAdministrator(QString &login, QString &password) {
    QPair<QString, QString> admin;
    try {
        admin = administratorsDAO->findAdministratorByLogin(login);
    } catch(AdministratorNotFound& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
    if(admin.first == login && admin.second == password) {
        return true;
    } else {
        return false;
    }
}

QMap<QString, QString> AdministratorsService::getAllAdministrators() {
    return administratorsDAO->findAllAdministrators();
}
