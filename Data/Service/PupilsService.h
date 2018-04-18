#ifndef PUPILSSERVICE_H
#define PUPILSSERVICE_H

#include <QScopedPointer>
#include "Utils/Logger.h"
#include "Data/DAO/PupilsDAO.h"
#include "Exceptions/NotWorkingRequest.h"
#include "Data/Service/IPupilsService.h"

class PupilsService : public IPupilsService {
    Logger _log;
    QScopedPointer<IPupilsDAO> _pupilsDAO;
public:
    PupilsService() : _pupilsDAO(new PupilsDAO) {}
    QVector<QSharedPointer<Pupil>> getPupilsByClass(const QString& nameClass) override;
    QVector<QSharedPointer<Pupil>> getPupilsByName(const QString& name) override;
    QVector<QSharedPointer<Pupil>> getAllPupils() override;
    bool addPupil(const QSharedPointer<Pupil>& pupil) override;
    bool removePupilByName(const QString& name) override;
};

#endif
