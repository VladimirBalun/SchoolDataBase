#ifndef IPROFESSIONSDAO_H
#define IPROFESSIONSDAO_H

#include <iostream>
#include <QVector>

struct IProfessionsDAO {
    virtual QVector<QString> findAllProfessions() = 0;
    virtual void addProfession(QString& name) = 0;
    virtual void removeProfessionByName(QString& name) = 0;
    virtual void changeNameProfession(QString& oldName, QString& newName) = 0;
    virtual ~IProfessionsDAO() {}
};

#endif
