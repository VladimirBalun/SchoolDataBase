#ifndef IPARENTSSERVICE_H
#define IPARENTSSERVICE_H

#include <QVector>
#include <QSharedPointer>
#include "Data/Entity/Parent.h"

struct IParentsService {
    virtual QVector<QSharedPointer<Parent>> getParentsByChild(const QString& name) = 0;
    virtual bool addParent(QSharedPointer<Parent>& parent) = 0;
    virtual bool removeParentByName(const QString& name) = 0;
    virtual ~IParentsService() {}
};

#endif
