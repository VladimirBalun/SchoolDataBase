#include "MainFormPageEmployees.h"
#include "ui_MainForm.h"

MainFormPageEmployees::MainFormPageEmployees(Ui::MainForm* mainForm) {
    ui = mainForm;
    employeesService = std::make_unique<EmployeesService>();
    professionsService = std::make_unique<ProfessionsService>();
    modelEmployees = std::make_unique<QStandardItemModel>();

    QStringList headers = {"ФИО", "Дата рождения", "Адрес", "Профессия", "Номер телефона", "Персональные данные"};
    modelEmployees->setHorizontalHeaderLabels(headers);
    ui->tableEmployees->setModel(modelEmployees.get());
    ui->tableEmployees->resizeColumnsToContents();
    ui->tableEmployees->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadEmployeesInTable();
    reloadProfessionsInCheckBox();
}

void MainFormPageEmployees::reloadEmployeesInTable() {
    QVector<Employe*> employees = employeesService->getAllEmployees();
    modelEmployees->removeRows(0, modelEmployees->rowCount());
    for (long i = 0; i < employees.size(); i++) {
        modelEmployees->setItem(i, 0, new QStandardItem(employees.at(i)->getName()));
        modelEmployees->setItem(i, 1, new QStandardItem(employees.at(i)->getDateBirth()));
        modelEmployees->setItem(i, 2, new QStandardItem(employees.at(i)->getAddress()));
        modelEmployees->setItem(i, 3, new QStandardItem(employees.at(i)->getProfession()));
        modelEmployees->setItem(i, 4, new QStandardItem(employees.at(i)->getPhoneNumber()));
        modelEmployees->setItem(i, 5, new QStandardItem(employees.at(i)->getPersonalData()));
    }
}

void MainFormPageEmployees::reloadProfessionsInCheckBox() {
    QVector<QString> professions = professionsService->getAllProfessions();
    ui->cbxProfessions->clear();
    ui->cbxProfessions->addItem("Не выбрано");
    for (auto profession : professions) {
          ui->cbxProfessions->addItem(profession);
    }
}

void MainFormPageEmployees::reloadEmployees() {
    reloadEmployeesInTable();
    reloadProfessionsInCheckBox();
    QMessageBox::information(0, "Успешная операция", "Сотрудники и их профессии успешно обновлены.");
}

void MainFormPageEmployees::addEmploye() {
    AddingEmployeDialog addingEmployeDialog;
    if (addingEmployeDialog.exec() == QDialog::Accepted) {
        Employe* employe = addingEmployeDialog.getData();
        if (employeesService->addEmploye(employe)) {
            QMessageBox::information(0, "Успешная операция", "Сотрудник [" + employe->getName() + "] был успешно добавлен.");
        } else {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо уже существует такой сотрудник с таким именем, добавление нового невозможно.");
        }
    }
}

void MainFormPageEmployees::removeEmploye() {

}

void MainFormPageEmployees::sortEmployees() {
    if (ui->cbxMethodSortingEmployees->currentText() == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка сортировки", "Не выбран метод сортировки, сортировка невозможна.");
        return;
    }
    reloadEmployeesInTable();
}

void MainFormPageEmployees::selectEmployees() {
    if (ui->cbxProfessions->currentText() == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка выборки", "Не выбрана профессия, выборка сотрудников невозможна.");
        return;
    }
    reloadEmployeesInTable();
}

void MainFormPageEmployees::searchEmployees() {
    if (ui->editSearchEmployee->text().isEmpty()) {
        QMessageBox::critical(0, "Ошибка поиска", "Не введено ФИО сотрудника, поиск невозможна.");
        return;
    }
    reloadEmployeesInTable();
}
