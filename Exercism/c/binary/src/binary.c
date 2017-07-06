#include <string.h>
#include <math.h>
#include "binary.h"

int convert(char* input) {
    int len = strlen(input)-1;

    int sum = 0;
    for (int i = len ; i >= 0 ; --i) {
        if (input[i] != '0' && input[i] != '1')
            return INVALID;

        sum += (input[i]-'0') * pow(2, len-i);
    }

    return sum;
}
