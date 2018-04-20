#ifndef PROFESSIONSDAO_H
#define PROFESSIONSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IProfessionsDAO.h"
#include "Exceptions/NotWorkingRequest.h"

struct ProfessionsDAO : public IProfessionsDAO {
    QVector<QString> findAllProfessions() override;
    void addProfession(QString &name) override;
    void removeProfessionByName(QString &name) override;
    void changeNameProfession(QString &oldName, QString &newName) override;
};

#endif
