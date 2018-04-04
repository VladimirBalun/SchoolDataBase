#include "PupilsDAO.h"

PupilsDAO::PupilsDAO() {
    _basicSelectQuery = "SELECT p.name, p.date_birth, p.address, c.name "
                        "FROM pupils p "
                        "LEFT JOIN classes c ON c.id = p.id_class ";
}

QVector<QSharedPointer<Pupil>> PupilsDAO::findAllPupils() {
    _pupils.clear();
    QSqlQuery query;
    query.prepare(_basicSelectQuery);
    query.exec();
    loadPupilsInVectorFromDB(query);
    return _pupils;
}

QVector<QSharedPointer<Pupil>> PupilsDAO::findPupilsByClass(const QString& nameClass) {
    _pupils.clear();
    QSqlQuery query;
    query.prepare(_basicSelectQuery + "WHERE c.name = :nameClass");
    query.bindValue(":nameClass", nameClass);
    query.exec();
    loadPupilsInVectorFromDB(query);
    return _pupils;
}

QVector<QSharedPointer<Pupil> > PupilsDAO::findPupilsByName(const QString& name)
{
    _pupils.clear();
    QSqlQuery query;
    query.prepare(_basicSelectQuery + "WHERE p.name LIKE :name");
    query.bindValue(":name", '%' + name + '%');
    query.exec();
    loadPupilsInVectorFromDB(query);
    return _pupils;
}

void PupilsDAO::loadPupilsInVectorFromDB(QSqlQuery& query) {
    while (query.next()) {
        QSharedPointer<Pupil> pupil = Pupil::Builder()
                .setName(QString(query.value(0).toString()))
                .setDateBirth(QString(query.value(1).toString()))
                .setAddress(QString(query.value(2).toString()))
                .setNameClass(QString(query.value(2).toString()))
                .build();
        _pupils.append(pupil);
    }
}


void PupilsDAO::addPupil(const QSharedPointer<Pupil>& pupil) {
    QSqlQuery query;
    query.prepare("INSERT INTO pupils(name, date_birth, address) "
                  "VALUES(':name', ':date_birth', ':address')"); // !!!!!!!!!!!!!! ADD class
    query.bindValue(":name", pupil->getName());
    query.bindValue(":date_birth", pupil->getDateBirth());
    query.bindValue(":address", pupil->getAddress());
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding an pupil[" + pupil->getName() + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void PupilsDAO::removePupilByName(const QString &name) {
    QSqlQuery query;
    query.prepare("DELETE FROM pupils "
                  "WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting an pupil[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

