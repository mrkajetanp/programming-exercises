#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

double f(double x) {
    return x / (sqrt((x + 1.0)) + 1.0);
}

void assertFuzzyEquals(double act, double exp)
{
    bool inrange;
    double merr = 1e-12;
    long double e;
    if (exp == 0.0) {
        e = fabsl(act);
    }
    else
        {
            e = fabsl((act - exp) / exp);
        }
    inrange = (e <= merr);
    //printf("Expected: %1.16e got: %1.16e. Error: %1.16e\n", exp ,act, (double)e);
    if (inrange == false)
        {
            printf("Expected should be near: %1.16e , but got: %1.16e\n", exp ,act);
        }
    assert(inrange == 1);
}

void dotest(double x, double expected)
{
    assertFuzzyEquals(f(x), expected);
}

int main() {
    dotest(2.6e-08, 1.29999999155e-08);
    dotest(1.4e-09, 6.999999997549999e-10);
    dotest(5.0e-06, 2.499996875007812e-06);
    dotest(2.4e-07, 1.1999999280000085e-07);
}
