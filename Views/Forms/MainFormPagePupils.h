#ifndef MAINFORMPAGEPUPILS_H
#define MAINFORMPAGEPUPILS_H

#include "MainFormPage.h"
#include "Data/Service/PupilsService.h"
#include "Data/Service/ParentsService.h"
#include "Data/Service/ClassesService.h"
#include "Views/Dialogs/AddingPupilDialog.h"
#include "Views/Dialogs/AddingParentDialog.h"

namespace Ui {
class MainForm;
}

class MainFormPagePupils : public MainFormPage {
public:
    MainFormPagePupils(Ui::MainForm* mainForm);
    void reloadPupilsAndParents();
    void addPupil();
    void removePupil();
    void selectPupils();
    void searchPupils();
    void addParent();
    void removeParent();
    void showParentsSelectedPupil(QModelIndex index);
    void addClass();
    void removeClass();
private:
    void reloadPupilsInTable(QVector<QSharedPointer<Pupil>> pupils);
    void reloadParentsInTable(QVector<QSharedPointer<Parent>> parents);
    void reloadClassesInCheckBox();
private:
    Ui::MainForm* _ui;
    QScopedPointer<IPupilsService> _pupilsService;
    QScopedPointer<IParentsService> _parentsService;
    QScopedPointer<IClassesService> _classesService;
    QScopedPointer<QStandardItemModel> _modelPupils;
    QScopedPointer<QStandardItemModel> _modelParents;
};

#endif
