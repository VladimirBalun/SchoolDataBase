#ifndef EMPLOYEESDAO_H
#define EMPLOYEESDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IEmployeesDAO.h"
#include "Exceptions/NotWorkingRequest.h"
#include "Exceptions/EmployeNotFound.h"

struct EmployeesDAO : public IEmployeesDAO {
    QVector<Employe*> findAllEmployees() override;
    QVector<Employe*> findEmployeByProfession(QString &profession) override;
    Employe* findEmployeByName(QString &name) override;
    void removeEmployeByName(QString &name) override;
    void addEmployee(Employe* employe) override;
};

#endif
