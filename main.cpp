#include <QApplication>
#include "Views/Forms/MainForm.h"
#include "Utils/DataBase.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    DataBase* database = DataBase::getInstance();
    MainForm mainForm;
    mainForm.show();
    return a.exec();
}
