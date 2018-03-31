#include <QApplication>
#include "Views/Forms/MainForm.h"
#include "Utils/DataBase.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DataBase* database = DataBase::getInstance();
    database->connect();
    MainForm mainForm;
    mainForm.show();
    return app.exec();
}
