#include "TeachersDAO.h"

QVector<QSharedPointer<Teacher>> TeachersDAO::findAllTeachers() {
    _teachers.clear();
    QSqlQuery query;
    query.prepare("SELECT "
                  "(SELECT e.name FROM employees e WHERE e.id = t.id_employe) AS name, "
                  "(SELECT c.name FROM classes c WHERE c.id = t.id_class) AS class, "
                  "p.name AS predmet "
                  "FROM teachers_predmets tp "
                  "LEFT JOIN predmets p ON p.id = tp.id_predmet "
                  "LEFT JOIN teachers t ON t.id = tp.id_teacher "
                  "GROUP BY name ");
    query.exec();
    while (query.next()) {
        QString name = query.value(0).toString();
        QString className = query.value(1).toString();
        if(_teachers.isEmpty() || _teachers.last()->getName() != name){
            QSharedPointer<Teacher> teacher(new Teacher(name, className));
            teacher->addPredmet(query.value(2).toString());
            _teachers.append(teacher);
        } else {
            _teachers.last()->addPredmet(query.value(2).toString());
        }
    }
    return _teachers;
}

void TeachersDAO::addPredmetForTeacher(const QString &nameTeacher, const QString &namePredmet) {
    QSqlQuery query;
    query.prepare("INSERT INTO teachers_predmets(id_teacher, id_predmet) "
                  "VALUES( "
                  "(SELECT t.id FROM teachers t WHERE t.id_employe = (SELECT e.id FROM employees e WHERE e.name = :nameTeacher)), "
                  "(SELECT p.id FROM predmets p WHERE p.name = :namePredmet))");
    query.bindValue(":nameTeacher", nameTeacher);
    query.bindValue(":namePredmet", namePredmet);
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a predemt for teacher [" + nameTeacher + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void TeachersDAO::removePredmetTeacherByName(const QString &nameTeacher, const QString &namePredmet) {
    QSqlQuery query;
    query.prepare("DELETE FROM teachers_predmets "
                  "WHERE id_teacher = (SELECT t.id FROM teachers t WHERE t.id_employe = (SELECT e.id FROM employees e WHERE e.name = :nameTeacher)) "
                  "AND id_predmet = (SELECT p.id FROM predmets p WHERE p.name = :namePredmet)");
    query.bindValue(":nameTeacher", nameTeacher);
    query.bindValue(":namePredmet", namePredmet);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a predemt of teacher [" + nameTeacher + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}


