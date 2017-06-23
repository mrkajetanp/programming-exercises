#include <stdio.h>
#include <string.h>
#include "hamming.h"

int compute(const char* a, const char* b) {
    size_t length = (strlen(a) < strlen(b)) ? strlen(a) : strlen(b);
    int count = 0;

    for (size_t i = 0 ; i < length ; ++i) {
        if (a[i] != b[i])
            count++;
    }

    return count;
}
