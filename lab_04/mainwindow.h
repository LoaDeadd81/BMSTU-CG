#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <ctime>
#include <QtCharts>
#include <QLineSeries>

#include <iostream>

using namespace std;

#include "Geometry.h"
#include "Graphics.h"
#include "Algo.h"
#include "Errors.h"
#include "form.h"

typedef void (*algorithm_circle)(Circle_t &, Graph_t &);

typedef void (*algorithm_ellipse)(Ellipse_t &, Graph_t &);

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

    void set_spectr_center();

private slots:

    void on_ButtonBlackLine_clicked();

    void on_ButtonWhiteLine_clicked();

    void on_ButtonYellowLine_clicked();

    void on_ButtonRedLine_clicked();

    void on_ButtonOrangeLine_clicked();

    void on_ButtonPurpleLine_clicked();

    void on_ButtonBlueLine_clicked();

    void on_ButtonGreenLine_clicked();

    void on_ButtonBlackBG_clicked();

    void on_ButtonWhiteBG_clicked();

    void on_ButtonYellowBG_clicked();

    void on_ButtonRedBG_clicked();

    void on_ButtonOrangeBG_clicked();

    void on_ButtonPurpleBG_clicked();

    void on_ButtonBlueBG_clicked();

    void on_ButtonGreenBG_clicked();

    void on_CleanButton_clicked();

    void on_DrawButton_clicked();

    void on_DrawSpectreButton_clicked();

    void on_TimeAnalButton_clicked();

private:
    Ui::MainWindow *ui;
    form *Graphics;

    Graph_t graph;
    QColor bg_color;

    void draw_circle();

    void draw_ellipse();

    void draw_circle_specter();

    void draw_ellipse_specter();

    void circle_time_mes();

    void ellipse_time_mes();

    algorithm_circle get_circle_alg();

    algorithm_ellipse get_ellipse_alg();

    Ellipse_t get_ellipse_param();

    Circle_t get_circle_param();

    Point_t get_center();
};

#endif // MAINWINDOW_H
