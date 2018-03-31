#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget* parent) : QMainWindow(parent), _ui(new Ui::MainForm) {
    _ui->setupUi(this);

    _mainFormPageEmployees = std::make_unique<MainFormPageEmployees>(_ui);
    _mainFormPageSettings = std::make_unique<MainFormPageSettings>(_ui);

    connect(_ui->btnReloadEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnReloadEmployees()));
    connect(_ui->btnAddEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddEmploye()));
    connect(_ui->btnRemoveEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveAdmin()));
    connect(_ui->btnSortEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSortEmployees()));
    connect(_ui->btnSelectEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSelectEmployees()));
    connect(_ui->btnSearchEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSearchEmployees()));

    connect(_ui->btnAddAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddAdmin()));
    connect(_ui->btnChangeAdminPassword, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChangeAdminPassword()));
    connect(_ui->btnRemoveAdmin, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveAdmin()));
}

//Page employees
void MainForm::clickedBtnReloadEmployees(){
    _mainFormPageEmployees->reloadEmployees();
}

void MainForm::clickedBtnAddEmploye() {
    _mainFormPageEmployees->addEmploye();
}

void MainForm::clickedBtnRemoveEmploye() {
    _mainFormPageEmployees->removeEmploye();
}

void MainForm::clickedBtnSortEmployees() {
    _mainFormPageEmployees->sortEmployees();
}

void MainForm::clickedBtnSelectEmployees() {
    _mainFormPageEmployees->selectEmployees();
}

void MainForm::clickedBtnSearchEmployees() {
    _mainFormPageEmployees->searchEmployees();
}

//Page settings
void MainForm::clickedBtnAddAdmin() {
    _mainFormPageSettings->addAdministrator();
}

void MainForm::clickedBtnChangeAdminPassword() {
    _mainFormPageSettings->changePasswordAdministrator();
}

void MainForm::clickedBtnRemoveAdmin() {
    _mainFormPageSettings->removeAdministrator();
}

MainForm::~MainForm() {
    delete _ui;
}


