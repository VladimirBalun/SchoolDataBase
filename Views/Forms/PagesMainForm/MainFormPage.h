#ifndef MAINFORMPAGE_H
#define MAINFORMPAGE_H

#include <QVector>
#include <QTableView>
#include <QCheckBox>
#include <QMessageBox>
#include <QInputDialog>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QStandardItem>
#include <QStandardItemModel>

class MainFormPage {
protected:
    QModelIndexList getSelectedRows(QTableView* table);
};

#endif
