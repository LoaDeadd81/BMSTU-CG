#include "GeometricFigures.h"

Rectangle::Rectangle()
{

}

//Rectangle::Rectangle(Point a, Point b, Point c, Point d)
//        : sides{Line(a, b), Line(b, c), Line(c, d), Line(d, a)},
//          rect_center(Line(a, c).get_center())
//{
//
//}

Rectangle::Rectangle(Point lb_apex, double width, double height)
{
    double x = lb_apex.get_x(), y = lb_apex.get_y();
    Point lt_apex = {x, y + height},
            rt_apex = {x + width, y + height},
            rb_apex = {x + width, y};
    Line left_side = {lb_apex, lt_apex},
            up_side = {lt_apex, rt_apex},
            right_side = {rt_apex, rb_apex},
            bottom_side = {rb_apex, lb_apex};
    sides[0] = left_side;
    sides[1] = up_side;
    sides[2] = right_side;
    sides[3] = bottom_side;

    double a = 2;
    rect_center = {x + width / a, y + height / a};
}

void Rectangle::draw(QGraphicsScene *scene, QPen &pen)
{
    for (auto side: sides)
        side.draw(scene, pen);
}

void Rectangle::move(double dx, double dy)
{
    for (auto &side: sides)
        side.move(dx, dy);
    rect_center.move(dx, dy);
}

void Rectangle::scale(Point center, double kx, double ky)
{
    for (auto &side: sides)
        side.scale(center, kx, ky);
    rect_center.scale(center, kx, ky);
}

void Rectangle::rotate(Point center, double degree)
{
    for (auto &side: sides)
        side.rotate(center, degree);
    rect_center.rotate(center, degree);
}

Line Rectangle::get_side(int i)
{
    if (i < 0 || i > 3)
        throw FigureError("Выход за пределы массива сторон.");
    return sides[i];
}

//Point Rectangle::get_center()
//{
//    double x = sides[0].get_center().get_x();
//    double y = sides[1].get_center().get_y();
//    return Point(x, y);
//}