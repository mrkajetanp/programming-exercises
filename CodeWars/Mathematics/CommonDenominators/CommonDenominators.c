#include <stdio.h>
#include <stdlib.h>
#include <check.h>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b,a%b);
}

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a,b);
}

long long vecLcm(const long long lst[][2], int row) {
    long long curr = lst[0][1];
    for (int i = 1 ; i < row ; ++i)
        curr = lcm(curr, lst[i][1]);
    return curr;
}

long long** convertFrac(long long lst[][2], int row) {
    long long* result = malloc(row * 2 * sizeof(long long));
    long long den = vecLcm(lst, row);
    int i;
    for (i = 0 ; i < row ; ++i) {
        *(result + (i*2)) = lst[i][0]*(den/lst[i][1]);
        *(result + (i*2)+1) = den;
    }
    return (long long**)result;
}

char* array2D2StringInt(long long a[][2], int row, int cols) {
    char* res = malloc((row * cols + row*18 + 2+1) * sizeof(char));
    strcpy(res, "");
    strcat(res, "{");

    char* temp = malloc(60*sizeof(char));
    strcpy(temp, "");

    for (int i = 0 ; i < row ; ++i) {
        strcat(res, "{");
        sprintf(temp, "%lld", a[i][0]);
        strcat(res, temp);
        strcat(res, ", ");
        sprintf(temp, "%lld", a[i][1]);
        strcat(res, temp);
        strcat(res, "},");
    }

    res[strlen(res)-1] = '}';
    free(temp);
    return res;
}

void dotest(long long a[][2], int row, char* sexpr) {
    long long** act = convertFrac(a, row);
    char* sdat = array2D2StringInt(a, row, 2);
    char* sact = array2D2StringInt((long long(*)[2])act, row, 2);
    printf("sdat: %s\n", sdat);
    printf("sact: %s\n", sact);

    free(act);
    act = NULL;
    free(sdat);
    sdat = NULL;
    free(sact);
    sact = NULL;
}

void test() {
    long long data[3][2] = { {1, 2}, {1, 3}, {1, 4} };
    dotest(data, 3, "x");
}

/* Test(convertFrac, ShouldPassAllTheTestsProvided) { */
/*     { */
/*         long long data[3][2] = { {1, 2}, {1, 3}, {1, 4} }; */
/*         dotest(data, 3, "{{6, 12},{4, 12},{3, 12}}"); */
/*     } */
/*     { */
/*         long long data[3][2] = { {69, 130}, {87, 1310}, {3, 4} }; */
/*         dotest(data, 3, "{{18078, 34060},{2262, 34060},{25545, 34060}}"); */
/*     } */
/*     { */
/*         long long data[3][2] = { {77, 130}, {84, 131}, {3, 4} }; */
/*         dotest(data, 3, "{{20174, 34060},{21840, 34060},{25545, 34060}}"); */
/*     } */
/* } */

int main() {
    test();
    return 0;
}
