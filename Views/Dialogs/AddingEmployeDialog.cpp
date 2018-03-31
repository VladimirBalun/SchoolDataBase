#include "AddingEmployeDialog.h"
#include "ui_AddingEmployeDialog.h"

AddingEmployeDialog::AddingEmployeDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddingEmployeDialog) {
    ui->setupUi(this);
    professionsService = std::make_unique<ProfessionsService>();

    connect(ui->btnAddProfession, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddProfession()));
    connect(ui->btnAccept, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAccept()));
    connect(ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(clickedBtnCancel()));

    ui->cbxProfessions->addItem("Не выбрано");
    QVector<QString> professions = professionsService->getAllProfessions();
    for(auto it = professions.begin(); it != professions.end(); it++) {
        ui->cbxProfessions->addItem(*it);
    }
}

QSharedPointer<Employe> AddingEmployeDialog::getData() {
    QSharedPointer<Employe> employe = Employe::Builder()
            .setName(ui->editName->text())
            .setDateBirth(ui->editDateBirth->text())
            .setAddress(ui->editAddress->text())
            .setPhoneNumber(ui->editPhoneNumber->text())
            .setPersonalData(ui->editPersonalData->text())
            .setProfession(ui->cbxProfessions->currentText())
            .build();
    std::cout << "[DEBUG] Sending Employe from dialog: " << employe << std::endl;
    return employe;
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

void AddingEmployeDialog::clickedBtnAddProfession() {
    bool ok;
    QString name = QInputDialog::getText(this, "Добавление профессии", "Введите название профессии:", QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !name.isEmpty()){
        if(professionsService->addProfession(name)){
            ui->cbxProfessions->addItem(name);
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
    delete ui;
}

