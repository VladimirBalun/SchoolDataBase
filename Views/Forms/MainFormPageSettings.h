#ifndef MAINFORMSETTINGS_H
#define MAINFORMSETTINGS_H

#include <QScopedPointer>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
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
private:
    void reloadAdministratorsInTable();
    void reloadAdministratorsInCheckBox();
    void removeSelectedRows(QModelIndexList selectedRows);
    QModelIndexList getSelectedRows();
private:
    Ui::MainForm* _ui;
    QScopedPointer<IAdministratorsService> _administratorsService;
    QScopedPointer<QStandardItemModel> _modelAdministrators;
};

#endif
