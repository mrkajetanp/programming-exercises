#include <string.h>
#include <ctype.h>
#include "pangram.h"

bool is_pangram(const char* sentence) {
    if (!sentence)
        return false;

    bool marker[26];
    for (int i = 0 ; i < 26 ; ++i)
        marker[i] = false;

    for (size_t i = 0 ; i < strlen(sentence) ; ++i) {
        if (isalpha(sentence[i]))
            marker[tolower(sentence[i]) - 97] = true;
    }

    for (int i = 0 ; i < 26 ; ++i) {
        if (!marker[i])
            return false;
    }

    return true;
}
