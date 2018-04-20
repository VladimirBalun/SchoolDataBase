#ifndef PREDMETSDAO_H
#define PREDMETSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IPredmetsDAO.h"
#include "Exceptions/NotWorkingRequest.h"

struct PredmetsDAO : public IPredmetsDAO {
    QVector<QString> findAllPredmets() override;
    void addPredmet(const QString &name) override;
    void removePredmetByName(const QString& name) override;
    void changeNamePredmet(const QString& oldName, const QString& newName) override;
};

#endif
