#ifndef PUPILSDAO_H
#define PUPILSDAO_H

#include "IPupilsDAO.h"

class PupilsDAO : IPupilsDAO{
public:
    PupilsDAO() {}
    void addPupil() override;
    void removePupilByName(QString& name) override;
    void findPupilsByClass(QString& nameClass) override;
    void findAllPupils() override;
    ~PupilsDAO() {}
};

#endif
