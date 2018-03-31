#include "LoginForm.h"
#include "ui_LogInForm.h"

LoginForm::LoginForm(QWidget* parent) : QMainWindow(parent), _ui(new Ui::LoginForm), _administratorsService(new AdministratorsService) {
    _ui->setupUi(this);
    connect(_ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnLogin()));
    connect(_ui->cbxShowPassword, SIGNAL(clicked(bool)), this, SLOT(clickedCbxShowPassword()));
}

void LoginForm::clickedBtnLogin() {
    QString login = _ui->editLogin->text();
    QString password = _ui->editPassword->text();
    if(isValidForm()) {
        if(_administratorsService->isExistAdministrator(login, password)) {
            MainForm* mainForm = new MainForm;
            mainForm->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Ошибка авторизация", "Вы ввели не правильный логин или пароль.");
        }
    }
}

bool LoginForm::isValidForm() {
    if(_ui->editLogin->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введене логин, авторизация невозможна.");
        return false;
    }
    if(_ui->editPassword->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введене пароль, авторизация невозможна.");
        return false;
    }
    return true;
}


void LoginForm::clickedCbxShowPassword() {
    if(_ui->cbxShowPassword->isChecked()) {
        _ui->editPassword->setEchoMode(QLineEdit::Normal);
    } else {
        _ui->editPassword->setEchoMode(QLineEdit::Password);
    }
}

LoginForm::~LoginForm() {
    delete _ui;
}
