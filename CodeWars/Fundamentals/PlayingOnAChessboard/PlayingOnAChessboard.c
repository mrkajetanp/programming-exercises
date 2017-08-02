#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* game (unsigned long long n) {
    char* result = malloc(30);

    if (n%2 == 0)
        sprintf(result, "[%lld]", n/2*n);
    else
        sprintf(result, "[%lld, %d]", n*n, 2);

    return result;
}

void dotest(unsigned long long n, char *expr)
{
    char *act = game(n);
    if(strcmp(act, expr) != 0)
        printf("Error. Expected %s but got %s\n", expr, act);
    assert(strcmp(act, expr) == 0);
}

int main() {
    {
        dotest(0, "[0]");
        dotest(1, "[1, 2]");
        dotest(8, "[32]");
        dotest(40, "[800]");
        dotest(101, "[10201, 2]");
    }
}


