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
    QVector<QSharedPointer<Employe>> getAllEmployees() override;
    QVector<QSharedPointer<Employe>> searchEmployeesByName(const QString& name) override;
    QVector<QSharedPointer<Employe>> selectEmployeesByProfession(const QString& profession) override;
    bool addEmploye(const QSharedPointer<Employe>& employe) override;
    bool removeEmployeByName(const QString &name) override;
};

#endif
