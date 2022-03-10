#include "figures.h"

Point::Point() : x(0), y(0)
{}

Point::Point(double x, double y) : x(x), y(y)
{};

void Point::set_x(double x)
{
    this->x = x;
}

void Point::set_y(double y)
{
    this->y = y;
}

double Point::get_x() const
{
    return this->x;
}


double Point::get_y() const
{
    return this->y;
}

bool Point::operator==(const Point &dot) const
{
    return x == dot.x && y == dot.y;
}

bool Point::operator!=(const Point &dot) const
{
    return !(*this == dot);
}

double LenBetweenPoints(Point a, Point b)
{
    double x = a.get_x() - b.get_x(), y = a.get_y() - b.get_y();
    return sqrt(pow(x, 2) + pow(y, 2));
}

Line::Line()
{

}

Line::Line(Point begin, Point end) : begin(begin), end(end), len(LenBetweenPoints(begin, end))
{
    if (begin == end)
        throw FigureError("Can't create line. Begin and end is same point");
}

const Point &Line::getBegin() const
{
    return begin;
}

const Point &Line::getAnEnd() const
{
    return end;
}

double Line::getLen() const
{
    return len;
}

void Line::setBegin(const Point &begin)
{
    if (begin == end)
        throw FigureError("Can't create line. Begin and end is same point");
    Line::begin = begin;
    len = LenBetweenPoints(begin, end);
}

void Line::setAnEnd(const Point &anEnd)
{
    if (begin == end)
        throw FigureError("Can't create line. Begin and end is same point");
    end = anEnd;
    len = LenBetweenPoints(begin, end);
}


Triangle::Triangle(Point a, Point b, Point c) :
        points{a, b, c},
        sides{Line(b, c), Line(c, a), Line(a, b)}
{
    if (!(sides[0].getLen() + sides[1].getLen() > sides[2].getLen() &&
          sides[0].getLen() + sides[2].getLen() > sides[1].getLen() &&
          sides[1].getLen() + sides[2].getLen() > sides[0].getLen()))
        throw TriangleNotExist("Triangle not exist");

    Point h_begin = points[0];
    Line max_side = sides[0];
    for (int i = 1; i < 3; i++)
    {
        if (sides[i].getLen() > max_side.getLen())
        {
            max_side = sides[i];
            h_begin = points[i];
        }
    }

    double norm_eq_max_side[3];
    norm_eq_max_side[0] = max_side.getAnEnd().get_y() - max_side.getBegin().get_y();
    norm_eq_max_side[1] = max_side.getBegin().get_x() - max_side.getAnEnd().get_x();
    norm_eq_max_side[2] =
            -norm_eq_max_side[1] * max_side.getBegin().get_y() - norm_eq_max_side[0] * max_side.getBegin().get_x();

    double norm_eq_h[3];
    norm_eq_h[0] = norm_eq_max_side[1];
    norm_eq_h[1] = -norm_eq_max_side[0];
    norm_eq_h[2] = norm_eq_max_side[0] * h_begin.get_y() - norm_eq_max_side[1] * h_begin.get_x();

    double y, x;
    if (abs(norm_eq_max_side[0]) < EPS)
    {
        y = norm_eq_max_side[2] / norm_eq_max_side[1];
        x = (-norm_eq_h[1] * y - norm_eq_h[2]) / norm_eq_h[0];

    }
    else
    {
        double k = (norm_eq_h[0] / norm_eq_max_side[0]) * -1;
        y = (-norm_eq_h[2] - norm_eq_max_side[2] * k) / (norm_eq_h[1] + norm_eq_max_side[1] * k);
        x = (-norm_eq_max_side[1] * y - norm_eq_max_side[2]) / norm_eq_max_side[0];
    }
    min_h = Line(h_begin, Point(x, y));
}

Point Triangle::get_point(int i)
{
    if (i < 0 || i > 2) throw FigureError("Out of range list of points");
    return points[i];
}

Line Triangle::get_side(int i)
{
    if (i < 0 || i > 2) throw FigureError("Out of range list of sides");
    return sides[i];
}

Line Triangle::get_min_h()
{
    return min_h;
}

Triangle search_triangle(QVector<Point> points_vec)
{
    if (points_vec.size() < 3)
        throw FigureError("Необходимо задать минимум 3 уникальные точки.");

    QVector<Triangle> trn_vec;
    for (int i = 0; i < points_vec.size() - 2; i++)
        for (int j = i + 1; j < points_vec.size() - 1; j++)
            for (int k = j + 1; k < points_vec.size(); k++)
            {
                try
                {
                    Triangle cur_trg(points_vec[i], points_vec[j], points_vec[k]);
                    trn_vec.append(cur_trg);
                }
                catch (TriangleNotExist &e)
                {
                    continue;
                }
            }


    if (trn_vec.empty())
        throw FigureError("Все треугольники вырождены в прямую.");

    Triangle min_trn = trn_vec[0];
    for (int i = 1; i < trn_vec.size(); i++)
        if (trn_vec[i].get_min_h().getLen() < min_trn.get_min_h().getLen())
            min_trn = trn_vec[i];

    return min_trn;
}


