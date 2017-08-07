#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

Pair** removNb(long long n, int* length) {
    Pair** result = malloc(sizeof(Pair*) * 100);
    long long sum = n*(n+1)/2; /* sum of numbers 1...n */

    for (long long a = 1 ; a <= n ; ++a) {
        if ((sum-a)%(a+1) == 0) {
            long long b = (sum-a)/(a+1.0);

            if (b < n && b > 0) {
                result[*length] = malloc(sizeof(Pair));
                result[*length]->first = a;
                result[*length]->snd = b;
                (*length)++;
            }
        }
    }

    return result;
}

// fct  to compare results; sz number of pairs / Pair** arr will be freed
char* array2StringData(Pair** arr, int size) {
    char* result = malloc(size * 7);
    strcpy(result, "{");

    char temp[50];
    strcpy(temp, "");
    for (int i = 0 ; i < size ; ++i) {
        sprintf(temp, "{%lld, %lld}", arr[i]->first, arr[i]->snd);
        strcat(result, temp);
        strcpy(temp, "");
    }
    strcat(result, "}");

    return result;
}


void dotest(long long n, char* sexpr) {
    int lg = 0;
    Pair** act = removNb(n, &lg);
    char* sact = array2StringData(act, lg);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (strcmp(sact, "{}") != 0) {
        free(sact); sact = NULL;
    }
}

int main() {
    dotest(26, "{{15, 21}{21, 15}}");
    dotest(100 , "{}");
    dotest(37 , "{{21, 31}{31, 21}}");
    dotest(101 , "{{55, 91}{91, 55}}");
}
