#ifndef IPROFESSIONSDAO_H
#define IPROFESSIONSDAO_H

#include <iostream>
#include <vector>

struct IProfessionsDAO{
    typedef std::string String;
    typedef std::vector<String> StringVector;

    virtual String findProfessionById(long id) = 0;
    virtual StringVector findAllProfessions() = 0;
    virtual IProfessionsDAO() {}
};

#endif
