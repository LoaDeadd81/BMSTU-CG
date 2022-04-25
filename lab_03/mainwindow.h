#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPen>
#include <QColor>

#include "Point.h"
#include "Graphics.h"
#include "Algo.h"
#include "Errors.h"

#include <QtCharts>

#include "form.h"


typedef void (*algorithm)(Point_t &, Point_t &, Graph_t &, int &);

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_DrawSpectre_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Form *secDialog;

    Graph_t graph;
    QColor bg_color;

    algorithm get_algorithm();

    Point_t get_start();

    Point_t get_end();

    Point_t get_spec_center();

    double get_spec_len();

    double get_spec_degree();
};

#endif // MAINWINDOW_H
