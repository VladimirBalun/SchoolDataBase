#include "MainFormPageSettings.h"
#include "ui_MainForm.h"

MainFormPageSettings::MainFormPageSettings(Ui::MainForm* mainForm)
    :  _administratorsService(new AdministratorsService), _modelAdministrators(new QStandardItemModel) {

    _ui = mainForm;
    QStringList headers = {"Логин", "Пароль"};
    _modelAdministrators->setHorizontalHeaderLabels(headers);
    _ui->tableAdministrators->setModel(_modelAdministrators.data());
    _ui->tableAdministrators->resizeColumnsToContents();
    _ui->tableAdministrators->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    reloadAdministratorsInTable();
    reloadAdministratorsInCheckBox();
}

void MainFormPageSettings::reloadAdministratorsInTable() {
    QMap<QString, QString> administrators = _administratorsService->getAllAdministrators();
    _modelAdministrators->removeRows(0, _modelAdministrators->rowCount());
    size_t row = 0;
    for (auto it = administrators.begin(); it != administrators.end(); it++) {
        _modelAdministrators->setItem(row, 0, new QStandardItem(it.key())); //login
        _modelAdministrators->setItem(row, 1, new QStandardItem(it.value())); //password
        row++;
    }
}

void MainFormPageSettings::reloadAdministratorsInCheckBox() {
    QMap<QString, QString> administrators = _administratorsService->getAllAdministrators();
    _ui->cbxAdminsLogin->clear();
    _ui->cbxAdminsLogin->addItem("Не выбрано");
    for (auto it = administrators.begin(); it != administrators.end(); it++) {
        _ui->cbxAdminsLogin->addItem(it.key());
    }
}

void MainFormPageSettings::addAdministrator() {
    QString login = _ui->editAdminLogin->text();
    QString password = _ui->editAdminPassword->text();
    if (login.isEmpty()) {
          QMessageBox::critical(0, "Ошибка добавления", "Не введене логин, добавление администратора невозможно.");
          return;
    }
    if (password.isEmpty()) {
          QMessageBox::critical(0, "Ошибка добавления", "Не введене пароль, добавление администратора невозможно.");
          return;
    }
    if (_administratorsService->addAdministrator(login , password)) {
          QMessageBox::information(0, "Успешная операция", "Администратор [" + login + "] успешно добавлен.");
          _ui->editAdminLogin->setText("");
          _ui->editAdminPassword->setText("");
          reloadAdministratorsInTable();
          reloadAdministratorsInCheckBox();
    } else {
          QMessageBox::warning(0, "Неудачная операция", "Администратор [" + login + "] не был добавлен. Возможно такой администратор уже существует.");
    }
}

void MainFormPageSettings::changePasswordAdministrator() {
    QString login = _ui->cbxAdminsLogin->currentText();
    QString oldPassword = _ui->editAdminOldPassword->text();
    QString newPassword = _ui->editAdminNewPassword->text();
    if (login == "Не выбрано") {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не выбран администратор для изменения пароля.");
        return;
    }
    if (oldPassword.isEmpty()) {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не введен старый пароль этого администартора.");
        return;
    }
    if(newPassword.isEmpty()) {
        QMessageBox::warning(0, "Ошибка изменения пароля", "Не введен новый пароль для администартора.");
        return;
    }
    if (_administratorsService->changePasswordAdministratoByLogin(login, oldPassword, newPassword)) {
        QMessageBox::information(0, "Успешная операция", "Пароль администратора[" + login + "] успешно изменен.");
        _ui->cbxAdminsLogin->setCurrentIndex(0);
        _ui->editAdminOldPassword->setText("");
        _ui->editAdminNewPassword->setText("");
        reloadAdministratorsInTable();
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Был введен неправильный страый пароль. Изменение пароля невозможно");
    }
}

void MainFormPageSettings::removeAdministrator() {
    QModelIndexList selectedRows = getSelectedRows(_ui->tableAdministrators);
    if(selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) администратор(ы) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить администратора(ов)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        removeSelectedRows(selectedRows);
        reloadAdministratorsInTable();
        reloadAdministratorsInCheckBox();
    }
}

void MainFormPageSettings::removeSelectedRows(QModelIndexList selectedRows) {
    for (auto row : selectedRows) {
        QString login = row.data().toString();
        if(_administratorsService->removeAdministratorByLogin(login)) {
            QMessageBox::information(0, "Успешная операция", "Администратор [" + login + "] успешно удален.");
        } else {
            QMessageBox::warning(0, "Неудачная операция", "Такого администратора не существует.");
        }
    }
}
