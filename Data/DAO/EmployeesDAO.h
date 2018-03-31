#ifndef EMPLOYEESDAO_H
#define EMPLOYEESDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IEmployeesDAO.h"
#include "Exceptions/NotWorkingRequest.h"
#include "Exceptions/EmployeNotFound.h"

struct EmployeesDAO : public IEmployeesDAO {
    QVector<QSharedPointer<Employe>> findAllEmployees() override;
    QVector<QSharedPointer<Employe>> findEmployeByProfession(const QString& profession) override;
    QSharedPointer<Employe> findEmployeByName(const QString& name) override;
    void removeEmployeByName(const QString& name) override;
    void addEmployee(const QSharedPointer<Employe>& employe) override;
};

#endif
