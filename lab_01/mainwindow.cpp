#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->xLineEdit->setStyleSheet("border: 1px solid black");
    ui->yLineEdit->setStyleSheet("border: 1px solid black");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddPushButton_clicked()
{
    bool e1 = true, e2 = true;
    auto *x_line = ui->xLineEdit, *y_line = ui->yLineEdit;
    x_line->setStyleSheet("border: 1px solid black");
    y_line->setStyleSheet("border: 1px solid black");
    double xd = x_line->text().todouble(&e1), yd = y_line->text().todouble(&e2);
    if(!e1 || !e2)
    {
        if(!e1)
            x_line->setStyleSheet("border: 1px solid red");
        if(!e2)
            y_line->setStyleSheet("border: 1px solid red");
        QErrorMessage error_msg;
        error_msg.showMessage("Значения координат должны быть вещественными числами.");
        error_msg.setWindowTitle("Ошибка ввода");
        error_msg.exec();
    }
    else
    {
        points.append(Point(xd, yd));

        auto *table = ui->PointTableWidget;
        int i = table->rowCount();
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(xd)));
        table->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(yd)));

        QPushButton *btn = new QPushButton(this);
        btn->setText("Удалить");
        table->setCellWidget(i, 2, btn);
        connect(btn, &QPushButton::clicked, this, &MainWindow::DelButton);
    }
}


void MainWindow::on_DrawPushButton_clicked()
{

    QVector<Point> points_copy = points;
    for(int i = 0; i < points_copy.size() - 1; i++)
    {
        for(int j = i + 1; j < points_copy.size(); j++)
        {
            if(points_copy[i] == points_copy[j])
                points_copy.remove(j--);
        }
    }
    try {
        Triangle res_trg = search_triangle(points_copy);
//        ui->statusbar->showMessage(QString("Answer: (%1, %2), (%3, %4)").arg(res_trg.get_min_h().getBegin().get_x()).arg(res_trg.get_min_h().getBegin().get_y()).arg(res_trg.get_min_h().getAnEnd().get_x()).arg(res_trg.get_min_h().getAnEnd().get_y()));
        QString text_res = "Треугольник построенный на вершинах %1 (%2, %3), %4(%5, %6), %7(%8, %9) имеет"
                           " наименьшую вершину длинной %10. Её координаты (%11, %12), (%13, %14)";
        text_res = text_res.arg(points.indexOf(res_trg.get_point(0))).arg(res_trg.get_point(0).get_x()).arg(res_trg.get_point(0).get_y());
        text_res = text_res.arg(points.indexOf(res_trg.get_point(1))).arg(res_trg.get_point(1).get_x()).arg(res_trg.get_point(1).get_y());
        text_res = text_res.arg(points.indexOf(res_trg.get_point(2))).arg(res_trg.get_point(2).get_x()).arg(res_trg.get_point(2).get_y());
        text_res = text_res.arg(res_trg.get_min_h().getLen());
        text_res = text_res.arg(res_trg.get_min_h().getBegin().get_x()).arg(res_trg.get_min_h().getBegin().get_y());
        text_res = text_res.arg(res_trg.get_min_h().getAnEnd().get_x()).arg(res_trg.get_min_h().getAnEnd().get_y());
        ui->ResLabel->setText(text_res);
    }
    catch (FigureError &e)
    {
        QErrorMessage error_msg;
        error_msg.showMessage(e.get_message());
        error_msg.setWindowTitle("Ошибка данных");
        error_msg.exec();
    }
}

void MainWindow::DelButton()
{
    auto *table = ui->PointTableWidget;
    int i = 0;
    for(; i < table->rowCount(); i++)
        if(sender() == table->cellWidget(i, 2))
            break;
    auto *btn = table->cellWidget(i, 2);
    points.remove(i);
    table->removeRow(i);
    delete btn;
}



void MainWindow::on_PointTableWidget_itemChanged(QTableWidgetItem *item)
{
    bool e = true;
    double a = item->text().todouble(&e);
    int row = item->row(), column = item->column();
    Point &p = points[row];
    if(!e)
    {
        double val = 0;
        if(column == 0)
            val = p.get_x();
        if(column == 1)
            val = p.get_y();
        item->setText(QString("%1").arg(val));
        QErrorMessage error_msg;
        error_msg.showMessage("Значения координат должны быть вещественными числами.");
        error_msg.setWindowTitle("Ошибка ввода");
        error_msg.exec();
    }
    else
    {

        if(column == 0)
            p.set_x(a);
        if(column == 1)
            p.set_y(a);
    }
}

