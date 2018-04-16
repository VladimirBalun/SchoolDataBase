#include "MainFormPageEmployees.h"
#include "ui_MainForm.h"

MainFormPageEmployees::MainFormPageEmployees(Ui::MainForm* mainForm)
    : _ui(mainForm), _employeesService(new EmployeesService), _professionsService(new ProfessionsService), _modelEmployees(new QStandardItemModel)  {

    QStringList headers = {"ФИО", "Дата рождения", "Адрес", "Профессия", "Номер телефона", "Персональные данные"};
    _modelEmployees->setHorizontalHeaderLabels(headers);
    _ui->tableEmployees->setModel(_modelEmployees.data());
    _ui->tableEmployees->resizeColumnsToContents();
    _ui->tableEmployees->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadEmployeesInTable(_employeesService->getAllEmployees());
    reloadProfessionsInCheckBox();
}

void MainFormPageEmployees::reloadEmployeesInTable(QVector<QSharedPointer<Employe> > employees) {
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
    _ui->cbxDeletingProfession->clear();
    _ui->cbxDeletingProfession->addItem("Не выбрано");
    for (auto profession : professions) {
          _ui->cbxProfessions->addItem(profession);
          _ui->cbxDeletingProfession->addItem(profession);
    }
}

void MainFormPageEmployees::reloadEmployees() {
    reloadEmployeesInTable(_employeesService->getAllEmployees());
    reloadProfessionsInCheckBox();
    QMessageBox::information(0, "Успешная операция", "Сотрудники и их профессии успешно обновлены.");
}

void MainFormPageEmployees::addEmploye() {
    AddingEmployeDialog addingEmployeDialog;
    if (addingEmployeDialog.exec() == QDialog::Accepted) {
        QSharedPointer<Employe> employe = addingEmployeDialog.getData();
        if (_employeesService->addEmploye(employe)) {
            QMessageBox::information(0, "Успешная операция", "Сотрудник [" + employe->getName() + "] был успешно добавлен.");
            reloadEmployeesInTable(_employeesService->getAllEmployees());
        } else {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо уже существует такой сотрудник с таким именем, добавление нового невозможно.");
        }
    }
}

void MainFormPageEmployees::removeEmploye() {
    QModelIndexList selectedRows = getSelectedRows(_ui->tableEmployees);
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) сотрудник(и) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить сотрудника(ов)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        removeSelectedRows(selectedRows);
        reloadEmployeesInTable(_employeesService->getAllEmployees());
    }
}

void MainFormPageEmployees::removeSelectedRows(QModelIndexList selectedRows) {
    for (auto row : selectedRows) {
        QString name = row.data().toString();
        if(_employeesService->removeEmployeByName(name)) {
            QMessageBox::information(0, "Успешная операция", "Сотрудник [" + name + "] успешно удален.");
        } else {
            QMessageBox::warning(0, "Неудачная операция", "Такого сотрудника не существует.");
        }
    }
}

void MainFormPageEmployees::selectEmployees() {
    QString profession = _ui->cbxProfessions->currentText();
    if (profession == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка выборки", "Не выбрана профессия, выборка сотрудников невозможна.");
        return;
    }
    reloadEmployeesInTable(_employeesService->selectEmployeesByProfession(profession));
}

void MainFormPageEmployees::searchEmployees() {
    QString name = _ui->editSearchEmployee->text();
    if (name.isEmpty()) {
        QMessageBox::critical(0, "Ошибка поиска", "Не введено ФИО сотрудника, поиск невозможна.");
        return;
    }
    reloadEmployeesInTable(_employeesService->searchEmployeesByName(name));
}

void MainFormPageEmployees::addProfession() {
    QString profession = _ui->editAddingProfession->text();
    if (profession.isEmpty()) {
        QMessageBox::critical(0, "Ошибка добавления", "Не введено название профессии, добавление невозможно.");
        return;
    }
    if(_professionsService->addProfession(profession)){
        QMessageBox::information(0, "Успешная операция", "Профессия [" + profession + "] успешно добавлена.");
        reloadProfessionsInCheckBox();
        _ui->editAddingProfession->setText("");
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Профессия [" + profession + "] не была добавлена. Возможно такая профессия уже существует.");
    }
}

void MainFormPageEmployees::removeProfession() {
    QString profession = _ui->cbxDeletingProfession->currentText();
    if (profession == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка удаления", "Не выбрано название профессии, удаление невозможно.");
        return;
    }
    if(_professionsService->removeProfessionByName(profession)){
        QMessageBox::information(0, "Успешная операция", "Профессия [" + profession + "] успешно удалена.");
        reloadProfessionsInCheckBox();
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Профессия [" + profession + "] не была удалена.");
    }
}
