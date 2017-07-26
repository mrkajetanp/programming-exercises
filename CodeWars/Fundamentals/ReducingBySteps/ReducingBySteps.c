#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

long long gcdi(long long a, long long b) {
    return (b == 0) ? llabs(a) : gcdi(b, a%b);
}

long long lcmu(long long a, long long b) {
    return (llabs(a)*llabs(b)) / gcdi(llabs(a), llabs(b));
}

long long som(long long a, long long b) {
    return a+b;
}

long long maxi(long long a, long long b) {
    return (a > b) ? a : b;
}

long long mini(long long a, long long b) {
    return (a < b) ? a : b;
}

typedef long long (*generic_func_t) (long long, long long);

long long* operArray(generic_func_t f, long long* arr, int sz, long long init) {
    long long* result = malloc(sz * sizeof *result);
    int idx = 0;

    result[idx++] = f(init, arr[0]);
    for (int i = 0 ; i < sz-1 ; ++i)
        result[idx++] = f(result[i], arr[i+1]);

    return result;
}

char* array2StringLongLong(long long* arr, int size) {
    char* result = malloc(size * 7);
    strcpy(result, "");

    char temp[50];
    strcpy(temp, "");
    for (int i = 0 ; i < size ; ++i) {
        sprintf(temp, "%lld", arr[i]);
        strcat(result, temp);
        strcat(result, ", ");
        strcpy(temp, "");
    }
    result[strlen(result)-2] = '\0';

    return result;
}

void dotest(generic_func_t f, long long* dta, int sz, long long init, char *expr) {
    long long *act = operArray(f, dta, sz, init);
    char* sact = array2StringLongLong(act, sz);
    char *sdta = array2StringLongLong(dta, sz);
    if(strcmp(sact, expr) != 0)
        printf("Error. Expected \n%s\n but got \n%s\n", expr, sact);
    assert(strcmp(sact, expr) == 0);
    free(sact); free(sdta); free(act);
}

int main() {
    printf("Fixed test Gcdi\n");
    {
        long long dta[6] = { 18, 69, -90, -78, 65, 40 };
        char* sol = "18, 3, 3, 3, 1, 1";
        dotest(gcdi, dta, 6, dta[0], sol);
    }
    printf("Fixed test lcmu\n");
    {
        long long dta[6] = { 18, 69, -90, -78, 65, 40 };
        char* sol = "18, 414, 2070, 26910, 26910, 107640";
        dotest(lcmu, dta, 6, dta[0], sol);
    }
    printf("Fixed test maxi\n");
    {
        long long dta[6] = { 18, 69, -90, -78, 65, 40 };
        char* sol = "18, 69, 69, 69, 69, 69";
        dotest(maxi, dta, 6, dta[0], sol);
    }
}
