#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm) {
    ui->setupUi(this);
    mainFormPageSettings = std::make_unique<MainFormPageSettings>(ui);

    connect(ui->btnAddAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddAdmin()));
    connect(ui->btnChangeAdminPassword, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChangeAdminPassword()));
    connect(ui->btnRemoveAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveAdmin()));
}

void MainForm::clickedBtnAddAdmin() {
    mainFormPageSettings->addAdministrator();
}

void MainForm::clickedBtnChangeAdminPassword() {
    mainFormPageSettings->changePasswordAdministrator();
}

void MainForm::clickedBtnRemoveAdmin() {
    mainFormPageSettings->removeAdministrator();
}

MainForm::~MainForm() {
    delete ui;
}

