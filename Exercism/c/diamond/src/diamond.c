#include "diamond.h"
#include <stdlib.h>
#include <string.h>

char* reverse_string(char* str);
char* reverse_string(char* str) {
    size_t len = strlen(str);
    char* result = malloc(len+1);

    size_t idx = 0;
    for (size_t i = len ; i > 0 ; --i)
        result[idx++] = str[i-1];
    result[idx] = '\0';

    return result;
}

char **make_diamond(const char letter) {
    size_t size = (letter-'A')*2 + 1;
    char** result = malloc(size * sizeof(char*));

    for (size_t i = 0 ; i < size ; ++i)
        result[i] = malloc(size+1);

    char position = 'A';
    size_t diamond_idx = 0;
    size_t max_padding = size/2;

    while (position <= letter) {
        size_t idx = 0;
        size_t padding = letter-position;

        for (size_t i = 0 ; i < padding ; ++i)
            result[diamond_idx][idx++] = ' ';
        result[diamond_idx][idx++] = position;

        result[diamond_idx][idx] = '\0';
        char* reversed = reverse_string(result[diamond_idx]);

        size_t middle_len = (diamond_idx == 0) ? 0 : 2*diamond_idx-1;
        for (size_t i = 0 ; i < middle_len ; ++i)
            result[diamond_idx][idx++] = ' ';

        result[diamond_idx][idx] = '\0';
        strcat(result[diamond_idx], (diamond_idx == 0) ? (reversed+1) : reversed);
        free(reversed);

        diamond_idx++;
        position++;
    }

    position -= 2;

    while (position >= 'A') {
        size_t idx = 0;
        size_t padding = letter-position;

        for (size_t i = 0 ; i < padding ; ++i)
            result[diamond_idx][idx++] = ' ';
        result[diamond_idx][idx++] = position;

        for (size_t i = 0 ; i < (max_padding - padding) ; ++i)
            result[diamond_idx][idx++] = ' ';
        result[diamond_idx][idx] = '\0';

        char* reversed = reverse_string(result[diamond_idx]);
        strcat(result[diamond_idx], reversed+1);
        free(reversed);

        diamond_idx++;
        position--;
    }

    return result;
}
