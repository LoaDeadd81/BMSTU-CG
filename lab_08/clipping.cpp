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

bool line_intersection(QLine a, QLine b)
{
//    int dx1 = a.x2() - a.x1(), dy1 = a.y2() - a.y1();
//    int dx2 = b.x2() - b.x1(), dy2 = b.y2() - b.y1();
//    int dxx = a.x1() - b.x1(), dyy = a.y1() - b.y1();
//    int div, mul;
//
//    int maxx1 = fmax(a.x1(), a.x2()), maxy1 = fmax(a.y1(), a.y2());
//    int minx1 = fmin(a.x1(), a.x2()), miny1 = fmin(a.y1(), a.y2());
//    int maxx2 = fmax(b.x1(), b.y2()), maxy2 = fmax(b.y1(), b.y2());
//    int minx2 = fmin(b.x1(), b.y2()), miny2 = fmin(b.y1(), b.y2());
//
//    if (minx1 > maxx2 || maxx1 < minx2 || miny1 > maxy2 || maxy1 < miny2)
//        return false;
//
//    div = (dy2 * dx1 - dx2 * dy1);
//    if (div == 0)
//        return false;
//    if (div > 0)
//    {
//        mul = dx1 * dyy - dy1 * dxx;
//        if (mul < 0 || mul > div)
//            return false;
//        mul = dx2 * dyy - dy2 * dxx;
//        if (mul < 0 || mul > div)
//            return false;
//    }
//    mul = dx1 * dyy - dy1 * dxx;
//    if (mul < 0 || mul > -div)
//        return false;
//    mul = dx2 * dyy - dy2 * dxx;
//    if (mul < 0 || mul > -div)
//        return false;
//
//    return true;

    double x1 = a.x1(), y1 = a.y1(), x2 = a.x2(), y2 = a.y2();
    double x3 = b.x1(), y3 = b.y1(), x4 = b.x2(), y4 = b.y2();
    double t1_ch = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3),
            t2_ch = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3),
        zn = (y4 - y3) * (x2 - x1) - (x4 - x3)*(y2 -  y1);
    if(zn == 0)
    {
        if(t1_ch == 0)
            return true;
        return false;
    }
    double t1 = t1_ch / zn, t2 = t2_ch / zn;
    if((t1 > 0 && t1 < 1) && (t2 > 0 && t2 < 1)) return true;
    return false;

}

bool self_intersection_check(const QList<QLine> clipper)
{
    bool res = false;
    for (auto i = clipper.begin(); !res && i != clipper.end(); i++)
        for (auto j = i + 1; !res && j != clipper.end(); j++)
            res = line_intersection(*i, *j);
    return res;
}
