#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdbool.h>

typedef struct {
   double a;
   double b;
   double c;
} Triangle_t;

bool is_equilateral(Triangle_t* triangle);

bool is_isosceles(Triangle_t* triangle);

bool is_scalene(Triangle_t* triangle);

#endif
