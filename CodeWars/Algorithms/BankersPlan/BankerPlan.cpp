#include <iostream>
#include <assert.h>

class BankerPlan {
public:
    static bool fortune (int f0, double p, int c0, int n, double i);
};

bool BankerPlan::fortune (int f0, double p, int c0, int n, double i) {
    p /= 100.0; // convert to %
    i /= 100.0;
    while (f0 > 0 && n > 0) {
        f0 += (f0*p)-c0; // calculate deposit for next year
        c0 += (c0*i); // calculate withdrawal for next year
        n--;
    }

    return (n == 0) ? true : false;
}
int main () {
    assert (BankerPlan::fortune(100000, 1, 2000, 15, 1) == true);
    assert (BankerPlan::fortune(100000, 1, 10000, 10, 1) == true);
    assert (BankerPlan::fortune(100000, 1, 9185, 12, 1) == false);
    assert (BankerPlan::fortune(6722682, 6.5, 448916, 24, 2.6) == true);

    return 0;
}
