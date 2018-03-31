#include "EmployeesDAO.h"

QVector<QSharedPointer<Employe>> EmployeesDAO::findAllEmployees() {
    QVector<QSharedPointer<Employe>> employees;
    QSqlQuery query;
    query.prepare("SELECT e.name, e.date_birth, e.address, e.phone_number, e.personal_data, p.name "
                  "FROM employees e "
                  "LEFT JOIN professions p ON e.id_profession = p.id");
    query.exec();
    while (query.next()) {
        QSharedPointer<Employe> employe = Employe::Builder()
                .setName(QString(query.value(0).toString()))
                .setDateBirth(QString(query.value(1).toString()))
                .setAddress(QString(query.value(2).toString()))
                .setPhoneNumber(QString(query.value(3).toString()))
                .setPersonalData(QString(query.value(4).toString()))
                .setProfession(QString(query.value(5).toString()))
                .build();
        employees.append(employe);
    }
    return employees;
}

QVector<QSharedPointer<Employe>> EmployeesDAO::findEmployeByProfession(const QString& profession) {

}

QSharedPointer<Employe> EmployeesDAO::findEmployeByName(const QString& name) {

}

void EmployeesDAO::removeEmployeByName(const QString& name) {
    QSqlQuery query;
    query.prepare("DELETE FROM employees WHERE name = :name");
    query.bindValue(":name", name);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting an employe[" + name + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void EmployeesDAO::addEmployee(const QSharedPointer<Employe>& employe) {
    QSqlQuery query;
    query.prepare("INSERT INTO employees(name, date_birth, address, phone_number, personal_data, id_profession) "
                  "VALUES(:name_employe, :date_birth, :address, :phone_number, :personal_data, "
                  "(SELECT p.id FROM professions p WHERE p.name = :name_profession)) ");
    query.bindValue(":name_employe", employe->getName());
    query.bindValue(":dte_birth",  employe->getDateBirth());
    query.bindValue(":address",  employe->getAddress());
    query.bindValue(":phone_number",  employe->getPhoneNumber());
    query.bindValue(":personal_data",  employe->getPersonalData());
    query.bindValue(":name_profession",  employe->getProfession());
    if (query.exec()) {
        QString exceptionMessage = "Error in adding an employe[" + employe->getName() + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
