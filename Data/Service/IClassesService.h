#ifndef ICLASSESSERVICE_H
#define ICLASSESSERVICE_H

#include <QVector>

struct IClassesService {
    virtual QVector<QString> getAllClasses() = 0;
    virtual bool addClass(const QString& name) = 0;
    virtual bool removeClassByName(const QString& name) = 0;
    virtual bool changeNameClass(const QString& oldName, const QString& newName) = 0;
};

#endif
