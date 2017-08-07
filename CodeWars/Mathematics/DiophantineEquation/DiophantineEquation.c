#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

Pair** solEquaStr(long long n, int* length) {
    Pair** result = malloc(100 * sizeof(Pair*));

    for (long long i = 1 ; i < floor(sqrt(n))+1 ; ++i) {
        // i == x-2y
        // j == x+2y
        if (n%i == 0) {
            long long j = n/i;

            if ((j-i)%4 == 0) {
                // j-i == 4y
                // i+j == 2x
                result[*length] = malloc(sizeof(Pair));
                result[*length]->first = (i+j)/2;
                result[*length]->snd = (j-i)/4;
                (*length)++;
            }
        }
    }

    return result;
}

char* array2StringData(Pair** arr, int sz) {
    char* result = malloc(sz * 16);
    strcpy(result, "{");

    char buff[40];

    for (int i = 0 ; i < sz ; ++i) {
        sprintf(buff, "{%lld, %lld}", arr[i]->first, arr[i]->snd);
        strcat(result, buff);
    }

    strcat(result, "}");

    for (int i = 0 ; i < sz ; ++i)
        free(arr[i]);
    free(arr);
    return result;
}

void dotest(long long n, char* sexpr) {
    int lg = 0;
    Pair** act = solEquaStr(n, &lg);
    char* sact = array2StringData(act, lg);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (strcmp(sact, "{}") != 0) {
        free(sact); sact = NULL;
    }
}

int main() {
    dotest(5, "{{3, 1}}");
    dotest(9001, "{{4501, 2250}}");
    dotest(9005, "{{4503, 2251}{903, 449}}");
    dotest(9008, "{{1128, 562}}");
    dotest(900005, "{{450003, 225001}{90003, 44999}}");
    dotest(90000001,
           "{{45000001, 22500000}{6428575, 3214284}"
           "{3461545, 1730766}{494551, 247230}}");
}
