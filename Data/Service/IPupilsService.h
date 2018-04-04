#ifndef IPUPILSSERVICE_H
#define IPUPILSSERVICE_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Pupil.h"

struct IPupilsService{
    virtual QVector<QSharedPointer<Pupil>> getPupilsByClass(const QString& nameClass) = 0;
    virtual QVector<QSharedPointer<Pupil>> getPupilsByName(const QString& name) = 0;
    virtual QVector<QSharedPointer<Pupil>> getAllPupils() = 0;
    virtual bool addPupil(const QSharedPointer<Pupil>& pupil) = 0;
    virtual bool removePupilByName(const QString& name) = 0;
    virtual ~IPupilsService() {}
};

#endif
