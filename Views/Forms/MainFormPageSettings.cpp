#include "MainFormPageSettings.h"
#include "ui_MainForm.h"

MainFormPageSettings::MainFormPageSettings(Ui::MainForm* mainForm) {
    ui = mainForm;
    administratorsService = std::make_unique<AdministratorsService>();
    modelAdministrators = std::make_unique<QStandardItemModel>();

    QStringList headers = {"Логин", "Пароль"};
    modelAdministrators->setHorizontalHeaderLabels(headers);
    ui->tableAdministrators->setModel(modelAdministrators.get());
    ui->tableAdministrators->resizeColumnsToContents();
    ui->tableAdministrators->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    reloadInformationInTable();
}

void MainFormPageSettings::reloadInformationInTable() {
    QMap<QString, QString> administrators = administratorsService->getAllAdministrators();
    modelAdministrators->removeRows(0, modelAdministrators->rowCount());
    ui->cbxAdminsLogin->clear();
    ui->cbxAdminsLogin->addItem("Не выбрано");
    size_t row = 0;
    for (auto it = administrators.begin(); it != administrators.end(); it++) {
        QString login = it.key();
        QString password = it.value();
        ui->cbxAdminsLogin->addItem(login);
        modelAdministrators->setItem(row, 0, new QStandardItem(login));
        modelAdministrators->setItem(row, 1, new QStandardItem(password));
        row++;
    }
}

void MainFormPageSettings::addAdministrator() {
    QString login = ui->editAdminLogin->text();
    QString password = ui->editAdminPassword->text();
    if(login.isEmpty()) {
          QMessageBox::critical(0, "Ошибка добавления", "Не введене логин, добавление администратора невозможно.");
          return;
    }
    if(password.isEmpty()) {
          QMessageBox::critical(0, "Ошибка добавления", "Не введене пароль, добавление администратора невозможно.");
          return;
    }
    if(administratorsService->addAdministrator(login , password)) {
          QMessageBox::information(0, "Успешная операция", "Администратор [" + login + "] успешно добавлен.");
          ui->editAdminLogin->setText("");
          ui->editAdminPassword->setText("");
          reloadInformationInTable();
    } else {
          QMessageBox::warning(0, "Неудачная операция", "Администратор [" + login + "] не был добавлен. Возможно такой администратор уже существует.");
    }
}

void MainFormPageSettings::changePasswordAdministrator() {
    QString login = ui->cbxAdminsLogin->currentText();
    QString oldPassword = ui->editAdminOldPassword->text();
    QString newPassword = ui->editAdminNewPassword->text();
    if(login == "Не выбрано") {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не выбран администратор для изменения пароля.");
        return;
    }
    if(oldPassword.isEmpty()) {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не введен старый пароль этого администартора.");
        return;
    }
    if(newPassword.isEmpty()) {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не введен новый пароль для администартора.");
        return;
    }
    if(administratorsService->changePasswordAdministratoByLogin(login, oldPassword, newPassword)) {
        QMessageBox::information(0, "Успешная операция", "Пароль администратора[" + login + "] успешно изменен.");
        ui->cbxAdminsLogin->setCurrentIndex(0);
        ui->editAdminOldPassword->setText("");
        ui->editAdminNewPassword->setText("");
        reloadInformationInTable();
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Был введен неправильный страый пароль. Изменение пароля невозможно");
    }
}

void MainFormPageSettings::removeAdministrator() {
    QModelIndexList selectedRows = getSelectedRows();
    if(selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) администратор(ы) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить сотрудника(ов)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        removeSelectedRows(selectedRows);
        reloadInformationInTable();
    }
}

QModelIndexList MainFormPageSettings::getSelectedRows() {
    QAbstractItemView* view = ui->tableAdministrators;
    QItemSelectionModel* selectedModel = view->selectionModel();
    return selectedModel->selectedRows();
}

void MainFormPageSettings::removeSelectedRows(QModelIndexList selectedRows) {
    for(auto row : selectedRows) {
        QString login = row.data().toString();
        if(administratorsService->removeAdministratorByLogin(login)) {
            QMessageBox::information(0, "Успешная операция", "Администратора[" + login + "] успешно удален.");
        } else {
            QMessageBox::warning(0, "Неудачная операция", "Такого администратора не существует.");
        }
    }
}


