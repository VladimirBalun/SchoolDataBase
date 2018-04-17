#include "AddingParentDialog.h"
#include "ui_AddingParentDialog.h"

AddingParentDialog::AddingParentDialog(QWidget *parent) : QDialog(parent), _ui(new Ui::AddingParentDialog), _pupilsService(new PupilsService) {
    _ui->setupUi(this);

    connect(_ui->btnAccept, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAccept()));
    connect(_ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(clickedBtnCancel()));

    _ui->cbxPupils->addItem("Не выбрано");
    QVector<QSharedPointer<Pupil>> pupils = _pupilsService->getAllPupils();
    for (auto pupil : pupils) {
        _ui->cbxPupils->addItem(pupil->getName());
    }
}

QSharedPointer<Parent> AddingParentDialog::getData() {
    QSharedPointer<Parent> parent = Parent::Builder()
            .setName(_ui->editName->text())
            .setDateBirth(_ui->editDateBirth->text())
            .setAddress(_ui->editAddress->text())
            .setChild(_ui->cbxPupils->currentText())
            .build();
    return parent;
}

void AddingParentDialog::clickedBtnAccept() {
    if(isValidDialog()) {
       accept();
    }
}

bool AddingParentDialog::isValidDialog() {
    if(_ui->editName->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите ФИО.");
        return false;
    }
    if(_ui->editDateBirth->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите дату рождения.");
        return false;
    }
    if(_ui->editAddress->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите адрес.");
        return false;
    }
    if(_ui->cbxPupils->currentText() == "Не вбырано") {
        QMessageBox::warning(0, "Ошибка", "Введите ребенка для родителя.");
        return false;
    }
    return true;
}

void AddingParentDialog::clickedBtnCancel() {
    this->close();
}

AddingParentDialog::~AddingParentDialog() {
    delete _ui;
}
