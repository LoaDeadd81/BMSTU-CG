#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPen>
#include <QRect>

#include "Figure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ParamButton_clicked();

    void on_MoveButton_clicked();

    void on_ScaleButton_clicked();

    void on_RotateButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::MainWindow *ui;
    Figure figure;
    QPen main_pen;
    QGraphicsScene main_scene;

    Point get_transform_center();
    void set_default_data();
    void create_scene();

};
#endif
