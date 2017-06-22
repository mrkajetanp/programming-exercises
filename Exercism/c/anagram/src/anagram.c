#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "anagram.h"

char* strdup(const char* a) {
    char* result = malloc(strlen(a)+1);

    if (result == NULL)
        return NULL;

    strcpy(result, a);

    return result;
}

bool isAnagram(const char* a, const char* b) {
    if (strlen(a) != strlen(b))
        return false;

    bool result = true;

    char* temp_a = strdup(a);
    char* temp_b = strdup(b);

    for (size_t i = 0 ; i < strlen(a) ; ++i) {
        temp_a[i] = tolower(temp_a[i]);
        temp_b[i] = tolower(temp_b[i]);
    }

    if (!strcmp(temp_a, temp_b))
        result = false;

    for (size_t i = 0 ; i < strlen(a) ; ++i) {
        if (!result)
            break;

        char* ch = strchr(temp_b, temp_a[i]);

        if (ch)
            *ch = ' ';
        else
            result = false;
    }

    free(temp_a);
    free(temp_b);

    return result;
}

struct Vector anagrams_for(char* string, struct Vector vec) {
    char (*results)[MAX_STR_LEN] = malloc(vec.size * sizeof *results);
    int count = 0;

    for (int i = 0 ; i < vec.size ; ++i) {
        if (isAnagram(string, vec.vec[i])) {
            strcpy(results[count], vec.vec[i]);
            count++;
        }
    }

    struct Vector vout = {
        (count == 0) ? NULL : results,
        count,
    };

    return vout;
}
