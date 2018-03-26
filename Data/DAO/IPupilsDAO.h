#ifndef IPUPILSDAO_H
#define IPUPILSDAO_H

#include <QString>

struct IPupilsDAO {
    virtual void addPupil() = 0;
    virtual void removePupilByName(QString& name) = 0;
    virtual void findPupilsByClass(QString& nameClass) = 0;
    virtual void findAllPupils() = 0;
    virtual ~IPupilsDAO() {}
};

#endif
