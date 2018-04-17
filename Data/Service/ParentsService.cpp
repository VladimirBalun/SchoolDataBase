#include "ParentsService.h"

QVector<QSharedPointer<Parent> > ParentsService::getParentsByChild(const QString &name) {
    return _parentsDAO->findParentsByChild(name);
}

bool ParentsService::addParent(QSharedPointer<Parent> &parent) {
    try {
        _parentsDAO->addParent(parent);
        _log.debug(__FILE__, "Parent [" + parent->toString() + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool ParentsService::removeParentByName(const QString &name) {
    try {
        _parentsDAO->removeParentByName(name);
        _log.debug(__FILE__, "Parent [" + name + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
