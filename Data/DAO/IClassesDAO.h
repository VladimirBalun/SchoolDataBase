#ifndef ICLASSESDAO_H
#define ICLASSESDAO_H

#include <QVector>

struct IClassesDAO {
    virtual QVector<QString> findAllClasses() = 0;
    virtual void addClass(const QString& name) = 0;
    virtual void removeClassByName(const QString& name) = 0;
    virtual void changeNameClass(const QString& oldName, const QString& newName) = 0;
    virtual ~IClassesDAO() {}
};

#endif
