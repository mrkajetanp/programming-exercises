#include <string.h>
#include <ctype.h>
#include "isogram.h"

bool isIsogram(char* input) {
    bool letters[26];
    for (int i = 0 ; i < 26 ; ++i)
        letters[i] = false;

    for (size_t i = 0 ; i < strlen(input) ; ++i) {
        if (!isalpha(input[i]))
            continue;

        if (letters[tolower(input[i])-97])
            return false;

        letters[tolower(input[i])-97] = true;
    }

    return true;
}
