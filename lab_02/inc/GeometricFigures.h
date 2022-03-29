#ifndef GEOMETRICFIGURES_H
#define GEOMETRICFIGURES_H

#include "Primitives.h"

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

class Rectangle
{
private:
    Line sides[4];
    Point rect_center;
public:
    Rectangle();

//    Rectangle(Point a, Point b, Point c, Point d);

    Rectangle(Point lb_apex,double width,double height);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    Line get_side(int i);

//    Point get_center();

};

class Ellipse
{
private:
    Point ellipse_center;
    double a, b;
    QVector<Point> point_vec;

    Point get_start_point(Point center, double start_rad);

    Point get_next_point(Point center, Point cur_point, double d_fi_sin, double d_fi_cos);

public:
    Ellipse();

    Ellipse(Point center, double a, double b, double start, double end, double dots_per_2pi);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

//    static Ellipse
//    construct_by_vertical_axis(Line vertical_axis, double a, double start, double end, double dots_per_2pi);

    static Ellipse
    construct_by_horizontal_axis(Line horizontal_axis, double b, double start, double end, double dots_per_2pi);
};

class Circle : public Ellipse
{
public:
    Circle();

    Circle(Point center, double r, double start, double end, double dots_per_2pi);
};

#endif 
