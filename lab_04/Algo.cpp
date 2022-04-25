#include "Algo.h"


double rad(double degree)
{
    return degree * M_PI / 180.0;
}

void horizontal_step_circle(int &x, int &y, int &delta);

void diagonal_step_circle(int &x, int &y, int &delta);

void vertical_step_circle(int &x, int &y, int &delta);

void horizontal_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b);

void diagonal_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b);

void vertical_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b);

void draw_point(int x, int y, Graph_t &graph)
{
    graph.scene->addLine(x, y, x, y, graph.pen);
}

void draw_ellipse_point_sym(Point_t center, int x, int y, Graph_t &graph)
{
    draw_point(center.x + x, center.y + y, graph);
    draw_point(center.x + x, center.y - y, graph);
    draw_point(center.x - x, center.y - y, graph);
    draw_point(center.x - x, center.y + y, graph);
}

void draw_circle_point_sym(Point_t center, int x, int y, Graph_t &graph)
{
    draw_point(center.x + x, center.y + y, graph);
    draw_point(center.x + x, center.y - y, graph);
    draw_point(center.x - x, center.y - y, graph);
    draw_point(center.x - x, center.y + y, graph);

    draw_point(center.x + y, center.y + x, graph);
    draw_point(center.x + y, center.y - x, graph);
    draw_point(center.x - y, center.y - x, graph);
    draw_point(center.x - y, center.y + x, graph);
}

void ellipse_param_draw(Ellipse_t &ellipse, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double d_fi = (ellipse.a >= ellipse.b) ? 1.0 / ellipse.a : 1.0 / ellipse.b;
    double end = rad(90);
    for (double i = 0; i <= end; i += d_fi)
    {
        int x = round(ellipse.a * cos(i)),
                y = round(ellipse.b * sin(i));
        if (draw_access) draw_ellipse_point_sym(ellipse.center, x, y, graph);
    }
}

void ellipse_canon_draw(Ellipse_t &ellipse, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double a_sqr = ellipse.a * ellipse.a, b_sqr = ellipse.b * ellipse.b,
            coeff1 = b_sqr / a_sqr, coeff2 = a_sqr / b_sqr;
    double border_x = a_sqr / sqrtl(a_sqr + b_sqr),
            border_y = b_sqr / sqrtl(a_sqr + b_sqr);

    for (int i = 0; i <= border_x; i++)
    {
        int x = i, y = round(sqrtl(b_sqr - coeff1 * x * x));
        if (draw_access)draw_ellipse_point_sym(ellipse.center, x, y, graph);
    }
    for (int i = 0; i <= border_y; i++)
    {
        int y = i, x = round(sqrtl(a_sqr - coeff2 * y * y));
        if (draw_access)draw_ellipse_point_sym(ellipse.center, x, y, graph);
    }
}

void ellipse_bres_draw(Ellipse_t &ellipse, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    int x = 0, y = ellipse.b;
    int sqr_a = ellipse.a * ellipse.a, sqr_b = ellipse.b * ellipse.b;
    int delta = sqr_b + (1 - 2 * ellipse.b) * sqr_a;
    while (y >= 0)
    {
        if (draw_access) draw_ellipse_point_sym(ellipse.center, x, y, graph);
        if (delta == 0) diagonal_step_ellipse(x, y, delta, sqr_a, sqr_b);
        else if (delta < 0)
        {
            long long sigma = 2 * delta + (2 * y - 1) * sqr_a;
            if (sigma <= 0) horizontal_step_ellipse(x, y, delta, sqr_a, sqr_b);
            else diagonal_step_ellipse(x, y, delta, sqr_a, sqr_b);
        }
        else if (delta > 0)
        {
            long long sigma = 2 * delta + (-2 * x - 1) * sqr_b;
            if (sigma <= 0) diagonal_step_ellipse(x, y, delta, sqr_a, sqr_b);
            else vertical_step_ellipse(x, y, delta, sqr_a, sqr_b);
        }
    }
}

