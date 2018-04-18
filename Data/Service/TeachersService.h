#ifndef TEACHERSSERVICE_H
#define TEACHERSSERVICE_H

#include <QScopedPointer>
#include "Utils/Logger.h"
#include "Data/DAO/TeachersDAO.h"
#include "Exceptions/NotWorkingRequest.h"
#include "ITeachersService.h"

class TeachersService : public ITeachersService {
    Logger _log;
    QScopedPointer<ITeachersDAO> _teachersDAO;
public:
    TeachersService() : _teachersDAO(new TeachersDAO) {}
    QVector<QSharedPointer<Teacher>> getAllTeachers() override;
    bool addPredmetForTeacher(const QString& nameTeacher, const QString& namePredmet) override;
    bool removePredmetTeacherByName(const QString& nameTeacher, const QString& namePredmet) override;
};

#endif
