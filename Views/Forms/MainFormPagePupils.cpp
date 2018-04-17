#include "MainFormPagePupils.h"
#include "ui_MainForm.h"

MainFormPagePupils::MainFormPagePupils(Ui::MainForm* mainForm) : _ui(mainForm), _pupilsService(new PupilsService),
    _modelPupils(new QStandardItemModel), _modelParents(new QStandardItemModel), _classesService(new ClassesService),
    _parentsService(new ParentsService) {

    QStringList headerPupils = { "ФИО", "Дата рождения", "Адрес", "Класс" };
    QStringList headerParents = { "ФИО", "Дата рождения", "Адрес" };

    _modelPupils->setHorizontalHeaderLabels(headerPupils);
    _modelParents->setHorizontalHeaderLabels(headerParents);

    _ui->tablePupils->setModel(_modelPupils.data());
    _ui->tablePupils->resizeColumnsToContents();
    _ui->tablePupils->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    _ui->tableParents->setModel(_modelParents.data());
    _ui->tableParents->resizeColumnsToContents();
    _ui->tableParents->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    reloadClassesInCheckBox();
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

void MainFormPagePupils::reloadParentsInTable(QVector<QSharedPointer<Parent>> parents) {
    _modelParents->removeRows(0, _modelParents->rowCount());
    for (long i = 0; i < parents.size(); i++) {
        _modelParents->setItem(i, 0, new QStandardItem(parents.at(i)->getName()));
        _modelParents->setItem(i, 1, new QStandardItem(parents.at(i)->getDateBirth()));
        _modelParents->setItem(i, 2, new QStandardItem(parents.at(i)->getAddress()));
    }
}

void MainFormPagePupils::reloadClassesInCheckBox() {
    QVector<QString> classes = _classesService->getAllClasses();
    _ui->cbxPupilsClasses->clear();
    _ui->cbxDeletingClass->clear();
    _ui->cbxPupilsClasses->addItem("Не выбрано");
    _ui->cbxDeletingClass->addItem("Не выбрано");
    for (auto curClass : classes) {
          _ui->cbxPupilsClasses->addItem(curClass);
          _ui->cbxDeletingClass->addItem(curClass);
    }
}

void MainFormPagePupils::reloadPupilsAndParents() {
    reloadPupilsInTable(_pupilsService->getAllPupils());
    QMessageBox::information(0, "Успешная операция", "Ученики и их родители успешно обновлены.");
}

void MainFormPagePupils::addPupil() {
    AddingPupilDialog addingPupilDialog;
    if (addingPupilDialog.exec() == QDialog::Accepted) {
        QSharedPointer<Pupil> pupil = addingPupilDialog.getData();
        if (_pupilsService->addPupil(pupil)) {
            QMessageBox::information(0, "Успешная операция", "Ученик [" + pupil->getName() + "] был успешно добавлен.");
            reloadPupilsInTable(_pupilsService->getAllPupils());
        } else {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо уже существует такой ученик с таким именем, добавление нового невозможно.");
        }
    }
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
    QString classPupils = _ui->cbxPupilsClasses->currentText();
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
    AddingParentDialog addingParentDialog;
    if (addingParentDialog.exec() == QDialog::Accepted) {
        QSharedPointer<Parent> parent = addingParentDialog.getData();
        if (_parentsService->addParent(parent)) {
            QMessageBox::information(0, "Успешная операция", "Родитель [" + parent->getName() + "] был успешно добавлен.");
            reloadParentsInTable(_parentsService->getParentsByChild(""));
        } else {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо уже существует такой родитель с таким именем, добавление нового невозможно.");
        }
    }
}

void MainFormPagePupils::removeParent() {
    QModelIndexList selectedRows = getSelectedRows(_ui->tableParents);
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(0, "Ошибка удаления", "Не выбран(ы) родитель(и) в таблице.");
        return;
    }
    QMessageBox::StandardButton confirm = QMessageBox::question(0, "Подтверждение", "Действительно хотите удалить родителя(ей)?", QMessageBox::Yes|QMessageBox::No);
    if(confirm == QMessageBox::Yes) {
        for (auto row : selectedRows) {
            QString name = row.data().toString();
            if(_parentsService->removeParentByName(name)) {
                QMessageBox::information(0, "Успешная операция", "Родитель [" + name + "] успешно удален.");
            } else {
                QMessageBox::warning(0, "Неудачная операция", "Такого родителя не существует.");
            }
        }
        reloadParentsInTable(_parentsService->getParentsByChild(""));
    }
}

void MainFormPagePupils::showParentsSelectedPupil(QModelIndex index) {
    QModelIndex selectedPupil = index.sibling(index.row(), 0);
    QString namePupil = selectedPupil.data().toString();
    reloadParentsInTable(_parentsService->getParentsByChild(namePupil));
}

void MainFormPagePupils::addClass() {
    QString newClass = _ui->editAddingNewClass->text();
    if (newClass.isEmpty()) {
        QMessageBox::critical(0, "Ошибка добавления", "Не введено название класса, добавление невозможно.");
        return;
    }
    if(_classesService->addClass(newClass)){
        QMessageBox::information(0, "Успешная операция", "Класс [" + newClass + "] успешно добавлен.");
        reloadClassesInCheckBox();
        _ui->editAddingNewClass->setText("");
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Класс [" + newClass + "] не была добавлен. Возможно такой класс уже существует.");
    }
}

void MainFormPagePupils::removeClass() {
    QString oldClass = _ui->cbxDeletingClass->currentText();
    if (oldClass == "Не выбрано") {
        QMessageBox::critical(0, "Ошибка удаления", "Не выбрано название профессии, удаление невозможно.");
        return;
    }
    if(_classesService->removeClassByName(oldClass)){
        QMessageBox::information(0, "Успешная операция", "Класс [" + oldClass + "] успешно удален.");
        reloadClassesInCheckBox();
        reloadPupilsInTable(_pupilsService->getAllPupils());
    } else {
        QMessageBox::warning(0, "Неудачная операция", "Класс [" + oldClass + "] не была удален.");
    }
}
