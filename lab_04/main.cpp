#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setWindowTitle("КГ ЛР№4");
    w.set_spectr_center();
    w.show();
    return a.exec();
}
