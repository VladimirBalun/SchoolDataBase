#ifndef ADD_STAFF_DIALOG_H
#define ADD_STAFF_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <memory>
#include "Data/Entity/Employe.h"

namespace Ui {
class AddingEmployeDialog;
}

class AddingEmployeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddingEmployeDialog(QWidget *parent = 0);
    Employe* getData();
    ~AddingEmployeDialog();
private:
    Ui::AddingEmployeDialog *ui;
    bool isValidDialog();
private slots:
    void clickedBtnAccept();
    void clickedBtnCancel();
};

#endif
