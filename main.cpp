#include <QApplication>
#include "Views/Forms/MainForm.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainForm mainForm;
    mainForm.show();
    return a.exec();
}
