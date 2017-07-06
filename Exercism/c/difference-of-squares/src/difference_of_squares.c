#include <math.h>
#include "difference_of_squares.h"

long square_of_sum(int n) {
    long sum = 0;

    for (int i = 0 ; i <= n ; ++i)
        sum += i;

    return pow(sum, 2);
}

long sum_of_squares(int n) {
    long sum = 0;

    for (int i = 0 ; i <= n ; ++i)
        sum += pow(i, 2);

    return sum;
}

long difference_of_squares(int n) {
    return square_of_sum(n) - sum_of_squares(n);
}

