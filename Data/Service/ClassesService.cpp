#include "ClassesService.h"

QVector<QString> ClassesService::getAllClasses() {
    return _classesDAO->findAllClasses();
}

bool ClassesService::addClass(const QString& name) {
    try {
        _classesDAO->addClass(name);
        _log.debug(__FILE__, "Class [" + name + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool ClassesService::removeClassByName(const QString& name) {
    try {
        _classesDAO->removeClassByName(name);
        _log.debug(__FILE__, "Class [" + name + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool ClassesService::changeNameClass(const QString& oldName, const QString& newName) {
    try {
        _classesDAO->changeNameClass(oldName, newName);
        _log.debug(__FILE__, "Class [" + oldName + "] was changed on [" + newName + "].");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
