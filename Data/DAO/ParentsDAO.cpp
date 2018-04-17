#include "ParentsDAO.h"

QVector<QSharedPointer<Parent> > ParentsDAO::findParentsByChild(const QString &name) {
    _parents.clear();
    QSqlQuery query;
    query.prepare("SELECT par.name, par.date_birth, par.address "
                  "FROM parents par "
                  "LEFT JOIN pupils pup ON pup.id = par.id_pupil "
                  "WHERE pup.name = :name");
    query.bindValue(":name", name);
    query.exec();
    while (query.next()) {
        QSharedPointer<Parent> parent = Parent::Builder()
                .setName(QString(query.value(0).toString()))
                .setDateBirth(QString(query.value(1).toString()))
                .setAddress(QString(query.value(2).toString()))
                .build();
        _parents.append(parent);
    }
    return _parents;
}

void ParentsDAO::addParent(QSharedPointer<Parent> &parent) {
    QSqlQuery query;
    query.prepare("INSERT INTO parents(name, date_birth, address, id_pupil) "
                  "VALUES(:name, :date_birth, :address, "
                  "(SELECT p.id FROM pupils p WHERE p.name = :child))");
    query.bindValue(":name", parent->getName());
    query.bindValue(":date_birth", parent->getDateBirth());
    query.bindValue(":address", parent->getAddress());
    query.bindValue(":child", parent->getChild());
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding parent[" + parent->getName() + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void ParentsDAO::removeParentByName(const QString &name) {
    QSqlQuery query;
    query.prepare("DELETE FROM parents WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting parent[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
