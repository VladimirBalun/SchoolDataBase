#ifndef PROFESSIONSSERVICE_H
#define PROFESSIONSSERVICE_H

#include <memory>
#include "IProfessionsService.h"
#include "Data/DAO/ProfessionsDAO.h"
#include "Utils/Logger.h"
#include "Exceptions/NotWorkingRequest.h"

class ProfessionsService : public IProfessionsService {
    std::unique_ptr<IProfessionsDAO> professionsDAO;
public:
    Logger log;
    ProfessionsService();
    QVector<QString> getAllProfessions() override;
    bool addProfession(QString &name) override;
    bool removeProfessionByName(QString &name) override;
    bool changeNameProfession(QString &oldName, QString &newName) override;
};

#endif
