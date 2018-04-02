#include "AddingEmployeDialog.h"
#include "ui_AddingEmployeDialog.h"

AddingEmployeDialog::AddingEmployeDialog(QWidget *parent) : QDialog(parent),
    _ui(new Ui::AddingEmployeDialog), _professionsService(new ProfessionsService) {

    _ui->setupUi(this);

    connect(_ui->btnAddProfession, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddProfession()));
    connect(_ui->btnAccept, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAccept()));
    connect(_ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(clickedBtnCancel()));

    _ui->cbxProfessions->addItem("Не выбрано");
    QVector<QString> professions = _professionsService->getAllProfessions();
    for(auto it = professions.begin(); it != professions.end(); it++) {
        _ui->cbxProfessions->addItem(*it);
    }
}

QSharedPointer<Employe> AddingEmployeDialog::getData() {
    QSharedPointer<Employe> employe = Employe::Builder()
            .setName(_ui->editName->text())
            .setDateBirth(_ui->editDateBirth->text())
            .setAddress(_ui->editAddress->text())
            .setPhoneNumber(_ui->editPhoneNumber->text())
            .setPersonalData(_ui->editPersonalData->text())
            .setProfession(_ui->cbxProfessions->currentText())
            .build();
    return employe;
}

void AddingEmployeDialog::clickedBtnAccept() {
    if (isValidDialog()) {
        accept();
    }
}

bool AddingEmployeDialog::isValidDialog() {
    if (_ui->editName->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите ФИО.");
        return false;
    }
    if (_ui->editDateBirth->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите дату рождения.");
        return false;
    }
    if (_ui->editAddress->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите адрес.");
        return false;
    }
    if (_ui->editPhoneNumber->text().isEmpty()) {
        QMessageBox::warning(0, "Ошибка", "Введите номер телефона.");
        return false;
    }
    if (_ui->editPersonalData->text().isEmpty())
    {
        QMessageBox::warning(0, "Ошибка", "Введите персональные данные.");
        return false;
    }
    if (_ui->cbxProfessions->currentText() == "Не выбрано") {
        QMessageBox::warning(0, "Ошибка", "Выберите профессию для сотрудника.");
        return false;
    }
    return true;
}

void AddingEmployeDialog::clickedBtnAddProfession() {
    bool ok;
    QString name = QInputDialog::getText(this, "Добавление профессии", "Введите название профессии:", QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !name.isEmpty()){
        if(_professionsService->addProfession(name)){
            _ui->cbxProfessions->addItem(name);
            QMessageBox::information(0, "Успешная операция", "Профессия [" + name + "] успешно добавлена.");
        } else {
            QMessageBox::warning(0, "Неудачная операция", "Профессия [" + name + "] не была добавлена. Возможно такая профессия уже существует.");
        }
    }
}

void AddingEmployeDialog::clickedBtnCancel() {
    this->close();
}

AddingEmployeDialog::~AddingEmployeDialog() {
    delete _ui;
}

