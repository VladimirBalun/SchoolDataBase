#ifndef MAINFORMSETTINGS_H
#define MAINFORMSETTINGS_H

#include "Data/Service/AdministratorsService.h"
#include "MainFormPage.h"

namespace Ui {
class MainForm;
}

class MainFormPageSettings : public MainFormPage {
public:
    MainFormPageSettings(Ui::MainForm* mainForm);
    void addAdministrator();
    void changePasswordAdministrator();
    void removeAdministrator();
private:
    void reloadAdministratorsInTable();
    void reloadAdministratorsInCheckBox();
    void removeSelectedRows(QModelIndexList selectedRows);
private:
    Ui::MainForm* _ui;
    QScopedPointer<IAdministratorsService> _administratorsService;
    QScopedPointer<QStandardItemModel> _modelAdministrators;
};

#endif
