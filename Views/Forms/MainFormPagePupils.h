#ifndef MAINFORMPAGEPUPILS_H
#define MAINFORMPAGEPUPILS_H

#include "MainFormPage.h"
#include "Data/Service/PupilsService.h"

namespace Ui {
class MainForm;
}

class MainFormPagePupils : MainFormPage {
public:
    MainFormPagePupils(Ui::MainForm* mainForm);
    void reloadPupilsAndParents();
    void addPupil();
    void removePupil();
    void selectPupils();
    void searchPupils();
    void addParent();
    void removeParent();
private:
    void reloadPupilsInTable(QVector<QSharedPointer<Pupil> > pupils);
private:
    Ui::MainForm* _ui;
    QScopedPointer<IPupilsService> _pupilsService;
    QScopedPointer<QStandardItemModel> _modelPupils;
    QScopedPointer<QStandardItemModel> _modelParents;
};

#endif
