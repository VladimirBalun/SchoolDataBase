#ifndef MAINFORMPAGEEMPLOYEES_H
#define MAINFORMPAGEEMPLOYEES_H

#include <memory>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include "Views/Dialogs/AddingEmployeDialog.h"
#include "Data/Service/EmployeesService.h"

namespace Ui {
class MainForm;
}

class MainFormPageEmployees {
    Ui::MainForm* ui;
    std::unique_ptr<IEmployeesService> employeesService;
    std::unique_ptr<QStandardItemModel> modelEmployees;
    void reloadEmployeesInTable();
    void reloadProfessionsInCheckBox();
public:
    MainFormPageEmployees(Ui::MainForm* mainForm);
    void addEmploye();
    void removeEmploye();
    void sortEmployees();
    void selectEmployees();
    void searchEmployees();
};

#endif
