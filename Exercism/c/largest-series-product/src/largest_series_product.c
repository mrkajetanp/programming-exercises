#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "largest_series_product.h"

#include <assert.h>

long long largest_series_product(char* series, size_t chain) {
    bool any_not_digit = false;
    for (size_t i = 0 ; i < strlen(series) ; ++i) {
        if (!isdigit(series[i])) {
            any_not_digit = true;
            break;
        }
    }

    if (chain > strlen(series) || any_not_digit)
        return -1;

    int* arr = malloc(strlen(series) * sizeof *arr);
    for (int i = 0 ; i < (int)strlen(series) ; ++i)
        arr[i] = series[i] - '0';

    long long sum = 0;
    long long temp = 1;

    for (int i = 0 ; i < (int)(strlen(series)-chain+1) ; ++i) {
        for (int j = i ; j < (int)(i+chain) ; ++j)
            temp *= arr[j];

        if (temp > sum)
            sum = temp;

        temp = 1;
    }

    free(arr);
    return sum;
}
