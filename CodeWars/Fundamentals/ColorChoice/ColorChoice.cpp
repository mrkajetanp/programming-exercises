#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include <boost/math/special_functions/factorials.hpp>

class ColorChoice {
public:
    static long long checkChoose(long long m, int n);
    static long long fct (long long n);
    static long long binCoef (int n, int x);
};

long long ColorChoice::fct (long long n) {
    return (n==1) ? n : n*ColorChoice::fct (n-1);
}

long long ColorChoice::binCoef (int n, int x) {
    return (fct(n)/(fct(x)*fct(n-x)));
}

long long ColorChoice::checkChoose (long long m, int n) {

    for (int i = 0 ; i < n ; ++i) {
    }

    return -1;
}

// FIXME

int main () {
    boost::multiprecision::mpz_int myint = 1213348231121212;
    boost::multiprecision::mpz_int myint2 = 1213348231121212;
    boost::multiprecision::mpz_int sum = myint+myint2;
    std::cout << std::fixed << boost::math::factorial<double>(52);
    return 0;
}
