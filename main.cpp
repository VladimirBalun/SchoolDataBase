#include <QApplication>
#include "Views/Forms/LoginForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm loginForm;
    loginForm.show();
    return a.exec();
}
