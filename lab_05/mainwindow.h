#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QKeyEvent>
#include <QTime>

#include "Graphics.h"
#include "Errors.h"
#include "Edge.h"

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

    void on_ButtonBlackBG_clicked();

    void on_ButtonWhiteBG_clicked();

    void on_ButtonYellowBG_clicked();

    void on_ButtonRedBG_clicked();

    void on_ButtonOrangeBG_clicked();

    void on_ButtonPurpleBG_clicked();

    void on_ButtonBlueBG_clicked();

    void on_ButtonGreenBG_clicked();

    void on_ButtonBlackLine_clicked();

    void on_ButtonWhiteLine_clicked();

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

    void on_ButtonWhiteBorder_clicked();

    void on_ButtonYellowBorder_clicked();

    void on_ButtonRedBorder_clicked();

    void on_ButtonOrangeBorder_clicked();

    void on_ButtonPurpleBorder_clicked();

    void on_ButtonBlueBorder_clicked();

    void on_ButtonGreenBorder_clicked();

private:
    Ui::MainWindow *ui;

    Graph_t graph;
    QColor bg_color;

    QPoint first_point, cur_start, cur_end, last_point;
    int point_count;
    bool first_line_drawen, first_point_inputed;

    int line_count;
    bool is_closed;

    QPoint center;
    QPoint lb_border, rt_border;
    QList<QLine> edge_list;
    QList<Edge_t> y_groups;
    QList<Edge_t> LAE;
    QList<QLine> horizontal_edges;

    QPoint read_new_point();

    void add_new_point(QPoint &point);

    void add_new_cur_point(QPoint &point);

    bool is_new_line_ready();

    void add_new_line();

    void draw_point(QPoint &point);

    void draw_border(QLine &line);

    void draw_fill(QPoint &p1, QPoint &p2);

    void clean_data();

    void create_edge_list();

    void draw_by_lae(int y, int delay_ms);

    void add_edges_LAE(int y);

    void update_LAE();

    void draw_horizontal_edges();

};

#endif // MAINWINDOW_H
