#ifndef POINT_H
#define POINT_H

#include <cmath>

#define EPS 1e-3

typedef struct Point_t
{
    double x, y;
} Point_t;

bool eq(Point_t &a, Point_t &b);

void rotate(Point_t &p, Point_t &center, double rad);

#endif 
