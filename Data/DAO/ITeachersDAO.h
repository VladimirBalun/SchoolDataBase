#ifndef ITEACHERSDAO_H
#define ITEACHERSDAO_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Teacher.h"

struct ITeachersDAO {
    virtual QVector<QSharedPointer<Teacher>> findAllTeachers() = 0;
    virtual void addPredmetForTeacher(const QString& nameTeacher, const QString& namePredmet) = 0;
    virtual void removePredmetTeacherByName(const QString& nameTeacher, const QString& namePredmet) = 0;
    virtual ~ITeachersDAO() {}
};

#endif
