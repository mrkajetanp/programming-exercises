#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

typedef struct _fib {
    ull curr;
    ull next;
} Fibonacci;

ull fib_next(Fibonacci* fib) {
    ull new_next = fib->curr + fib->next;

    fib->curr = fib->next;
    fib->next = new_next;

    return fib->curr;
}

ull perimeter(int n) {
    Fibonacci fib = { .curr = 0, .next = 1 };
    ull result = 0;

    for (int i = 0 ; i <= n ; ++i)
        result += fib_next(&fib);

    return result*4;
}

void dotest(int n, ull expr) {
    ull act = perimeter(n);
    printf("For numbers: %d Expected: %llu Got: %llu\n", n, expr, act);
    if(act != expr)
        printf("Expected %llu, got %llu\n", expr, act);
    assert(act == expr);
}

int main() {
    {
        dotest(5, 80);
        dotest(7, 216);
        dotest(20, 114624);
        dotest(30, 14098308);
    }
}
