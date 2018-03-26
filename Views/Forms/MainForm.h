#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <memory>
#include <QMainWindow>
#include "MainFormPageSettings.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
protected:
    Ui::MainForm *ui;
private slots:
    void clickedBtnAddAdmin();
    void clickedBtnChangeAdminPassword();
    void clickedBtnRemoveAdmin();
private:
    std::unique_ptr<MainFormPageSettings> mainFormPageSettings;
};

#endif
