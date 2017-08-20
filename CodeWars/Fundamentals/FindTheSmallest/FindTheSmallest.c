#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int smallest_idx_between(char* str, int start, int end) {

    int smallest = start;

    for (int i = start ; i < end ; ++i) {
        if (str[i]-'0' < str[smallest]-'0')
            smallest = i;
    }

    return smallest;
}

long long* smallest(long long n) {
    long long* result = malloc(3 * sizeof *result);
    char temp[100];
    sprintf(temp, "%lld", n);

    int min_idx = 0;
    int tmp = -1;
    do {
        tmp++;
        min_idx = smallest_idx_between(temp, tmp, strlen(temp));
    } while (min_idx == 0);

    char temp_char = temp[min_idx];
    for (size_t i = min_idx+1 ; i < strlen(temp) ; ++i)
        temp[i-1] = temp[i];
    temp[strlen(temp)-1] = '\0';

    if (tmp > 0) {
        temp[strlen(temp)+1] = '\0';
        int i;
        for (i = strlen(temp) ; i >= tmp+1 ; --i) {
            temp[i] = temp[i-1];
        }

        temp[i] = temp_char;
        result[0] = atoi(temp);
    } else {
        result[0] = atoi(temp);
        sprintf(temp, "%c%lld", temp_char, result[0]);
        result[0] = atoi(temp);
    }

    if (temp_char != '0' || min_idx > 1) {
        result[1] = min_idx;
        result[2] = tmp;
    } else {
        result[1] = 0;
        result[2] = min_idx;
   }

    printf("n: %lld ; m_i: %d ; tmp: %d ; %c\n", n, min_idx, tmp, temp_char);

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


void dotest(long long n, char *expr) {
    long long* act = smallest(n);
    char* sact = array2StringLongLong(act, 3);
    if(strcmp(sact, expr) != 0)
        printf("step. Error. Expected \n%s\n but got \n%s\n", expr, sact);
    assert(strcmp(sact, expr) == 0);
    free(act); act = NULL;
    free(sact); sact = NULL;
}

int main() {
    dotest(261235, "126235, 2, 0");
    dotest(209917, "29917, 0, 1");
    dotest(285365, "238565, 3, 1");
    dotest(296837, "239687, 4, 1");
    dotest(269045, "26945, 3, 0");
}
