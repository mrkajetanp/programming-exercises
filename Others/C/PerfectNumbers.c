#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int a) {
    int cnt = 1;

    int i;
    for (i = 2 ; i <= a ; ++i) {
        if (a % i == 0)
            cnt++;

        if (cnt > 2)
            return false;
    }


    return true;
}

void perfect_below(int a) {
    int num = 0;
    int p = 2;

    while (num < a) {
        while (!is_prime(p))
            p++;

        num = pow(2, p-1)*(pow(2, p) - 1);
        p++;

        if (num < a)
            printf("%d\n", num);
    }
}

int main() {
    perfect_below(9000);
    return 0;
}
