#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int lengthSupUK(int n, int k) {
    int fibos[n+1];
    fibos[0] = 1;
    fibos[1] = 1;

    int count = 0;

    for (int i = 3 ; i <= n ; ++i) {
        int curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1];

        if (curr >= k)
            count++;

        fibos[i-1] = curr;
    }

    return count;
}

int comp(int n) {
    int fibos[n+1];
    fibos[0] = 1;
    fibos[1] = 1;

    int count = 0;

    for (int i = 3 ; i <= n ; ++i) {
        int curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1];

        if (curr < fibos[i-2])
            count++;

        fibos[i-1] = curr;
    }

    return count;
}

void dotest1(int n, int k, int expr) {
    int act = lengthSupUK(n, k);
    if(act != expr)
        printf("Expected %d, got %d\n", expr, act);
    assert(act == expr);
}
void dotest2(int n, int expr) {
    int act = comp(n);
    if(act != expr)
        printf("Expected %d, got %d\n", expr, act);
    assert(act == expr);
}

int main() {
    printf("lengthSupUK\n");
    {
        dotest1(50, 25, 2);
        dotest1(3332, 973, 1391);
        dotest1(2941, 862, 1246);
        dotest1(3177, 573, 2047);
    }
    printf("comp\n");
    {
        dotest2(74626, 37128);
        dotest2(71749, 35692);
        dotest2(56890, 28281);
        dotest2(60441, 30054);
    }
}
