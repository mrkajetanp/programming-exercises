#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int compare_weight(const void* a, const void* b) {
    char* a_ptr = *((char**)a);
    char* b_ptr = *((char**)b);

    int sum_a = 0;
    for (size_t i = 0 ; i < strlen(a_ptr) ; ++i)
        sum_a += a_ptr[i] - '0';

    int sum_b = 0;
    for (size_t i = 0 ; i < strlen(b_ptr) ; ++i)
        sum_b += b_ptr[i] - '0';

    if (sum_a == sum_b)
        return strcmp(a_ptr, b_ptr);
    else {
        if (sum_a > sum_b)
            return 1;
        else if (sum_a < sum_b)
            return -1;
        else
            return 0;
    }
}

char* order_weight(char* s) {
    int len = strlen(s)+1;
    char input[len];
    strcpy(input, s);

    char* parts[len];
    int parts_len = 0;

    char* pch = strtok(input, " ");
    while (pch != NULL) {
        parts[parts_len++] = pch;
        pch = strtok(NULL, " ");
    }

    qsort(parts, parts_len, sizeof(char*), compare_weight);

    char* result = malloc(len);
    strcpy(result, "");
    for (int i = 0 ; i < parts_len ; ++i) {
        strcat(result, parts[i]);
        strcat(result, " ");
    }
    result[strlen(result)-1] = '\0';

    return result;
}

void dotest(char* s, char *expr) {
    char *act = order_weight(s);

    if(strcmp(act, expr) != 0)
        printf("scale. Error. Expected \n%s\n but got \n%s\n", expr, act);

    assert(strcmp(act, expr) == 0);
}

int main() {
    dotest("103 123 4444 99 2000", "2000 103 123 4444 99");
    dotest("2000 10003 1234000 44444444 9999 11 11 22 123", "11 11 2000 10003 22 123 1234000 44444444 9999");
    dotest("", "");
    dotest("10003 1234000 44444444 9999 2000 123456789", "2000 10003 1234000 44444444 9999 123456789");

    return 0;
}

