#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("КГ ЛР№3");
    w.showMaximized();
    w.show();
    return a.exec();
}
