#ifndef IPROFESSIONSSERVICE_H
#define IPROFESSIONSSERVICE_H

#include <QString>
#include <QVector>

struct IProfessionsService {
    virtual QVector<QString> getAllProfessions() = 0;
    virtual bool addProfession(QString &name) = 0;
    virtual bool removeProfessionByName(QString &name) = 0;
    virtual bool changeNameProfession(QString &oldName, QString &newName) = 0;
    virtual ~IProfessionsService() {}
};

#endif
