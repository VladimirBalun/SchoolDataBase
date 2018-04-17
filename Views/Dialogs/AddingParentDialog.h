#ifndef ADD_PARENT_DIALOG_H
#define ADD_PARENT_DIALOG_H

#include <QVector>
#include <QMessageBox>
#include <QScopedPointer>
#include <QSharedPointer>
#include "Data/Entity/Parent.h"
#include "Data/Service/PupilsService.h"

namespace Ui {
class AddingParentDialog;
}

class AddingParentDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddingParentDialog(QWidget *parent = 0);
    QSharedPointer<Parent> getData()   ;
    ~AddingParentDialog();
private:
    Ui::AddingParentDialog *_ui;
    QScopedPointer<IPupilsService> _pupilsService;
    bool isValidDialog();
private slots:
    void clickedBtnAccept();
    void clickedBtnCancel();
};

#endif
