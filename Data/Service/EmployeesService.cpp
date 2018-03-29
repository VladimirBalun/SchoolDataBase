#include "EmployeesService.h"

EmployeesService::EmployeesService() {
    emploeesDAO = std::make_unique<EmployeesDAO>();
}

QVector<Employe*> EmployeesService::getAllEmployees() {
    return emploeesDAO->findAllEmployees();
}

bool EmployeesService::addEmploye(Employe *employe) {
    try {
        emploeesDAO->addEmployee(employe);
        return true;
    } catch(NotWorkingRequest& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
}

bool EmployeesService::removeEmployeByName(QString &name) {
    try {
        emploeesDAO->removeEmployeByName(name);
        return true;
    } catch(NotWorkingRequest& e) {
        std::cerr << e.what().toStdString() << std::endl;
        return false;
    }
}
