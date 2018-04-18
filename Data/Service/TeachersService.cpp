#include "TeachersService.h"

QVector<QSharedPointer<Teacher> > TeachersService::getAllTeachers() {
    return _teachersDAO->findAllTeachers();
}

bool TeachersService::addPredmetForTeacher(const QString &nameTeacher, const QString &namePredmet) {
    try {
        _teachersDAO->addPredmetForTeacher(nameTeacher, namePredmet);
        _log.debug(__FILE__, "Predmet for teacher [" + nameTeacher + "] was added.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}

bool TeachersService::removePredmetTeacherByName(const QString &nameTeacher, const QString &namePredmet) {
    try {
        _teachersDAO->removePredmetTeacherByName(nameTeacher, namePredmet);
        _log.debug(__FILE__, "Predmet of teacher [" + nameTeacher + "] was deleted.");
        return true;
    } catch(NotWorkingRequest& e) {
        _log.warning(__FILE__, e.what());
        return false;
    }
}
