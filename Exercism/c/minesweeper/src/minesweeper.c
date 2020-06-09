#include "minesweeper.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_mines(const char**, size_t, size_t, size_t, size_t);
int count_mines(const char** field, size_t col, size_t row,
                size_t cols, size_t rows) {
    int result = 0;

    if (row == 0) {
        if (col == 0) {
            result += (field[row][col+1] == '*') ? 1 : 0;
            if (row+1 != rows)
                result += (field[row+1][col+1] == '*') ? 1 : 0;
        } else if (col+1 == cols) {
            result += (field[row][col-1] == '*') ? 1 : 0;
            if (row+1 != rows)
                result += (field[row+1][col-1] == '*') ? 1 : 0;
        } else {
            result += (field[row][col+1] == '*') ? 1 : 0;
            result += (field[row][col-1] == '*') ? 1 : 0;
            if (row+1 != rows) {
                result += (field[row+1][col+1] == '*') ? 1 : 0;
                result += (field[row+1][col-1] == '*') ? 1 : 0;
            }
        }
        if (row+1 != rows)
            result += (field[row+1][col] == '*') ? 1 : 0;
    } else if (row+1 == rows) {
        if (col == 0) {
            result += (field[row][col+1] == '*') ? 1 : 0;
            result += (field[row-1][col+1] == '*') ? 1 : 0;
        } else if (col+1 == cols) {
            result += (field[row][col-1] == '*') ? 1 : 0;
            result += (field[row-1][col-1] == '*') ? 1 : 0;
        } else {
            result += (field[row-1][col+1] == '*') ? 1 : 0;
            result += (field[row-1][col-1] == '*') ? 1 : 0;
            result += (field[row][col+1] == '*') ? 1 : 0;
            result += (field[row][col-1] == '*') ? 1 : 0;
        }
        result += (field[row-1][col] == '*') ? 1 : 0;
    } else {
        result += (field[row][col+1] == '*') ? 1 : 0;
        result += (field[row][col-1] == '*') ? 1 : 0;
        result += (field[row+1][col] == '*') ? 1 : 0;
        result += (field[row-1][col] == '*') ? 1 : 0;
        result += (field[row-1][col-1] == '*') ? 1 : 0;
        result += (field[row+1][col-1] == '*') ? 1 : 0;
        result += (field[row-1][col+1] == '*') ? 1 : 0;
        result += (field[row+1][col+1] == '*') ? 1 : 0;
    }

    return result;
}

char **annotate(const char **minefield, const size_t rows) {
    if (minefield == NULL)
        return NULL;

    char** annotate = malloc(sizeof(char*) * rows);
    size_t len = strlen(minefield[0]);

    for (size_t i = 0 ; i < rows ; ++i) {
        annotate[i] = malloc(len+1);
        for (size_t j = 0 ; j < len ; ++j) {
            if (minefield[i][j] == '*') {
                annotate[i][j] = '*';
            } else {
                int count = count_mines(minefield, j, i, len, rows);
                if (count == 0)
                    annotate[i][j] = ' ';
                else
                    annotate[i][j] = '0'+count;
            }
        }
        annotate[i][len] = '\0';
    }

    return annotate;
}

void free_annotation(char **annotation) {
    free(annotation);
}
