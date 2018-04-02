#ifndef MAINFORMPAGEEMPLOYEES_H
#define MAINFORMPAGEEMPLOYEES_H

#include "Views/Dialogs/AddingEmployeDialog.h"
#include "Data/Service/EmployeesService.h"
#include "Data/Service/ProfessionsService.h"
#include "MainFormPage.h"

namespace Ui {
class MainForm;
}

class MainFormPageEmployees : public MainFormPage {
public:
    MainFormPageEmployees(Ui::MainForm* mainForm);
    void reloadEmployees();
    void addEmploye();
    void removeEmploye();
    void selectEmployees();
    void searchEmployees();
    void addProfession();
    void removeProfession();
private:
    void reloadEmployeesInTable(QVector<QSharedPointer<Employe>> employees);
    void reloadProfessionsInCheckBox();
    void removeSelectedRows(QModelIndexList selectedRows);
private:
    Ui::MainForm* _ui;
    QScopedPointer<IEmployeesService> _employeesService;
    QScopedPointer<IProfessionsService> _professionsService;
    QScopedPointer<QStandardItemModel> _modelEmployees;
};

#endif
