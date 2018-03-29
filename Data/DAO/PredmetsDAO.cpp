#include "PredmetsDAO.h"

QVector<QString> PredmetsDAO::findAllPredmets() {
    QVector<QString> predmets;
    QSqlQuery query;
    query.prepare("SELECT name FROM predmets");
    query.exec();
    while (query.next()) {
        predmets.append(QString(query.value(0).toString()));
    }
    return predmets;
}

void PredmetsDAO::addPredmet(QString &name) {
    QSqlQuery query;
    query.prepare("INSERT INTO predmets(name) VALUES(:name)");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a predmet[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void PredmetsDAO::removePredmetByName(QString &name) {
    QSqlQuery query;
    query.prepare("DELETE FROM predmets WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a predmet[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void PredmetsDAO::changeNamePredmet(QString &oldName, QString &newName) {
    QSqlQuery query;
    query.prepare("UPDATE predmets SET name = :newName WHERE name = :oldName");
    query.bindValue(":oldName", oldName);
    query.bindValue(":newName", newName);
    if (!query.exec()) {
        QString exceptionMessage = "Error in changing predmet[" + oldName + "] on [" + newName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
