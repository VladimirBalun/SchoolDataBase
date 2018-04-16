#include "ClassesDAO.h"

QVector<QString> ClassesDAO::findAllClasses() {
    _classes.clear();
    QSqlQuery query;
    query.prepare("SELECT name FROM classes");
    query.exec();
    while (query.next()) {
        _classes.append(query.value(0).toString());
    }
    return _classes;
}

void ClassesDAO::addClass(const QString& name) {
    QSqlQuery query;
    query.prepare("INSERT INTO classes(name) VALUES(:name)");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding class[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void ClassesDAO::removeClassByName(const QString& name) {
    QSqlQuery query;
    query.prepare("DELETE FROM classes WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting class[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void ClassesDAO::changeNameClass(const QString& oldName, const QString& newName) {
    QSqlQuery query;
    query.prepare("UPDATE classes SET name = :newName WHERE name = :oldName");
    query.bindValue(":oldName", oldName);
    query.bindValue(":newName", newName);
    if (!query.exec()) {
        QString exceptionMessage = "Error in changing class[" + oldName + "] on [" + newName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
