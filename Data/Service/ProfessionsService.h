#ifndef PROFESSIONSSERVICE_H
#define PROFESSIONSSERVICE_H

#include <QScopedPointer>
#include "IProfessionsService.h"
#include "Data/DAO/ProfessionsDAO.h"
#include "Utils/Logger.h"
#include "Exceptions/NotWorkingRequest.h"

class ProfessionsService : public IProfessionsService {
    Logger _log;
    QScopedPointer<IProfessionsDAO> _professionsDAO;
public:
    ProfessionsService() : _professionsDAO(new ProfessionsDAO) {}
    QVector<QString> getAllProfessions() override;
    bool addProfession(QString &name) override;
    bool removeProfessionByName(QString &name) override;
    bool changeNameProfession(QString &oldName, QString &newName) override;
};

#endif
