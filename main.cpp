#include <QApplication>
#include "Views/Forms/LoginForm.h"
#include "Utils/DataBase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase* dataBase = DataBase::getInstance();
    dataBase->connect();
    LoginForm loginForm;
    loginForm.show();
    return a.exec();
}
