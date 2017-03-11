#include <stdio.h>

long decimal_to_binary(long n) {
    long binary = 0;
    long i = 1;
    while (n != 0) {
        int remainder = n%2;
        n = n/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

int longest_consecutive_one(long n) {
    long i;
    int counter = 0;
    int biggest_counter = 0;
    for (i = n ; i > 0 ; i /= 10) {
        if (i%10 == 1)
            counter++;
        else if (i%10 == 0) {
            if (counter > biggest_counter)
                biggest_counter = counter;
            counter = 0;
        }
    }
    return counter;
}

int main() {
    printf("Binary of 25 is %ld \n", decimal_to_binary(5));
    printf("Binary of 65535 is %ld \n", decimal_to_binary(65535));
    int l1 = longest_consecutive_one(decimal_to_binary(5));
    int l2 = longest_consecutive_one(decimal_to_binary(65535));
    printf("l1: %d \n", l1);
    printf("l2: %d \n", l2);

    return 0;
}
