#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

long long* john(long long n) {
    long long* johns = malloc(sizeof *johns * n);
    johns[0] = 0;
    johns[1] = 0;

    long long anns[n];
    anns[0] = 1;
    anns[1] = 1;

    for (long long i = 2 ; i < n ; ++i) {
        anns[i] = i - johns[anns[i-1]];
        johns[i] = i - anns[johns[i-1]];
    }

    return johns;
}

long long sumJohn(long long n) {
    long long sum = 0;
    long long* johns = john(n);

    for (long long i = 0 ; i < n ; ++i)
        sum += johns[i];

    free(johns);
    return sum;
}

long long* ann(long long n) {
    long long* anns = malloc(sizeof *anns * n);
    anns[0] = 1;
    anns[1] = 1;

    long long johns[n];
    johns[0] = 0;
    johns[1] = 0;

    for (long long i = 2 ; i < n ; ++i) {
        anns[i] = i - johns[anns[i-1]];
        johns[i] = i - anns[johns[i-1]];
    }

    return anns;
}

long long sumAnn(long long n) {
    long long sum = 0;
    long long* anns = ann(n);

    for (long long i = 0 ; i < n ; ++i)
        sum += anns[i];

    free(anns);
    return sum;
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

void dotestJohn(int n, long long* exp) {
    char *s1 = array2StringLongLong(exp, n);
    long long* act = john(n);
    char *s2 = array2StringLongLong(act, n);
    if(strcmp(s1, s2) != 0)
        printf("Error. Expected %s\n but got %s\n", s1, s2);
    assert(strcmp(s1, s2) == 0);
    free(s1); s1 = NULL;
    free(s2); s2 = NULL;
}

void dotestsumJohn(int n, long long exp) {
    long long act = sumJohn(n);
    if(act != exp)
        printf("Error. Expected %llu\n but got %llu\n", exp, act);
    assert(act == exp);
}

void dotestAnn(int n, long long* exp)
{
    char *s1 = array2StringLongLong(exp, n);
    long long* act = ann(n);
    char *s2 = array2StringLongLong(act, n);
    if(strcmp(s1, s2) != 0)
        printf("Error. Expected %s\n but got %s\n", s1, s2);
    assert(strcmp(s1, s2) == 0);
    free(s1); s1 = NULL;
    free(s2); s2 = NULL;
}

void dotestsumAnn(int n, long long exp) {
    long long act = sumAnn(n);
    if(act != exp)
        printf("Error. Expected %llu\n but got %llu\n", exp, act);
    assert(act == exp);
}

int main() {
    printf("john\n");
    {
        long long sol1[11] = {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6};
        dotestJohn(11, sol1);
        long long sol2[14] = {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8};
        dotestJohn(14, sol2);
    }
    printf("ann\n");
    {
        long long sol1[6] = {1, 1, 2, 2, 3, 3};
        dotestAnn(6, sol1);
        long long sol2[15] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9};
        dotestAnn(15, sol2);
    }
    printf("sumJohn\n");
    {
        dotestsumJohn(75, 1720);
        dotestsumJohn(78, 1861);
    }

    printf("sumAnn\n");
    {
        dotestsumAnn(115, 4070);
        dotestsumAnn(150, 6930);
    }
}
