#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nucleotide_count.h"

char* count(const char* strand) {
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;

    char* result = malloc(25);
    for (size_t i = 0 ; i < strlen(strand) ; ++i) {
        switch (strand[i]) {
        case 'A':
            a++;
            break;

        case 'C':
            c++;
            break;

        case 'G':
            g++;
            break;

        case 'T':
            t++;
            break;

        default:
            strcpy(result, "");
            return result;
        }
    }

    sprintf(result, "A:%d C:%d G:%d T:%d", a, c, g, t);
    return result;
}
