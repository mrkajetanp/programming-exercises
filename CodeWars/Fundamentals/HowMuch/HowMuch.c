#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

char* howMuch (int m, int n) {
    if (m > n)    swap (&m, &n);
    char* results = malloc (sizeof(char)*1000);
    strcat (results, "[");

    double c = 0.0, b = 0.0;

    int i;
    for (i = m ; i <= n ; ++i) {
        c = (i-1)/9.0;
        b = (i-2)/7.0;
        if (c < 0 || b < 0)    continue;
        double intpart;
        if (modf (c, &intpart) == 0 && modf (b, &intpart) == 0) {
            char* temp = malloc (sizeof(char)*35);
            sprintf (temp, "[M: %d B: %d C: %d]", i, (int)b, (int)c);
            strcat (results, temp);
            strcpy (temp, "");
        }
    }
    strcat (results, "]");

    return results;
}

void tests () {
    printf ("%s\n", howMuch (1,100));
    assert(strcmp(howMuch (1,100),"[[M: 37 B: 5 C: 4][M: 100 B: 14 C: 11]]") == 0);
    assert (strcmp (howMuch (2950, 2950), "[]") == 0);
    assert (strcmp(howMuch (20000, 20100),
                   "[[M: 20008 B: 2858 C: 2223][M: 20071 B: 2867 C: 2230]]") == 0);
}

int main () {
    tests ();

    return 0;
}
