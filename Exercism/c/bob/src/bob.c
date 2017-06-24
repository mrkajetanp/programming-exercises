#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "bob.h"

char* hey_bob(char* text) {
    bool empty = true;
    for (size_t i = 0 ; i < strlen(text) ; ++i) {
        if (!isspace(text[i])) {
            empty = false;
            break;
        }
    }

    if (empty || strlen(text) == 0)
        return "Fine. Be that way!";

    bool whoa = true;
    for (size_t i = 0 ; i < strlen(text) ; ++i) {
        if (text[i] != toupper(text[i]))
            whoa = false;
    }

    if (whoa) {
        whoa = false;
        for (size_t i = 0 ; i < strlen(text) ; ++i) {
            if (isalpha(text[i])) {
                whoa = true;
                break;
            }
        }
    }

    if (whoa)
        return "Whoa, chill out!";

    int last_idx = strlen(text)-1;
    while (isspace(text[last_idx]))
        last_idx--;

    if (text[last_idx] == '?')
        return "Sure.";

    return "Whatever.";
}
