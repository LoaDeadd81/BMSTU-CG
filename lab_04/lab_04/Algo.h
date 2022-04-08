#ifndef ALGO_H
#define ALGO_H

#include "Geometry.h"
#include "Graphics.h"
#include "Errors.h"

void ellipse_param_draw(Ellipse &ellipse, Graph_t &graph);

void ellipse_canon_draw(Ellipse &ellipse, Graph_t &graph);

void ellipse_bres_draw(Ellipse &ellipse, Graph_t &graph);

void ellipse_mid_point_draw(Ellipse &ellipse, Graph_t &graph);

void ellipse_lib_draw(Ellipse &ellipse, Graph_t &graph);

void circle_param_draw(Circle &circle, Graph_t &graph);

void circle_canon_draw(Circle &circle, Graph_t &graph);

void circle_bres_draw(Circle &circle, Graph_t &graph);

void circle_mid_point_draw(Circle &circle, Graph_t &graph);

void circle_lib_draw(Circle &circle, Graph_t &graph);

#endif 
