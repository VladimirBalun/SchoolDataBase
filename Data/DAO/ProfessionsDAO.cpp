#include "ProfessionsDAO.h"

QVector<QString> ProfessionsDAO::findAllProfessions() {
    QVector<QString> professions;
    QSqlQuery query;
    query.prepare("SELECT name FROM professions");
    query.exec();
    while (query.next()) {
        professions.append(QString(query.value(0).toString()));
    }
    return professions;
}

void ProfessionsDAO::addProfession(QString &name) {
    QSqlQuery query;
    query.prepare("INSERT INTO professions(name) VALUES(:name)");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a profession[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void ProfessionsDAO::removeProfessionByName(QString &name) {
    QSqlQuery query;
    query.prepare("DELETE FROM professions WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a profession[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void ProfessionsDAO::changeNameProfession(QString &oldName, QString &newName) {
    QSqlQuery query;
    query.prepare("UPDATE professions SET name = :newName WHERE name = :oldName");
    query.bindValue(":oldName", oldName);
    query.bindValue(":newName", newName);
    if (!query.exec()) {
        QString exceptionMessage = "Error in changing profession[" + oldName + "] on [" + newName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
