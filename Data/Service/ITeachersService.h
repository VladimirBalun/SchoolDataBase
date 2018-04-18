#ifndef ITEACHERSSERVICE_H
#define ITEACHERSSERVICE_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Teacher.h"

struct ITeachersService {
    virtual QVector<QSharedPointer<Teacher>> getAllTeachers() = 0;
    virtual bool addPredmetForTeacher(const QString& nameTeacher, const QString& namePredmet) = 0;
    virtual bool removePredmetTeacherByName(const QString& nameTeacher, const QString& namePredmet) = 0;
    virtual ~ITeachersService() {}
};

#endif
