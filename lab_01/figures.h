#ifndef FIGURES_H
#define FIGURES_H

#include <cmath>
#include <QVector>

#include "myerrors.h"

#define EPS 1e-4

class Point
{
private:
    double x, y;
public:
    Point();

    Point(double x, double y);

    bool operator==(const Point &dot) const;

    bool operator!=(const Point &dot) const;

    void set_x(double x);

    void set_y(double y);

    double get_x() const;

    double get_y() const;
};

double LenBetweenPoints(Point a, Point b);


class Line
{
private:
    Point begin;
    Point end;
    double len;
public:
    Line();

    Line(Point begin, Point end);

    const Point &getBegin() const;

    const Point &getAnEnd() const;

    double getLen() const;

    void setBegin(const Point &begin);

    void setAnEnd(const Point &anEnd);
};


class Triangle
{
private:
    Point points[3];
    Line sides[3];
    Line min_h;
public:
    Triangle(Point a, Point b, Point c);

    Point get_point(int i);

    Line get_side(int i);

    Line get_min_h();
};

Triangle search_triangle(QVector<Point> points_vec);

#endif // FIGURES_H
