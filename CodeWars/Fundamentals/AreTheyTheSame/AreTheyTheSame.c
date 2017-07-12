#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int cmp(const void* a, const void* b) {
    if (*(int*)a == *(int*)b)
        return 0;

    if (*(int*)a > *(int*)b)
        return 1;

    return -1;
}

bool comp(int* a, int* b, size_t sizeArray) {
    int arr_a[sizeArray];
    int arr_b[sizeArray];

    for (size_t i = 0 ; i < sizeArray ; ++i) {
        arr_a[i] = pow(a[i], 2);
        arr_b[i] = b[i];
    }

    qsort(arr_a, sizeArray, sizeof(int), cmp);
    qsort(arr_b, sizeArray, sizeof(int), cmp);

    for (size_t i = 0 ; i < sizeArray ; ++i) {
        if (arr_a[i] != arr_b[i])
            return false;
    }

    return true;
}

void dotest(int *d1, int *d2, int k, bool exp) {
    bool act = comp(d1, d2, k);

    if(act != exp)
        printf("Error. Expected %d but got %d\n", exp, act);
    assert(act == exp);
}

int main() {
    {
        int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
        int b[8] = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
        dotest(a, b, 8, true);
    }
    {
        int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
        int b[8] = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
        dotest(a, b, 8, false);
    }
    {
        int a[9] = {121, 144, 19, 161, 19, 144, 19, 11, 1008};
        int b[9] = {14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340};
        dotest(a, b, 9, false);
    }
}
