#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

bool contains(int* arr, int size, int num) {
    for (int i = 0 ; i < size ; ++i) {
        if (arr[i] == num)
            return true;
    }

    return false;
}

void prime_factors(int* dest, int* size, int n) {
    n = abs(n);

    for (int i = 2 ; i < sqrt(n)+1 ; ++i) {
        while (n%i == 0) {
            if (!contains(dest, *size, i))
                dest[(*size)++] = i;
            n /= i;
        }
    }

    if (n > 1) {
        if (!contains(dest, *size, n))
            dest[(*size)++] = n;
    }
}

char* sumOfDivided(int* lst, int len) {
    int factors[100];
    int idx = 0;

    printf("[ ");
    for (int i = 0 ; i < len ; ++i)
        printf("%d ", lst[i]);
    printf("]\n");

    for (int i = 0 ; i < len ; ++i)
        prime_factors(factors, &idx, lst[i]);
    qsort(factors, idx, sizeof(int), compare);

    char* result = malloc(len*20);
    strcpy(result, "");
    char temp[30];

    for (int i = 0 ; i < idx ; ++i) {
        int sum = 0;

        for (int j = 0 ; j < len ; ++j) {
            if (lst[j]%factors[i] == 0)
                sum += lst[j];
        }

        sprintf(temp, "(%d %d)", factors[i], sum);
        strcat(result, temp);
    }

    return result;
}

char* array2StringInt(int* array, size_t sz) {
    char* result = malloc(sz * 10);
    strcpy(result, "[");

    char buff[15];
    for (size_t i = 0 ; i < sz ; ++i) {
        sprintf(buff, "%d", array[i]);
        strcat(result, buff);
        strcat(result, ", ");
    }
    result[strlen(result)-2] = '\0';
    strcat(result, "]");

    return result;
}

void dotest(int* lst, int l, char* sexpr) {
    char* sact = sumOfDivided(lst, l);
    char* slst = array2StringInt(lst, l);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    if (l != 0) {
        free(slst); slst = NULL;
    }
}

int main() {
    {
        int d1[2] = {12, 15};
        char* sol1 = "(2 12)(3 27)(5 15)";
        dotest(d1, 2, sol1);
    }
    {
        int d1[5] = {15,21,24,30,45};
        char* sol1  = "(2 54)(3 135)(5 90)(7 21)";
        dotest(d1, 5, sol1);
    }
    {
        int d1[10] = {107, 158, 204, 100, 118, 123, 126, 110, 116, 100};
        char* sol1 = "(2 1032)(3 453)(5 310)(7 126)(11 110)(17 204)(29 116)(41 123)(59 118)(79 158)(107 107)";
        dotest(d1, 10, sol1);
    }
}
