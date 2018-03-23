#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QMainWindow>
#include <QMessageBox>
#include "MainForm.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();
private:
    Ui::LoginForm *ui;
    bool isValidForm();
private slots:
    void clickedBtnLogin();
    void clickedCbxShowPassword();
};

#endif
