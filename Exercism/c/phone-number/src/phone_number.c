#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "phone_number.h"

char* phone_number_clean(const char* input) {
    int cnt = 0;
    bool fail = false;

    char* result = malloc(10);
    for (size_t i = 0 ; i < strlen(input) ; ++i) {
        if (isdigit(input[i]))
            result[cnt++] = input[i];
        else {
            if (isalpha(input[i])) {
                fail = true;
                break;
            }
        }
    }
    result[cnt] = '\0';

    int len = strlen(result);
    if (fail || len < 10 || len > 11 ||
        (len > 10 && result[0] != '1')) {

        size_t i;
        for (i = 0 ; i < 10 ; ++i)
            result[i] = '0';
        result[i] = '0';
        result[i+1] = '\0';
    }

    len = strlen(result);
    if (len == 11) {
        size_t i;
        for (i = 1 ; i < strlen(result) ; ++i)
            result[i-1] = result[i];
        result[i-1] = '\0';
    }

    return result;
}

char* phone_number_get_area_code(const char* input) {
    if (input)
        ;

    return NULL;
}

char* phone_number_format(const char* input) {
    if (input)
        ;

    return NULL;
}
