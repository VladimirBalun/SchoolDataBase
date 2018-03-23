#include "Views/Forms/LoginForm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm loginForm;
    loginForm.show();
    return a.exec();
}
