#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

typedef struct _Pair {
    int small_palind;
    int larg_palind;
} Pair;

Pair getPalindromeProduct(int, int);

#endif
