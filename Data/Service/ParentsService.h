#ifndef PARENTSSERVICE_H
#define PARENTSSERVICE_H

#include "IParentsService.h"
#include "Utils/Logger.h"
#include "Data/DAO/ParentsDAO.h"
#include "Exceptions/NotWorkingRequest.h"
#include "Data/Service/IParentsService.h"

class ParentsService : public IParentsService {
    Logger _log;
    QScopedPointer<IParentsDAO> _parentsDAO;
public:
    ParentsService() : _parentsDAO(new ParentsDAO) {}
    QVector<QSharedPointer<Parent>> getParentsByChild(const QString& name) override;
    bool addParent(QSharedPointer<Parent>& parent) override;
    bool removeParentByName(const QString& name) override;
};

#endif
