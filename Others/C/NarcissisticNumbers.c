#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_narcissistic(int a) {
    int n_digits = 1;
    int temp = a;
    while ((temp /= 10) > 0)
        n_digits++;

    if (n_digits == 1)
        return false;

    int sum = 0;
    temp = a;

    while (temp > 0) {
        sum += pow(temp%10, n_digits);
        temp /= 10;
    }

    return sum == a;
}

void narcissistic(int a) {
    for (int i = 1 ; i < a ; ++i) {
        if (is_narcissistic(i))
            printf("%d, ", i);
    }
    printf("\n");
}


int main() {
    narcissistic(20000);

    return 0;
}
