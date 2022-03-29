#ifndef FIGURE_H
#define FIGURE_H

#include "GeometricFigures.h"

class Figure
{
private:
    Rectangle rect;
    Ellipse ellipses[2];
    Circle circles[2];
    Point figure_center;

    double draw_scale_k;

    void check_data(double width, double height, double ellipse_b);

public:
    Figure();

    Figure(double width, double height, double ellipse_b, const QRect &rect1);

    void draw(QGraphicsScene *scene, QPen &pen);

    void move(double dx, double dy);

    void scale(Point center, double kx, double ky);

    void rotate(Point center, double degree);

    Point get_center();
};

#endif
