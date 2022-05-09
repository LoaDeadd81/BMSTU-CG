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

private:
    Ui::MainWindow *ui;

    Graphics_t graph_info;

    QLine cur_line;
    int dot_count;

    QList<QLine> lines_list;

    QList<QLine> clipper;
    QLine cur_clipper_line;
    QPoint first_dot;
    int clipper_dot_count;
    bool clipper_closed;

    void create_scene();
    void clean_data();

    void add_dot_to_line(QPoint &point, bool shift_modif, bool cntrl_modif);
    void add_dot_to_clipper(QPoint &point, bool shift_modif);

    QLine read_line();
    QPoint read_clipper();

    void draw_line();
    void draw_clipper_line();
    void draw_cut_off_line(QLine &line);

    void disable_clipper_input();
    void enable_clipper_input();

    void clipping();

};

#endif
