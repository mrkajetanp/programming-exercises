#include "run_length_encoding.h"

#include <ctype.h>
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
    char* result = malloc(sizeof(char) * length * 2);
    size_t result_size = length * 2;
    size_t result_len = 0;
    result[0] = '\0';

    char temp[20];
    temp[0] = '\0';

    if (length == 0)
        return result;

    for (size_t i = 0; i < length; ++i) {
        if (isdigit(data[i])) {
            strncat(temp, &data[i], 1);
        } else {
            if (strlen(temp) > 0) {
                size_t number = atoi(temp);
                for (size_t j = 0; j < number; ++j) {
                    strncat(result, &data[i], 1);
                    result_len++;
                    // Double available memory if approaching the allocated size
                    if (result_len > result_size * 2 / 3) {
                        result = realloc(result, result_size * 2);
                        result_size *= 2;
                    }
                }
            } else {
                strncat(result, &data[i], 1);
                result_len++;
                // Double available memory if approaching the allocated size
                if (result_len > result_size * 2 / 3) {
                    result = realloc(result, result_size * 2);
                    result_size *= 2;
                }
            }
            temp[0] = '\0';
        }
    }

    return result;
}