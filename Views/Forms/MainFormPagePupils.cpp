#include "MainFormPagePupils.h"
#include "ui_MainForm.h"

MainFormPagePupils::MainFormPagePupils(Ui::MainForm* mainForm) : _ui(mainForm), _pupilsService(new PupilsService),
    _modelPupils(new QStandardItemModel), _modelParents(new QStandardItemModel)  {

    QStringList headers = {"ФИО", "Дата рождения", "Адрес", "Класс"};
    _modelPupils->setHorizontalHeaderLabels(headers);
    _ui->tablePupils->setModel(_modelPupils.data());
    _ui->tablePupils->resizeColumnsToContents();
    _ui->tablePupils->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadPupilsInTable(_pupilsService->getAllPupils());
}

void MainFormPagePupils::reloadPupilsInTable(QVector<QSharedPointer<Pupil>> pupils) {
    _modelPupils->removeRows(0, _modelPupils->rowCount());
    for (long i = 0; i < pupils.size(); i++) {
        _modelPupils->setItem(i, 0, new QStandardItem(pupils.at(i)->getName()));
        _modelPupils->setItem(i, 1, new QStandardItem(pupils.at(i)->getDateBirth()));
        _modelPupils->setItem(i, 2, new QStandardItem(pupils.at(i)->getAddress()));
        _modelPupils->setItem(i, 3, new QStandardItem(pupils.at(i)->getNameClass()));
    }
}

void MainFormPagePupils::reloadPupilsAndParents() {
    reloadPupilsInTable(_pupilsService->getAllPupils());
    QMessageBox::information(0, "Успешная операция", "Сотрудники и их родители успешно обновлены.");
}

void MainFormPagePupils::addPupil() {

}

void MainFormPagePupils::removePupil() {
    QModelIndexList selectedRows = getSelectedRows(_ui->tablePupils);
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) ученик(и) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить ученика(ов)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        for (auto row : selectedRows) {
            QString name = row.data().toString();
            if(_pupilsService->removePupilByName(name)) {
                QMessageBox::information(0, "Успешная операция", "Ученик [" + name + "] успешно удален.");
            } else {
                QMessageBox::warning(0, "Неудачная операция", "Такого ученика не существует.");
            }
        }
        reloadPupilsInTable(_pupilsService->getAllPupils());
    }
}

void MainFormPagePupils::selectPupils() {
    QString classPupils = _ui->cbxProfessions->currentText();
    if (classPupils == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка выборки", "Не выбран класс, выборка ученков невозможна.");
        return;
    }
     reloadPupilsInTable(_pupilsService->getPupilsByClass(classPupils));
}

void MainFormPagePupils::searchPupils() {
    QString name = _ui->editSearchingPupils->text();
    if (name.isEmpty()) {
        QMessageBox::critical(0, "Ошибка поиска", "Не введено данных для поиска.");
        return;
    }
    reloadPupilsInTable(_pupilsService->getPupilsByName(name));
}

void MainFormPagePupils::addParent() {

}

void MainFormPagePupils::removeParent() {
    QModelIndexList selectedRows = getSelectedRows(_ui->tableParents);
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) родитель(и) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить родителя(ей)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        reloadPupilsInTable(_pupilsService->getAllPupils());
    }
}


