#include "MainFormPage.h"

QModelIndexList MainFormPage::getSelectedRows(QTableView* table) {
    QAbstractItemView* view = table;
    QItemSelectionModel* selectedModel = view->selectionModel();
    return selectedModel->selectedRows();
}
