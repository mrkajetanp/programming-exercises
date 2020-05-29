#include "darts.h"
#include <math.h>
#include <stdio.h>

uint8_t score(coordinate_t landing) {
    float distance = sqrtf(landing.x*landing.x + landing.y*landing.y);

    if (distance > 10.0F)
        return 0;

    if (distance > 5.0F)
        return 1;

    if (distance > 1.0F)
        return 5;

    return 10;
}
