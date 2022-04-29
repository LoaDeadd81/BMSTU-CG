#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QPen>

typedef struct Graphics_t
{
    QGraphicsScene *scene;
    QPen pen_clipper;
    QPen pen_segment;
    QPen pen_cut_off_segment;
}Graph_t;

#endif 
