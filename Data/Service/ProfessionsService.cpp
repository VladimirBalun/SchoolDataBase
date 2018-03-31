#include "ProfessionsService.h"

QVector<QString> ProfessionsService::getAllProfessions() {
    return _professionsDAO->findAllProfessions();
}

bool ProfessionsService::addProfession(QString &name) {
    try {
        _professionsDAO->addProfession(name);
        _log.debug(__FILE__, "Profession [" + name + "] was added.");
        return true;
    } catch (NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool ProfessionsService::removeProfessionByName(QString &name) {
    try {
        _professionsDAO->removeProfessionByName(name);
        _log.debug(__FILE__, "Profession [" + name + "] was deleted.");
        return true;
    } catch (NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool ProfessionsService::changeNameProfession(QString &oldName, QString &newName) {
    try {
        _professionsDAO->changeNameProfession(oldName, newName);
        _log.debug(__FILE__, "Profession [" + oldName + "] was changed on [" + newName + "].");
        return true;
    } catch (NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
