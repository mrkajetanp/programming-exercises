#define true 1
#define false 0

#include <assert.h>

int fortune (int f0, double p, int c0, int n, double i) {
    p /= 100.0;
    i /= 100.0;
    while (f0 > 0 && n > 0) {
        f0 += (f0*p)-c0;
        c0 += (c0*i);
        n--;
    }
    return (n == 0) ? true : false;
}

int main () {
    assert (fortune(100000, 1, 2000, 15, 1) == true);
    assert (fortune(100000, 1, 10000, 10, 1) == true);
    assert (fortune(100000, 1, 9185, 12, 1) == false);
    assert (fortune(6722682, 6.5, 448916, 24, 2.6) == true);
}
