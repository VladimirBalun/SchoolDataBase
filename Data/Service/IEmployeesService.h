#ifndef IEMPLOYEESSERVICE_H
#define IEMPLOYEESSERVICE_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Employe.h"

struct IEmployeesService{
    virtual QVector<QSharedPointer<Employe>> getAllEmployees() = 0;
    virtual bool addEmploye(const QSharedPointer<Employe>& employe) = 0;
    virtual bool removeEmployeByName(const QString& name) = 0;
    virtual ~IEmployeesService() {}
};

#endif
