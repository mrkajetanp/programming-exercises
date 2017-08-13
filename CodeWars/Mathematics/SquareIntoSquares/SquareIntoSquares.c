#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

char* aux(long long num, long long rac) {
    if (num == 0)
        return "[]";

    long long i = rac;
    char* result = malloc(200);
    strcpy(result, "[]");

    while (i >= sqrt(num/2.0)+1) {
        long long diff = num - i*i;
        rac = sqrt(diff);

        if (strcmp(result, "[]") != 0) {

        }
    }

    return result;
}

char* decompose(long long n) {
    return aux(n*n, (sqrt(n*n-1)));
}

void testing(long long n, char* sexpr) {
    char* sact = decompose(n);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (strcmp(sact, "[]") != 0)
        free(sact); sact = NULL;
}

int main() {

    printf("Testing decompose\n");
    {
        testing(50, "[1,3,5,8,49]");
        testing(44, "[2,3,5,7,43]");
        testing(625, "[2,5,8,34,624]");
        testing(2, "[]");
    }

}
