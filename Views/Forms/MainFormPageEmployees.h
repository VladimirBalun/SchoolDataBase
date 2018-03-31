#ifndef MAINFORMPAGEEMPLOYEES_H
#define MAINFORMPAGEEMPLOYEES_H

#include <QMessageBox>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QStandardItem>
#include <QStandardItemModel>
#include "Views/Dialogs/AddingEmployeDialog.h"
#include "Data/Service/EmployeesService.h"
#include "Data/Service/ProfessionsService.h"

namespace Ui {
class MainForm;
}

class MainFormPageEmployees {
public:
    MainFormPageEmployees(Ui::MainForm* mainForm);
    void reloadEmployees();
    void addEmploye();
    void removeEmploye();
    void sortEmployees();
    void selectEmployees();
    void searchEmployees();
private:
    void reloadEmployeesInTable();
    void reloadProfessionsInCheckBox();
private:
    Ui::MainForm* _ui;
    QScopedPointer<IEmployeesService> _employeesService;
    QScopedPointer<IProfessionsService> _professionsService;
    QScopedPointer<QStandardItemModel> _modelEmployees;
};

#endif
