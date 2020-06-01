#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "acronym.h"

char* abbreviate(char* input_text) {
    char* input = malloc(strlen(input_text)+1);

    int idx = 0;
    for (size_t i = 0 ; i < strlen(input_text) ; ++i) {
        if (isalpha(input_text[i]) || isspace(input_text[i]))
            input[idx++] = input_text[i];

        if (input_text[i] == '-')
        input[idx++] = ' ';
    }
    input[idx] = '\0';

    idx = 0;
    char* result = malloc(strlen(input)/5);

    char* pch = strtok(input, " ");
    while (pch != NULL) {
        result[idx++] = toupper(pch[0]);
        pch = strtok(NULL, " ");
    }
    result[idx] = '\0';

    free(input);
    return result;
}

int main() {
    abbreviate("Hello There My Friend");
}
