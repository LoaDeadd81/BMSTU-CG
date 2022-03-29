#include "Primitives.h"

bool eq_double(double a, double b);

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
    msg = msg.arg((double) copy.x).arg((double) copy.get_y());
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
    if(*this == center)
        return;
    x = kx * x + (1 - kx) * center.get_x();
    y = ky * y + (1 - ky) * center.get_y();
}


void Point::rotate(Point center, double degree)
{
    if(*this == center)
        return;
    double radians = DegreeToRadians(degree);
    double dx = x - center.get_x(), dy = y - center.get_y();
    x = center.get_x() + dx * cos(radians) + dy * sin(radians);
    y = center.get_y() - dx * sin(radians) + dy * cos(radians);
}

bool Point::operator==(const Point &point) const
{
    return eq_double(x, point.x) && eq_double(y, point.y);
}

//bool Point::operator!=(const Point &point) const
//{
//    return !(*this == point);
//}

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

//Point Point::operator*(double k)
//{
//    Point a = *this;
//    return a *= k;;
//}

double DegreeToRadians(double degree)
{
    return degree * (M_PI / 180.0);
}

bool eq_double(double a, double b)
{
    if (fabs(a - b) < EPS)
        return true;
    return false;
}