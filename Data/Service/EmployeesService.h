#ifndef EMPLOYEESSERVICE_H
#define EMPLOYEESSERVICE_H

#include <memory>
#include <iostream>
#include "Data/Service/IEmployeesService.h"
#include "Data/DAO/EmployeesDAO.h"

class EmployeesService : public IEmployeesService {
    std::unique_ptr<IEmployeesDAO> emploeesDAO;
public:
    EmployeesService();
    QVector<Employe *> getAllEmployees();
    bool addEmploye(Employe *employe);
    bool removeEmployeByName(QString &name);
    ~EmployeesService() {}
};

#endif
