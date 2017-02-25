#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char** towerBuilder (int nFloors) {
    char** res = malloc (sizeof(char*)*nFloors);

    int i;
    for (i = 0 ; i < nFloors ; ++i)
        res[i] = malloc(sizeof(char)*(2*nFloors));

    char* temp = malloc(sizeof(char)*(2*nFloors));
    for (i = 0 ; i < nFloors ; ++i) {
        memset (temp, ' ', nFloors-i-1);
        strcat (res[i], temp);
        strcpy (temp, "");

        memset (temp, '*', i*2+1);
        strcat (res[i], temp);
        strcpy (temp, "");

        memset (temp, ' ', nFloors-i-1);
        strcat (res[i], temp);
        strcpy (temp, "");
    }

    free (temp);

    return res;
}

void tests () {
    int floors = 2;
    char** actual = towerBuilder (floors);

    int i;
    for (i = 0 ; i < floors ; ++i)
        printf ("%s\n", actual[i]);

    floors = 3;

    printf ("\n");

    actual = towerBuilder (floors);

    for (i = 0 ; i < floors ; ++i)
        printf ("%s\n", actual[i]);

    for (i = 0 ; i < floors ; ++i)
        free (actual[i]);

    free (actual);

}

int main () {
    tests ();
    return 0;
}

