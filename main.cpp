#include <QApplication>
#include "Views/Forms/LoginForm.h"
#include "Utils/DataBase.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DataBase* database = DataBase::getInstance();
    database->connect();
    LoginForm loginForm;
    loginForm.show();
    return app.exec();
}
