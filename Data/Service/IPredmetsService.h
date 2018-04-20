#ifndef IPREDMETSSERVICE_H
#define IPREDMETSSERVICE_H

#include <QString>
#include <QSharedPointer>
#include "Data/Entity/Pupil.h"

struct IPredmetsService {
    virtual QVector<QString> getAllPredmets() = 0;
    virtual bool addPredmet(const QString& name) = 0;
    virtual bool removePredmetByName(const QString& name) = 0;
};

#endif
