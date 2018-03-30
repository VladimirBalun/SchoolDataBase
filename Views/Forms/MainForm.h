#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <memory>
#include <QMainWindow>

#include "MainFormPageEmployees.h"
#include "MainFormPageSettings.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
private slots:
    void clickedBtnReloadEmployees();
    void clickedBtnAddEmploye();
    void clickedBtnRemoveEmploye();
    void clickedBtnSortEmployees();
    void clickedBtnSelectEmployees();
    void clickedBtnSearchEmployees();

    void clickedBtnAddAdmin();
    void clickedBtnChangeAdminPassword();
    void clickedBtnRemoveAdmin();
private:
    Ui::MainForm *ui;
    std::unique_ptr<MainFormPageEmployees> mainFormPageEmployees;
    std::unique_ptr<MainFormPageSettings> mainFormPageSettings;
};

#endif
