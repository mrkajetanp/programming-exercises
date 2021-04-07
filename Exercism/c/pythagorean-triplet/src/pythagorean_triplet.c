#include "pythagorean_triplet.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
bool triplet_eq(triplet_t* t1, triplet_t* t2);
triplet_t make_triplet(int a, int b, int c);

int gcd(int a, int b)
{
    int y = 0;
    int x = 0;

    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    while (x % y != 0) {
        int temp = x;
        x = y;
        y = temp % x;
    }
    return y;
}

bool triplet_eq(triplet_t* t1, triplet_t* t2)
{
    return (t1->a == t2->a && t1->b == t2->b && t1->c == t2->c);
}

triplet_t make_triplet(int a, int b, int c)
{
    int max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    int mid_candidate = (max == c) ? b : c;
    int min = (a < mid_candidate) ? a : mid_candidate;
    int mid = (a > mid_candidate) ? a : mid_candidate;
    return (triplet_t) { min, mid, max };
}

triplets_t* triplets_with_sum(uint16_t sum)
{
    if (sum) { }
    triplets_t* result = malloc(sizeof(triplets_t));
    result->count = 0;
    int allocated = 10;
    result->triplets = malloc(sizeof(triplet_t) * allocated);

    int a = 0, b = 0, c = 0;
    int k = 0, n = 0, d = 0;
    bool found = false;

    for (int m = 2; m <= (int)sqrt(sum); ++m) {
        if ((sum / 2) % m != 0)
            continue;

        k = m + ((m % 2 == 0) ? 1 : 2);

        while ((k < 2 * m) && k <= (sum / (2 * m))) {
            if (sum / (2 * m) % k == 0 && gcd(k, m) == 1) {
                d = sum / 2 / (k * m);
                n = k - m;
                a = d * (m * m - n * n);
                b = 2 * d * n * m;
                c = d * (m * m + n * n);
                found = true;
                break;
            }
            k += 2;
        }

        if (found && a + b + c == sum) {
            bool contains = false;
            for (int i = 0; i < result->count; ++i) {
                triplet_t* triplet = &result->triplets[i];
                triplet_t new_candidate = make_triplet(a, b, c);
                if (triplet_eq(triplet, &new_candidate)) {
                    contains = true;
                    break;
                }
            }
            if (!contains) {
                result->triplets[result->count++] = make_triplet(a, b, c);
                printf("adding triplet (%d,%d,%d)\n", a, b, c);
                // Approaching allocated memory, double available space
                if (result->count > allocated * 2 / 3) {
                    allocated *= 2;
                    result->triplets = realloc(result->triplets, sizeof(triplet_t) * allocated);
                }
            }
            found = false;
        }
    }

    return result;
}

void free_triplets(triplets_t* triplets)
{
    free(triplets->triplets);
    free(triplets);
}