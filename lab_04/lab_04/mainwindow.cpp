#include "mainwindow.h"
#include "ui_mainwindow.h"

#define WHITE {255, 255, 255}
#define RED {255, 0, 0}
#define ORANGE {255, 102, 0}
#define YELLOW {255, 255, 0}
#define GREEN {0, 255, 0}
#define BLUE {0, 0, 255}
#define PURPLE {128, 0, 128}
#define BLACK {0, 0, 0}

#define ELLIPSE_TYPE 0
#define CIRCLE_TYPE 1

void show_error(QString title, QString message);

double checked_double_read(QLineEdit *line);

int checked_pos_int_read(QLineEdit *line);

double checked_pos_double_read(QLineEdit *line);

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graph.pen = QPen();
    graph.scene = new QGraphicsScene(this);
    graph.scene->setSceneRect(0, 0, ui->ResView->width(), ui->ResView->height());
    ui->ResView->setScene(graph.scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_spectr_center()
{
//    int cx = ui->ResView->size().width(), cy = ui->ResView->size().height()/2;
    ui->xcCircleLE->setText(QString::number(800));
    ui->ycCircleLE->setText(QString::number(500));
}

void MainWindow::on_ButtonBlackLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-черный)");
    graph.pen.setColor(BLACK);
}


void MainWindow::on_ButtonWhiteLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-белый)");
    graph.pen.setColor(WHITE);
}


void MainWindow::on_ButtonYellowLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-жёлтый)");
    graph.pen.setColor(YELLOW);
}


void MainWindow::on_ButtonRedLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-красный)");
    graph.pen.setColor(RED);
}


void MainWindow::on_ButtonOrangeLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-оранжевый)");
    graph.pen.setColor(ORANGE);
}


void MainWindow::on_ButtonPurpleLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-фиолетовый)");
    graph.pen.setColor(PURPLE);
}


void MainWindow::on_ButtonBlueLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-синий)");
    graph.pen.setColor(BLUE);
}


void MainWindow::on_ButtonGreenLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет линии(текущий цвет-зелёный)");
    graph.pen.setColor(GREEN);
}


void MainWindow::on_ButtonBlackBG_clicked()
{
    bg_color = BLACK;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonWhiteBG_clicked()
{
    bg_color = WHITE;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonYellowBG_clicked()
{
    bg_color = YELLOW;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonRedBG_clicked()
{
    bg_color = RED;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonOrangeBG_clicked()
{
    bg_color = ORANGE;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonPurpleBG_clicked()
{
    bg_color = PURPLE;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonBlueBG_clicked()
{
    bg_color = BLUE;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_ButtonGreenBG_clicked()
{
    bg_color = GREEN;
    graph.scene->setBackgroundBrush(bg_color);
}


void MainWindow::on_CleanButton_clicked()
{
    graph.scene->clear();
}


void MainWindow::on_DrawButton_clicked()
{
    try
    {
        int circle_type = ui->CircleType->currentIndex();
        if (circle_type == ELLIPSE_TYPE)
            draw_ellipse();
        else
            draw_circle();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_DrawSpectreButton_clicked()
{
    try
    {
        int circle_type = ui->CircleType->currentIndex();
        if (circle_type == ELLIPSE_TYPE)
            draw_ellipse_specter();
        else
            draw_circle_specter();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_TimeAnalButton_clicked()
{
//    try
//    {
//        int circle_type = ui->CircleType->currentIndex();
//        if (circle_type == ELLIPSE_TYPE)
//            ellipse_time_mes();
//        else
//            circle_time_mes();
//    }
//    catch (Error &e)
//    {
//        show_error("Ошибка", e.get_message());
//    }
}

void MainWindow::draw_ellipse()
{
    algorithm_ellipse alg = get_ellipse_alg();
    Ellipse ellipse = get_ellipse_param();
    alg(ellipse, graph);
}

void MainWindow::draw_circle()
{
    algorithm_circle alg = get_circle_alg();
    Circle circle = get_circle_param();
    alg(circle, graph);
}

void MainWindow::draw_circle_specter()
{
    algorithm_circle alg = get_circle_alg();
    Circle circle = get_circle_param();
    double step = checked_double_read(ui->StepTE);
    int num = checked_pos_int_read(ui->CircleNunTE);
    for (int i = 0; i < num; i++)
    {
        alg(circle, graph);
        scale(circle, step);
    }
}

void MainWindow::draw_ellipse_specter()
{
    algorithm_ellipse alg = get_ellipse_alg();
    Ellipse ellipse = get_ellipse_param();
    double step = checked_double_read(ui->StepTE);
    int num = checked_pos_int_read(ui->CircleNunTE);
    for (int i = 0; i < num; i++)
    {
        alg(ellipse, graph);
        scale(ellipse, step);
    }
}

void MainWindow::circle_time_mes()
{

}

algorithm_ellipse MainWindow::get_ellipse_alg()
{
    if (ui->ParamButton->isChecked())
        return ellipse_param_draw;
    else if (ui->CanonButton->isChecked())
        return ellipse_canon_draw;
    else if (ui->BresButton->isChecked())
        return ellipse_bres_draw;
    else if (ui->MidButton->isChecked())
        return ellipse_mid_point_draw;
    else if (ui->LibButton->isChecked())
        return ellipse_lib_draw;
    else
        throw UIError("Не выбран метод рисования");
}

algorithm_circle MainWindow::get_circle_alg()
{
    if (ui->ParamButton->isChecked())
        return circle_param_draw;
    else if (ui->CanonButton->isChecked())
        return circle_canon_draw;
    else if (ui->BresButton->isChecked())
        return circle_bres_draw;
    else if (ui->MidButton->isChecked())
        return circle_mid_point_draw;
    else if (ui->LibButton->isChecked())
        return circle_lib_draw;
    else
        throw UIError("Не выбран метод рисования");
}


Ellipse MainWindow::get_ellipse_param()
{
    double a = checked_pos_double_read(ui->a_ellipse),
            b = checked_pos_double_read(ui->b_ellipse);
    Point_t center = get_center();
    return {center, a, b};
}

Circle MainWindow::get_circle_param()
{
    double r = checked_pos_double_read(ui->radius);
    Point_t center = get_center();
    return {center, r};
}

Point_t MainWindow::get_center()
{
    double cx = checked_double_read(ui->xcCircleLE),
            cy = checked_double_read(ui->ycCircleLE);
    return {cx, cy};
}

double checked_double_read(QLineEdit *line)
{
    bool e1 = true;
    line->setStyleSheet("");
    double x = line->text().toDouble(&e1);
    if (!e1)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Исправьте поля выделенные красным");
    }
    return x;
}

double checked_pos_double_read(QLineEdit *line)
{
    bool e1 = true;
    line->setStyleSheet("");
    double x = line->text().toDouble(&e1);
    if (!e1)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Исправьте поля выделенные красным");
    }
    if (x <= 0)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Значение в полях выделенных красным должны быть положительными");
    }
    return x;
}

int checked_pos_int_read(QLineEdit *line)
{
    bool e1 = true;
    line->setStyleSheet("");
    int x = line->text().toInt(&e1);
    if (!e1)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Исправьте поля выделенные красным");
    }
    if (x <= 0)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Значение в полях выделенных красным должны быть положительными");
    }
    return x;
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