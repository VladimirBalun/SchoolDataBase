#ifndef ICLASSESDAO_H
#define ICLASSESDAO_H

#include <iostream>
#include <vector>

struct IClassesDAO{
    typedef std::string String;
    typedef std::vector<String> StringVector;

    virtual String findClassById(long id) = 0;
    virtual StringVector findAllClasses() = 0;
    virtual ~IClassesDAO() {}
};

#endif
