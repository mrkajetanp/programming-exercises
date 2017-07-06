#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "palindrome_products.h"

char* str_rev(char* buff, char* str) {
    int len = strlen(str)-1;

    int cnt = 0;
    for (int i = len ; i >= 0 ; --i)
        buff[cnt++] = str[i];
    buff[cnt] = '\0';

    return buff;
}

bool is_palindrome(int num) {
    char buff[20];
    char buff2[20];
    sprintf(buff, "%d", num);

    return num == atoi(str_rev(buff2, buff));
}

Pair getPalindromeProduct(int from, int to) {
    int min = 0;
    int max = 0;

    for (int i = from ; i <= to ; ++i) {
        for (int j = from ; j <= to ; ++j) {
            int product = i*j;

            if (min == 0 && is_palindrome(product))
                min = product;

            if (product > max && is_palindrome(product))
                max = product;
        }
    }

    Pair result = { min, max };
    return result;
}
