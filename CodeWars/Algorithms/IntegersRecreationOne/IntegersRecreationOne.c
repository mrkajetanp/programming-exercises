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

long long sum_square_divisors(long long n) {
    if (n == 1)
        return 1;

    long long sum = 0;

    for (long long i = 1 ; i < ceil(sqrt(n)) ; ++i) {
        if (n%i == 0)
            sum += i*i + (n/i)*(n/i);
    }

    return sum;
}

Pair** listSquared(long long m, long long n, int* length) {
    Pair** result = calloc(100, sizeof(Pair*));
    *length = 0;

    for (long long i = m ; i < n ; ++i) {
        double sum = sum_square_divisors(i);

        if (sqrt(sum) == round(sqrt(sum))) {
            result[*length] = malloc(sizeof(Pair));
            result[*length]->first = i;
            result[*length]->snd = sum;
            (*length)++;
        }
    }

    return result;
}

char* array2StringData(Pair** arr, int size) {
    char* result = malloc(size * 20);
    strcpy(result, "{");

    char temp[50];
    for (int i = 0 ; i < size ; ++i) {
        sprintf(temp, "{%lld, %lld}", arr[i]->first, arr[i]->snd);
        strcat(result, temp);
        free(arr[i]);
    }
    strcat(result, "}");

    free(arr);
    return result;
}



void dotest(long long m, long long n, char* sexpr) {
    int lg = 0;
    Pair** act = listSquared(m, n, &lg);
    char* sact = array2StringData(act, lg);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (strcmp(sact, "{}") != 0) {
        free(sact); sact = NULL;
    }
}

int main() {
    dotest(1, 250, "{{1, 1}{42, 2500}{246, 84100}}");
    dotest(42, 250, "{{42, 2500}{246, 84100}}");
    dotest(250, 500, "{{287, 84100}}");
    dotest(300, 600, "{}");
}
