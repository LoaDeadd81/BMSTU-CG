#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

#define EPS 1e-3

typedef struct Point_t
{
    double x, y;
} Point_t;

typedef struct Circle
{
    Point_t center;
    double r;
} Circle;

typedef struct Ellipse
{
    Point_t center;
    double a, b;
} Ellipse;

bool eq(Point_t &a, Point_t &b);

void rotate(Point_t &p, Point_t &center, double rad);

void scale(Circle &circle, double k);

void scale(Ellipse &ellipse, double k);

#endif 
