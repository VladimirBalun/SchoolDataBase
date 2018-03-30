#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm) {
    ui->setupUi(this);

    mainFormPageEmployees = std::make_unique<MainFormPageEmployees>(ui);
    mainFormPageSettings = std::make_unique<MainFormPageSettings>(ui);

    connect(ui->btnReloadEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnReloadEmployees()));
    connect(ui->btnAddEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddEmploye()));
    connect(ui->btnRemoveEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveAdmin()));
    connect(ui->btnSortEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSortEmployees()));
    connect(ui->btnSelectEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSelectEmployees()));
    connect(ui->btnSearchEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSearchEmployees()));

    connect(ui->btnAddAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddAdmin()));
    connect(ui->btnChangeAdminPassword, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChangeAdminPassword()));
    connect(ui->btnRemoveAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveAdmin()));
}

//Page employees
void MainForm::clickedBtnReloadEmployees(){
    mainFormPageEmployees->reloadEmployees();
}

void MainForm::clickedBtnAddEmploye() {
    mainFormPageEmployees->addEmploye();
}

void MainForm::clickedBtnRemoveEmploye() {
    mainFormPageEmployees->removeEmploye();
}

void MainForm::clickedBtnSortEmployees() {
    mainFormPageEmployees->sortEmployees();
}

void MainForm::clickedBtnSelectEmployees() {
    mainFormPageEmployees->selectEmployees();
}

void MainForm::clickedBtnSearchEmployees() {
    mainFormPageEmployees->searchEmployees();
}

//Page settings
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


