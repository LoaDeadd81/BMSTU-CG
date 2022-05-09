#ifndef CLIPPING_H
#define CLIPPING_H

#include <QLine>
#include <QRect>
#include <QPoint>
#include <cmath>

void find_visible_segment(bool &is_visible, QLine &line, const QRect &clipper);

#endif
