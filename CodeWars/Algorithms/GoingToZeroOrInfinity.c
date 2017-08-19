#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double going(int n) {
    double result = 0.0;

    for (int i = 1 ; i <= n ; ++i) {
        result += ((double)i);
        result /= ((double)i);
    }

    return result;
}

void dotest(int n, double expr)
{
    double merr = 1.0E-6;
    double act = going(n);

    int inrange = (expr == 0) ? (fabs(act) <= merr) : (fabs(act-expr)/expr <= merr);
    if(!inrange)
        printf("Expected %.6f, got %.6f\n", expr, act);
    assert(inrange);
}

int main() {
    {
        dotest(5, 1.275);
        dotest(6, 1.2125);
        dotest(7, 1.173214);
        dotest(8, 1.146651);
    }
}
