#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QPen>

typedef struct Graph_t
{
    QGraphicsScene *scene;
    QPen pen_fill;
    QPen pen_border;
}Graph_t;

#endif 
