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
        log.debug(__FILE__, "Employe [" + employe->toString() + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool EmployeesService::removeEmployeByName(QString &name) {
    try {
        emploeesDAO->removeEmployeByName(name);
        log.debug(__FILE__, "Employe [" + name + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        log.warning(__FILE__, e.what());
        return false;
    }
}
