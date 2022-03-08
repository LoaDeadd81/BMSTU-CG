#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPen>
#include <QRect>
#include <QErrorMessage>

#include "Figure.h"
#include "MyErrors.h"
#include "Pair.h"

typedef DiffTypePair<Figure, QString> action_type;

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

    void on_SelectCenterButton_clicked();

private:
    Ui::MainWindow *ui;
    Figure figure;
    QPen main_pen;
    QGraphicsScene *main_scene;
    vector <DiffTypePair<Figure, QString>> action_vec;

    Point get_transform_center();
    void set_default_params();
    void create_scene();
    void create_figure();

    bool is_empty_action_list();
    void push_action(action_type action);
    action_type pop_action();
    void clean_actions();
};
#endif
