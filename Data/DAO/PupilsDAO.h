#ifndef PUPILSDAO_H
#define PUPILSDAO_H

#include "IPupilsDAO.h"

struct PupilsDAO : IPupilsDAO{
    void findPupilsByClass(QString& nameClass) override;
    void findAllPupils() override;
    void addPupil() override;
    void removePupilByName(QString& name) override;
};

#endif
