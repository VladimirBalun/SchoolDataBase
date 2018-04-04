#ifndef PUPILSDAO_H
#define PUPILSDAO_H

#include <QtSql>
#include <QSqlQuery>
#include "IPupilsDAO.h"
#include "Data/Entity/Pupil.h"
#include "Exceptions/NotWorkingRequest.h"

class PupilsDAO : public IPupilsDAO {
public:
    PupilsDAO();
    QVector<QSharedPointer<Pupil>> findAllPupils() override;
    QVector<QSharedPointer<Pupil>> findPupilsByClass(const QString& nameClass) override;
    QVector<QSharedPointer<Pupil>> findPupilsByName(const QString& name) override;
    void addPupil(const QSharedPointer<Pupil>& pupil) override;
    void removePupilByName(const QString& name) override;
private:
    void loadPupilsInVectorFromDB(QSqlQuery& query);
private:
    QVector<QSharedPointer<Pupil>> _pupils;
    QString _basicSelectQuery;
};

#endif
