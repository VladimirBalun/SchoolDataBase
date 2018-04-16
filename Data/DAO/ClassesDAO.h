#ifndef CLASSESDAO_H
#define CLASSESDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IClassesDAO.h"
#include "Exceptions/NotWorkingRequest.h"

class ClassesDAO : public IClassesDAO {
public:
    QVector<QString> findAllClasses() override;
    void addClass(const QString& name) override;
    void removeClassByName(const QString& name) override;
    void changeNameClass(const QString& oldName, const QString& newName) override;
private:
    QVector<QString> _classes;
};

#endif
