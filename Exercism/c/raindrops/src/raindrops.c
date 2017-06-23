#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raindrops.h"

/* int* get_factors() */

char* convert(char buffer[], size_t size, int num) {
    buffer[0] = '\0';

    if (size) {}

    for (int i = 1 ; i <= num ; ++i) {
        if (num % i == 0 && i == 3) {
            if (strlen(buffer)-1 + 5 < size)
                strcat(buffer, "Pling");
        }
    }

    for (int i = 1 ; i <= num ; ++i) {
        if (num % i == 0 && i == 5) {
            if (strlen(buffer)-1 + 5 < size)
                strcat(buffer, "Plang");
        }
    }

    for (int i = 1 ; i <= num ; ++i) {
        if (num % i == 0 && i == 7) {
            if (strlen(buffer)-1 + 5 < size)
                strcat(buffer, "Plong");
        }
    }

    if (strlen(buffer) == 0) {
        char num_buff[15];
        sprintf(num_buff, "%d", num);

        if (strlen(num_buff) < size)
            strcat(buffer, num_buff);
    }

    return buffer;
}

