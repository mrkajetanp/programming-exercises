#include <stdio.h>
#include "pascals_triangle.h"

size_t** create_triangle(int rows) {
    if (rows < 0)
        return NULL;

    if (rows == 0) {
        size_t** result = malloc(sizeof(size_t*));
        result[0] = malloc(sizeof(size_t));
        result[0][0] = 0;
        return result;
    }

    size_t** result = malloc(rows * sizeof(size_t*));
    for (int i = 0 ; i < rows ; ++i)
        result[i] = malloc(rows * sizeof(size_t));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j)
            result[i][j] = 0;
    }

    int coef = 1;
    for (int i = 0 ; i < rows ; ++i) {
        for (int j = 0 ; j < i+1 ; ++j) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i-j+1)/j;

            result[i][j] = coef;
        }
    }

    return result;
}

void free_triangle(size_t** triangle, int rows) {
    for (int i = 0 ; i < rows ; ++i)
        free(triangle[i]);

    free(triangle);
}
