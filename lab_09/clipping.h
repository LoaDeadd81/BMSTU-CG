#ifndef CLIPPING_H
#define CLIPPING_H

#include <QList>
#include <QLine>
#include <QVector2D>
#include <QVector>
#include <cmath>

//void get_n(QList<QVector2D> &n, int n_orientation, const QList<QVector2D> &clipper);

QList<QPoint> clip(const QVector<QPoint> clipper, const QVector<QPoint> polygon, int dir);


#endif
