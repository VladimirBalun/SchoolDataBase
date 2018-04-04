#include "PupilsService.h"

QVector<QSharedPointer<Pupil>> PupilsService::getPupilsByClass(const QString& nameClass) {
    return _pupilsDAO->findPupilsByClass(nameClass);
}

QVector<QSharedPointer<Pupil> > PupilsService::getPupilsByName(const QString &name) {
    return _pupilsDAO->findPupilsByName(name);
}

QVector<QSharedPointer<Pupil>> PupilsService::getAllPupils() {
    return _pupilsDAO->findAllPupils();
}

bool PupilsService::addPupil(const QSharedPointer<Pupil>& pupil) {
    try {
        _pupilsDAO->addPupil(pupil);
        _log.debug(__FILE__, "Employe [" + pupil->toString() + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool PupilsService::removePupilByName(const QString& name) {
    try {
        _pupilsDAO->removePupilByName(name);
        _log.debug(__FILE__, "Employe [" + name + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
