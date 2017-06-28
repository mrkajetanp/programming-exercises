#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "atbash_cipher.h"

char* atbash_encode(char* input) {
    int len = strlen(input);

    int cnt = 0;
    char* temp = malloc(len);

    for (int i = 0 ; i < len ; ++i) {
        if (isalnum(input[i])) {
            if (isalpha(input[i]))
                temp[cnt++] = 123 - tolower(input[i]) + 96;
            else
                temp[cnt++] = tolower(input[i]);
        }
    }
    temp[cnt] = '\0';

    char* result = malloc(len + len/5);

    cnt = 1;
    int j = 0;
    for (size_t i = 0 ; i < strlen(temp) ; ++i) {
        result[j++] = temp[i];

        if (cnt%5 == 0)
            result[j++] = ' ';

        cnt++;
    }
    result[j] = '\0';

    len = strlen(result);
    if (result[len-1] == ' ')
        result[len-1] = '\0';

    free(temp);
    return result;
}

char* atbash_decode(char* input) {
    int len = strlen(input);

    int cnt = 0;
    char* result = malloc(len);

    for (int i = 0 ; i < len ; ++i) {
        if (isalnum(input[i])) {
            if (isalpha(input[i]))
                result[cnt++] = 123 - tolower(input[i]) + 96;
            else
                result[cnt++] = tolower(input[i]);
        }
    }
    result[cnt] = '\0';

    return result;
}
