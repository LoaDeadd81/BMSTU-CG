#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>
#include <QPen>
#include <QLineF>
#include <QVector>
#include <QGraphicsTextItem>

#include "figures.h"

#define EPS 1e-4

void DrawResult(QGraphicsScene *scene, Triangle &trn, QVector<Point> &points);

#endif
