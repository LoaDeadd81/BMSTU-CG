#ifndef ALGO_H
#define ALGO_H

#include <math.h>
#include <ctime>
#include <iostream>
#include <QtCharts>

#include "Point.h"
#include "Graphics.h"

typedef void (*algorithm)(Point_t&, Point_t&, Graph_t&, int&);

void bres_float(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void bres_int(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void cda(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void bres_smooth(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void wu(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void lib(Point_t &start, Point_t &end, Graph_t &graph, int &steps);

void spectre(Point_t &center, double len, double degree, Graph_t &graph, algorithm alg);

double eff(algorithm alg);

void steps(algorithm alg, QLineSeries *series);

#endif 
