#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <vector>
#include <cmath>

#include "MyErrors.h"
#include "Figure.h"

using namespace std;

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

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

    bool operator!=(const Point &point) const;

    Point &operator/=(double k);

    Point &operator*=(double k);

    Point operator/(double k);
};

class Line
{
private:
    Point begin, end;
public:
    Line();

    Line(Point begin, Point end);

    Point get_begin();

    Point get_end();

    Point get_center();

    double get_len();

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);
};

class Rectangle
{
private:
    Line sides[4];
    Point rect_center;
public:
    Rectangle();

    Rectangle(Point a, Point b, Point c, Point d);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    Line get_side(int i);

    Point get_center();

};

class Ellipse
{
private:
    Point ellipse_center;
    double a, b;
    QVector<Point> point_vec;
public:
    Ellipse();

    Ellipse(Point center, double a, double b, double start, double end, double n);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);
};

class Figure
{
private:
    Rectangle rect;
    Ellipse ellipses[2];
    Ellipse circles[2];
    Point figure_center;

    double proport_k;

public:
    Figure();

    Figure(double width, double height, double ellipse_b, QGraphicsScene *scene);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    Point get_center();
};

#endif
