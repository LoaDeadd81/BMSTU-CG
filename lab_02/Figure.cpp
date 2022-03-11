#include "Figure.h"



void Figure::check_data(double width, double height, double ellipse_b)
{
    if (width <= 0)
        throw FigureError("Ширина прямоугольника должна быть больше нуля");
    if (height <= 0)
        throw FigureError("Высота прямоугольника должна быть больше нуля");
    if (ellipse_b <= 0)
        throw FigureError("Полуось эллипса должна быть больше нуля");
}

Figure::Figure()
{

}

Figure::Figure(double width, double height, double ellipse_b, QGraphicsScene *scene)
{
    check_data(width, height, ellipse_b);
    double num_of_figures_on_scene = 4, dots_per_2pi = 360;
    double sc_width = scene->width(), sc_height = scene->height();
    double width_k = sc_width / ((width + height / 2) * num_of_figures_on_scene),
            height_k = sc_height / ((height + ellipse_b) * num_of_figures_on_scene);
    double a = 2;
    figure_center = Point(sc_width / a, sc_height / a);
    draw_scale_k = (width_k < height_k) ? width_k : height_k;

    width *= draw_scale_k;
    height *= draw_scale_k;
    ellipse_b *= draw_scale_k;
    Point lb_apex = {figure_center.get_x() - width / a, figure_center.get_y() - height / a};
    rect = Rectangle(lb_apex, width, height);
    ellipses[0] = Ellipse::construct_by_horizontal_axis(rect.get_side(UP), ellipse_b, 0, 180, dots_per_2pi);
    ellipses[1] = Ellipse::construct_by_horizontal_axis(rect.get_side(DOWN), ellipse_b, 180, 360, dots_per_2pi);
    circles[0] = Circle(rect.get_side(LEFT).get_center(), height / a, 90, 270, dots_per_2pi);
    circles[1] = Circle(rect.get_side(RIGHT).get_center(), height / a, -90, 90, dots_per_2pi);
}

void Figure::draw(QGraphicsScene *scene, QPen &pen)
{
    scene->clear();
    QBrush brush_point = QBrush(QBrush(Qt::black, Qt::SolidPattern));
    figure_center.draw(scene, pen, brush_point, 4, draw_scale_k);

    rect.draw(scene, pen);
    ellipses[0].draw(scene, pen);
    ellipses[1].draw(scene, pen);
    circles[0].draw(scene, pen);
    circles[1].draw(scene, pen);
}

void Figure::move(double dx, double dy)
{
    if (fabs(dx) < 0.5 || fabs(dy) < 0.5)
        throw Chill("");

    dx *= draw_scale_k;
    dy *= draw_scale_k;

    rect.move(dx, dy);
    ellipses[0].move(dx, dy);
    ellipses[1].move(dx, dy);
    circles[0].move(dx, dy);
    circles[1].move(dx, dy);
    figure_center.move(dx, dy);
}

void Figure::scale(Point center, double kx, double ky)
{
    if (fabs(kx) < EPS || fabs(ky) < EPS)
        throw Chill("");

    center *= draw_scale_k;

    rect.scale(center, kx, ky);
    ellipses[0].scale(center, kx, ky);
    ellipses[1].scale(center, kx, ky);
    circles[0].scale(center, kx, ky);
    circles[1].scale(center, kx, ky);
    figure_center.scale(center, kx, ky);
}

void Figure::rotate(Point center, double degree)
{
    if (fabs(degree) < EPS)
        throw Chill("");

    center *= draw_scale_k;

    rect.rotate(center, degree);
    ellipses[0].rotate(center, degree);
    ellipses[1].rotate(center, degree);
    circles[0].rotate(center, degree);
    circles[1].rotate(center, degree);
    figure_center.rotate(center, degree);
}

Point Figure::get_center()
{
    return figure_center / draw_scale_k;
}
