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
    graph_info.scene->clear();
    cur_line = QLine();
    dot_count = 0;
    lines_list.clear();
    clipper = QRect();
    corner_count = 0;
    clipper_exist = false;
    enable_clipper_input();
    clean_clipper_info();
    ui->PointTableWidget->setRowCount(0);
}

void MainWindow::on_CleanButton_clicked()
{
    clean_data();
}

void MainWindow::on_DrawButton_clicked()
{
    try
    {
        if(!clipper_exist) throw UIError("Введите отсекатель");
        if (lines_list.empty()) throw UIError("Введите хоть один отрезок");
        clipping();
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::clipping()
{
    for(auto item : lines_list)
    {
        bool is_visible = false;
        find_visible_segment(is_visible, item, clipper);
        if(is_visible) draw_cut_off_line(item);
    }
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent *mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPoint pos = mouse_event->scenePos().toPoint();
        if (mouse_event->button() == Qt::LeftButton)
        {
            bool shift_modif = false;
            switch (QApplication::keyboardModifiers())
            {
                case Qt::ShiftModifier:
                    shift_modif = true;
                default:
                    break;
            }
            add_dot_to_line(pos, shift_modif);
            if (dot_count == 2) draw_line();
        }
        else if (mouse_event->button() == Qt::RightButton)
        {
            add_dot_to_clipper(pos);
            if (corner_count == 2) draw_clipper();
        }
    }
    return false;
}

void MainWindow::on_DrawClipperButton_clicked()
{
    clipper = read_clipper();
    draw_clipper();
}

void MainWindow::on_DrawSegmentButton_clicked()
{
    cur_line = read_line();
    draw_line();
}

void MainWindow::add_dot_to_line(QPoint &point, bool shift_modif)
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
        cur_line.setP2(point);
    }
    dot_count++;
}

void MainWindow::add_dot_to_clipper(QPoint &point)
{
    try
    {
        if (clipper_exist) throw UIError("Отсекатель уже введён");
        if (corner_count == 0) clipper_points[0] = point;
        else
        {
            clipper_points[1] = point;
            clipper = QRect(clipper_points[0], clipper_points[1]);
        }
        corner_count++;
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

void MainWindow::draw_clipper()
{
    try
    {
        if (clipper.left() >= clipper.right() || clipper.bottom() >= clipper.top())
        {
            clipper = QRect();
            corner_count = 0;
            throw UIError("Неверные данные для отсекателя. Первым кликом "
                          "задаётся левая верхняя вершина, вторым правая нижняя.");
        }
        graph_info.scene->addRect(clipper.left(), clipper.bottom(), clipper.right() - clipper.left(), clipper.top() - clipper.bottom(), graph_info.pen_clipper);
        disable_clipper_input();
        set_clipper_info();
        clipper_exist = true;
    }
    catch (Error &e)
    {
        show_error("Ошибка", e.get_message());
    }
}

void MainWindow::draw_cut_off_line(QLine &line)
{
    graph_info.scene->addLine(line, graph_info.pen_cut_off_segment);
}

void MainWindow::set_clipper_info()
{
    ui->lt_x_clipperLineEdit->setText(QString::number(clipper.left()));
    ui->lt_y_clipperLineEdit->setText(QString::number(clipper.top()));
    ui->rb_x_clipperLineEdit->setText(QString::number(clipper.right()));
    ui->rb_y_clipperLineEdit->setText(QString::number(clipper.bottom()));
}

void MainWindow::clean_clipper_info()
{
    ui->lt_x_clipperLineEdit->clear();
    ui->lt_y_clipperLineEdit->clear();
    ui->rb_x_clipperLineEdit->clear();
    ui->rb_y_clipperLineEdit->clear();
}

void MainWindow::disable_clipper_input()
{
    ui->lt_x_clipperLineEdit->setDisabled(true);
    ui->lt_y_clipperLineEdit->setDisabled(true);
    ui->rb_x_clipperLineEdit->setDisabled(true);
    ui->rb_y_clipperLineEdit->setDisabled(true);
}

void MainWindow::enable_clipper_input()
{
    ui->lt_x_clipperLineEdit->setDisabled(false);
    ui->lt_y_clipperLineEdit->setDisabled(false);
    ui->rb_x_clipperLineEdit->setDisabled(false);
    ui->rb_y_clipperLineEdit->setDisabled(false);
}

QLine MainWindow::read_line()
{
    QPoint start = read_point(ui->start_x_LE, ui->start_y_LE),
            end = read_point(ui->end_x_LE, ui->end_y_LE);
    dot_count = 2;
    return {start, end};
}

QRect MainWindow::read_clipper()
{
    QPoint lt = read_point(ui->lt_x_clipperLineEdit, ui->lt_y_clipperLineEdit),
            rb = read_point(ui->rb_x_clipperLineEdit, ui->rb_y_clipperLineEdit);
    corner_count = 2;
    return {lt, rb};
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
