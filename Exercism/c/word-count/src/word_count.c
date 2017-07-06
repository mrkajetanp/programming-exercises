#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_count.h"

int find_str(WordCount_Word_t words[MAX_WORDS], int count, char* str) {
    int idx = -1;

    for (int i = 0 ; i < count ; ++i) {
        if (strcmp(words[i].text, str) == 0) {
            idx = i;
            break;
        }
    }

    return idx;
}

int word_count(char *input_text, WordCount_Word_t words[MAX_WORDS]) {
    char* input = malloc(strlen(input_text)+1);
    int idx = 0;

    for (size_t i = 0 ; i < strlen(input_text) ; ++i) {
        if (isalnum(input_text[i]) || isspace(input_text[i]) ||
            input_text[i] == ',' || input_text[i] == '\'')

            input[idx++] = tolower(input_text[i]);
    }
    input[idx] = '\0';

    int word = 0;
    char* pch = strtok(input, " ,\n");
    while (pch != NULL) {
        if (pch[0] == '\'' && pch[strlen(pch)-1] == '\'') {
            pch[strlen(pch)-1] = '\0';
            pch++;
        }

        int idx = find_str(words, word, pch);
        if (idx != -1)
            words[idx].count++;
        else {
            strcpy(words[word].text, pch);
            words[word++].count = 1;
        }

        pch = strtok(NULL, " ,\n");
    }

    free(input);
    return word;
}
