#ifndef SUPPORT_H
#define SUPPORT_H

#include <QList>
#include <QLine>
#include <QVector2D>
#include <QVector>
#include <cmath>

#define NO_N 0
#define N_RIGHT -1
#define N_LEFT 1

QVector2D qline_to_qvector2d(const QLine &clipper);

void qlines_to_qvector2ds(QVector<QVector2D> &vectors, const QVector<QLine> &clipper);

void qpointss_to_qliness(QVector<QLine> &vectors, const QVector<QPoint> &clipper);

bool convexity_check(int &n_orientation, const QVector<QVector2D> &clipper);

bool self_intersection_check(const QVector<QLine> clipper);

#endif
