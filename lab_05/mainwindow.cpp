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

#define EPS 1e-3

int checked_int_read(QLineEdit *line);

void show_error(QString title, QString message);

void delay(int ms);

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clean_data();
    graph.pen_fill = QPen();
    graph.pen_border = QPen();
    graph.scene = new QGraphicsScene(this);
    graph.scene->setSceneRect(0, 0, ui->ResView->width(), ui->ResView->height());
    ui->ResView->setScene(graph.scene);
    graph.scene->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonBlackLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-черный)");
    graph.pen_fill.setColor(BLACK);
}


void MainWindow::on_ButtonWhiteLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-белый)");
    graph.pen_fill.setColor(WHITE);
}


void MainWindow::on_ButtonYellowLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-жёлтый)");
    graph.pen_fill.setColor(YELLOW);
}


void MainWindow::on_ButtonRedLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-красный)");
    graph.pen_fill.setColor(RED);
}


void MainWindow::on_ButtonOrangeLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-оранжевый)");
    graph.pen_fill.setColor(ORANGE);
}


void MainWindow::on_ButtonPurpleLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-фиолетовый)");
    graph.pen_fill.setColor(PURPLE);
}


void MainWindow::on_ButtonBlueLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-синий)");
    graph.pen_fill.setColor(BLUE);
}


void MainWindow::on_ButtonGreenLine_clicked()
{
    ui->LIneColorLabel->setText("Цвет заливки(текущий цвет-зелёный)");
    graph.pen_fill.setColor(GREEN);
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

void MainWindow::on_ButtonBlackBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-черный)");
    graph.pen_border.setColor(BLACK);
}


void MainWindow::on_ButtonWhiteBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-белый)");
    graph.pen_border.setColor(WHITE);
}


void MainWindow::on_ButtonYellowBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-желтый)");
    graph.pen_border.setColor(YELLOW);
}


void MainWindow::on_ButtonRedBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-красный)");
    graph.pen_border.setColor(RED);
}


void MainWindow::on_ButtonOrangeBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-оранжевый)");
    graph.pen_border.setColor(ORANGE);
}


void MainWindow::on_ButtonPurpleBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-фиолетовый)");
    graph.pen_border.setColor(PURPLE);
}


void MainWindow::on_ButtonBlueBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-синий)");
    graph.pen_border.setColor(BLUE);
}


void MainWindow::on_ButtonGreenBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-зелёный)");
    graph.pen_border.setColor(GREEN);
}


void MainWindow::on_CleanButton_clicked()
{
    graph.scene->clear();
    ui->PointTableWidget->setRowCount(0);
    clean_data();
}


