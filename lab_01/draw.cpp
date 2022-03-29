#include "draw.h"

void DrawLine(Line line, QGraphicsScene *scene, QPen &pen)
{
    double height = scene->height();
    QLineF l(line.get_begin().get_x(), height - line.get_begin().get_y(), line.get_end().get_x(), height - line.get_end().get_y());
    scene->addLine(l, pen);
}

void DrawPoint(Point point, QGraphicsScene *scene, QPen &pen, QBrush &brush, QString msg)
{
    double height = scene->height();
    int r = 6;
    scene->addEllipse(point.get_x() - r / 2, height - point.get_y() - r / 2, r, r, pen, brush);
    QGraphicsTextItem *label;
    QFont font = QFont("sans", 14);
    label = scene->addText(msg, font);
    label->setX(point.get_x() - label->boundingRect().width() / 2);
    label->setY(height - point.get_y() - 2 - label->boundingRect().height());
}


void DrawResult(QGraphicsScene *scene, Triangle &trn, QVector<Point> &points)
{
    //поиск размеров треугольника
    double left = trn.get_point(0).get_x(), right = trn.get_point(0).get_x();
    double top = trn.get_point(0).get_y(), bottom = trn.get_point(0).get_y();
    for (int i = 1; i < 3; i++)
    {
        if (trn.get_point(i).get_x() < left)
            left = trn.get_point(i).get_x();
        if (trn.get_point(i).get_x() > right)
            right = trn.get_point(i).get_x();
        if (trn.get_point(i).get_y() < bottom)
            bottom = trn.get_point(i).get_y();
        if (trn.get_point(i).get_y() > top)
            top = trn.get_point(i).get_y();
    }

    //Подготовка точек
    QVector<Point> points_to_draw = points;
    QVector<int> points_num;
    for (int i = 0; i < points.size(); i++) points_num.append(i);

    for (int i = 0; i < points_to_draw.size() - 1; i++)
    {
        for (int j = i + 1; j < points_to_draw.size(); j++)
        {
            if (points_to_draw[i] == points_to_draw[j])
            {
                points_to_draw.remove(j);
                points_num.remove(j);
                j--;
            }
        }
    }

    //маштабирование
    double padding = 1.1;
    double trn_width = right - left, trn_height = top - bottom;
    double height = scene->height(), width = scene->width();
    double k_x = width / (trn_width * padding), k_y = height / (trn_height * padding);
    double k = (k_x < k_y) ? k_x : k_y;
    trn.scale(k);
    for (auto &p: points_to_draw)
        p.scale(k, trn.get_center());

    //выравнивание
    left = trn.get_point(0).get_x();
    right = trn.get_point(0).get_x();
    top = trn.get_point(0).get_y();
    bottom = trn.get_point(0).get_y();
    for (int i = 1; i < 3; i++)
    {
        if (trn.get_point(i).get_x() < left)
            left = trn.get_point(i).get_x();
        if (trn.get_point(i).get_x() > right)
            right = trn.get_point(i).get_x();
        if (trn.get_point(i).get_y() < bottom)
            bottom = trn.get_point(i).get_y();
        if (trn.get_point(i).get_y() > top)
            top = trn.get_point(i).get_y();
    }
    double rect_x_center = (left + right) / 2, rect_y_center = (bottom + top) / 2;
    double x_center = width / 2, y_center = height / 2;
    double x_move = x_center - rect_x_center, y_move = y_center - rect_y_center;
    trn.move(x_move, y_move);
    for (auto &p: points_to_draw)
        p.move(x_move, y_move);

    //рисование
    QPen pen_sides(Qt::black, 1, Qt::SolidLine, Qt::FlatCap);
    for (int i = 0; i < 3; i++)
        DrawLine(trn.get_side(i), scene, pen_sides);

    QPen pen_h(Qt::red, 1, Qt::SolidLine, Qt::FlatCap);
    DrawLine(trn.get_min_h(), scene, pen_h);

    QPen pen_point(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap);
    QBrush brush_point = QBrush(QBrush(Qt::black, Qt::SolidPattern));
    for (int i = 0; i < points_to_draw.size(); i++)
    {
        if (points_to_draw[i].inRect(0, width, 0, height))
        {
            int num = points_num[i];
            QString msg = "%1 (%2, %3)";
            msg = msg.arg(num + 1).arg(points[num].get_x()).arg(points[num].get_y());
            DrawPoint(points_to_draw[i], scene, pen_point, brush_point, msg);
        }
    }

    QPen pen_H(Qt::red, 1, Qt::SolidLine, Qt::FlatCap);
    QBrush brush_H = QBrush(QBrush(Qt::black, Qt::SolidPattern));
    DrawPoint(trn.get_min_h().get_end(), scene, pen_H, brush_H, "H");
}
