#include <stdio.h>
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
    char* result = malloc(5);

    int len = strlen(input);

    if (len == 10) {
        strncpy(result, input, 3);
        result[3] = '\0';
    }

    if (len == 11) {
        strncpy(result, input+1, 4);
        result[4] = '\0';
    }

    return result;
}

char* phone_number_format(const char* input) {
    char* clean_input = phone_number_clean(input);
    char* result = malloc(15);

    int len = strlen(clean_input);
    if (len == 10) {
        strcpy(result, "(");
        strncat(result, clean_input, 3);
        strcat(result, ") ");
        strncat(result, clean_input+3, 3);
        strcat(result, "-");
        strcat(result, clean_input+6);
    }

    if (len == 11) {
        strcpy(result, "(");
        strncat(result, clean_input+1, 4);
        strcat(result, ") ");
        strncat(result, clean_input+4, 3);
        strcat(result, "-");
        strcat(result, clean_input+7);
    }

    free(clean_input);
    return result;
}
