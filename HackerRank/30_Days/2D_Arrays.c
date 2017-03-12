#include <stdio.h>
#include <limits.h>

int main(){
    int arr[6][6] = {
        { -1, -1, 0, -9, -2, -2, },
        { -2, -1, -6, -8, -2, -5, },
        { -1, -1, -1, -2, -3, -4, },
        { -1, -9, -2, -4, -4, -5, },
        { -7, -3, -3, -2, -9, -9, },
        { -1, -3, -1, -2, -4, -5, }
    };

    int max = INT_MIN;
    int current = 0;
    int i, j;
    for (i = 0 ; i < 4 ; ++i) {
        for (j = 0 ; j < 4 ; ++j) {
            current += arr[i][j] + arr[i][j+1] + arr[i][j+2];
            current += arr[i+1][j+1];
            current += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (current > max)
                max = current;
            current = 0;
        }
    }
    printf("%d\n", max);
    return 0;
}
