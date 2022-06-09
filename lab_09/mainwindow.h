#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QKeyEvent>
#include <QLineEdit>

#include "Graphics.h"
#include "Errors.h"
#include "clipping.h"
#include "Support.h"

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

    void on_ButtonBlackCipper_clicked();

    void on_ButtonWhiteCipper_clicked();

    void on_ButtonYellowCipper_clicked();

    void on_ButtonRedCipper_clicked();

    void on_ButtonOrangeCipper_clicked();

    void on_ButtonPurpleCipper_clicked();

    void on_ButtonBlueCipper_clicked();

    void on_ButtonGreenCipper_clicked();

    void on_ButtonBlackFragment_clicked();

    void on_ButtonWhiteFragment_clicked();

    void on_ButtonYellowFragment_clicked();

    void on_ButtonRedFragment_clicked();

    void on_ButtonOrangeFragment_clicked();

    void on_ButtonPurpleFragment_clicked();

    void on_ButtonBlueFragment_clicked();

    void on_ButtonGreenFragment_clicked();

    void on_ButtonBlackLine_clicked();

    void on_ButtonWhiteLine_clicked();

    void on_ButtonYellowLine_clicked();

    void on_ButtonRedLine_clicked();

    void on_ButtonOrangeLine_clicked();

    void on_ButtonPurpleLine_clicked();

    void on_ButtonBlueLine_clicked();

    void on_ButtonGreenLine_clicked();


    void on_CleanButton_clicked();

    void on_DrawButton_clicked();

    void on_DrawSegmentButton_clicked();

    void on_CloseClipperButton_clicked();

    void on_AddDorClipperButton_clicked();

    void on_ClosePolygonButton_clicked();

private:
    Ui::MainWindow *ui;

    Graphics_t graph_info;

    QVector<QPoint> polygon;
    int polygon_dot_count;
    QPoint polygon_first_dot;
    bool polygon_closed;

    QVector<QPoint> clipper;
    int clipper_dot_count;
    QPoint clipper_first_dot;
    bool clipper_closed;

    void create_scene();
    void clean_data();
    void clean_polygon_data();
    void clean_clipper_data();

    void add_dot_to_polygon(QPoint &point, bool shift_modif);
    void add_dot_to_clipper(QPoint &point, bool shift_modif);

    void draw_polygon_line();
    void draw_clipper_line();
    void draw_cut_off_line(QLine &line);

    QPoint read_polygon();
    QPoint read_clipper();

    void disable_clipper_input();
    void enable_clipper_input();

    void clipping();
    void redraw_without_clipper();

};

#endif
