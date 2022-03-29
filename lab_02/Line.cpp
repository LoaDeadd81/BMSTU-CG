#include "Primitives.h"

Line::Line()
{

}

Line::Line(Point begin, Point end) : begin(begin), end(end)
{
    if (begin == end)
        throw LineError("Невозможно создать отрезок");
}

//Point Line::get_begin()
//{
//    return begin;
//}
//
//Point Line::get_end()
//{
//    return end;
//}

Point Line::get_center()
{
    double x = (begin.get_x() + end.get_x()) / 2.0, y = (begin.get_y() + end.get_y()) / 2.0;
    return Point(x, y);
}

double Line::get_len()
{
    double dx = end.get_x() - begin.get_x(), dy = end.get_y() - begin.get_y();
    return sqrt(dx * dx + dy * dy);
}

void Line::draw(QGraphicsScene *scene, QPen &pen)
{
    double height = scene->height();
    QLineF l(begin.get_x(), height - begin.get_y(), end.get_x(), height - end.get_y());
    scene->addLine(l, pen);
}

void Line::move(double dx, double dy)
{
    begin.move(dx, dy);
    end.move(dx, dy);
}

void Line::scale(Point center, double kx, double ky)
{
    begin.scale(center, kx, ky);
    end.scale(center, kx, ky);
}

void Line::rotate(Point center, double degree)
{
    begin.rotate(center, degree);
    end.rotate(center, degree);
}