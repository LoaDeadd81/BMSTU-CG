#include "Support.h"

#define EPS 1e-4

int vec_mult(const QVector2D &v1, const QVector2D &v2)
{
    return v1.x() * v2.y() - v1.y() * v2.x();
}

QVector2D qline_to_qvector2d(const QLine &clipper)
{
    float dx = clipper.p2().x() - clipper.p1().x(), dy = clipper.p2().y() - clipper.p1().y();
    return {dx, dy};
}

void qlines_to_qvector2ds(QVector<QVector2D> &vectors, const QVector<QLine> &clipper)
{
    for (const auto &item: clipper) vectors.append(qline_to_qvector2d(item));
}

void qpointss_to_qliness(QVector<QLine> &vectors, const QVector<QPoint> &clipper)
{
    auto it = clipper.begin();
    auto start = it, end = ++it;
    while (end != clipper.end())
    {
        vectors.append({*start, *end});
        start++;
        end++;
    }
    vectors.append({*start, clipper.first()});
}

bool convexity_check(int &n_orientation, const QVector<QVector2D> &clipper)
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

bool line_intersection(QLine a, QLine b)
{
    int dx1 = a.x2() - a.x1(), dy1 = a.y2() - a.y1();
    int dx2 = b.x2() - b.x1(), dy2 = b.y2() - b.y1();
    int dxx = a.x1() - b.x1(), dyy = a.y1() - b.y1();
    int div, mul;

    div = (dy2 * dx1 - dx2 * dy1);
    if (div == 0)
        return false;
    if (div > 0)
    {
        mul = dx1 * dyy - dy1 * dxx;
        if (mul < 0 || mul > div)
            return false;
        mul = dx2 * dyy - dy2 * dxx;
        if (mul < 0 || mul > div)
            return false;
    }
    mul = dx1 * dyy - dy1 * dxx;
    if (mul < 0 || mul > -div)
        return false;
    mul = dx2 * dyy - dy2 * dxx;
    if (mul < 0 || mul > -div)
        return false;

    return true;
}

bool self_intersection_check(const QVector<QLine> clipper)
{
    bool res = false;
    for (auto i = clipper.begin(); !res && i != clipper.end(); i++)
        for (auto j = i + 1; !res && j != clipper.end(); j++)
            res = line_intersection(*i, *j);
    return res;
}
