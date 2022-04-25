#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QImage>

typedef struct Graph_t
{
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmap_item;
    QImage image;
    QPen pen_fill;
    QPen pen_border;
} Graph_t;

#endif 
