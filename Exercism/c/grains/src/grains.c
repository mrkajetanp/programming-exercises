#include <math.h>
#include "grains.h"

unsigned long square(int s) {
    if (s < 1 || s > 64)
        return 0;

    return pow(2, s-1);
}

unsigned long total() {
    unsigned long long sum = 0;

    for (int i = 1 ; i < 65 ; ++i)
        sum += square(i);

    return sum;
}
