#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stdlib.h>
#include <assert.h>

size_t** create_triangle(int rows);

void free_triangle(size_t** triangle, int rows);

#endif
