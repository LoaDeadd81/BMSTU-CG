#ifndef CLIPPING_H
#define CLIPPING_H

#include <QList>
#include <QLine>
#include <QVector2D>
#include <QVector>
#include <cmath>

#define NO_N 0
#define N_RIGHT 1
#define N_LEFT 2

QVector2D qline_to_qvector2d(const QLine &clipper);

void qline_to_qvector2d(QList<QVector2D> &vectors, const QList<QLine> &clipper);

bool convexity_check(int &n_orientation, const QList<QVector2D> &clipper);

void get_n(QList<QVector2D> &n, int n_orientation, const QList<QVector2D> &clipper);

QLine find_visible_segment(bool &is_visible, const QLine &line, const QList<QVector2D> &n, const QList<QLine> &clipper);

#endif
