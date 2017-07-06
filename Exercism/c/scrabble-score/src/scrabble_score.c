#include <string.h>
#include <ctype.h>
#include "scrabble_score.h"

int get_point(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u'
        || c == 'l'|| c == 'n' || c == 'r' || c == 's' || c == 't')
        return 1;

    if (c == 'd' || c == 'g')
        return 2;

    if (c == 'b' || c == 'c' || c == 'm' || c == 'p')
        return 3;

    if (c == 'f' || c == 'h' || c == 'v' || c == 'w' || c == 'y')
        return 4;

    if (c == 'k')
        return 5;

    if (c == 'j' || c == 'x')
        return 8;

    if (c == 'q' || c == 'z')
        return 10;

    return 0;
}

int score(char* input) {
    int sum = 0;

    for (size_t i = 0 ; i < strlen(input) ; ++i)
        sum += get_point(tolower(input[i]));

    return sum;
}
