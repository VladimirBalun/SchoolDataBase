#ifndef EMPLOYEESSERVICE_H
#define EMPLOYEESSERVICE_H

#include <QScopedPointer>
#include "Utils/Logger.h"
#include "Data/DAO/EmployeesDAO.h"
#include "Data/Service/IEmployeesService.h"

class EmployeesService : public IEmployeesService {
    Logger _log;
    QScopedPointer<IEmployeesDAO> _emploeesDAO;
public:
    EmployeesService() : _emploeesDAO(new EmployeesDAO) {}
    QVector<QSharedPointer<Employe>> getAllEmployees();
    bool addEmploye(const QSharedPointer<Employe>& employe);
    bool removeEmployeByName(const QString &name);
};

#endif
