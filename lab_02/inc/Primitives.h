#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>

#include "MyErrors.h"

#define EPS 1e-3

class Point
{
private:
    double x, y;
public:
    Point();

    Point(double x, double y);

    double get_x();

    double get_y();

    void draw(QGraphicsScene *scene, QPen &pen, QBrush &brush, int r, double k = 1);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    bool operator==(const Point &point) const;

//    bool operator!=(const Point &point) const;

    Point &operator/=(double k);

    Point &operator*=(double k);

    Point operator/(double k);

//    Point operator*(double k);
};

class Line
{
private:
    Point begin, end;
public:
    Line();

    Line(Point begin, Point end);

//    Point get_begin();

//    Point get_end();

    Point get_center();

    double get_len();

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);
};

double DegreeToRadians(double degree);


#endif 
