#include <iostream>
#include <cassert>

class ColorChoice {
public:
    static long long checkChoose(long long m, int n);
    static long long binCoef (long long n, int x);
};

long long ColorChoice::binCoef (long long n, int x) {
    long long res = 1;

    if ( x > n - x )
        x = n - x;

    for (int i = 0; i < x; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

long long ColorChoice::checkChoose (long long m, int n) {
    for (int i = 0 ; i < n ; ++i)
        if (ColorChoice::binCoef(n, i) == m)
            return i;
    return -1;
}

void tests () {
    assert(ColorChoice::checkChoose(6, 4) == 2);
    assert(ColorChoice::checkChoose(4, 4) == 1);
    assert(ColorChoice::checkChoose(4, 2) == -1);
    assert(ColorChoice::checkChoose(35, 7) == 3);
    assert(ColorChoice::checkChoose(155117520, 30) == 15);
}

int main () {
    tests();

    return 0;
}
