#include <math.h>
#include <stdbool.h>
#include "nth_prime.h"

bool is_prime(int x) {
    if (x == 2 || x == 3)
        return true;

    if (x%2 == 0)
        return false;

    for (unsigned i = 3 ; i < (unsigned)sqrt(x)+1 ; i += 2) {
        if (x%i == 0)
            return false;
    }

    return true;
}

unsigned nth(unsigned num) {
    if (num < 1)
        return 0;

    unsigned nth = 0;

    for (int i = 2 ; ; ++i) {
        if (is_prime(i))
            nth++;

        if (nth == num)
            return i;
    }

    return num;
}
