#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

char* longestConsec(char* strarr[], int n, int k) {
    if (n == 0 || k > n || k <= 0)
        return "";

    int max_len = 0;
    int long_idx = 0;

    for (int i = 0 ; i < n-k+1 ; ++i) {
        int temp_len = 0;

        for (int j = 0 ; j < k ; ++j)
            temp_len += strlen(strarr[i+j]);

        if (temp_len > max_len) {
            max_len = temp_len;
            long_idx = i;
        }
    }

    char* result = malloc(max_len+1);
    strcpy(result, "");

    for (int i = 0 ; i < k ; ++i)
        strcat(result, strarr[long_idx+i]);

    return result;
}

char* longestConsec(char* strarr[], int n, int k);

void dotest(char* strarr[], int n, int k, char *expr)
{
    char *act = longestConsec(strarr, n, k);
    if(strcmp(act, expr) != 0)
        printf("Error. Expected %s but got %s\n", expr, act);
    assert(strcmp(act, expr) == 0);
}
int main() {
    {
        char* a1[] = {"zone", "abigail", "theta", "form",
                      "libe", "zas", "theta", "abigail"};
        dotest(a1, 8, 2, "abigailtheta");
    }
    {
        char* a1[] = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx",
                      "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
        dotest(a1, 5, 1, "oocccffuucccjjjkkkjyyyeehh");
    }
    {
        char* arr[] = {};
        dotest(arr, 0, 3, "");
    }
    {
        char* arr[] = {"itvayloxrp","wkppqsztdkmvcuwvereiupccauycnjutlv",
                       "vweqilsfytihvrzlaodfixoyxvyuyvgpck"};
        dotest(arr, 3, 2,
               "wkppqsztdkmvcuwvereiupccauycnjutlvvweqilsfytihvrzlaodfixoyxvyuyvgpck");
    }
}
