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

Point_t checked_point_read(QLineEdit *line1, QLineEdit *line2);

double checked_double_read(QLineEdit *line);

void show_error(QString title, QString message);

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


void MainWindow::on_pushButton_clicked()
{
    graph.scene->clear();
}

//draw
void MainWindow::on_pushButton_2_clicked()
{
    try
    {
        algorithm algo = get_algorithm();
        Point_t start = get_start(), end = get_end();
        int steps = 0;
        algo(start, end, graph, steps);
    }
    catch(Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_DrawSpectre_clicked()
{
    try
    {
        algorithm algo = get_algorithm();
        Point_t center = get_spec_center();
        double len = get_spec_len(), degree = get_spec_degree();
        spectre(center, len, degree, graph, algo);
    }
    catch(Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

//step
void MainWindow::on_pushButton_3_clicked()
{
    QLineSeries *series = new QLineSeries(this);

    double maxLen = 100;
    for (int iang = 0; iang <= 90; iang++) {
        double angle = M_PI / 180 * iang;

        double dx = maxLen * cos(angle);
        double dy = maxLen * sin(angle);

        double minDxy = (dx <= dy) ? dx : dy;
        int stairsNum = round(minDxy);
        series->append(iang, stairsNum);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Анализ ступенчатости");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QValueAxis *axisY = new QValueAxis(chart);
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Кол-во ступенек");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis(chart);
    axisX->setLabelFormat("%i");
    axisX->setTitleText("Угол");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    secDialog = new Form(this);
    QGridLayout *layout = new QGridLayout(this);
    QLabel *label = new QLabel(secDialog);
    label->setText("Зависимость количества ступенек от угла наклона отрезка длинной 100");
    label->setAlignment(Qt::AlignTop);
    layout->addWidget(label);
    layout->addWidget(chartView);
    secDialog->setLayout(layout);
    secDialog->resize(1000, 500);
    secDialog->show();
}

//time
void MainWindow::on_pushButton_4_clicked()
{
    QBarSet *set0 = new QBarSet("Алгоритмы");

    algorithm alg_arr[] = {cda, bres_float, bres_int, bres_smooth, wu};

    for(int i = 0; i < 5; i ++)
        *set0 << eff(alg_arr[i]);

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Среднее время построения отрезка длиной 1000, в секундах");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "ЦДА" << "Брезенхем (double)" << "Брезенхем (int)" << "Брезенхем с устр. ступенч." << "Ву";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,0.00015);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    secDialog = new Form(this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(chartView);
    secDialog->setLayout(layout);
    secDialog->resize(1000, 500);
    secDialog->show();
}

algorithm MainWindow::get_algorithm()
{
    if(ui->CDAButton->isChecked())
        return cda;
    else if (ui->BFButton->isChecked())
        return bres_float;
    else if(ui->BIButton->isChecked())
        return bres_int;
    else if(ui->BSButton->isChecked())
        return bres_smooth;
    else if(ui->WUButton->isChecked())
        return wu;
    else if(ui->LibButton->isChecked())
        return lib;
    else
        throw UIError("Не выбран метод рисования");
}

Point_t MainWindow::get_start()
{
    return checked_point_read(ui->Xstart, ui->Ystart);
}

Point_t MainWindow::get_end()
{
    return checked_point_read(ui->Xend, ui->Yend);
}

Point_t MainWindow::get_spec_center()
{
    return checked_point_read(ui->xcSpectre, ui->ycSpectre);
}

double MainWindow::get_spec_len()
{
    return checked_double_read(ui->LenSpectre);
}

double MainWindow::get_spec_degree()
{
    return checked_double_read(ui->DegreeSpectre);
}


Point_t checked_point_read(QLineEdit *line1, QLineEdit *line2)
{
    bool e1 = true, e2 = true;
    line1->setStyleSheet("");
    line2->setStyleSheet("");
    double x = line1->text().toDouble(&e1), y = line2->text().toDouble(&e2);
    if (!e1 || !e2)
    {
        if (!e1)
            line1->setStyleSheet("border: 1px solid red");
        if (!e2)
            line2->setStyleSheet("border: 1px solid red");
        throw UIError("Исправьте поля выделенные красным");

    }
    return {x, y};
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
