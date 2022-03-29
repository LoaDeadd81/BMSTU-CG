#include "GeometricFigures.h"

Circle::Circle()
{

}

Circle::Circle(Point center, double r, double start, double end, double dots_per_2pi)
        : Ellipse(center, r, r, start, end, dots_per_2pi)
{

}