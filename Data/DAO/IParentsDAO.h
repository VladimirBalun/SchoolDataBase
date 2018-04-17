#ifndef IPARENTSDAO_H
#define IPARENTSDAO_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Parent.h"

struct IParentsDAO {
    virtual QVector<QSharedPointer<Parent>> findParentsByChild(const QString& name) = 0;
    virtual void addParent(QSharedPointer<Parent>& parent) = 0;
    virtual void removeParentByName(const QString& name) = 0;
    virtual ~IParentsDAO() {}
};

#endif
