#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

bool is_prime(long long n) {
    if (n <= 3)
        return true;

    if (n%2 == 0 || n%3 == 0)
        return false;

    long long i = 5;
    long long w = 2;

    while (pow(i, 2) <= n) {
        if (n%i == 0)
            return false;

        i += w;
        w = 6-w;
    }

    return true;
}

long long* gap(int g, long long m, long long n) {
    long long* result = malloc(2 * sizeof *result);

    if (n-m == g) {
        result[0] = m;
        result[1] = n;
        return result;
    }

    long long last_prime = 0;

    for (long long i = m ; i <= n ; ++i) {
        if (!is_prime(i))
            continue;

        if (i-last_prime == g) {
            result[0] = last_prime;
            result[1] = i;
            return result;
        }

        last_prime = i;
    }

    result[0] = 0;
    result[1] = 0;
    return result;
}

char* array2StringLongLong(long long *array, size_t sz) {
    char* result = malloc(sz * 8);
    strcpy(result, "");

    char buff[10];

    for (size_t i = 0 ; i < sz ; ++i) {
        sprintf(buff, "%lld", array[i]);
        strcat(result, buff);
        strcat(result, ", ");
    }
    result[strlen(result)-2] = '\0';
    strcat(result, "");

    return result;
}

void dotest(int g, long long start, long long nd, char *expr) {
    long long* act = gap(g, start, nd);
    char* sact = array2StringLongLong(act, 2);
    if(strcmp(sact, expr) != 0)
        printf("step. Error. Expected \n%s\n but got \n%s\n", expr, sact);
    assert(strcmp(sact, expr) == 0);
    free(sact); sact = NULL;
}




int main() {

    dotest(2,100,110, "101, 103");
    dotest(4,100,110, "103, 107");
    dotest(6,100,110, "0, 0");
    dotest(8,300,400, "359, 367");
}
