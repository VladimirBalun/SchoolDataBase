#ifndef IEMPLOYEESDAO_H
#define IEMPLOYEESDAO_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Employe.h"

struct IEmployeesDAO {
    virtual QVector<QSharedPointer<Employe>> findAllEmployees() = 0;
    virtual QVector<QSharedPointer<Employe>> findEmployeByProfession(const QString& profession) = 0;
    virtual QSharedPointer<Employe> findEmployeByName(const QString& name) = 0;
    virtual void removeEmployeByName(const QString& name) = 0;
    virtual void addEmployee(const QSharedPointer<Employe>& employe) = 0;
    virtual ~IEmployeesDAO() {}
};

#endif
