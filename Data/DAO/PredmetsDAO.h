#ifndef PREDMETSDAO_H
#define PREDMETSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IPredmetsDAO.h"
#include "Exceptions/NotWorkingRequest.h"

struct PredmetsDAO : public IPredmetsDAO {
    QVector<QString> findAllPredmets();
    void addPredmet(QString &name);
    void removePredmetByName(QString &name);
    void changeNamePredmet(QString &oldName, QString &newName);
};

#endif
