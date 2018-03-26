#ifndef MAINFORMSETTINGS_H
#define MAINFORMSETTINGS_H

#include <memory>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include "Data/Service/IAdministratorsService.h"
#include "Data/Service/AdministratorsService.h"

namespace Ui {
class MainForm;
}

class MainFormPageSettings {
public:
    MainFormPageSettings(Ui::MainForm* mainForm);
    void addAdministrator();
    void changePasswordAdministrator();
    void removeAdministrator();
    ~MainFormPageSettings() {}
private:
    Ui::MainForm* ui;
    std::unique_ptr<IAdministratorsService> administratorsService;
    std::unique_ptr<QStandardItemModel> modelAdministrators;
    void reloadInformationInTable();
    void removeSelectedRows(QModelIndexList selectedRows);
    QModelIndexList getSelectedRows();
};

#endif
