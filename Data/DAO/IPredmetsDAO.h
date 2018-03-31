#ifndef IPREDMETSDAO_H
#define IPREDMETSDAO_H

#include <QString>
#include <QVector>

struct IPredmetsDAO {
    virtual QVector<QString> findAllPredmets() = 0;
    virtual void addPredmet(const QString& name) = 0;
    virtual void removePredmetByName(const QString& name) = 0;
    virtual void changeNamePredmet(const QString& oldName, const QString& newName) = 0;
    virtual ~IPredmetsDAO() {}
};

#endif
