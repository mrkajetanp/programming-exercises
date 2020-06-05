#include "prime_factors.h"
#include <stdbool.h>
#include <math.h>

bool is_prime(uint64_t x);
bool is_prime(uint64_t x) {
    if (x == 2 || x == 3)
        return true;

    if (x%2 == 0)
        return false;

    for (uint64_t i = 3 ; i < (uint64_t)sqrt(x)+1 ; i += 2) {
        if (x%i == 0)
            return false;
    }

    return true;
}

size_t find_factors(uint64_t n, uint64_t factors[]) {
    if (n == 1)
        return 0;

    if (is_prime(n)) {
        factors[0] = n;
        return 1;
    }

    int result_len = 0;

    while (!is_prime(n)) {
        uint64_t i = 2;
        // Find the smallest prime factor of n
        while (!(n%i == 0 && is_prime(i)))
            ++i;

        // Add to factors, divide n by found factor
        factors[result_len++] = i;
        n /= i;
    }

    // If at the end n is prime, it's the last factor
    if (is_prime(n) && n != 1)
        factors[result_len++] = n;

    return result_len;
}
