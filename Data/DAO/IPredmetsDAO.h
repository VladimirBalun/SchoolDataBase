#ifndef IPREDMETSDAO_H
#define IPREDMETSDAO_H

#include <QString>
#include <QVector>

struct IPredmetsDAO {
    virtual QVector<QString> findAllPredmets() = 0;
    virtual void addPredmet(QString& name) = 0;
    virtual void removePredmetByName(QString& name) = 0;
    virtual void changeNamePredmet(QString& oldName, QString& newName) = 0;
    virtual ~IPredmetsDAO() {}
};

#endif
