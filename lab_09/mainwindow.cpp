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

QPoint read_point(QLineEdit *x_le, QLineEdit *y_le);

void show_error(QString title, QString message);


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graph_info.pen_cut_off_segment.setWidth(2);

    create_scene();
    clean_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_scene()
{
    graph_info.scene = new QGraphicsScene(this);
    graph_info.scene->setSceneRect(0, 0, ui->ResView->width(), ui->ResView->height());
    ui->ResView->setScene(graph_info.scene);
    graph_info.scene->installEventFilter(this);
}

void MainWindow::clean_data()
{
    clean_polygon_data();
    clean_clipper_data();
    graph_info.scene->clear();
}

void MainWindow::clean_polygon_data()
{
    polygon.clear();
    polygon_dot_count = 0;
    polygon_first_dot = QPoint();
    polygon_closed = false;
}

void MainWindow::clean_clipper_data()
{
    clipper.clear();
    clipper_dot_count = 0;
    clipper_first_dot = QPoint();
    clipper_closed = false;
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent *mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPoint pos = mouse_event->scenePos().toPoint();
        bool shift_modif = false;
        if (mouse_event->button() == Qt::LeftButton)
        {
            switch (QApplication::keyboardModifiers())
            {
                case Qt::ShiftModifier:
                {
                    shift_modif = true;
                    break;
                }
                default:
                    break;
            }
            add_dot_to_polygon(pos, shift_modif);
            draw_polygon_line();
        }
        else if (mouse_event->button() == Qt::RightButton)
        {
            switch (QApplication::keyboardModifiers())
            {
                case Qt::ShiftModifier:
                {
                    shift_modif = true;
                    break;
                }
                default:
                    break;
            }
            add_dot_to_clipper(pos, shift_modif);
            draw_clipper_line();
        }
    }
    return false;
}

void MainWindow::on_CleanButton_clicked()
{
    clean_data();
}

