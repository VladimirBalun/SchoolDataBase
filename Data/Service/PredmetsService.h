#ifndef PREDMETSSERVICE_H
#define PREDMETSSERVICE_H

#include "IPredmetsService.h"
#include "Utils/Logger.h"
#include "Data/DAO/PredmetsDAO.h"
#include "Exceptions/NotWorkingRequest.h"

class PredmetsService : public IPredmetsService {
    Logger _log;
    QScopedPointer<IPredmetsDAO> _predmetsDAO;
public:
    PredmetsService() : _predmetsDAO(new PredmetsDAO) {}
    QVector<QString> getAllPredmets() override;
    bool addPredmet(const QString& name) override;
    bool removePredmetByName(const QString& name) override;
};

#endif
