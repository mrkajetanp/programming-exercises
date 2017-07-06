#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sieve.h"

unsigned int sieve(const unsigned int limit, primesArray_t primes) {
    if (limit <= 1)
        return 0;

    int prime_count = 0;

    bool prime_mask[limit+1];
    for (unsigned i = 0 ; i < limit+1 ; ++i)
        prime_mask[i] = true;

    unsigned i = 2;
    while (pow(i, 2) < limit) {
        if (prime_mask[i]) {
            unsigned j = i*2;
            while (j <= limit) {
                prime_mask[j] = false;
                j += i;
            }
        }
        i++;
    }

    prime_mask[0] = false;
    prime_mask[1] = false;

    for (unsigned i = 0 ; i < limit+1 ; ++i) {
        if (prime_mask[i])
            primes[prime_count++] = i;
    }

    return prime_count;
}
