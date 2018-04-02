#ifndef EMPLOYEESDAO_H
#define EMPLOYEESDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IEmployeesDAO.h"
#include "Exceptions/NotWorkingRequest.h"

class EmployeesDAO : public IEmployeesDAO {
public:
    EmployeesDAO();
    QVector<QSharedPointer<Employe>> findAllEmployees() override;
    QVector<QSharedPointer<Employe>> findEmployeesByProfession(const QString& profession) override;
    QVector<QSharedPointer<Employe>> findEmployeesByName(const QString& name) override;
    void removeEmployeByName(const QString& name) override;
    void addEmployee(const QSharedPointer<Employe>& employe) override;
private:
    void loadEmployeesInVectorFromDB(QSqlQuery& query);
private:
    QVector<QSharedPointer<Employe>> _employees;
    QString _basicSelectQuery;
};

#endif
