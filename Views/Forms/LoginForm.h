#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QMessageBox>
#include "MainForm.h"
#include "Data/Service/IAdministratorsService.h"
#include "Data/Service/AdministratorsService.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QMainWindow {
    Q_OBJECT
public:
    explicit LoginForm(QWidget* parent = 0);
    ~LoginForm();
private slots:
    void clickedBtnLogin();
    void clickedCbxShowPassword();
private:
    Ui::LoginForm* _ui;
    QScopedPointer<IAdministratorsService> _administratorsService;
    bool isValidForm();
};

#endif
