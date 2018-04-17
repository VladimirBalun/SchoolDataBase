#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget* parent) : QMainWindow(parent), _ui(new Ui::MainForm) {
    _ui->setupUi(this);

    _mainFormPageEmployees = std::make_unique<MainFormPageEmployees>(_ui);
    _mainFormPagePupils = std::make_unique<MainFormPagePupils>(_ui);
    _mainFormPageSettings = std::make_unique<MainFormPageSettings>(_ui);

    connect(_ui->btnReloadEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnReloadEmployees()));
    connect(_ui->btnAddEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddEmploye()));
    connect(_ui->btnRemoveEmploye, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveEmploye()));
    connect(_ui->btnSelectEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSelectEmployees()));
    connect(_ui->btnSearchEmployees, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSearchEmployees()));
    connect(_ui->btnAddProfession, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddProfession()));
    connect(_ui->btnRemoveProfession, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveProfession()));

    connect(_ui->btnAddPupil, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddPupil()));
    connect(_ui->btnRemovePupil, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemovePupil()));
    connect(_ui->btnSelectPupils, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSelectPupils()));
    connect(_ui->btnSearchPupils, SIGNAL(clicked(bool)), this, SLOT(clickedBtnSearchPupils()));
    connect(_ui->btnReloadPupilsAndTeachers, SIGNAL(clicked(bool)), this, SLOT(clickedBtnReloadPupils()));
    connect(_ui->btnAddParent, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddParent()));
    connect(_ui->btnRemoveParent, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveParent()));
    connect(_ui->tablePupils, SIGNAL(pressed(QModelIndex)), this, SLOT(selectedPupil(QModelIndex)));
    connect(_ui->btnAddClass, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddClass()));
    connect(_ui->btnRemoveClass, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRemoveClass()));

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

void MainForm::clickedBtnSelectEmployees() {
    _mainFormPageEmployees->selectEmployees();
}

void MainForm::clickedBtnSearchEmployees() {
    _mainFormPageEmployees->searchEmployees();
}

void MainForm::clickedBtnAddProfession() {
    _mainFormPageEmployees->addProfession();
}

void MainForm::clickedBtnRemoveProfession() {
    _mainFormPageEmployees->removeProfession();
}

// Page pupils and employees
void MainForm::clickedBtnAddPupil() {
     _mainFormPagePupils->addPupil();
}

void MainForm::clickedBtnRemovePupil() {
    _mainFormPagePupils->removePupil();
}

void MainForm::clickedBtnSelectPupils() {
    _mainFormPagePupils->selectPupils();
}

void MainForm::clickedBtnSearchPupils() {
    _mainFormPagePupils->searchPupils();
}

void MainForm::clickedBtnReloadPupils() {
    _mainFormPagePupils->reloadPupilsAndParents();
}

void MainForm::clickedBtnAddParent() {
    _mainFormPagePupils->addParent();
}

void MainForm::clickedBtnRemoveParent() {
    _mainFormPagePupils->removeParent();
}

void MainForm::selectedPupil(QModelIndex index) {
    _mainFormPagePupils->showParentsSelectedPupil(index);
}

void MainForm::clickedBtnAddClass() {
    _mainFormPagePupils->addClass();
}

void MainForm::clickedBtnRemoveClass() {
    _mainFormPagePupils->removeClass();
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


