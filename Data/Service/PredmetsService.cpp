#include "PredmetsService.h"

QVector<QString> PredmetsService::getAllPredmets() {
    return _predmetsDAO->findAllPredmets();
}

bool PredmetsService::addPredmet(const QString &name) {
    try {
        _predmetsDAO->addPredmet(name);
        _log.debug(__FILE__, "Predmet [" + name + "] was added.");
        return true;
    } catch (NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool PredmetsService::removePredmetByName(const QString &name) {
    try {
        _predmetsDAO->removePredmetByName(name);
        _log.debug(__FILE__, "Predmet [" + name + "] was deleted.");
        return true;
    } catch (NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