void MainWindow::on_DrawButton_clicked()
{
    try
    {
        if (clipper_dot_count < 2) throw UIError("Введите отсекатель");
        if (!clipper_closed) throw UIError("Замкните отсекатель");
        if (polygon_dot_count < 2) throw UIError("Введите отсекаемый многоугольник");
        if (!polygon_closed) throw UIError("Замкните отсекаемый многоугольник");
        clipping();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_AddDorClipperButton_clicked()
{
    try
    {
        QPoint tmp = read_clipper();
        add_dot_to_clipper(tmp, false);
        draw_clipper_line();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::on_DrawSegmentButton_clicked()
{
    try
    {
        QPoint tmp = read_polygon();
        add_dot_to_polygon(tmp, false);
        draw_polygon_line();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::on_CloseClipperButton_clicked()
{
    try
    {
        if (clipper_closed) throw UIError("Отсекатель уже замкнут");
        if (clipper_dot_count < 3) throw UIError("Недостаточно точек для замыкания");
        clipper_closed = true;
        graph_info.scene->addLine({clipper.last(), clipper_first_dot}, graph_info.pen_clipper);
//        disable_clipper_input();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::on_ClosePolygonButton_clicked()
{
    try
    {
        if (polygon_closed) throw UIError("Многоугольник уже замкнут");
        if (polygon_dot_count < 3) throw UIError("Недостаточно точек для замыкания");
        polygon_closed = true;
        graph_info.scene->addLine({polygon.last(), polygon_first_dot}, graph_info.pen_segment);
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}


void MainWindow::clipping()
{
    QVector<QLine> clipper_line;
    qpointss_to_qliness(clipper_line, clipper);
    QVector<QVector2D> clipper_vec;
    qlines_to_qvector2ds(clipper_vec, clipper_line);

    int n_orientation;
    if (!convexity_check(n_orientation, clipper_vec)) throw UIError("Отсекатель должен быть выпуклым");
    if (self_intersection_check(clipper_line)) throw UIError("Отсекатель не должен само пересекаться");
    if (n_orientation == NO_N) throw UIError("Отсекатель вырожден в прямую");

    QVector<QPoint> res = clip(clipper, polygon, n_orientation);
    if (res.empty()) return;
    for (int i = 0; i < res.size() - 1; i++)
        graph_info.scene->addLine({res[i], res[i + 1]}, graph_info.pen_cut_off_segment);
    graph_info.scene->addLine({res[res.size() - 1], res[0]}, graph_info.pen_cut_off_segment);
}

void MainWindow::add_dot_to_polygon(QPoint &point, bool shift_modif)
{
    if (polygon_dot_count == 0) polygon_first_dot = point;
    else if (shift_modif)
    {
        if (abs(polygon.last().x() - point.x()) < abs(polygon.last().y() - point.y()))
            point.setX(polygon.last().x());
        else
            point.setY(polygon.last().y());
    }
    polygon.append(point);
    polygon_dot_count++;

}

void MainWindow::add_dot_to_clipper(QPoint &point, bool shift_modif)
{
    if (clipper_closed) redraw_without_clipper();
    if (clipper_dot_count == 0) clipper_first_dot = point;
    else if (shift_modif)
    {
        if (abs(clipper.last().x() - point.x()) < abs(clipper.last().y() - point.y()))
            point.setX(clipper.last().x());
        else
            point.setY(clipper.last().y());
    }
    clipper.append(point);
    clipper_dot_count++;
}

void MainWindow::draw_polygon_line()
{

    ui->mx_LE->setText(QString::number(polygon.last().x()));
    ui->my_LE->setText(QString::number(polygon.last().y()));
    if (polygon.size() < 2)
        return;
    auto it = polygon.end();
    QPoint end = *(--it), start = *(--it);
    graph_info.scene->addLine({start, end}, graph_info.pen_segment);
}

void MainWindow::draw_clipper_line()
{
    ui->x_clipperLineEdit->setText(QString::number(clipper.last().x()));
    ui->y_clipperLineEdit->setText(QString::number(clipper.last().y()));
    if (clipper.size() < 2)
        return;
    auto it = clipper.end();
    QPoint end = *(--it), start = *(--it);
    graph_info.scene->addLine({start, end}, graph_info.pen_clipper);
}

void MainWindow::draw_cut_off_line(QLine &line)
{
    graph_info.scene->addLine(line, graph_info.pen_cut_off_segment);
}


QPoint MainWindow::read_polygon()
{
    return read_point(ui->mx_LE, ui->my_LE);
}

QPoint MainWindow::read_clipper()
{
    return read_point(ui->x_clipperLineEdit, ui->y_clipperLineEdit);
}

void MainWindow::disable_clipper_input()
{
    ui->x_clipperLineEdit->setDisabled(true);
    ui->y_clipperLineEdit->setDisabled(true);
    ui->AddDorClipperButton->setDisabled(true);
}

void MainWindow::enable_clipper_input()
{
    ui->x_clipperLineEdit->setDisabled(false);
    ui->y_clipperLineEdit->setDisabled(false);
    ui->AddDorClipperButton->setDisabled(false);
}

int checked_int_read(QLineEdit *line);

QPoint read_point(QLineEdit *x_le, QLineEdit *y_le)
{
    int x = checked_int_read(x_le), y = checked_int_read(y_le);
    return {x, y};
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

void MainWindow::redraw_without_clipper()
{
    clean_clipper_data();
    graph_info.scene->clear();
    auto it = polygon.begin();
    auto start = it, end = ++it;
    while (end != polygon.end())
    {
        graph_info.scene->addLine({*start, *end}, graph_info.pen_segment);
        start++;
        end++;
    }
    graph_info.scene->addLine({*start, polygon_first_dot}, graph_info.pen_segment);
}

void show_error(QString title, QString message)
{
    QErrorMessage error_msg;
    error_msg.showMessage(message);
    error_msg.setWindowTitle(title);
    error_msg.exec();
}

//цвет

void MainWindow::on_ButtonBlackCipper_clicked()
{
    graph_info.pen_clipper.setColor(BLACK);
    ui->CipperColorLabel->setText("Цвет отсекателя (чёрный)");
}


void MainWindow::on_ButtonWhiteCipper_clicked()
{
    graph_info.pen_clipper.setColor(WHITE);
    ui->CipperColorLabel->setText("Цвет отсекателя (белый)");
}


void MainWindow::on_ButtonYellowCipper_clicked()
{
    graph_info.pen_clipper.setColor(YELLOW);
    ui->CipperColorLabel->setText("Цвет отсекателя (жёлтый)");
}


void MainWindow::on_ButtonRedCipper_clicked()
{
    graph_info.pen_clipper.setColor(RED);
    ui->CipperColorLabel->setText("Цвет отсекателя (красный)");
}


void MainWindow::on_ButtonOrangeCipper_clicked()
{
    graph_info.pen_clipper.setColor(ORANGE);
    ui->CipperColorLabel->setText("Цвет отсекателя (оранжевый)");
}


void MainWindow::on_ButtonPurpleCipper_clicked()
{
    graph_info.pen_clipper.setColor(PURPLE);
    ui->CipperColorLabel->setText("Цвет отсекателя (фиолетовый)");
}


void MainWindow::on_ButtonBlueCipper_clicked()
{
    graph_info.pen_clipper.setColor(BLUE);
    ui->CipperColorLabel->setText("Цвет отсекателя (голубой)");
}


void MainWindow::on_ButtonGreenCipper_clicked()
{
    graph_info.pen_clipper.setColor(GREEN);
    ui->CipperColorLabel->setText("Цвет отсекателя (зелёный)");
}


void MainWindow::on_ButtonBlackFragment_clicked()
{
    graph_info.pen_segment.setColor(BLACK);
    ui->LIneColorFragment->setText("Цвет отрезков (чёрный)");
}


void MainWindow::on_ButtonWhiteFragment_clicked()
{
    graph_info.pen_segment.setColor(WHITE);
    ui->LIneColorFragment->setText("Цвет отрезков (белый)");
}


void MainWindow::on_ButtonYellowFragment_clicked()
{
    graph_info.pen_segment.setColor(YELLOW);
    ui->LIneColorFragment->setText("Цвет отрезков (жёлтый)");
}


void MainWindow::on_ButtonRedFragment_clicked()
{
    graph_info.pen_segment.setColor(RED);
    ui->LIneColorFragment->setText("Цвет отрезков (красный)");
}


void MainWindow::on_ButtonOrangeFragment_clicked()
{
    graph_info.pen_segment.setColor(ORANGE);
    ui->LIneColorFragment->setText("Цвет отрезков (оранжевый)");
}


void MainWindow::on_ButtonPurpleFragment_clicked()
{
    graph_info.pen_segment.setColor(PURPLE);
    ui->LIneColorFragment->setText("Цвет отрезков (фиолетовый)");
}


void MainWindow::on_ButtonBlueFragment_clicked()
{
    graph_info.pen_segment.setColor(BLUE);
    ui->LIneColorFragment->setText("Цвет отрезков (синий)");
}


void MainWindow::on_ButtonGreenFragment_clicked()
{
    graph_info.pen_segment.setColor(GREEN);
    ui->LIneColorFragment->setText("Цвет отрезков (зелёный)");
}


void MainWindow::on_ButtonBlackLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(BLACK);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (чёрный)");
}


void MainWindow::on_ButtonWhiteLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(WHITE);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (белый)");
}


void MainWindow::on_ButtonYellowLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(YELLOW);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (жёлтый)");
}


void MainWindow::on_ButtonRedLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(RED);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (красный)");
}


void MainWindow::on_ButtonOrangeLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(ORANGE);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (оранжевый)");
}


void MainWindow::on_ButtonPurpleLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(PURPLE);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (фиолетовый)");
}


void MainWindow::on_ButtonBlueLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(BLUE);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (синий)");
}


void MainWindow::on_ButtonGreenLine_clicked()
{
    graph_info.pen_cut_off_segment.setColor(GREEN);
    ui->LIneColorLabel->setText("Цвет отсечённых отрезков (зелёный)");
}


