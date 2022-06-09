#include "clipping.h"

#define EPS 1e-4

#define HORIZONTAL 0
#define VERTICAL 1
#define GENERAL 2

#define VISIBLE 0
#define INVISIBLE 1
#define PARTLY_VISIBLE 2

#define TOP 0
#define BOTTOM 1
#define RIGHT 2
#define LEFT 3

void get_code(int code[4], const QPoint &point, const QRect &clipper);

int check_visible(int code1[4], int code2[4]);

void swap(QPoint &p1, QPoint &p2);

QPoint find_intersection(int edge_selector, double m, const QPoint &point, const QRect &clipper);

void find_visible_segment(bool &is_visible, QLine &line, const QRect &clipper)
{
    QPoint p1 = line.p1(), p2 = line.p2();
    double m = 0;
    int pos_flag = GENERAL;
    if (p2.x() - p1.x() == 0)
        pos_flag = HORIZONTAL;
    else
    {
        m = double(p2.y() - p1.y()) / (p2.x() - p1.x());
        if (fabs(m) < EPS) pos_flag = VERTICAL;
    }
    is_visible = true;
    for (int i = 0; i < 4; i++)
    {
        int code1[4], code2[4];
        get_code(code1, p1, clipper);
        get_code(code2, p2, clipper);
        int visible_status = check_visible(code1, code2);
        if (visible_status != PARTLY_VISIBLE)
        {
            if(visible_status == INVISIBLE) is_visible = false;
            break;
        }
        if (code1[i] == code2[i]) continue;
        if (code1[i] == 0) swap(p1, p2);
        if (!(pos_flag == HORIZONTAL && i < 2 || pos_flag == VERTICAL && i >= 2))
            p1 = find_intersection(i, m, p1, clipper);
    }
    line = {p1, p2};
}


void get_code(int *code, const QPoint &point, const QRect &clipper)
{
    code[0] = (point.y() > clipper.top()) ? 1 : 0;
    code[1] = (point.y() < clipper.bottom()) ? 1 : 0;
    code[2] = (point.x() > clipper.right()) ? 1 : 0;
    code[3] = (point.x() < clipper.left()) ? 1 : 0;
}

int code_sum(const int code[4]);

int code_and(const int code1[4], const int code2[4]);

int check_visible(int *code1, int *code2)
{
    if (code_sum(code1) == 0 && code_sum(code2) == 0) return VISIBLE;
    if (code_and(code1, code2) != 0) return INVISIBLE;
    return PARTLY_VISIBLE;
}

void swap(QPoint &p1, QPoint &p2)
{
    QPoint tmp = p1;
    p1 = p2;
    p2 = tmp;
}

QPoint top_intersection(double m, const QPoint &point, const QRect &clipper);

QPoint bottom_intersection(double m, const QPoint &point, const QRect &clipper);

QPoint right_intersection(double m, const QPoint &point, const QRect &clipper);

QPoint left_intersection(double m, const QPoint &point, const QRect &clipper);

QPoint find_intersection(int edge_selector, double m, const QPoint &point, const QRect &clipper)
{
    QPoint res;
    switch (edge_selector)
    {
        case TOP:
            res = top_intersection(m, point, clipper);
            break;
        case BOTTOM:
            res = bottom_intersection(m, point, clipper);
            break;
        case RIGHT:
            res = right_intersection(m, point, clipper);
            break;
        case LEFT:
            res = left_intersection(m, point, clipper);
            break;
        default:
            break;
    }
    return res;
}

int code_sum(const int *code)
{
    int sum = 0;
    for (int i = 0; i < 4; i++) sum += code[i];
    return sum;
}

int code_and(const int *code1, const int *code2)
{
    int res = 0;
    for (int i = 0; i < 4; i++) res += code1[i] * code2[i];
    return res;
}

QPoint top_intersection(double m, const QPoint &point, const QRect &clipper)
{
    int y = clipper.top(),
            x = point.x() + round((1.0 / m) * double(clipper.top() - point.y()));
    return {x, y};
}

QPoint bottom_intersection(double m, const QPoint &point, const QRect &clipper)
{
    int y = clipper.bottom(),
            x = point.x() + round((1.0 / m) * double(clipper.bottom() - point.y()));
    return {x, y};
}

QPoint right_intersection(double m, const QPoint &point, const QRect &clipper)
{
    int x = clipper.right(),
            y = round(m * double(clipper.right() - point.x())) + point.y();
    return {x, y};
}

QPoint left_intersection(double m, const QPoint &point, const QRect &clipper)
{
    int x = clipper.left(),
            y = round(m * double(clipper.left() - point.x())) + point.y();
    return {x, y};
}


