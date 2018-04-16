#ifndef CLASSESSERVICE_H
#define CLASSESSERVICE_H

#include "IClassesService.h"
#include "Data/DAO/ClassesDAO.h"
#include "Utils/Logger.h"

class ClassesService : public IClassesService {
    Logger _log;
    QScopedPointer<IClassesDAO> _classesDAO;
public:
    ClassesService() : _classesDAO(new ClassesDAO) {}
    QVector<QString> getAllClasses() override;
    bool addClass(const QString& name) override;
    bool removeClassByName(const QString& name) override;
    bool changeNameClass(const QString& oldName, const QString& newName) override;
};

#endif
