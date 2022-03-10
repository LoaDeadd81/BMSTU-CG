#include "mainwindow.h"
#include "ui_mainwindow.h"

//todo протестировать
double checked_read(QLineEdit *lineEdit1);

Pair<double> checked_pair_read(QLineEdit *lineEdit1, QLineEdit *lineEdit2);

void show_error(QString title, QString message);

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap);
    set_default_params();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ParamButton_clicked()
{
    try
    {
        if (!ui->ResView->scene())
        {
            create_scene();
        }
        else
        {
            delete ui->ResView->scene();
            create_scene();
        }
        create_figure();
        figure.draw(main_scene, main_pen);
        clean_actions();
    }
    catch (InputError &e)
    {
        show_error("Ошибка ввода", "Исправьте поля выделенные красным. Программа ожидает на вход вещественные числа.");
    }
    catch (FigureError &e)
    {
        show_error("Ошибка данных", e.get_message());
    }
}

void MainWindow::on_SelectCenterButton_clicked()
{
    Point cur_center = figure.get_center();
    ui->xLineEdit->setText(QString::number(cur_center.get_x()));
    ui->yLineEdit->setText(QString::number(cur_center.get_y()));
}

void MainWindow::on_MoveButton_clicked()
{
    try
    {
        Pair<double> val;
        val = checked_pair_read(ui->dxLineEdit, ui->dyLineEdit);
        double dx = val.get_first(), dy = val.get_second();
        Figure figure_copy = figure;
        figure.move(dx, dy);
        figure.draw(ui->ResView->scene(), main_pen);
        push_action({figure_copy, QString("Смещение на (%1, %2)").arg(dx).arg(dy)});
    }
    catch (InputError &e)
    {
        show_error("Ошибка ввода", "Исправьте поля выделенные красным. Программа ожидает на вход вещественные числа.");
    }
}


void MainWindow::on_ScaleButton_clicked()
{
    try
    {
        Pair<double> val;
        val = checked_pair_read(ui->kxLineEdit, ui->kyLineEdit);
        double kx = val.get_first(), ky = val.get_second();
        Point center = this->get_transform_center();
        Figure figure_copy = figure;
        figure.scale(center, kx, ky);
        figure.draw(ui->ResView->scene(), main_pen);
        push_action({figure_copy, QString("Маштабирование в (%1, %2) раза").arg(kx).arg(ky)});
    }
    catch (InputError &e)
    {
        show_error("Ошибка ввода", "Исправьте поля выделенные красным. Программа ожидает на вход вещественные числа.");
    }
}


void MainWindow::on_RotateButton_clicked()
{
    try
    {
        double degree = checked_read(ui->DegreeLineEdit);
        Point center = this->get_transform_center();
        Figure figure_copy = figure;
        figure.rotate(center, degree);
        figure.draw(ui->ResView->scene(), main_pen);
        push_action({figure_copy, QString("Поворот на %1 градусов").arg(degree)});
    }
    catch (InputError &e)
    {
        show_error("Ошибка ввода", "Исправьте поля выделенные красным. Программа ожидает на вход вещественные числа.");
    }
}


void MainWindow::on_CancelButton_clicked()
{
    if (is_empty_action_list())
        return;
    action_type last_action = pop_action();
    figure = last_action.get_first();
    figure.draw(main_scene, main_pen);
}

Point MainWindow::get_transform_center()
{
    Pair<double> dot;
    dot = checked_pair_read(ui->xLineEdit, ui->yLineEdit);
    return {dot.get_first(), dot.get_second()};
}

void MainWindow::set_default_params()
{
    ui->RectWidthLineEdit->setText("100");
    ui->RectHeightLineEdit->setText("60");
    ui->ElipsParam->setText("20");
}

void MainWindow::create_scene()
{
    QRect rect = ui->ResView->geometry();
    main_scene = new QGraphicsScene(0, 0, rect.width(), rect.height(), this);
    ui->ResView->setScene(main_scene);
}

void MainWindow::create_figure()
{
    Pair<double> size;
    size = checked_pair_read(ui->RectWidthLineEdit, ui->RectHeightLineEdit);
    double ellipse_a = checked_read(ui->ElipsParam);
    figure = Figure(size.get_first(), size.get_second(), ellipse_a, main_scene);
}

double checked_read(QLineEdit *lineEdit1)
{
    bool e1 = true;
    lineEdit1->setStyleSheet("");
    double x = lineEdit1->text().toDouble(&e1);
    if (!e1)
    {
        lineEdit1->setStyleSheet("border: 1px solid red");
        throw InputError("");
    }
    return x;
}

Pair<double> checked_pair_read(QLineEdit *lineEdit1, QLineEdit *lineEdit2)
{
    bool e1 = true, e2 = true;
    lineEdit1->setStyleSheet("");
    lineEdit2->setStyleSheet("");
    double x = lineEdit1->text().toDouble(&e1), y = lineEdit2->text().toDouble(&e2);
    if (!e1 || !e2)
    {
        if (!e1)
            lineEdit1->setStyleSheet("border: 1px solid red");
        if (!e2)
            lineEdit2->setStyleSheet("border: 1px solid red");
        throw InputError("");

    }
    return {x, y};
}

void show_error(QString title, QString message)
{
    QErrorMessage error_msg;
    error_msg.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    error_msg.setStyleSheet("QLabel{min-height: 100px; font-size: 100px;}");
    error_msg.showMessage(message);
    error_msg.setWindowTitle(title);
    QFont font;
    font.setPointSize(14);
    error_msg.setFont(font);
    error_msg.exec();
}

bool MainWindow::is_empty_action_list()
{
    return action_vec.empty();
}

void MainWindow::push_action(action_type action)
{
    action_vec.push_back(action);
    ui->DoWidgetList->addItem(action.get_second());
}

action_type MainWindow::pop_action()
{
    action_type tmp = action_vec.back();
    action_vec.erase(action_vec.end());
    delete ui->DoWidgetList->item(ui->DoWidgetList->count() - 1);
    return tmp;
}

void MainWindow::clean_actions()
{
    while (ui->DoWidgetList->count() > 0)
        delete ui->DoWidgetList->item(0);
    action_vec.clear();
}




