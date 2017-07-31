#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

int rank_name(char* name) {
    int result = strlen(name);

    for (size_t i = 0 ; i < strlen(name) ; ++i)
        result += tolower(name[i]) - 'a' + 1;

    return result;
}

char* array2StringInt(int *array, size_t sz);

char* nthRank(char* st, int* we, int n) {
    if (strlen(st) == 0)
        return "No participants";

    int count = 0;
    for (size_t i = 0 ; i < strlen(st) ; ++i) {
        if (st[i] == ',')
            count++;
    }

    if (n > count)
        return "Not enough participants";

    char *names[count];
    char buff[strlen(st)+2];
    strcpy(buff, st);

    count = 0;
    char* pch = strtok(buff, ",");
    while (pch != NULL) {
        names[count++] = pch;
        pch = strtok(NULL, ",");
    }

    return NULL;
}

char* array2StringInt(int *array, size_t sz) {
    char* result = malloc(sz * 8);
    strcpy(result, "[ ");

    char buff[10];

    for (size_t i = 0 ; i < sz ; ++i) {
        sprintf(buff, "%d", array[i]);
        strcat(result, buff);
        strcat(result, ", ");
    }
    result[strlen(result)-2] = '\0';
    strcat(result, " ]");

    return result;
}

void dotest(char* st, int* we, int n, int szarray, char* sexpr) {
    char* sact = nthRank(st, we, n);
    char* sarr = array2StringInt(we, szarray);
    printf("st: %s / we: %s / nth: %d Expected: %s\n", st, sarr, n, sexpr);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    free(sarr); sarr = NULL;
}

int main() {

    {
        char* st = "";
        int we[7] = {4, 2, 1, 4, 3, 1, 2};
        dotest(st, we, 4, 7, "No participants");
    }
    {
        char* st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
        int we[7] = {4, 2, 1, 4, 3, 1, 2};
        dotest(st, we, 4, 7, "Benjamin");
    }
    {
        char* st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
        int we[6] = {1, 3, 5, 5, 3, 6};
        dotest(st, we, 2, 6, "Matthew");
    }
    {
        char* st = "Aubrey,Olivai,Abigail,Chloe,Andrew,Elizabeth";
        int we[6] = {3, 1, 4, 4, 3, 2};
        dotest(st, we, 4, 6, "Abigail");
    }
}
