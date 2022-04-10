#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

#define EPS 1e-3

typedef struct Circle Circle_t;

typedef struct Ellipse Ellipse_t;

typedef struct Point_t
{
    int x, y;
} Point_t;

struct Circle
{
    Point_t center;
    int r;
};

struct Ellipse
{
    Point_t center;
    int a, b;
};

bool eq(Point_t &a, Point_t &b);

void rotate(Point_t &p, Point_t &center, double rad);

void scale(Circle_t &circle, double k);

void scale(Ellipse_t &ellipse, double k);

#endif 
