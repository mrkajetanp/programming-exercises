#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long thirt(long long n) {
    long long new_num = n;
    long long old_num = n-1;

    long long rems[] = { 1, 10, 9, 12, 3, 4 };

    while (new_num != old_num) {
        old_num = new_num;

        long long tmp = old_num;
        int arr_cnt = 0;
        int arr[100];

        do {
            arr[arr_cnt++] = tmp%10;
        } while ((tmp /= 10) > 0);

        new_num = 0;
        for (int i = 0 ; i < arr_cnt ; ++i)
            new_num += arr[i]*rems[i%6];
    }

    return new_num;
}

void testequal(long long n, long long exp) {
    long long act = thirt(n);
    if(act != exp)
        printf("Error. Expected %lld but got %lld\n", exp, act);
    assert(exp == act);
}

int main() {
    testequal(8529, 79);
    testequal(85299258, 31);
    testequal(5634, 57);
    testequal(1111111111, 71);
    testequal(987654321, 30);

    return 0;
}
