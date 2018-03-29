#include "AddingEmployeDialog.h"
#include "ui_AddingEmployeDialog.h"

AddingEmployeDialog::AddingEmployeDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddingEmployeDialog) {
    ui->setupUi(this);
    connect(ui->btnAccept, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAccept()));
    connect(ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(clickedBtnCancel()));

    ui->cbxProfessions->addItem("Не выбрано");
    QVector<QString> professions; // needs add service here!!!
    for(auto it = professions.begin(); it != professions.end(); it++) {
        ui->cbxProfessions->addItem(*it);
    }
}

Employe* AddingEmployeDialog::getData() {
    return Employe::Builder()
            .setName(ui->editName->text())
            .setDateBirth(ui->editDateBirth->text())
            .setAddress(ui->editAddress->text())
            .setPhoneNumber(ui->editPhoneNumber->text())
            .setPersonalData(ui->editPersonalData->text())
            .setProfession(ui->cbxProfessions->currentText())
            .build();
}

void AddingEmployeDialog::clickedBtnAccept() {
    if (isValidDialog()) {
        accept();
    }
}

bool AddingEmployeDialog::isValidDialog() {
    if (ui->editName->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите ФИО.");
        return false;
    }
    if (ui->editDateBirth->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите дату рождения.");
        return false;
    }
    if (ui->editAddress->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите адрес.");
        return false;
    }
    if (ui->editPhoneNumber->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите номер телефона.");
        return false;
    }
    if (ui->editPersonalData->text().isEmpty())
    {
        QMessageBox::warning(0, "Ошибка", "Введите персональные данные.");
        return false;
    }
    if (ui->cbxProfessions->currentText() == "Не выбрано") {
        QMessageBox::warning(0, "Ошибка", "Выберите профессию для сотрудника.");
        return false;
    }
    return true;
}

void AddingEmployeDialog::clickedBtnCancel() {
    this->close();
}

AddingEmployeDialog::~AddingEmployeDialog() {
    delete ui;
}

