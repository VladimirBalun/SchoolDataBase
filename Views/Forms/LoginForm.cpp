#include "LoginForm.h"
#include "ui_login_form.h"

LoginForm::LoginForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    connect(ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnLogin()));
    connect(ui->cbxShowPassword, SIGNAL(clicked(bool)), this, SLOT(clickedCbxShowPassword()));
}

void LoginForm::clickedBtnLogin()
{
    QString login = ui->editLogin->text();
    QString password = ui->editPassword->text();
    if(isValidForm())
    {
        if(login == "admin" && password == "admin")
        {
            MainForm* mainForm = new MainForm;
            mainForm->show();
            this->close();
        }
        else
        {
            QMessageBox::warning(this, "Ошибка авторизация", "Вы ввели не правильный логин или пароль.");
        }
    }
}

bool LoginForm::isValidForm()
{
    if(ui->editLogin->text().isEmpty())
    {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введене логин, авторизация невозможна.");
        return false;
    }
    if(ui->editPassword->text().isEmpty())
    {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введене пароль, авторизация невозможна.");
        return false;
    }
    return true;
}


void LoginForm::clickedCbxShowPassword()
{
    if(ui->cbxShowPassword->isChecked())
    {
        ui->editPassword->setEchoMode(QLineEdit::Normal);

    }
    else
    {
        ui->editPassword->setEchoMode(QLineEdit::Password);
    }
}

LoginForm::~LoginForm()
{
    delete ui;
}
