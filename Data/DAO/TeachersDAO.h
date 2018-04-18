#ifndef TEACHERSDAO_H
#define TEACHERSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "ITeachersDAO.h"
#include "Exceptions/NotWorkingRequest.h"

class TeachersDAO : public ITeachersDAO {
public:
    TeachersDAO();
    QVector<QSharedPointer<Teacher>> findAllTeachers() override;
    void addPredmetForTeacher(const QString& nameTeacher, const QString& namePredmet) override;
    void removePredmetTeacherByName(const QString& nameTeacher, const QString& namePredmet) override;
private:
    QVector<QSharedPointer<Teacher>> _teachers;
};

#endif
