#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#undef max
#define max(a, b) ((a > b) ? a : b)

#undef min
#define min(a, b) ((a < b) ? a : b)

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

typedef long long lglg;

int pair_cmp(const void* a, const void* b) {
    return (*(Pair**)a)->first - (*(Pair**)b)->first;
}

bool arr_contains_pair(Pair** arr, int len, Pair* pair) {
    for (int i = 0 ; i < len ; ++i) {
        if (arr[i]->first == pair->first && arr[i]->snd == pair->snd)
            return true;
    }

    return false;
}

Pair** prod2Sum(lglg a, lglg b, lglg c, lglg d, int* length) {
    Pair** result = malloc(sizeof(Pair*) * 20);
    *length = 0;

    lglg n = (pow(a, 2) + pow(b, 2)) * (pow(c, 2) + pow(d, 2));
    lglg sums[] = {llabs(a*c+b*d), llabs(a*d+b*c),
                   llabs(a*c-b*d), llabs(a*d-b*c)};

    for (int i = 0 ; i < 4 ; ++i) {
        for (int j = 0 ; j < 4 ; ++j) {
            if (pow(sums[i], 2) + pow(sums[j], 2) == n) {
                Pair* p = malloc(sizeof *p);
                p->first = min(sums[i], sums[j]);
                p->snd = max(sums[i], sums[j]);

                if (!arr_contains_pair(result, *length, p))
                    result[(*length)++] = p;
                else
                    free(p);
            }
        }
    }

    qsort(result, *length, sizeof(Pair*), pair_cmp);
    return result;
}

char* array2StringData(Pair** arr, int sz) {
    char* result = malloc(sz * 12);
    char temp[20];

    strcpy(result, "{");
    for (int i = 0 ; i < sz ; ++i) {
        sprintf(temp, "{%lld, %lld}", arr[i]->first, arr[i]->snd);
        strcat(result, temp);
    }
    strcat(result, "}");

    return result;
}

void dotest(lglg a, lglg b, lglg c, lglg d, char* sexpr) {
    int lg = 0;
    Pair** act = prod2Sum(a, b, c, d, &lg);
    char* sact = array2StringData(act, lg);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (strcmp(sact, "{}") != 0) {
        free(sact); sact = NULL;
    }
}

int main() {
    dotest(1, 2, 1, 3, "{{1, 7}{5, 5}}");
    dotest(2, 3, 4, 5, "{{2, 23}{7, 22}}");
    dotest(1, 2, 2, 3, "{{1, 8}{4, 7}}");
    dotest(1, 1, 3, 5, "{{2, 8}}");
}
