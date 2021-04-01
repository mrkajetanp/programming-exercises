#include "run_length_encoding.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(const char* text)
{
    size_t length = strlen(text);
    char* result = malloc(sizeof(char) * length * 2);
    result[0] = '\0';

    if (length == 0)
        return result;

    char temp[20];

    size_t count = 1;
    char curr_char = text[0];

    for (size_t i = 1; i < length; ++i) {
        if (text[i] != curr_char) {
            if (count != 1) {
                sprintf(temp, "%ld", count);
                strcat(result, temp);
            }
            strncat(result, &curr_char, 1);

            curr_char = text[i];
            count = 1;
        } else {
            count++;
        }
    }

    if (count != 1) {
        sprintf(temp, "%ld", count);
        strcat(result, temp);
    }
    strncat(result, &curr_char, 1);

    return result;
}

char* decode(const char* data)
{
    size_t length = strlen(data);
    char* result = malloc(sizeof(char) * length);
    result[0] = '\0';

    return result;
}