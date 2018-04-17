#ifndef PARENTSDAO_H
#define PARENTSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IParentsDAO.h"
#include "Exceptions/NotWorkingRequest.h"

class ParentsDAO : public IParentsDAO {
    QVector<QSharedPointer<Parent>> _parents;
public:
    QVector<QSharedPointer<Parent>> findParentsByChild(const QString& name) override;
    void addParent(QSharedPointer<Parent>& parent) override;
    void removeParentByName(const QString& name) override;
};

#endif
