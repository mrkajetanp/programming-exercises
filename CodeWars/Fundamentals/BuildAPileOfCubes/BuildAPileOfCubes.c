
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

long long findNb(long long m) {
    long long n = 1;

    while (pow((n*(n+1)/2.0), 2) < m)
        n++;

    return pow((n*(n+1)/2.0), 2) == m ? n : -1;
}

long long findNb(long long m);

void testequal(long long m, long long  exp)
{
    long long act = findNb(m);
    if(act != exp)
        printf("Error. Expected %lld but got %lld\n", exp, act);
    assert(act == exp);
}

int main() {
    {
        testequal(24723578342962, -1);
        testequal(135440716410000, 4824);
        testequal(26825883955641, 3218);
        testequal(441, 6);
    }
}

