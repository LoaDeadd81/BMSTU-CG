#include "Figure.h"

double DegreToRadians(double degree)
{
    return degree * (M_PI / 180.0);
}

Point::Point()
{

}

Point::Point(double x, double y) : x(x), y(y)
{

}

double Point::get_x()
{
    return x;
}

double Point::get_y()
{
    return y;
}

void Point::draw(QGraphicsScene *scene, QPen &pen, QBrush &brush, int r)
{
    double height = scene->height();
    scene->addEllipse(x - r / 2, height - y - r / 2, r, r, pen, brush);
    QGraphicsTextItem *label;
    QFont font = QFont("sans", 12);
    label = scene->addText("msg", font);
    label->setX(x - label->boundingRect().width() / 2);
    label->setY(height - y - 2 - label->boundingRect().height());
}

void Point::move(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Point::scale(Point center, double kx, double ky)
{
    x = kx * x + (1 - kx) * center.get_x();
    y = ky * y + (1 - ky) * center.get_y();
}

void Point::rotate(Point center, double degree)
{
    double radians = DegreToRadians(degree);
    x = center.get_x() + (x - center.get_x()) * cos(radians)
        + (y - center.get_y()) * sin(radians);
}

bool Point::operator==(const Point &point) const
{
    return x == point.x && y == point.y;
}

bool Point::operator!=(const Point &point) const
{
    return !(*this == point);
}

Line::Line()
{

}

Line::Line(Point begin, Point end) : begin(begin), end(end)
{
    if (begin == end)
        throw LineError("Невозможно создать отрезок");
}

Point Line::get_begin()
{
    return begin;
}

Point Line::get_end()
{
    return end;
}

Point Line::get_center()
{
    double x = (begin.get_x() + end.get_x()) / 2.0, y = (begin.get_y() + end.get_y()) / 2.0;
    return Point(x, y);
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

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(Point a, Point b, Point c, Point d)
        : sides{Line(a, b), Line(b, c), Line(c, d), Line(d, a)},
          rect_center(Line(a, c).get_center())
{

}

void Rectangle::draw(QGraphicsScene *scene, QPen &pen)
{
    for (auto &side: sides)
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

Point Rectangle::get_center()
{
    double x = sides[0].get_center().get_x();
    double y = sides[1].get_center().get_y();
    return Point(x, y);
}

Figure::Figure()
{

}

Figure::Figure(Rectangle rect)
{
    Rectangle *cur_rect = new Rectangle(rect);
    shapes_vec.append(cur_rect);
}



void Figure::draw(QGraphicsScene *scene, QPen &pen)
{
    scene->clear();
    for (auto item: shapes_vec)
        item->draw(scene, pen);
}

void Figure::move(double dx, double dy)
{
    for (auto item: shapes_vec)
        item->move(dx, dy);
}

void Figure::scale(Point center, double kx, double ky)
{
    for (auto item: shapes_vec)
        item->scale(center, kx, ky);
}

void Figure::rotate(Point center, double degree)
{
    for (auto item: shapes_vec)
        item->rotate(center, degree);
}

void Figure::append(Shape *shape)
{
    shapes_vec.push_back(shape);
}

void Figure::remove(int i)
{
    shapes_vec.remove(i);
}

void Figure::set_default(QGraphicsScene *scene)
{
    double default_width = 50, default_height = 30;
    double default_k = 2;
    double width = scene->width(), height = scene->height();
    Point center(width / 2.0, height / 2.0);
    double k_w = width / (default_width * 2 * default_k), k_h = height / (default_height * 2 * default_k);
    double k = (k_w < k_h) ? k_w : k_h;
    auto *rect = new Rectangle({center.get_x() - default_width * k, center.get_y() - default_height * k},
                               {center.get_x() - default_width * k, center.get_y() + default_height * k},
                               {center.get_x() + default_width * k, center.get_y() + default_height * k},
                               {center.get_x() + default_width * k, center.get_y() - default_height * k});
    shapes_vec.append(rect);
}

Figure::~Figure()
{
    for (auto item: shapes_vec)
        delete item;
}
