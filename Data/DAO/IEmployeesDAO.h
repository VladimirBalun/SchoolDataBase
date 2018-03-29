#ifndef IEMPLOYEESDAO_H
#define IEMPLOYEESDAO_H

#include <QVector>
#include "Data/Entity/Employe.h"

struct IEmployeesDAO{
    virtual QVector<Employe*> findAllEmployees() = 0;
    virtual QVector<Employe*> findEmployeByProfession(QString& profession) = 0;
    virtual Employe* findEmployeByName(QString& name) = 0;
    virtual void removeEmployeByName(QString& name) = 0;
    virtual void addEmployee(Employe* employe) = 0;
    virtual ~IEmployeesDAO() {}
};

#endif
