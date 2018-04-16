#ifndef ADDING_PUPIL_DIALOG_H
#define ADDING_PUPIL_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSharedPointer>
#include <QScopedPointer>
#include "Data/Entity/Pupil.h"
#include "Data/Service/ClassesService.h"

namespace Ui {
class AddingPupilDialog;
}

class AddingPupilDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddingPupilDialog(QWidget *parent = 0);
    QSharedPointer<Pupil> getData();
    ~AddingPupilDialog();
private:
    Ui::AddingPupilDialog *_ui;
    QScopedPointer<IClassesService> _classesService;
    bool isValidDialog();
private slots:
    void clickedBtnAccept();
    void clickedBtnCancel();
};

#endif
