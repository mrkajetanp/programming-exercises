#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _PairIS {
    int one;
    char* two;
} PairIS;

char* num_as_roman(int num) {
    PairIS table[13] = {
        { 1, "I" }, { 4, "IV" }, { 5, "V" }, { 9, "IX" },
        { 10, "X" }, { 40, "XL" }, { 50, "L" }, { 90, "XC" },
        { 100, "C" }, { 400, "CD" }, { 500, "D" }, { 900, "CM" },
        { 1000, "M" },
    };

    char* result = malloc(10);
    result[0] = '\0';

    while (num > 0) {
        int idx = 12;

        while (table[idx].one > num)
            idx--;

        num -= table[idx].one;
        strcat(result, table[idx].two);
    }

    return result;
}

void dotest(int num, char* exp) {
    char* act = num_as_roman(num);
    assert(strcmp(act, exp) == 0);
    free(act);
}

int main() {
    dotest(1000, "M");
    dotest(4, "IV");
    dotest(1, "I");
    dotest(2008, "MMVIII");
    dotest(3999, "MMMCMXCIX");
    dotest(182, "CLXXXII");
    dotest(1990, "MCMXC");
    dotest(1875, "MDCCCLXXV");
}
