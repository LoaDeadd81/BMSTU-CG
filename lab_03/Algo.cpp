#include "Algo.h"

void draw_point(int x, int y, Graph_t &graph)
{
    graph.scene->addLine(x, y, x, y, graph.pen);
}

int sign(double x)
{
    if (fabs(x) < EPS)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

void swap(double &a, double &b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}


double fpart(double a)
{
    return a - floor(a);
}

double rpart(double a)
{
    return 1 - fpart(a);
}


double to_rad(double degree)
{
    return degree * M_PI / 180.0;
}

void cda(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    steps = 0;
    if (eq(start, end))
    {
        if (graph.scene != nullptr) draw_point(start.x, start.y, graph);
        steps = 0;
        return;
    }

    double dx = end.x - start.x, dy = end.y - start.y, len = 0;
    bool xb = false;
    if (fabs(dx) >= fabs(dy))
    {
        len = fabs(dx);
        xb = true;
    }
    else
    {
        len = fabs(dy);
        xb = false;
    }
    double x_step = dx / len, y_step = dy / len;
    double xi = start.x, yi = start.y;
    for (int i = 0; i < len; i++)
    {
        int x = round(xi), y = round(yi);
        if (graph.scene != nullptr) draw_point(x, y, graph);
        if (xb && round(yi + y_step) > round(yi))
            steps++;
        else if (!xb && round(xi + y_step) > round(xi))
            steps++;
        xi += x_step;
        yi += y_step;
    }
}

void bres_float(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    steps = 0;
    if (eq(start, end))
    {
        if (graph.scene != nullptr) draw_point(start.x, start.y, graph);
        steps = 1;
        return;
    }

    double dx = end.x - start.x, dy = end.y - start.y;
    int sx = sign(dx), sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    bool swap = dy > dx;
    if (swap)
    {
        double tmp = dy;
        dy = dx;
        dx = tmp;
    }

    double m = dy / dx;
    double e = m - 0.5;
    int xi = round(start.x), yi = round(start.y);
    for (int i = 0; i < dx + 1; i++)
    {
        if (graph.scene != nullptr) draw_point(xi, yi, graph);
        if (e >= 0)
        {
            if (swap)
                xi += sx;
            else
                yi += sy;
            e -= 1;
            steps++;
        }
        if (swap)
            yi += sy;
        else
            xi += sx;
        e += m;
    }
}

void bres_int(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    steps = 0;
    if (eq(start, end))
    {
        if (graph.scene != nullptr) draw_point(start.x, start.y, graph);
        steps = 1;
        return;
    }

    int dx = end.x - start.x, dy = end.y - start.y;
    int sx = sign(dx), sy = sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swap = dy > dx;
    if (swap)
    {
        int tmp = dy;
        dy = dx;
        dx = tmp;
    }
    int e = 2 * dy - dx;
    int xi = round(start.x), yi = round(start.y);
    for (int i = 0; i < dx + 1; i++)
    {
        if (graph.scene != nullptr) draw_point(xi, yi, graph);
        if (e >= 0)
        {
            if (swap)
                xi += sx;
            else
                yi += sy;
            e -= 2 * dx;
            steps++;
        }
        if (swap)
            yi += sy;
        else
            xi += sx;
        e += 2 * dy;
    }
}

void bres_smooth(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    steps = 0;
    if (eq(start, end))
    {
        if (graph.scene != nullptr) draw_point(start.x, start.y, graph);
        steps = 1;
        return;
    }

    double dx = end.x - start.x, dy = end.y - start.y;
    int sx = sign(dx), sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    bool is_swap = dy > dx;
    if (is_swap)
        swap(dx, dy);

    double i_max = 1;
    double m = (i_max * dy) / dx, e = i_max / 2.0, w = i_max - m;
    int xi = round(start.x), yi = round(start.y);
    for (int i = 0; i < dx; i++)
    {
        QColor tmp_color = graph.pen.color();
        tmp_color.setAlphaF(i_max - e);
        graph.pen.setColor(tmp_color);
        if (graph.scene != nullptr) draw_point(xi, yi, graph);
        if (e <= w)
        {
            if (is_swap)
                yi += sy;
            else
                xi += sx;
            e += m;
        }
        else
        {
            yi += sy;
            xi += sx;
            e -= w;
            steps++;
        }
    }
}

void wu(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    steps = 0;

    double dx = end.x - start.x, dy = end.y - start.y;
    int sx = sign(dx), sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    if (dx == 0)
    {
        int x = start.x;
        int y = start.y;
        for (int i = 0; i < dy + 1; i++)
        {
            if (graph.scene != nullptr) draw_point(x, y, graph);
            y += sy;
        }
    }
    else if (dy == 0)
    {
        int x = start.x;
        int y = start.y;
        for (int i = 0; i < dx + 1; i++)
        {
            if (graph.scene != nullptr) draw_point(x, y, graph);
            x += sx;
        }
    }

    bool is_swap = dy > dx;
    if (is_swap)
    {
        swap(dx, dy);
        swap(sx, sy);
    }

    double m = dy / dx;
    double xi = is_swap ? start.y : start.x;
    double yi = is_swap ? start.x : start.y;
    for (int i = 0; i < dx + 1; i++)
    {
        double tmp_y = floor(yi);
        if (is_swap)
        {
            QColor tmp_color = graph.pen.color();

            tmp_color.setAlphaF(rpart(yi));
            graph.pen.setColor(tmp_color);
            if (graph.scene != nullptr) draw_point(tmp_y, xi, graph);

            tmp_color.setAlphaF(fpart(yi));
            graph.pen.setColor(tmp_color);
            if (graph.scene != nullptr) draw_point(tmp_y + 1, xi, graph);
        }
        else
        {
            QColor tmp_color = graph.pen.color();

            tmp_color.setAlphaF(rpart(yi));
            graph.pen.setColor(tmp_color);
            if (graph.scene != nullptr) draw_point(xi, tmp_y, graph);

            tmp_color.setAlphaF(fpart(yi));
            graph.pen.setColor(tmp_color);
            if (graph.scene != nullptr) draw_point(xi, tmp_y + 1, graph);
        }
        if (round(yi + m) > round(yi))
            steps++;
        xi += sx;
        yi += sy * m;
    }

}

void lib(Point_t &start, Point_t &end, Graph_t &graph, int &steps)
{
    graph.scene->addLine(start.x, start.y, end.x, end.y, graph.pen);
}

void spectre(Point_t &center, double len, double degree, Graph_t &graph, algorithm alg)
{
//    Point_t start = center, end = {center.x + len, center.y};
    Point_t start = center, end = {center.x, center.y - len};
    int count = 360 / degree;
    double d_fi = to_rad(degree);
    for (int i = 0; i < count; i++)
    {
        int tmp = 0;
        alg(start, end, graph, tmp);
        rotate(end, start, d_fi);
    }
}

double eff(algorithm alg)
{
//    Point_t start = center, end = {center.x + len, center.y};
    double len = 1000;
    Point_t start = {0, 0}, end = {len, 0};
    int count = 360;
    double d_fi = to_rad(1);
    Graph_t graph = {nullptr};

    double time_avg = 0;
    clock_t time = 0, start_time = 0, end_time = 0;

    for (int i = 0; i < count; i++)
    {
        int tmp = 0;
        start_time = clock();
        alg(start, end, graph, tmp);
        end_time = clock();
        time += end_time - start_time;
        rotate(end, start, d_fi);
    }
    std::cout << start_time << "   " << end_time << "   " << time << std::endl;
    time_avg = (double) time;
    time_avg /= count;
    time_avg /= CLOCKS_PER_SEC;
//    std::cout << time_avg << std::endl;
    return time_avg;
}

void steps(algorithm alg, QLineSeries *series)
{
    double len = 100;
    Point_t start = {0, 0}, end = {len, 0};
    int count = 90;
    double d_fi = to_rad(-1);
    Graph_t graph = {nullptr};
    for (int i = 0; i < count; i++)
    {
        int tmp = 0;
        alg(start, end, graph, tmp);
        series->append(i, tmp);
        rotate(end, start, d_fi);
    }
}
