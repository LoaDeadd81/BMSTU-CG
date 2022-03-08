#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

#include <QVector>
#include <QString>

#include <cmath>

#include "MyErrors.h"

#include "Figure.h"

#define RECT 0
#define L_CIRCLE 1
#define R_CIRCLE 2
#define UP_ELIPSE 3
#define DOWN_ELIPSE 4

class Point
{
private:
    double x, y;
public:
    Point();

    Point(double x, double y);

    double get_x();

    double get_y();

    void draw(QGraphicsScene *scene, QPen &pen, QBrush &brush, int r);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    bool operator==(const Point &point) const;

    bool operator!=(const Point &point) const;
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

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);
};

class Shape
{
public:
    virtual void draw(QGraphicsScene *scene, QPen &pen) = 0;

    virtual void move(double dx, double dy) = 0;

    virtual void scale(Point center, double kx, double ky) = 0;

    virtual void rotate(Point center, double degree) = 0;
};

class Rectangle : public Shape
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

    Point get_center();

};

class Ellipse : public Shape
{
private:
    Point ellipse_center;
    double a, b;
    QVector<Point> point_vec;
public:
    Ellipse();

    Ellipse(Point a, Point b, Point c, Point d);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);
};

class Figure
{
private:
    QVector<Shape *> shapes_vec;
    Point figure_center;

public:
    Figure();

    Figure(Rectangle rect);

    void initial_draw(QGraphicsScene *scene, QPen &pen);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    void append(Shape *shape);

    void remove(int i);

    void set_default(QGraphicsScene *scene);

    ~Figure();
};

#endif
