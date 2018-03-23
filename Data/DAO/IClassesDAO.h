#ifndef ICLASSESDAO_H
#define ICLASSESDAO_H

#include <iostream>
#include <QVector>

struct IClassesDAO{
    virtual QString findClassById(long id) = 0;
    virtual QVector<QString> findAllClasses() = 0;
    virtual void addClass(QString& name) = 0;
    virtual void removeClassByName(QString& name) = 0;
    virtual void changeNameClass(QString& oldName, QString& newName) = 0;
    virtual ~IClassesDAO() {}
};

#endif
