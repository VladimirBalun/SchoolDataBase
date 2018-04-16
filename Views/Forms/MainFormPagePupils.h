#ifndef MAINFORMPAGEPUPILS_H
#define MAINFORMPAGEPUPILS_H

#include "MainFormPage.h"
#include "Data/Service/PupilsService.h"
#include "Data/Service/ClassesService.h"
#include "Views/Dialogs/AddingPupilDialog.h"

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
    void addClass();
    void removeClass();
private:
    void reloadPupilsInTable(QVector<QSharedPointer<Pupil>> pupils);
    void reloadClassesInCheckBox();
private:
    Ui::MainForm* _ui;
    QScopedPointer<IPupilsService> _pupilsService;
    QScopedPointer<IClassesService> _classesService;
    QScopedPointer<QStandardItemModel> _modelPupils;
    QScopedPointer<QStandardItemModel> _modelParents;
};

#endif