void MainWindow::on_AddDotButton_clicked()
{
    try
    {
        QPoint new_point = read_new_point();
        add_new_point(new_point);
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::on_CloseFigureButton_clicked()
{
    try
    {
        if (is_closed && !edge_list.empty())
            throw UIError("Фигура уже замкнута");
        if (line_count < 2)
            throw UIError("Недостаточно отрезков для замыкания фигуры. Необходимо минимум 2.");

        cur_start = cur_end;
        cur_end = first_point;
        add_new_line();
        point_count = 0;
        first_line_drawen = false;
        line_count = 0;
        is_closed = true;
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::on_DrawButton_clicked()
{
    try
    {
        if (edge_list.empty())
            throw UIError("Нет ни одного ребра");
        if (!is_closed)
            throw UIError("Необходимо замкнуть последнюю фигуру");
        int delay = 0;
        if (ui->DelayCJeckBox->isChecked())
            delay = ui->DelaySpinBox->text().toInt();
        timeval tv_s, tv_e;
        mingw_gettimeofday(&tv_s, NULL);
        create_edge_list();
        int n = rt_border.y() - lb_border.y();
        for (int i = 0; i < n; i++)
        {
            add_edges_LAE(lb_border.y() + i);
            draw_by_lae(i, delay);
            update_LAE();
        }
        if(!horizontal_edges.empty()) draw_horizontal_edges();
        mingw_gettimeofday(&tv_e, NULL);
        if (ui->DelayCJeckBox->isChecked())
            ui->label_2->setText("Время работы алгоритма: " + QString::number((tv_e.tv_sec - tv_s.tv_sec) * 1000.0) + " мс");
        else
            ui->label_2->setText("Время работы алгоритма: " + QString::number((tv_e.tv_usec - tv_s.tv_usec) / 1000.0) + " мс");
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

bool cmp_edge(const Edge_t &e1, const Edge_t &e2)
{
    return e1.min_y < e2.min_y;
}

void MainWindow::create_edge_list()
{
    for (auto &it: edge_list)
    {
        double x, dy = fabs(it.y2() - it.y1()), dx;
        int min_y;
        if (abs(it.y1() - it.y2()) == 0)
        {
            horizontal_edges.append(it);
            continue;
        }
        if (it.y1() > it.y2())
        {
            dx = (it.x1() - it.x2()) / dy;
            x = it.x2() + dx * 0.5;
            min_y = it.y2();
        }
        else
        {
            dx = (it.x2() - it.x1()) / dy;
            x = it.x1() + dx * 0.5;
            min_y = it.y1();
        }
        y_groups.append({min_y, x, dx, dy});
    }
    std::sort(y_groups.begin(), y_groups.end(), cmp_edge);
}

void MainWindow::add_edges_LAE(int y)
{
    QList<Edge_t>::iterator it = y_groups.begin(), next;
    while (!y_groups.empty() && it->min_y == y)
    {
        next = it + 1;
        LAE.append(*it);
        y_groups.erase(it);
        it = next;
    }
}

void MainWindow::update_LAE()
{
    QList<Edge_t>::iterator next, cur = LAE.begin();
    while (!(LAE.empty() || cur >= LAE.end()))
    {
        cur->delta_y -= 1;
        cur->cur_x += cur->dx;
        next = cur + 1;
        if (fabs(cur->delta_y) <= EPS)
        {
            if (cur != LAE.begin())
                next = cur;
            LAE.erase(cur);
        }
        cur = next;
    }
}

void MainWindow::draw_by_lae(int y, int delay_ms)
{
    int real_y = lb_border.y() + y;
    QVector<double> points = QVector<double>(LAE.size());
    for (int i = 0; i < LAE.size(); i++) points[i] = LAE[i].cur_x;
    std::sort(points.begin(), points.end());
    for (int i = 0; i < points.size(); i += 2)
    {
        QPoint p1 = {int(round(points[i] + 0.5)), real_y},
                p2 = {int(floor(points[i + 1] - 0.5)), real_y};
        if (delay_ms != 0) delay(delay_ms);
        draw_fill(p1, p2);
    }
}

void MainWindow::draw_horizontal_edges()
{
    for (auto &it: horizontal_edges)
    {
        draw_border(it);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent *mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPoint pos = mouse_event->scenePos().toPoint();
        switch (QApplication::keyboardModifiers())
        {
            case Qt::ShiftModifier:
            {
                if (abs(last_point.x() - pos.x()) < abs(last_point.y() - pos.y()))
                    pos.setX(last_point.x());
                else
                    pos.setY(last_point.y());
                break;
            }
            default:
                break;
        }
        add_new_point(pos);
    }
    return false;
}

QPoint MainWindow::read_new_point()
{
    int x = checked_int_read(ui->xLineEdit),
            y = checked_int_read(ui->yLineEdit);
    return {x, y};
}

void MainWindow::add_new_point(QPoint &point)
{
    auto *table = ui->PointTableWidget;
    int i = table->rowCount();
    table->insertRow(i);
    table->setItem(i, 0, new QTableWidgetItem(QString::number(point.x())));
    table->setItem(i, 1, new QTableWidgetItem(QString::number(point.y())));
    draw_point(point);

    last_point = point;

    if (!first_point_inputed)
    {
        lb_border = rt_border = point;
        first_point_inputed = true;
    }
    else
    {
        if (point.x() < lb_border.x()) lb_border.setX(point.x());
        if (point.y() < lb_border.y()) lb_border.setY(point.y());
        if (point.x() > rt_border.x()) rt_border.setX(point.x());
        if (point.y() > rt_border.y()) rt_border.setY(point.y());
    }

    add_new_cur_point(point);
    if (is_new_line_ready()) add_new_line();
    is_closed = false;
}

void MainWindow::add_new_cur_point(QPoint &point)
{
    if (first_line_drawen)
    {
        cur_start = cur_end;
        cur_end = point;
    }
    else
    {
        if (point_count == 0) first_point = cur_start = point;
        else cur_end = point;
        point_count++;
    }
}

bool MainWindow::is_new_line_ready()
{
    return first_line_drawen || point_count == 2;
}

void MainWindow::add_new_line()
{
    QLine line = {cur_start, cur_end};
    first_line_drawen = true;
    draw_border(line);
    edge_list.append(line);
    line_count++;
}

void MainWindow::draw_border(QLine &line)
{
    graph.scene->addLine(line, graph.pen_border);
}

void MainWindow::draw_fill(QPoint &p1, QPoint &p2)
{
    graph.scene->addLine({p1, p2}, graph.pen_fill);
}

void MainWindow::draw_point(QPoint &point)
{
    double r = 10;
    graph.scene->addEllipse(point.x() - r / 2, point.y() - r / 2, r, r, graph.pen_border);
}

void MainWindow::clean_data()
{
    first_point = cur_start = cur_end = lb_border = rt_border = QPoint();
    point_count = line_count = 0;
    first_line_drawen = first_point_inputed = is_closed = false;
    edge_list.clear();
    y_groups.clear();
    LAE.clear();
    horizontal_edges.clear();
}

int checked_int_read(QLineEdit *line)
{
    bool e1 = true;
    line->setStyleSheet("");
    int x = line->text().toInt(&e1);
    if (!e1)
    {
        line->setStyleSheet("border: 1px solid red");
        throw UIError("Исправьте поля выделенные красным. Ожидается ввод целого числа");
    }
//    if (x <= 0)
//    {
//        line->setStyleSheet("border: 1px solid red");
//        throw UIError("Значение в полях выделенных красным должны быть положительными");
//    }
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

void delay(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents, 5);
}
