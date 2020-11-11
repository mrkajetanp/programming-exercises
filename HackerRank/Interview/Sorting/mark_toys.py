#!/usr/bin/env python3


def maximumToys(prices, k):
    count = 0

    for x in sorted(prices):
        if k >= x:
            k -= x
            count += 1

    return count

print(maximumToys([1, 12, 5, 111, 200, 1000, 10], 50))
