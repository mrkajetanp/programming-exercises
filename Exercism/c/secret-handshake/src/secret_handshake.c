#include "secret_handshake.h"
#include <stdlib.h>
#include <stdbool.h>

void swap(char**, char**);
void swap(char** a, char** b) {
    char* temp = *b;
    *b = *a;
    *a = temp;
}

const char** commands(size_t number) {
    bool reverse = false;
    if (number >= 16) {
        reverse = true;
        number -= 16;
    }

    char** result = malloc(sizeof(char*) * 4);
    if (number == 0 || number == 16) {
        result[0] = NULL;
        return (const char**)result;
    }

    int idx = 0;
    if (number >= 8) {
        result[idx++] = "jump";
        number -= 8;
    }

    if (number >= 4) {
        result[idx++] = "close your eyes";
        number -= 4;
    }

    if (number >= 2) {
        result[idx++] = "double blink";
        number -= 2;
    }

    if (number >= 1) {
        result[idx++] = "wink";
        number -= 1;
    }

    if (!reverse) {
        for (int i = 0 ; i < idx/2 ; ++i)
            swap(&result[i], &result[idx-i-1]);
    }

    return (const char**)result;
}
