#include "EmployeesService.h"

QVector<QSharedPointer<Employe>> EmployeesService::getAllEmployees() {
    return _emploeesDAO->findAllEmployees();
}

bool EmployeesService::addEmploye(const QSharedPointer<Employe>& employe) {
    try {
        _emploeesDAO->addEmployee(employe);
        _log.debug(__FILE__, "Employe [" + employe->toString() + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool EmployeesService::removeEmployeByName(const QString& name) {
    try {
        _emploeesDAO->removeEmployeByName(name);
        _log.debug(__FILE__, "Employe [" + name + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
