#include "etl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int mapcmp(const void* a, const void* b);
int mapcmp(const void* a, const void* b) {
    char ca = ((new_map*)a)->key;
    char cb = ((new_map*)b)->key;
    return ca - cb;
}

void insert(new_map* input, int* len, new_map value);
void insert(new_map* input, int* len, new_map value) {
    for (int i = 0 ; i < *len ; ++i) {
        if (input[i].key == value.key)
            return;
    }

    input[*len].key = value.key;
    input[(*len)++].value = value.value;
}

int convert(const legacy_map * input, const size_t input_len, new_map ** output) {
    new_map* result = malloc(sizeof(new_map) * 26);
    int result_len = 0;

    for (size_t i = 0 ; i < input_len ; ++i) {
        for (size_t j = 0 ; j < strlen(input[i].keys) ; ++j) {
            insert(result, &result_len,
                   (new_map){ tolower(input[i].keys[j]), input[i].value} );
        }
    }

    qsort(result, result_len, sizeof(new_map), mapcmp);
    *output = result;
    return result_len;
}