void ellipse_mid_point_draw(Ellipse_t &ellipse, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double a_sqr = ellipse.a * ellipse.a, b_sqr = ellipse.b * ellipse.b,
            border = a_sqr / sqrt(a_sqr + b_sqr);
    int aa = 2 * a_sqr, bb = 2 * b_sqr, delta = -aa * ellipse.b;
    int x = 0, y = ellipse.b;
    double df = 0, f = b_sqr - a_sqr * y + 0.25 * a_sqr + 0.5;
    for (x = 0; x <= border; x++)
    {
        if (draw_access) draw_ellipse_point_sym(ellipse.center, x, y, graph);
        if (f >= 0)
        {
            y -= 1;
            delta += aa;
            f += delta;
        }
        df += bb;
        f += df + b_sqr;
    }

    delta = bb * x;
    f += -b_sqr * (x + 0.75) - a_sqr * (y - 0.75);
    df = -aa * y;
    for (; y >= 0; y--)
    {
        if (draw_access) draw_ellipse_point_sym(ellipse.center, x, y, graph);
        if (f < 0)
        {
            x += 1;
            delta += bb;
            f += delta;
        }
        df += aa;
        f += df + a_sqr;
    }
}

void ellipse_lib_draw(Ellipse_t &ellipse, Graph_t &graph)
{
    double x = ellipse.center.x - ellipse.a,
            y = ellipse.center.y - ellipse.b;
    graph.scene->addEllipse(x, y, ellipse.a * 2, ellipse.b * 2, graph.pen);
}

void circle_param_draw(Circle_t &circle, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double d_fi = 1.0 / circle.r;
    double end = rad(45);
    for (double i = 0; i <= end; i += d_fi)
    {
        int x = round(circle.r * cos(i)),
                y = round(circle.r * sin(i));
        if (draw_access) draw_circle_point_sym(circle.center, x, y, graph);
    }
}

void circle_canon_draw(Circle_t &circle, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double r_sqr = circle.r * circle.r;
    for (int i = 0; i <= circle.r / sqrt(2); i++)
    {
        int x = i, y = round(sqrt(r_sqr - x * x));
        if (draw_access) draw_circle_point_sym(circle.center, x, y, graph);
    }
}

void circle_bres_draw(Circle_t &circle, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    double border = circle.r / sqrt(2);
    int x = 0, y = circle.r, delta = 2 * (1 - circle.r);
    while (x <= border)
    {
        if (draw_access) draw_circle_point_sym(circle.center, x, y, graph);
        if (delta < 0)
        {
            int sigma = 2 * (delta + y) - 1;
            if (sigma <= 0) horizontal_step_circle(x, y, delta);
            else diagonal_step_circle(x, y, delta);
        }
        else if (delta > 0)
        {
            int sigma = 2 * (delta - x) - 1;
            if (sigma <= 0) diagonal_step_circle(x, y, delta);
            else vertical_step_circle(x, y, delta);
        }
        else diagonal_step_circle(x, y, delta);
    }

}

void circle_mid_point_draw(Circle_t &circle, Graph_t &graph)
{
    bool draw_access = graph.scene != nullptr;
    int x = 0, y = circle.r;
    double f = 5.0 / 4.0 - circle.r;
    while (x <= y)
    {
        if (draw_access)draw_circle_point_sym(circle.center, x, y, graph);
        x++;
        if (f < 0)
            f += 2 * x + 1;
        else
        {
            y--;
            f += 2 * (x - y) + 1;
        }
    }
}

void circle_lib_draw(Circle_t &circle, Graph_t &graph)
{
    double x = circle.center.x - circle.r,
            y = circle.center.y - circle.r;
    graph.scene->addEllipse(x, y, circle.r * 2, circle.r * 2, graph.pen);
}

void horizontal_step_circle(int &x, int &y, int &delta)
{
    x++;
    delta += 2 * x + 1;
}

void diagonal_step_circle(int &x, int &y, int &delta)
{
    x++;
    y--;
    delta += 2 * (x - y + 1);
}

void vertical_step_circle(int &x, int &y, int &delta)
{
    y--;
    delta += -2 * y + 1;
}

void horizontal_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b)
{
    x++;
    delta += (2 * x + 1) * sqr_b;
}

void diagonal_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b)
{
    x++;
    y--;
    delta += (2 * x + 1) * sqr_b + (-2 * y + 1) * sqr_a;
}

void vertical_step_ellipse(int &x, int &y, int &delta, int sqr_a, int sqr_b)
{
    y--;
    delta += (-2 * y + 1) * sqr_a;
}
