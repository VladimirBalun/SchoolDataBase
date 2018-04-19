#include "MainFormPageTeachers.h"
#include "ui_MainForm.h"

MainFormPageTeachers::MainFormPageTeachers(Ui::MainForm *mainForm) : _ui(mainForm), _teachersService(new TeachersService),
    _modelTeachers(new QStandardItemModel){

    QStringList headerTeachers = { "ФИО", "Класс", "Предметы" };
    _modelTeachers->setHorizontalHeaderLabels(headerTeachers);

    _ui->tableTeachers->setModel(_modelTeachers.data());
    _ui->tableTeachers->resizeColumnsToContents();
    _ui->tableTeachers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadTeachersInTable();
    reloadPredmetsInCheckBox();
}

void MainFormPageTeachers::reloadTeachersInTable() {
    _modelTeachers->removeRows(0, _modelTeachers->rowCount());
    QVector<QSharedPointer<Teacher>> teachers = _teachersService->getAllTeachers();
    for (long i = 0; i < teachers.size(); i++) {
        _modelTeachers->setItem(i, 0, new QStandardItem(teachers.at(i)->getName()));
        _modelTeachers->setItem(i, 1, new QStandardItem(teachers.at(i)->getNameClass()));

        QVector<QString> predmets = teachers.at(i)->getPredmets();
        QString predmetsTeacher;
        for(QString predmet : predmets) {
            predmetsTeacher.append(predmet + " ");
        }

        _modelTeachers->setItem(i, 2, new QStandardItem(predmetsTeacher));
    }
}

void MainFormPageTeachers::reloadPredmetsInCheckBox() {
    _ui->cbxAddingPredmetForTeacher->addItem("Не выбрано");
    _ui->cbxDeletingPredmet->addItem("Не выбрано");
    _ui->cbxPredmets->addItem("Не выбрано");
}

void MainFormPageTeachers::removeTeacherPredmet() {
    QString selectedTeacher = _ui->cbxTeachers->currentText();
    QString selectedPredmet = _ui->cbxPredmets->currentText();
    if (selectedTeacher == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка ", "Не выбран учитель для удаления у него предмета.");
        return;
    }
    if (selectedPredmet == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка ", "Не выбран предмет для удаления у учителя.");
        return;
    }
    if(_teachersService->removePredmetTeacherByName(selectedTeacher, selectedPredmet)){
        QMessageBox::information(0,"Успешная операция", "Предмет у учителя успешно удален.");
        reloadPredmetsInCheckBox();
    } else {
        QMessageBox::warning(0, "Ошибка ", "Не получилось удалить предмет у учителя.");
    }
}

void MainFormPageTeachers::addPredmetForTeacher() {
    QString selectedTeacher = _ui->cbxTeachersForAddingPredmer->currentText();
    QString predmetForTeacher = _ui->cbxAddingPredmetForTeacher->currentText();
    if (selectedTeacher == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка ", "Не выбран учитель для добавления предмета.");
        return;
    }
    if (predmetForTeacher == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка ", "Не выбран предмет для учителя.");
        return;
    }
    if(_teachersService->addPredmetForTeacher(selectedTeacher, predmetForTeacher)){
        QMessageBox::information(0,"Успешная операция", "Предмет для учителя успешно добавлен.");
        reloadPredmetsInCheckBox();
    } else {
        QMessageBox::warning(0, "Ошибка ", "Не получилось добавить предмет для учителя.");
    }
}

void MainFormPageTeachers::addPredmet() {
    QString predmet = _ui->editAddingPredmet->text();
    if(predmet.isEmpty()){
        QMessageBox::critical(0, "Ошибка ", "Не введено название предмета");
        return;
    }
}

void MainFormPageTeachers::removePredmet() {
    QString predmet = _ui->cbxDeletingPredmet->currentText();
    if(predmet == "Не выбрано"){
        QMessageBox::critical(0, "Ошибка ", "Не выбран предмет для удаления");
        return;
    }
}
