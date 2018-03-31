#include "AdministratorsDAO.h"

QPair<QString, QString> AdministratorsDAO::findAdministratorByLogin(const QString &login) {
    QSqlQuery query;
    query.prepare("SELECT login, password "
                  "FROM administrators "
                  "WHERE login = :login");
    query.bindValue(":login", login);
    query.exec();
    if (query.next()) {
        QPair<QString, QString> admin;
        admin.first = QString(query.value(0).toString()); //login
        admin.second = QString(query.value(1).toString()); //password
        return admin;
    } else {
        QString exceptionMessage = "Administrator [" + login + "] isn't exist.";
        throw AdministratorNotFound(exceptionMessage);
    }
}

QMap<QString, QString> AdministratorsDAO::findAllAdministrators() {
    QMap<QString, QString> administrators;
    QSqlQuery query;
    query.prepare("SELECT login, password FROM administrators");
    query.exec();
    while (query.next()) {
        QString login = QString(query.value(0).toString());
        QString password = QString(query.value(1).toString());
        administrators.insert(login, password);
    }
    return administrators;
}

void AdministratorsDAO::addAdministrator(const QString &login, const QString &password) {
    QSqlQuery query;
    query.prepare("INSERT INTO administrators(login, password) VALUES(:login, :password)");
    query.bindValue(":login", login);
    query.bindValue(":password", hashPassword(password));
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding an administrator[" + login + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void AdministratorsDAO::removeAdministratorByLogin(const QString &login) {
    QSqlQuery query;
    query.prepare("DELETE FROM administrators WHERE login = :login");
    query.bindValue(":login", login);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting an administrator[" + login + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void AdministratorsDAO::changePasswordAdministratorByLogin(const QString &login, const QString &oldPassword, const QString &newPassword) {
    QSqlQuery query;
    query.prepare("UPDATE administrators "
                  "SET password = :newPassword "
                  "WHERE password = :oldPassword AND login = :login");
    query.bindValue(":login", login);
    query.bindValue(":oldPassword", hashPassword(oldPassword));
    query.bindValue(":newPassword", hashPassword(newPassword));
    if (!query.exec()) {
        QString exceptionMessage = "Error in changing administrator[" + login + "] password. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

QString AdministratorsDAO::hashPassword(const QString &password) {
    QByteArray arrayForHash = password.toUtf8();
    QString hashPassword = QString(QCryptographicHash::hash(arrayForHash, QCryptographicHash::Sha256).toHex());
    return hashPassword;
}
