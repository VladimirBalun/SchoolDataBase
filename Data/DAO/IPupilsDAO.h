#ifndef IPUPILSDAO_H
#define IPUPILSDAO_H

#include <QString>
#include <QSharedPointer>
#include "Data/Entity/Pupil.h"

struct IPupilsDAO {
    virtual void addPupil(const QSharedPointer<Pupil>& pupil) = 0;
    virtual void removePupilByName(const QString& name) = 0;
    virtual void findPupilsByClass(const QString& nameClass) = 0;
    virtual void findAllPupils() = 0;
    virtual ~IPupilsDAO() {}
};

#endif
