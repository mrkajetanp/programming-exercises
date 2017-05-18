#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum_of_divisors(int a) {
    int sum = 0;

    for (int i = 1 ; i < a ; ++i) {
        if (a%i == 0)
            sum += i;
    }

    return sum;
}

void amicable_below(int a) {
    for (int i = 0 ; i < a ; ++i) {
        for (int j = 0 ; j < a ; ++j) {
            if (i < j && sum_of_divisors(i) == j && sum_of_divisors(j) == i)
                printf("(%d, %d) ", i, j);
        }
    }
    printf("\n");
}

int main() {
    amicable_below(1500);

    return 0;
}
