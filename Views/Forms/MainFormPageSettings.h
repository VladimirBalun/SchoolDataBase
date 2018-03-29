#ifndef MAINFORMSETTINGS_H
#define MAINFORMSETTINGS_H

#include <memory>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include "Data/Service/AdministratorsService.h"

namespace Ui {
class MainForm;
}

class MainFormPageSettings {
    Ui::MainForm* ui;
    std::unique_ptr<IAdministratorsService> administratorsService;
    std::unique_ptr<QStandardItemModel> modelAdministrators;
    void reloadAdministratorsInTable();
    void reloadAdministratorsInCheckBox();
    void removeSelectedRows(QModelIndexList selectedRows);
    QModelIndexList getSelectedRows();
public:
    MainFormPageSettings(Ui::MainForm* mainForm);
    void addAdministrator();
    void changePasswordAdministrator();
    void removeAdministrator();
};

#endif
