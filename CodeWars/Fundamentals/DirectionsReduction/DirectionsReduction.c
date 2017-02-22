#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char ** dirReduc (char** arr, int sz, int* lg);
char** deleteArrItem (char **arr, int* size, int index);
char* joinStringsStringArray (char *strings[], int count);
void doTest (char** arr, int sz, char* expr);
int ifEqual (char* a, char* b);
void tests ();

int main () {
    tests ();
    return 0;
}

// arr: directions to reduce, sz: size of arr, lg size of returned array
char** dirReduc(char** arr, int sz, int* lg) {
    int i = 0;
    while (i != sz) {
        if (sz == 1)
            break;
        if ((strcmp (arr[i], "NORTH") == 0 && strcmp(arr[i+1],"SOUTH")==0) ||
            (strcmp (arr[i], "SOUTH") == 0 && strcmp (arr[i+1],"NORTH") == 0) ||
            (strcmp (arr[i], "WEST") == 0 && strcmp (arr[i+1],"EAST") == 0) ||
            (strcmp (arr[i], "EAST") == 0 && strcmp (arr[i+1],"WEST") == 0)) {
            deleteArrItem(arr, &sz, i);
            deleteArrItem(arr, &sz, i);
            i = 0;
            continue;
        }
        i++;
    }
    *lg = sz;
    return arr;
}

char** deleteArrItem (char **arr, int* size, int index) {
    int i;
    for (i = index ; i < (*size)-1 ; ++i)
        arr[i] = arr[i+1];
    (*size)--;
    return arr;
}

void tests () {
    char* d1[7] = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    doTest(d1, 7, "{WEST}");
    /* char* d2[4] = {"NORTH", "WEST", "SOUTH", "EAST"}; */
    /* doTest(d2, 4,  "{NORTH, WEST, SOUTH, EAST}"); */

}

void doTest (char** arr, int sz, char* expr) {
    int lg = -1;
    char** act = dirReduc(arr, sz, &lg);
    char* sact = joinStringsStringArray (act, lg);
    if (strcmp(sact, expr) != 0)
        printf("Expected:\n%s\nGot:\n%s\n", expr, sact);
    assert (strcmp(sact, expr) == 0);
    act = NULL;
    free (sact);
    sact = NULL;
}

char* joinStringsStringArray (char *strings[], int count) {
    char *result = malloc (sizeof(char)*count*2);
    strcat (result, "{");
    int i;
    for (i = 0 ; i < count ; ++i) {
        strcat (result, strings[i]);
        if (i != count-1)
            strcat (result, ", ");
    }
    strcat (result, "}");
    return result;
}


