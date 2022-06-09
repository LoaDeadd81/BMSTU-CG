#include "clipping.h"

//int vector_mult(const QVector2D &v1, const QVector2D &v2)
//{
//    return v1.x() * v2.y() - v1.y() * v2.x();
//}

int vector_mult(const QVector2D &v1, const QVector2D &v2)
{
    int tmp = v1.x() * v2.y() - v1.y() * v2.x();
    return v1.x() * v2.y() - v1.y() * v2.x();
}

int sign(int num)
{
    if (num == 0)
        return 0;
    return num / abs(num);
}

int is_visible(const QPoint &c1, const QPoint &c2, const QPoint &p)
{
    QVector2D v1(p.x() - c1.x(), p.y() - c1.y()), v2(c2.x() - c1.x(), c2.y() - c1.y());
    return sign(vector_mult(v1, v2));
}

bool is_intersectioning(const QPoint &p1, const QPoint &p2, const QPoint &c1, const QPoint &c2)
{
    return is_visible(c1, c2, p1) * is_visible(c1, c2, p2) <= 0;
}

QPoint intersection(const QPoint &p1, const QPoint &p2, const QPoint &c1, const QPoint &c2)
{
    QVector2D v1(p2.x() - p1.x(), p2.y() - p1.y()), v2(c1.x() - c2.x(), c1.y() - c2.y()),
            v3(c1.x() - p1.x(), c1.y() - p1.y());
    double det = vector_mult(v1, v2);
    double t = double (vector_mult(v3, v2)) / det;
    return p1 + (p2 - p1) * t;
}

QList<QPoint> clip(const QVector<QPoint> clipper, const QVector<QPoint> polygon, int dir)
{
    QVector<QPoint> res;
    QVector<QPoint> tmp_polygon = polygon;
    QVector<QPoint> tmp_clipper = clipper;
    tmp_clipper.append(clipper.first());
    QPoint first, start;
    for (int i = 0; i < tmp_clipper.size() - 1; i++)
    {
        for (int j = 0; j < tmp_polygon.size(); j++)
        {
            if (j == 0) first = tmp_polygon[j];
            else if (is_intersectioning(start, tmp_polygon[j], tmp_clipper[i], tmp_clipper[i + 1]))
                res.append(intersection(start, tmp_polygon[j], tmp_clipper[i], tmp_clipper[i + 1]));
            start = tmp_polygon[j];
            int tmp = is_visible(tmp_clipper[i], tmp_clipper[i + 1], start);
            if (is_visible(tmp_clipper[i], tmp_clipper[i + 1], start) * dir <= 0)
                res.append(start);
        }
        if (!res.empty() && is_intersectioning(start, first, tmp_clipper[i], tmp_clipper[i + 1]))
            res.append(intersection(start, first, tmp_clipper[i], tmp_clipper[i + 1]));
        if(res.empty())
        {
            tmp_polygon.clear();
            break;
        }
        tmp_polygon = res;
        res.clear();
    }
    return tmp_polygon;
}


//int scalar_mult(const QVector2D &v1, const QVector2D &v2);

//QLine get_new_line(const QLine &line, double t_start, double t_end);


//void get_n(QList<QVector2D> &n, int n_orientation, const QList<QVector2D> &clipper)
//{
//    for (const auto &item: clipper)
//    {
//        if (n_orientation == N_RIGHT)
//            n.append({item.y(), -item.x()});
//        else
//            n.append({-item.y(), item.x()});
//    }
//}

//int scalar_mult(const QVector2D &v1, const QVector2D &v2)
//{
//    return v1.x() * v2.x() + v1.y() * v2.y();
//}
//
//QLine get_new_line(const QLine &line, double t_start, double t_end)
//{
//    int x1 = round(line.x1() + double(line.x2() - line.x1()) * t_start),
//            y1 = round(line.y1() + double(line.y2() - line.y1()) * t_start),
//            x2 = round(line.x1() + double(line.x2() - line.x1()) * t_end),
//            y2 = round(line.y1() + double(line.y2() - line.y1()) * t_end);
//    return {x1, y1, x2, y2};
//}

