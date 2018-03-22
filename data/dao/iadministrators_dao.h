#ifndef IADMINISTRATORSDAO_H
#define IADMINISTRATORSDAO_H

#include <iostream>
#include <map>

struct IAdministratorsDAO{
    typedef std::string String;
    typedef std::pair<String, String> LoginAndPassword;
    typedef std::map<String, String> Map;

    virtual LoginAndPassword findAdministratorByLogin(String& login) = 0;
    virtual Map findAllAdministrators() = 0;
    virtual void addAdministrator(String& login, String& password) = 0;
    virtual void removeAdministratorByLogin(String& login) = 0;
    virtual ~IAdministratorsDAO() {}
};

#endif
