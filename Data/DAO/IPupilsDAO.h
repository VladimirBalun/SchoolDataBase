#ifndef IPUPILSDAO_H
#define IPUPILSDAO_H

struct IPupilsDAO{
    virtual void addPupil() = 0;
    virtual void removePupilByName(QString& name) = 0;
    virtual void findPupilsByClass(QString& nameClass) = 0;
    virtual void findAllPupils();
    virtual ~IPupilsDAO() {}
};

#endif
