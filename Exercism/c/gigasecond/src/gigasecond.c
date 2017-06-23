#include <stdio.h>
#include "gigasecond.h"

time_t gigasecond_after(time_t start) {
    return start + 1e9;
}
