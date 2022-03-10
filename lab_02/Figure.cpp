#include "Figure.h"

#define EPS 1e-4

double DegreeToRadians(double degree)
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

void Point::draw(QGraphicsScene *scene, QPen &pen, QBrush &brush, int r, double k)
{
    double height = scene->height();
    scene->addEllipse(x - r / 2, height - y - r / 2, r, r, pen, brush);
    QGraphicsTextItem *label;
    QFont font = QFont("sans", 14);
    QString msg = "(%1, %2)";
    Point copy = *this;
    copy /= k;
    msg = msg.arg(copy.x).arg(copy.get_y());
    label = scene->addText(msg, font);
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
    double radians = DegreeToRadians(degree);
    double dx = x - center.get_x(), dy = y - center.get_y();
    x = center.get_x() + dx * cos(radians) + dy * sin(radians);
    y = center.get_y() - dx * sin(radians) + dy * cos(radians);
}

bool Point::operator==(const Point &point) const
{
    return x == point.x && y == point.y;
}

bool Point::operator!=(const Point &point) const
{
    return !(*this == point);
}

Point &Point::operator/=(double k)
{
    this->x /= k;
    this->y /= k;
    return *this;
}

Point &Point::operator*=(double k)
{
    this->x *= k;
    this->y *= k;
    return *this;
}

Point Point::operator/(double k)
{
    Point a = *this;
    return a /= k;
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
    if(i < 0 || i > 3)
        throw FigureError("Выход за пределы массива сторон.");
    return sides[i];
}

Point Rectangle::get_center()
{
    double x = sides[0].get_center().get_x();
    double y = sides[1].get_center().get_y();
    return Point(x, y);
}

Ellipse::Ellipse()
{

}

Ellipse::Ellipse(Point center, double a, double b, double start, double end, double n)
        : ellipse_center(center), a(a), b(b)
{
    double start_rad = DegreeToRadians(start), end_rad = DegreeToRadians(end);
    int num_point = (n / 360.0) * fabs(end - start);
    double d_fi = fabs(end_rad - start_rad) / (num_point - 1);
    double d_fi_cos = cos(d_fi), d_fi_sin = sin(d_fi);

    double x1 = center.get_x() + a * cos(start_rad), y1 = center.get_y() + b * sin(start_rad);
    point_vec.append({x1, y1});
    double xi = center.get_x() + (x1 - center.get_x()) * d_fi_cos - (a / b) * (y1 - center.get_y()) * d_fi_sin,
            yi = center.get_y() + (b / a) * (x1 - center.get_x()) * d_fi_sin + (y1 - center.get_y()) * d_fi_cos;
    point_vec.append({xi, y1});

    for (int i = 0; i < num_point - 2; i++)
    {
        double x_tmp = center.get_x() + (xi - center.get_x()) * d_fi_cos - (a / b) * (yi - center.get_y()) * d_fi_sin,
                y_tmp = center.get_y() + (b / a) * (xi - center.get_x()) * d_fi_sin + (yi - center.get_y()) * d_fi_cos;
        point_vec.append({x_tmp, y_tmp});
        xi = x_tmp;
        yi = y_tmp;
    }
    int z = 0;
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

Figure::Figure()
{

}

Figure::Figure(double width, double height, double ellipse_b, QGraphicsScene *scene)
{
    double k = 4;
    if (width <= 0)
        throw FigureError("Ширина прямоугольника должна быть больше нуля");
    if (height <= 0)
        throw FigureError("Высота прямоугольника должна быть больше нуля");
    if (ellipse_b <= 0)
        throw FigureError("Полуось эллипса должна быть больше нуля");
    double sc_width = scene->width(), sc_height = scene->height();
    Point center(sc_width / 2.0, sc_height / 2.0);
    figure_center = center;
    double k_w = sc_width / ((width + height / 2) * k), k_h = sc_height / ((height + ellipse_b) * k);
    proport_k = (k_w < k_h) ? k_w : k_h;
    width /= 2.0;
    height /= 2.0;
    rect = Rectangle({center.get_x() - width * proport_k, center.get_y() - height * proport_k},
                               {center.get_x() - width * proport_k, center.get_y() + height * proport_k},
                               {center.get_x() + width * proport_k, center.get_y() + height * proport_k},
                               {center.get_x() + width * proport_k, center.get_y() - height * proport_k});
    ellipses[0] = Ellipse(rect.get_side(UP).get_center(), rect.get_side(UP).get_len() / 2.0,
                           ellipse_b * proport_k, 0,180, 360);
    ellipses[1] = Ellipse(rect.get_side(DOWN).get_center(), rect.get_side(DOWN).get_len() / 2.0,
                               ellipse_b * proport_k, 180,360, 360);
    circles[0] = Ellipse(rect.get_side(LEFT).get_center(), rect.get_side(LEFT).get_len() / 2.0,
                             rect.get_side(LEFT).get_len() / 2.0, 90,270, 360);
    circles[1] = Ellipse(rect.get_side(RIGHT).get_center(), rect.get_side(RIGHT).get_len() / 2.0,
                              rect.get_side(RIGHT).get_len() / 2.0, -90,90, 360);
}

void Figure::draw(QGraphicsScene *scene, QPen &pen)
{
    scene->clear();
    QBrush brush_point = QBrush(QBrush(Qt::black, Qt::SolidPattern));
    figure_center.draw(scene, pen, brush_point, 4, proport_k);
    rect.draw(scene, pen);
    ellipses[0].draw(scene, pen);
    ellipses[1].draw(scene, pen);
    circles[0].draw(scene, pen);
    circles[1].draw(scene, pen);
}

void Figure::move(double dx, double dy)
{
    if(dx < 0.5 || dy < 0.5)
        throw Chill("");
    dx *= proport_k;
    dy *= proport_k;
    rect.move(dx, dy);
    ellipses[0].move(dx, dy);
    ellipses[1].move(dx, dy);
    circles[0].move(dx, dy);
    circles[1].move(dx, dy);
    figure_center.move(dx, dy);
}

void Figure::scale(Point center, double kx, double ky)
{
    if(fabs(kx) < EPS || fabs(ky) < EPS)
        throw Chill("");
    center *= proport_k;
    rect.scale(center, kx, ky);
    ellipses[0].scale(center, kx, ky);
    ellipses[1].scale(center, kx, ky);
    circles[0].scale(center, kx, ky);
    circles[1].scale(center, kx, ky);
    figure_center.scale(center, kx, ky);
}

void Figure::rotate(Point center, double degree)
{
    if(fabs(degree) < EPS)
        throw Chill("");
    center *= proport_k;
    rect.rotate(center, degree);
    ellipses[0].rotate(center, degree);
    ellipses[1].rotate(center, degree);
    circles[0].rotate(center, degree);
    circles[1].rotate(center, degree);
    figure_center.rotate(center, degree);
}

Point Figure::get_center()
{
    return figure_center / proport_k;
}
