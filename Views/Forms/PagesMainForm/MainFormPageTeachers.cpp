#include "MainFormPageTeachers.h"
#include "ui_MainForm.h"

MainFormPageTeachers::MainFormPageTeachers(Ui::MainForm *mainForm) : _ui(mainForm), _teachersService(new TeachersService),
    _predmetsService(new PredmetsService), _modelTeachers(new QStandardItemModel){

    QStringList headerTeachers = { "ФИО", "Класс", "Предметы" };
    _modelTeachers->setHorizontalHeaderLabels(headerTeachers);

    _ui->tableTeachers->setModel(_modelTeachers.data());
    _ui->tableTeachers->resizeColumnsToContents();
    _ui->tableTeachers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadTeachersInTable();
    reloadTeachersInCheckBox();
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

void MainFormPageTeachers::reloadTeachersInCheckBox() {
    _ui->cbxTeachers->clear();
    _ui->cbxTeachersForAddingPredmer->clear();
    _ui->cbxTeachers->addItem("Не выбрано");
    _ui->cbxTeachersForAddingPredmer->addItem("Не выбрано");
     QVector<QSharedPointer<Teacher>> teachers = _teachersService->getAllTeachers();
     for (auto teacher : teachers) {
         _ui->cbxTeachers->addItem(teacher->getName());
         _ui->cbxTeachersForAddingPredmer->addItem(teacher->getName());
     }
}

void MainFormPageTeachers::reloadPredmetsInCheckBox() {
    _ui->cbxAddingPredmetForTeacher->clear();
    _ui->cbxDeletingPredmet->clear();
    _ui->cbxPredmets->clear();
    _ui->cbxAddingPredmetForTeacher->addItem("Не выбрано");
    _ui->cbxDeletingPredmet->addItem("Не выбрано");
    _ui->cbxPredmets->addItem("Не выбрано");
    QVector<QString> predmets = _predmetsService->getAllPredmets();
    for (QString predmet : predmets) {
        _ui->cbxAddingPredmetForTeacher->addItem(predmet);
        _ui->cbxDeletingPredmet->addItem(predmet);
        _ui->cbxPredmets->addItem(predmet);
    }
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
        reloadTeachersInTable();
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
        reloadTeachersInTable();
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
    if(_predmetsService->addPredmet(predmet)) {
        QMessageBox::information(0,"Успешная операция", "Предмет успешно добавлен.");
        reloadPredmetsInCheckBox();
        _ui->editAddingPredmet->clear();
    } else {
        QMessageBox::warning(0, "Ошибка", "Не получилось добавить предмет.");
    }
}

void MainFormPageTeachers::removePredmet() {
    QString predmet = _ui->cbxDeletingPredmet->currentText();
    if(predmet == "Не выбрано"){
        QMessageBox::critical(0, "Ошибка ", "Не выбран предмет для удаления");
        return;
    }
    if(_predmetsService->removePredmetByName(predmet)) {
        QMessageBox::information(0,"Успешная операция", "Предмет успешно удален.");
        reloadPredmetsInCheckBox();
    } else {
        QMessageBox::warning(0, "Ошибка", "Не получилось удалить предмет.");
    }

}
