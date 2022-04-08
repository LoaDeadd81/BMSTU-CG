#include "Geometry.h"

bool eq(Point_t &a, Point_t &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

void rotate(Point_t &p, Point_t &center, double rad)
{
    double dx = p.x - center.x, dy = p.y - center.y;
    p.x = center.x + dx * cos(rad) + dy * sin(rad);
    p.y = center.y - dx * sin(rad) + dy * cos(rad);
}

void scale(Circle &circle, double k)
{
    circle.r *= k;
}

void scale(Ellipse &ellipse, double k)
{
    ellipse.a *= k;
    ellipse.b *= k;
}
