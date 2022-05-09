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
    graph_info.scene->clear();
    cur_line = QLine();
    dot_count = 0;
    lines_list.clear();
    ui->PointTableWidget->setRowCount(0);

    clipper.clear();
    clipper_dot_count = 0;
    clipper_closed = false;
    enable_clipper_input();
    ui->ClipperPointTableWidget->setRowCount(0);
}

//todo параллельные линии

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent *mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPoint pos = mouse_event->scenePos().toPoint();
        bool shift_modif = false, control_modif = false;
        if (mouse_event->button() == Qt::LeftButton)
        {
            switch (QApplication::keyboardModifiers())
            {
                case Qt::ShiftModifier:
                {
                    shift_modif = true;
                    break;
                }
                case Qt::ControlModifier:
                {
                    control_modif = true;
                    break;
                }
                default:
                    break;
            }
            add_dot_to_line(pos, shift_modif, control_modif);
            if (dot_count == 2) draw_line();
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
            if (clipper_dot_count >= 2 && !clipper_closed) draw_clipper_line();
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
        if (lines_list.empty()) throw UIError("Введите хоть один отрезок");
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
        if (clipper_dot_count >= 2) draw_clipper_line();
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
        cur_line = read_line();
        draw_line();
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
        cur_clipper_line.setP1(cur_clipper_line.p2());
        cur_clipper_line.setP2(first_dot);
        draw_clipper_line();
        clipper_closed = true;
        disable_clipper_input();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::clipping()
{
    QList<QVector2D> clipper_vec;
    qline_to_qvector2d(clipper_vec, clipper);
    int n_orientation;
    if (!convexity_check(n_orientation, clipper_vec)) throw UIError("Отсекатель должен быть выпуклым");
    if (n_orientation == NO_N) throw UIError("Отсекатель вырожден в прямую");
    QList<QVector2D> n;
    get_n(n, n_orientation, clipper_vec);
    for (auto item: lines_list)
    {
        bool is_visible;
        QLine res = find_visible_segment(is_visible, item, n, clipper);
        if (is_visible) draw_cut_off_line(res);
    }
}

void MainWindow::add_dot_to_line(QPoint &point, bool shift_modif, bool cntrl_modif)
{
    if (dot_count == 0) cur_line.setP1(point);
    else
    {
        if (shift_modif)
        {
            if (abs(cur_line.p1().x() - point.x()) < abs(cur_line.p1().y() - point.y()))
                point.setX(cur_line.p1().x());
            else
                point.setY(cur_line.p1().y());
        }
        if (cntrl_modif)
        {
            int i = ui->spinBox->value();
            if (!clipper.empty() && i < clipper.size())
            {
                QLine line = clipper.at(i - 1);
                double m = double(line.y2() - line.y1()) / double(line.x2() - line.x1());
                double dx = point.x() - cur_line.x1();
                double x = point.x(),
                        y = cur_line.y1() + m * dx;
                point = {int(x), int(y)};
            }
        }
        cur_line.setP2(point);
    }
    dot_count++;
}

void MainWindow::add_dot_to_clipper(QPoint &point, bool shift_modif)
{
    try
    {
        if (clipper_closed) throw UIError("Отсекатель уже введён");
        if (clipper_dot_count == 0)
        {
            first_dot = point;
            cur_clipper_line.setP1(point);
        }
        else
        {
            if (clipper_dot_count > 1) cur_clipper_line.setP1(cur_clipper_line.p2());
            if (shift_modif)
            {
                if (abs(cur_line.p1().x() - point.x()) < abs(cur_line.p1().y() - point.y()))
                    point.setX(cur_line.p1().x());
                else
                    point.setY(cur_line.p1().y());
            }
            cur_clipper_line.setP2(point);
        }
        clipper_dot_count++;
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::draw_line()
{
    graph_info.scene->addLine(cur_line, graph_info.pen_segment);
    lines_list.append(cur_line);

    auto *table = ui->PointTableWidget;
    int i = table->rowCount();
    table->insertRow(i);
    QString start_str = "( " + QString::number(cur_line.x1()) + ", " + QString::number(cur_line.y1()) + ")",
            end_str = "( " + QString::number(cur_line.x2()) + ", " + QString::number(cur_line.y2()) + ")";
    table->setItem(i, 0, new QTableWidgetItem(start_str));
    table->setItem(i, 1, new QTableWidgetItem(end_str));

    cur_line = QLine();
    dot_count = 0;
}

void MainWindow::draw_clipper_line()
{
    graph_info.scene->addLine(cur_clipper_line, graph_info.pen_clipper);
    clipper.append(cur_clipper_line);

    auto *table = ui->ClipperPointTableWidget;
    int i = table->rowCount();
    table->insertRow(i);
    QString start_str =
            "( " + QString::number(cur_clipper_line.x1()) + ", " + QString::number(cur_clipper_line.y1()) + ")",
            end_str =
            "( " + QString::number(cur_clipper_line.x2()) + ", " + QString::number(cur_clipper_line.y2()) + ")";
    table->setItem(i, 0, new QTableWidgetItem(start_str));
    table->setItem(i, 1, new QTableWidgetItem(end_str));
}

void MainWindow::draw_cut_off_line(QLine &line)
{
    graph_info.scene->addLine(line, graph_info.pen_cut_off_segment);
}


QLine MainWindow::read_line()
{
    QPoint start = read_point(ui->start_x_LE, ui->start_y_LE),
            end = read_point(ui->end_x_LE, ui->end_y_LE);
    dot_count = 2;
    return {start, end};
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


