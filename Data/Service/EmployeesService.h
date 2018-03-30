#ifndef EMPLOYEESSERVICE_H
#define EMPLOYEESSERVICE_H

#include <memory>
#include "Utils/Logger.h"
#include "Data/DAO/EmployeesDAO.h"
#include "Data/Service/IEmployeesService.h"

class EmployeesService : public IEmployeesService {
    Logger log;
    std::unique_ptr<IEmployeesDAO> emploeesDAO;
public:
    EmployeesService();
    QVector<Employe *> getAllEmployees();
    bool addEmploye(Employe *employe);
    bool removeEmployeByName(QString &name);
    ~EmployeesService() {}
};

#endif
