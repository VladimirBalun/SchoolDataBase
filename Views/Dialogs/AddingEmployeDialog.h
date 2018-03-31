#ifndef ADD_STAFF_DIALOG_H
#define ADD_STAFF_DIALOG_H

#include <memory>
#include <iostream>
#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QSharedPointer>
#include "Data/Entity/Employe.h"
#include "Data/Service/ProfessionsService.h"

namespace Ui {
class AddingEmployeDialog;
}

class AddingEmployeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddingEmployeDialog(QWidget *parent = 0);
    QSharedPointer<Employe> getData();
    ~AddingEmployeDialog();
private:
    Ui::AddingEmployeDialog *ui;
    std::unique_ptr<IProfessionsService> professionsService;
    bool isValidDialog();
private slots:
    void clickedBtnAddProfession();
    void clickedBtnAccept();
    void clickedBtnCancel();
};

#endif
