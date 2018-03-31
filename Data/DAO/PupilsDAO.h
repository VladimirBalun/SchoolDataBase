#ifndef PUPILSDAO_H
#define PUPILSDAO_H

#include "IPupilsDAO.h"
#include "Data/Entity/Pupil.h"

struct PupilsDAO : public IPupilsDAO {
    void findAllPupils() override;
    void findPupilsByClass(const QString& nameClass) override;
    void addPupil(const QSharedPointer<Pupil>& pupil) override;
    void removePupilByName(const QString& name) override;
};

#endif
