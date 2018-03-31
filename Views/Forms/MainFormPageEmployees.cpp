#include "MainFormPageEmployees.h"
#include "ui_MainForm.h"

MainFormPageEmployees::MainFormPageEmployees(Ui::MainForm* mainForm)
    : _employeesService(new EmployeesService), _professionsService(new ProfessionsService), _modelEmployees(new QStandardItemModel)  {

    _ui = mainForm;
    QStringList headers = {"ФИО", "Дата рождения", "Адрес", "Профессия", "Номер телефона", "Персональные данные"};
    _modelEmployees->setHorizontalHeaderLabels(headers);
    _ui->tableEmployees->setModel(_modelEmployees.data());
    _ui->tableEmployees->resizeColumnsToContents();
    _ui->tableEmployees->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadEmployeesInTable();
    reloadProfessionsInCheckBox();
}

void MainFormPageEmployees::reloadEmployeesInTable() {
    QVector<QSharedPointer<Employe>> employees = _employeesService->getAllEmployees();
    _modelEmployees->removeRows(0, _modelEmployees->rowCount());
    for (long i = 0; i < employees.size(); i++) {
        _modelEmployees->setItem(i, 0, new QStandardItem(employees.at(i)->getName()));
        _modelEmployees->setItem(i, 1, new QStandardItem(employees.at(i)->getDateBirth()));
        _modelEmployees->setItem(i, 2, new QStandardItem(employees.at(i)->getAddress()));
        _modelEmployees->setItem(i, 3, new QStandardItem(employees.at(i)->getProfession()));
        _modelEmployees->setItem(i, 4, new QStandardItem(employees.at(i)->getPhoneNumber()));
        _modelEmployees->setItem(i, 5, new QStandardItem(employees.at(i)->getPersonalData()));
    }
}

void MainFormPageEmployees::reloadProfessionsInCheckBox() {
    QVector<QString> professions = _professionsService->getAllProfessions();
    _ui->cbxProfessions->clear();
    _ui->cbxProfessions->addItem("Не выбрано");
    for (auto profession : professions) {
          _ui->cbxProfessions->addItem(profession);
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
        QSharedPointer<Employe> employe = addingEmployeDialog.getData();
        if (_employeesService->addEmploye(employe)) {
            QMessageBox::information(0, "Успешная операция", "Сотрудник [" + employe->getName() + "] был успешно добавлен.");
        } else {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо уже существует такой сотрудник с таким именем, добавление нового невозможно.");
        }
    }
}

void MainFormPageEmployees::removeEmploye() {

}

void MainFormPageEmployees::sortEmployees() {
    if (_ui->cbxMethodSortingEmployees->currentText() == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка сортировки", "Не выбран метод сортировки, сортировка невозможна.");
        return;
    }
    reloadEmployeesInTable();
}

void MainFormPageEmployees::selectEmployees() {
    if (_ui->cbxProfessions->currentText() == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка выборки", "Не выбрана профессия, выборка сотрудников невозможна.");
        return;
    }
    reloadEmployeesInTable();
}

void MainFormPageEmployees::searchEmployees() {
    if (_ui->editSearchEmployee->text().isEmpty()) {
        QMessageBox::critical(0, "Ошибка поиска", "Не введено ФИО сотрудника, поиск невозможна.");
        return;
    }
    reloadEmployeesInTable();
}
