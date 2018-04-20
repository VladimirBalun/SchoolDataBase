#ifndef MAINFORMPAGETEACHERS_H
#define MAINFORMPAGETEACHERS_H

#include "Data/Service/TeachersService.h"
#include "Data/Service/PredmetsService.h"
#include "MainFormPage.h"

namespace Ui {
class MainForm;
}

class MainFormPageTeachers :public  MainFormPage {
public:
    MainFormPageTeachers(Ui::MainForm* mainForm);
    void removeTeacherPredmet();
    void addPredmetForTeacher();
    void addPredmet();
    void removePredmet();
    void reloadTeachersInTable();
    void reloadTeachersInCheckBox();
private:
    void reloadPredmetsInCheckBox();
private:
    Ui::MainForm* _ui;
    QScopedPointer<ITeachersService> _teachersService;
    QScopedPointer<IPredmetsService> _predmetsService;
    QScopedPointer<QStandardItemModel> _modelTeachers;
};

#endif
