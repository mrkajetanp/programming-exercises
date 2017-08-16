#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int arr_idx(char** arr, int sz, char* str) {

    for (int i = 0 ; i < sz ; ++i) {
        if (strcmp(arr[i], str) == 0)
            return i;
    }

    return -1;
}

int tour(char** arrFriends, int szArrFriends, char** ftwns,
         char** townsDist, int szFTwns) {

    char *f_arr[szArrFriends];
    int temp_idx = 0;

    for (int i = 0 ; i < szArrFriends ; ++i) {
        if (arr_idx(ftwns, szFTwns, arrFriends[i]) != -1)
            f_arr[temp_idx++] = arrFriends[i];
    }
    szArrFriends = temp_idx;

    double sum = atof(townsDist[arr_idx(townsDist,
                                        szFTwns,ftwns[arr_idx(ftwns,szFTwns,
                                                              f_arr[0])+1])+1]);

    for (int i = 0 ; i < szArrFriends-1 ; ++i) {
        double d1 = atof(townsDist[arr_idx(townsDist,
                                           szFTwns, ftwns[arr_idx(ftwns,szFTwns,
                                                                  f_arr[i+1])+1])+1]);

        double d2 = atof(townsDist[arr_idx(townsDist,
                                           szFTwns, ftwns[arr_idx(ftwns, szFTwns,
                                                                  f_arr[i])+1])+1]);

        sum += sqrt(d1*d1-d2*d2);
    }

    sum  += atof(townsDist[arr_idx(townsDist,
                                   szFTwns, ftwns[arr_idx(ftwns, szFTwns,
                                                          f_arr[szArrFriends-1])+1])+1]);

    return floor(sum);
}

void dotest(char** arrFriends, int szArrFriends, char** ftwns,
            char** townsDist, int szFTwns, int expr) {
    int act = tour(arrFriends, szArrFriends, ftwns, townsDist, szFTwns);
    if(act != expr)
        printf("Expected %d, got %d\n", expr, act);

    assert(act == expr);
}

int main() {
    {
        char* friends1[5] = { "A1", "A2", "A3", "A4", "A5" };
        char* fTowns1[8] = {"A1", "X1", "A2", "X2", "A3", "X3", "A4", "X4"};
        char* distTable1[8] =
            {"X1", "100.0", "X2", "200.0", "X3", "250.0", "X4", "300.0"};
        dotest(friends1, 5, fTowns1, distTable1, 8, 889);
    }
    {
        char* friends1[2] = { "B1", "B2" };
        char* fTowns1[10] =  {"B1", "Y1", "B2", "Y2", "B3", "Y3", "B4", "Y4", "B5", "Y5"};
        char* distTable1[10] = {"Y1", "50.0", "Y2", "70.0", "Y3",
                                "90.0", "Y4", "110.0", "Y5", "150.0"};
        dotest(friends1, 2, fTowns1, distTable1, 10, 168);
    }
}
