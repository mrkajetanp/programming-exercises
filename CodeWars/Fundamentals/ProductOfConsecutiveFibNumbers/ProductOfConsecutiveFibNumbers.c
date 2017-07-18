#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

unsigned long long* productFib(ull prod) {
    ull* result = malloc(sizeof(ull) * 3);

    ull a = 0;
    ull b = 1;

    while (a*b < prod) {
        ull tmp = a;
        a = b;
        b += tmp;
    }

    result[0] = a;
    result[1] = b;
    result[2] = (a*b == prod);

    return result;
}

void dotest(ull n, ull a, ull b, ull f) {
    ull* result = productFib(n);

    assert(result[0] == a);
    assert(result[1] == b);
    assert(result[2] == f);

    free(result);
}

int main() {
    dotest(4895, 55, 89, 1);
    dotest(5895, 89, 144, 0);
    dotest(74049690, 6765, 10946, 1);
}
