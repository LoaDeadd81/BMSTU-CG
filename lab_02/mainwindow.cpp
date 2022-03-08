#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap);
    set_default_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ParamButton_clicked()
{
    if(!ui->ResView->scene())
    {
        create_scene();
    }

}


void MainWindow::on_MoveButton_clicked()
{
    //todo добавить проверку ввода
    double dx = ui->dxLineEdit->text().toDouble();
    double dy = ui->dyLineEdit->text().toDouble();
    //todo добавить сохранение действия
    figure.move(dx, dy);
    figure.draw(ui->ResView->scene(), main_pen);

}


void MainWindow::on_ScaleButton_clicked()
{
    //todo добавить проверку ввода
    Point center = this->get_transform_center();
    double kx = ui->kxLineEdit->text().toDouble();
    double ky = ui->kyLineEdit->text().toDouble();
    //todo добавить сохранение действия
    figure.scale(center, kx, ky);
    figure.draw(ui->ResView->scene(), main_pen);
}


void MainWindow::on_RotateButton_clicked()
{
    //todo добавить проверку ввода
    Point center = this->get_transform_center();
    double degree = ui->DegreeLineEdit->text().toDouble();
    //todo добавить сохранение действия
    figure.rotate(center, degree);
    figure.draw(ui->ResView->scene(), main_pen);
}


void MainWindow::on_CancelButton_clicked()
{

}

Point MainWindow::get_transform_center()
{
    //todo проверка ввода
    double x = ui->xLineEdit->text().toDouble();
    double y = ui->yLineEdit->text().toDouble();
    return Point(x, y);
}

void MainWindow::set_default_data()
{
    ui->RectWidthLineEdit->setText("100");
    ui->RectHeightLineEdit->setText("60");
    ui->ElipsParam->setText("20");
}

void MainWindow::create_scene()
{
    QRect rect = ui->ResView->geometry();
    auto *scene = new QGraphicsScene(0, 0, rect.width(), rect.height(), this);
    ui->ResView->setScene(scene);
}
