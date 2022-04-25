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

    width = ui->ResView->width(), height = ui->ResView->height();
    graph.scene = new QGraphicsScene(this);
    graph.scene->setSceneRect(0, 0, width, height);
    ui->ResView->setScene(graph.scene);
    graph.scene->installEventFilter(this);

    clean_data();
    bg_color = WHITE;
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

void MainWindow::on_ButtonBlackBorder_clicked()
{
    ui->LIneColorBorder->setText("Цвет границ(текущий цвет-черный)");
    graph.pen_border.setColor(BLACK);
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
        if (line_count < 2)
            throw UIError("Недостаточно отрезков для замыкания фигуры. Необходимо минимум 2.");
        if (is_closed)
            throw UIError("Фигура уже замкнута");

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
        if (ui->PointTableWidget->rowCount() < 2 && !is_ellipse_added)
            throw UIError("Нет ни одного ребра");
        if (!is_closed)
            throw UIError("Необходимо замкнуть последнюю фигуру");
        if(!center_inputed)
            throw UIError("Введите затравочную точку");
        int delay = 0;
        if (ui->DelayCJeckBox->isChecked())
            delay = ui->DelaySpinBox->text().toInt();
        fill();
        center_input_access = true;
        ui->AddZatravButton->setDisabled(false);
        ui->cxLineEdit->setDisabled(false);
        ui->cyLineEdit->setDisabled(false);
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_AddZatravButton_clicked()
{
    try
    {
        QPoint new_point = read_center();
        add_center(new_point);
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
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
        if (mouse_event->button() == Qt::LeftButton)
            add_new_point(pos);
        else
            add_center(pos);
    }
    return false;
}

QPoint MainWindow::read_new_point()
{
    int x = checked_int_read(ui->xLineEdit),
            y = checked_int_read(ui->yLineEdit);
    return {x, y};
}


QPoint MainWindow::read_center()
{
    int x = checked_int_read(ui->cxLineEdit),
            y = checked_int_read(ui->cyLineEdit);
    return {x, y};
}

void MainWindow::set_center_data()
{
    ui->cxLineEdit->setText(QString::number(center.x()));
    ui->cyLineEdit->setText(QString::number(center.y()));
}

void MainWindow::add_center(QPoint &point)
{
    try
    {
        if (!center_input_access)
            throw UIError("Затравочная точка уже добавлена");
        center = point;
        draw_center();
        center_inputed = true;
        center_input_access = false;
        ui->AddZatravButton->setDisabled(true);
        ui->cxLineEdit->setDisabled(true);
        ui->cyLineEdit->setDisabled(true);
        set_center_data();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::add_new_point(QPoint &point)
{
    auto *table = ui->PointTableWidget;
    int i = table->rowCount();
    table->insertRow(i);
    table->setItem(i, 0, new QTableWidgetItem(QString::number(point.x())));
    table->setItem(i, 1, new QTableWidgetItem(QString::number(point.y())));
//    draw_point(point);

    last_point = point;

    if (!first_point_inputed) first_point_inputed = true;

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
    line_count++;
}

void MainWindow::clean_data()
{
    graph.scene->clear();

    int width = ui->ResView->width(), height = ui->ResView->height();
    graph.image = QImage(width, height, QImage::Format_ARGB32);
    graph.image.fill(WHITE);
    graph.pixmap_item = graph.scene->addPixmap(QPixmap::fromImage(graph.image));

    first_point = cur_start = cur_end = QPoint();
    point_count = line_count = 0;
    first_line_drawen = first_point_inputed = is_closed = center_inputed = is_ellipse_added = false;
    center_input_access = true;

    ui->AddZatravButton->setDisabled(false);
    ui->cxLineEdit->setDisabled(false);
    ui->cyLineEdit->setDisabled(false);

}

void MainWindow::fill()
{
    int delay_ms = 0;
    if (ui->DelayCJeckBox->isChecked()) delay_ms = ui->DelaySpinBox->text().toInt();
    remove_center();
    timeval tv_s, tv_e;
    mingw_gettimeofday(&tv_s, NULL);
    point_stack.push(center);
    while (!point_stack.empty())
    {
        QPoint pix = point_stack.pop();
        int x = pix.x(), y = pix.y();

        int tmp_x = x++;
        while (!eq_border_color({x, y}) && x < width) x++;
        int x_right = x - 1;

        x = tmp_x - 1;
        while (!eq_border_color({x, y}) && x > 0) x--;
        int x_left = x + 1;

        draw_fill({x_left, y}, {x_right, y}, 0);
        if (ui->DelayCJeckBox->isChecked()) delay(delay_ms);

        check_row({x_left, y + 1}, x_right);
        check_row({x_left, y - 1}, x_right);
    }
    mingw_gettimeofday(&tv_e, NULL);
    if (ui->DelayCJeckBox->isChecked())
        ui->label_2->setText("Время работы алгоритма: " + QString::number((tv_e.tv_sec - tv_s.tv_sec) * 1000.0) + " мс");
    else
        ui->label_2->setText("Время работы алгоритма: " + QString::number((tv_e.tv_usec - tv_s.tv_usec) / 1000.0) + " мс");
}

void MainWindow::check_row(QPoint p, int x_right)
{
    int x = p.x(), y = p.y();
    if(y <= 0 || y >= height) return;
    while (x <= x_right && x < width)
    {
        bool flag = false;
        while (!eq_border_color({x, y}) && !eq_filled_color({x, y}) && x < x_right && x < width)
        {
            flag = true;
            x++;
        }
        if (flag)
        {
            if (x == x_right && !eq_border_color({x, y}) && !eq_filled_color({x, y})) point_stack.push({x, y});
            else point_stack.push({x - 1, y});
            flag = false;
        }
        int tmp_x = x;
        while ((eq_border_color({x, y}) || eq_filled_color({x, y})) && x < x_right  && x < width) x++;
        if (x == tmp_x) x++;
    }
}

void MainWindow::draw_center()
{
//    QPixmap pixmap = graph.pixmap_item->pixmap();
//    QPainter painter(&pixmap);
//    painter.setPen(graph.pen_border);

//    int r = 10;
//    double x = double(r) * cos(M_PI / 4.0), y = double(r) * sin(M_PI / 4.0);
//    painter.drawEllipse(center.x() - r / 2, center.y() - r / 2, r, r);
//    painter.drawLine(center.x() + x, center.y() + y, center.x() - x, center.y() - y);
//    painter.drawLine(center.x() + x, center.y() - y, center.x() - x, center.y() + y);

//    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
//    graph.pixmap_item->setPixmap(pixmap);

    int r = 10;
    ellipse_item = graph.scene->addEllipse(center.x() - r / 2, center.y() - r / 2, r, r, graph.pen_border);
}

void MainWindow::remove_center()
{
//    QPixmap pixmap = graph.pixmap_item->pixmap();
//    QPainter painter(&pixmap);
//    QPen pen;
//    pen.setColor(bg_color);
//    painter.setPen(pen);

//    int r = 10;
//    double x = double(r) * cos(M_PI / 4.0), y = double(r) * sin(M_PI / 4.0);
//    painter.drawEllipse(center.x() - r / 2, center.y() - r / 2, r, r);
//    painter.drawLine(center.x() + x, center.y() + y, center.x() - x, center.y() - y);
//    painter.drawLine(center.x() + x, center.y() - y, center.x() - x, center.y() + y);

//    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
//    graph.pixmap_item->setPixmap(pixmap);
    graph.scene->removeItem(ellipse_item);
    delete ellipse_item;
}


void MainWindow::draw_point(QPoint &point)
{
    QPixmap pixmap = graph.pixmap_item->pixmap();
    QPainter painter(&pixmap);
    painter.setPen(graph.pen_border);

    int r = 10;
    painter.drawEllipse(point.x() - r / 2, point.y() - r / 2, r, r);

    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
    graph.pixmap_item->setPixmap(pixmap);
}

void MainWindow::draw_border(QLine &line)
{
    QPixmap pixmap = graph.pixmap_item->pixmap();
    QPainter painter(&pixmap);
    painter.setPen(graph.pen_border);

    painter.drawLine(line);

    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
    graph.pixmap_item->setPixmap(pixmap);
}

void MainWindow::draw_fill(QPoint p1, QPoint p2, int delay)
{
    QPixmap pixmap = graph.pixmap_item->pixmap();
    QPainter painter(&pixmap);
    painter.setPen(graph.pen_fill);

    painter.drawLine(p1, p2);

    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
    graph.pixmap_item->setPixmap(pixmap);
}

bool MainWindow::eq_border_color(QPoint p)
{
    return graph.image.pixelColor(p) == graph.pen_border.color();
}

bool MainWindow::eq_filled_color(QPoint p)
{
    return graph.image.pixelColor(p) == graph.pen_fill.color();;
}

bool MainWindow::eq_bg_color(QPoint p)
{
    return graph.image.pixelColor(p) == bg_color;
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


void MainWindow::on_DrawEllipseButton_clicked()
{
    int cx = checked_int_read(ui->cxLineEdit_2),
            cy = checked_int_read(ui->cyLineEdit_2);
    int a = checked_int_read(ui->cxLineEdit_3),
            b = checked_int_read(ui->cyLineEdit_3);
    QPixmap pixmap = graph.pixmap_item->pixmap();
    QPainter painter(&pixmap);
    painter.setPen(graph.pen_border);

    painter.drawEllipse({cx, cy}, a, b);

    graph.image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
    graph.pixmap_item->setPixmap(pixmap);
    is_ellipse_added = true;
    is_closed = true;
}

