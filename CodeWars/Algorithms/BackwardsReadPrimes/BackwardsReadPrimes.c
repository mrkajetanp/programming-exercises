#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

typedef long long ll;

typedef struct _data {
    ll* array;
    int sz;
} Data;

bool is_prime(ll n) {
    if (n <= 3)
        return true;

    if (n%2 == 0 || n%3 == 0)
        return false;

    ll i = 5;
    ll w = 2;

    while (pow(i, 2) <= n) {
        if (n%i == 0)
            return false;

        i += w;
        w = 6-w;
    }

    return true;
}

ll reverse_num(ll x) {
    char buff[20];

    int idx = 0;
    while (x > 0) {
        buff[idx++] = '0'+x%10;
        x /= 10;
    }
    buff[idx] = '\0';

    return atoll(buff);
}

Data* backwardsPrime(ll start, ll end) {
    Data* result = malloc(sizeof *result);
    result->array = malloc(sizeof(ll) * end/4);
    result->sz = 0;

    for (ll i = start ; i <= end ; ++i) {
        int i2 = reverse_num(i);

        if (i != i2 && is_prime(i) && is_prime(i2))
            result->array[result->sz++] = i;
    }

    return result;
}

char* array2StringLongLong(Data* d) {
    char* result = malloc(d->sz * 15);
    strcpy(result, "");

    char temp[50];
    strcpy(temp, "");
    for (int i = 0 ; i < d->sz ; ++i) {
        sprintf(temp, "%lld", d->array[i]);
        strcat(result, temp);
        strcat(result, ", ");
        strcpy(temp, "");
    }
    result[strlen(result)-2] = '\0';

    return result;
}


void dotest(ll start, ll end, char* sexpr) {
    Data* act = backwardsPrime(start, end);
    char* sact = array2StringLongLong(act);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (act->sz != 0) {
        free(act->array);
        free(sact); sact = NULL;
    }
    free(act); act = NULL;
}

int main() {
    dotest(7000, 7100, "7027, 7043, 7057");
    dotest(70000, 70245, "70001, 70009, 70061, 70079, 70121, 70141, 70163, 70241");
    dotest(70485, 70600, "70489, 70529, 70573, 70589");
    dotest(60000, 70000, "");
}
