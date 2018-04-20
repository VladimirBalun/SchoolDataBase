#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <memory>
#include <QMainWindow>

#include "PagesMainForm/MainFormPageEmployees.h"
#include "PagesMainForm/MainFormPageTeachers.h"
#include "PagesMainForm/MainFormPagePupils.h"
#include "PagesMainForm/MainFormPageSettings.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
    Q_OBJECT
public:
    explicit MainForm(QWidget* parent = 0);
    ~MainForm();
private slots:
    void clickedBtnReloadEmployees();
    void clickedBtnAddEmploye();
    void clickedBtnRemoveEmploye();
    void clickedBtnSelectEmployees();
    void clickedBtnSearchEmployees();
    void clickedBtnAddProfession();
    void clickedBtnRemoveProfession();

    void clickedBtnAddPredmetForTeacher();
    void clickedBtnRemoveTeacherPredmet();
    void clickedBtnAddPredmet();
    void clickedBtnRemovePredmet();

    void clickedBtnAddPupil();
    void clickedBtnRemovePupil();
    void clickedBtnSelectPupils();
    void clickedBtnSearchPupils();
    void clickedBtnReloadPupils();
    void clickedBtnAddParent();
    void clickedBtnRemoveParent();
    void selectedPupil(QModelIndex index);
    void clickedBtnAddClass();
    void clickedBtnRemoveClass();

    void clickedBtnAddAdmin();
    void clickedBtnChangeAdminPassword();
    void clickedBtnRemoveAdmin();
private:
    Ui::MainForm* _ui;
    std::unique_ptr<MainFormPageEmployees> _mainFormPageEmployees;
    std::unique_ptr<MainFormPageTeachers> _mainFormPageTeachers;
    std::unique_ptr<MainFormPagePupils> _mainFormPagePupils;
    std::unique_ptr<MainFormPageSettings> _mainFormPageSettings;
};

#endif
