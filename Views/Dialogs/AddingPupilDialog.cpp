#include "AddingPupilDialog.h"
#include "ui_AddingPupilDialog.h"

AddingPupilDialog::AddingPupilDialog(QWidget *parent) : QDialog(parent), _ui(new Ui::AddingPupilDialog), _classesService(new ClassesService) {
    _ui->setupUi(this);

    connect(_ui->btnAccept, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAccept()));
    connect(_ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(clickedBtnCancel()));

   _ui->cbxClasses->addItem("Не выбрано");
   QVector<QString> classes = _classesService->getAllClasses();
   for (auto curClass : classes) {
          _ui->cbxClasses->addItem(curClass);
   }
}

QSharedPointer<Pupil> AddingPupilDialog::getData() {
    QSharedPointer<Pupil> pupil = Pupil::Builder()
            .setName(_ui->editName->text())
            .setDateBirth(_ui->editDateBirth->text())
            .setAddress(_ui->editAddress->text())
            .setNameClass(_ui->cbxClasses->currentText())
            .build();
    return pupil;
}

void AddingPupilDialog::clickedBtnAccept() {
    if(isValidDialog()) {
        accept();
    }
}

bool AddingPupilDialog::isValidDialog() {
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
    if (_ui->cbxClasses->currentText() == "Не выбрано") {
        QMessageBox::warning(0, "Ошибка", "Выберите профессию для сотрудника.");
        return false;
    }
    return true;
}

void AddingPupilDialog::clickedBtnCancel() {
    this->close();
}

AddingPupilDialog::~AddingPupilDialog() {
    delete _ui;
}
