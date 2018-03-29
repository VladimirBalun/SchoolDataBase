#ifndef IEMPLOYEESSERVICE_H
#define IEMPLOYEESSERVICE_H

#include <QVector>
#include "Data/Entity/Employe.h"

struct IEmployeesService{
    virtual QVector<Employe*> getAllEmployees() = 0;
    virtual bool addEmploye(Employe* Employe) = 0;
    virtual bool removeEmployeByName(QString& name) = 0;
    virtual ~IEmployeesService() {}
};

#endif
