#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <QPainter>
#include <QStack>
#include <QResizeEvent>
#include <QSize>

#include <iostream>

#include "Graphics.h"
#include "Errors.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event);


private slots:

    void on_ButtonBlackLine_clicked();

    void on_ButtonYellowLine_clicked();

    void on_ButtonRedLine_clicked();

    void on_ButtonOrangeLine_clicked();

    void on_ButtonPurpleLine_clicked();

    void on_ButtonBlueLine_clicked();

    void on_ButtonGreenLine_clicked();

    void on_AddDotButton_clicked();

    void on_CleanButton_clicked();

    void on_DrawButton_clicked();

    void on_CloseFigureButton_clicked();

    void on_ButtonBlackBorder_clicked();

    void on_ButtonYellowBorder_clicked();

    void on_ButtonRedBorder_clicked();

    void on_ButtonOrangeBorder_clicked();

    void on_ButtonPurpleBorder_clicked();

    void on_ButtonBlueBorder_clicked();

    void on_ButtonGreenBorder_clicked();

    void on_AddZatravButton_clicked();

    void on_DrawEllipseButton_clicked();

private:
    Ui::MainWindow *ui;

    int width, height;

    Graph_t graph;
    //todo add color proc
    QColor bg_color;

    QPoint first_point, cur_start, cur_end, last_point;
    int point_count;
    bool first_line_drawen, first_point_inputed;
    int line_count;
    bool is_closed, center_inputed, center_input_access, is_ellipse_added;

    QGraphicsEllipseItem *ellipse_item;

    QPoint center;
    QStack<QPoint> point_stack;


    QPoint read_new_point();

    void add_center(QPoint &point);

    void draw_center();

    void add_new_point(QPoint &point);

    void add_new_cur_point(QPoint &point);

    bool is_new_line_ready();

    void add_new_line();

    void draw_point(QPoint &point);

    void draw_border(QLine &line);

    void draw_fill(QPoint p1, QPoint p2, int delay);

    void clean_data();

    void fill();

    bool eq_border_color(QPoint p);

    bool eq_filled_color(QPoint p);

    bool eq_bg_color(QPoint p);

    void check_row(QPoint p, int x_right);

    void remove_center();

    QPoint read_center();

    void set_center_data();

};

#endif // MAINWINDOW_H
