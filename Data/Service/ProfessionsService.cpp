#include "ProfessionsService.h"

ProfessionsService::ProfessionsService() {
    professionsDAO = std::make_unique<ProfessionsDAO>();
}

QVector<QString> ProfessionsService::getAllProfessions() {
    return professionsDAO->findAllProfessions();
}

bool ProfessionsService::addProfession(QString &name) {
    try {
        professionsDAO->addProfession(name);
        log.debug(__FILE__, "Profession [" + name + "] was added.");
        return true;
    } catch (NotWorkingRequest& e) {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool ProfessionsService::removeProfessionByName(QString &name) {
    try {
        professionsDAO->removeProfessionByName(name);
        log.debug(__FILE__, "Profession [" + name + "] was deleted.");
        return true;
    } catch (NotWorkingRequest& e) {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool ProfessionsService::changeNameProfession(QString &oldName, QString &newName) {
    try {
        professionsDAO->changeNameProfession(oldName, newName);
        log.debug(__FILE__, "Profession [" + oldName + "] was changed on [" + newName + "].");
        return true;
    } catch (NotWorkingRequest& e) {
        log.warning(__FILE__, e.what());
        return false;
    }
}
