#include "clipping.h"

#define EPS 1e-4

int vec_mult(const QVector2D &v1, const QVector2D &v2);

int scalar_mult(const QVector2D &v1, const QVector2D &v2);

QLine get_new_line(const QLine &line, double t_start, double t_end);

QVector2D qline_to_qvector2d(const QLine &clipper)
{
    float dx = clipper.p2().x() - clipper.p1().x(), dy = clipper.p2().y() - clipper.p1().y();
    return {dx, dy};
}

void qline_to_qvector2d(QList<QVector2D> &vectors, const QList<QLine> &clipper)
{
    for (const auto &item: clipper) vectors.append(qline_to_qvector2d(item));
}

bool convexity_check(int &n_orientation, const QList<QVector2D> &clipper)
{
    QVector<int> vec_mult_res(clipper.size());
    for (int i = 0; i < clipper.size(); i++)
    {
        int j = i + 1;
        if (i == clipper.size() - 1) j = 0;
        vec_mult_res[i] = vec_mult(clipper[i], clipper[j]);
    }
    int flag = true, res = true;
    int sign = 0;
    for (int item: vec_mult_res)
    {
        if (item != 0)
        {
            if (flag)
            {
                sign = (item < 0) ? -1 : 1;
                flag = false;
            }
            else if (item < 0 && sign > 0 || item > 0 && sign < 0)
            {
                res = false;
                break;
            }
        }
    }
    if (flag == true) n_orientation = NO_N;
    else n_orientation = (sign < 0) ? N_RIGHT : N_LEFT;
    return res;
}

void get_n(QList<QVector2D> &n, int n_orientation, const QList<QVector2D> &clipper)
{
    for (const auto &item: clipper)
    {
        if (n_orientation == N_RIGHT)
            n.append({item.y(), -item.x()});
        else
            n.append({-item.y(), item.x()});
    }
}

QLine find_visible_segment(bool &is_visible, const QLine &line, const QList<QVector2D> &n, const QList<QLine> &clipper)
{
    QLine res = QLine();
    double t_start = 0, t_end = 1;
    QVector2D d(line.x2() - line.x1(), line.y2() - line.y1());
    is_visible = true;
    for (int i = 0; i < clipper.size(); i++)
    {
        QVector2D w(line.x1() - clipper[i].x2(), line.y1() - clipper[i].y2());
        int d_sk = scalar_mult(d, n[i]), w_sk = scalar_mult(w, n[i]);
        if (fabs(d.length()) < EPS && w_sk < 0)
        {
            is_visible = false;
            break;
        }
        if (d_sk == 0)
        {
            if (w_sk < 0)
            {
                is_visible = false;
                break;
            }
            else continue;
        }
        double t = -double(w_sk) / double(d_sk);
        if (d_sk > 0)
        {
            if (t > 1)
            {
                is_visible = false;
                break;
            }
            else t_start = (t > t_start) ? t : t_start;
        }
        else
        {
            if (t < 0)
            {
                is_visible = false;
                break;
            }
            else t_end = (t < t_end) ? t : t_end;
        }
    }
    if (t_start > t_end) is_visible = false;
    if (is_visible) res = get_new_line(line, t_start, t_end);
    return res;
}

int vec_mult(const QVector2D &v1, const QVector2D &v2)
{
    return v1.x() * v2.y() - v1.y() * v2.x();
}

int scalar_mult(const QVector2D &v1, const QVector2D &v2)
{
    return v1.x() * v2.x() + v1.y() * v2.y();
}

QLine get_new_line(const QLine &line, double t_start, double t_end)
{
    int x1 = round(line.x1() + double(line.x2() - line.x1()) * t_start),
            y1 = round(line.y1() + double(line.y2() - line.y1()) * t_start),
            x2 = round(line.x1() + double(line.x2() - line.x1()) * t_end),
            y2 = round(line.y1() + double(line.y2() - line.y1()) * t_end);
    return {x1, y1, x2, y2};
}
