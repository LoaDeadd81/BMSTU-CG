#include "GeometricFigures.h"

Point Ellipse::get_start_point(Point center, double start_rad)
{
    double x = center.get_x() + a * cos(start_rad),
            y = center.get_y() + b * sin(start_rad);
    return {x, y};
}

Point Ellipse::get_next_point(Point center, Point cur_point, double d_fi_sin, double d_fi_cos)
{
    double x = center.get_x() + (cur_point.get_x() - center.get_x()) * d_fi_cos -
               (a / b) * (cur_point.get_y() - center.get_y()) * d_fi_sin,
            y = center.get_y() + (b / a) * (cur_point.get_x() - center.get_x()) * d_fi_sin +
                (cur_point.get_y() - center.get_y()) * d_fi_cos;
    return {x, y};
}

Ellipse::Ellipse()
{

}

Ellipse::Ellipse(Point center, double a, double b, double start, double end, double dots_per_2pi)
        : ellipse_center(center), a(a), b(b)
{
    double start_rad = DegreeToRadians(start), end_rad = DegreeToRadians(end);
    int num_point = (dots_per_2pi / 360.0) * fabs(end - start);
    double d_fi = fabs(end_rad - start_rad) / (num_point - 1);
    double d_fi_cos = cos(d_fi), d_fi_sin = sin(d_fi);

    Point start_point = get_start_point(center, start_rad);
    Point cur_point = get_next_point(center, start_point, d_fi_sin, d_fi_cos);
    point_vec.append(start_point);
    point_vec.append(cur_point);

    for (int i = 0; i < num_point - 2; i++)
    {
        Point next_point = get_next_point(center, cur_point, d_fi_sin, d_fi_cos);;
        point_vec.append(next_point);
        cur_point = next_point;
    }
}

void Ellipse::draw(QGraphicsScene *scene, QPen &pen)
{
    for (int i = 0; i < point_vec.size() - 1; i++)
    {
        Line tmp({point_vec.at(i), point_vec.at(i + 1)});
        tmp.draw(scene, pen);
    }
}

void Ellipse::move(double dx, double dy)
{
    for (auto &item: point_vec)
        item.move(dx, dy);
    ellipse_center.move(dx, dy);
}

void Ellipse::scale(Point center, double kx, double ky)
{
    for (auto &item: point_vec)
        item.scale(center, kx, ky);
    ellipse_center.scale(center, kx, ky);
}

void Ellipse::rotate(Point center, double degree)
{
    for (auto &item: point_vec)
        item.rotate(center, degree);
    ellipse_center.rotate(center, degree);
}

//Ellipse Ellipse::construct_by_vertical_axis(Line vertical_axis, double a, double start, double end, double dots_per_2pi)
//{
//    Point center = vertical_axis.get_center();
//    double b = vertical_axis.get_len() / (double) 2.0;
//    return Ellipse(center, a, b, start, end, dots_per_2pi);
//}

Ellipse
Ellipse::construct_by_horizontal_axis(Line horizontal_axis, double b, double start, double end, double dots_per_2pi)
{
    Point center = horizontal_axis.get_center();
    double a = horizontal_axis.get_len() / (double) 2.0;
    return Ellipse(center, a, b, start, end, dots_per_2pi);
}