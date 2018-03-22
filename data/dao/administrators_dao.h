#ifndef ADMINISTRATORS_DAO_H
#define ADMINISTRATORS_DAO_H

#include <QtSql>
#include "iadministrators_dao.h"

class AdministratorsDAO : public IAdministratorsDAO
{
public:
    AdministratorsDAO() {}
    LoginAndPassword findAdministratorByLogin(String& login) override;
    Map findAllAdministrators() override;
    void addAdministrator(String& login, String& password) override;
    void removeAdministratorByLogin(String& login) override;
    ~AdministratorsDAO() {}
};

#endif
