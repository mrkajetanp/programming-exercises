#!/usr/bin/env python3

def countTriplets(arr, r):
    count = 0
    singles = {}
    pairs = {}

    for i in reversed(arr):
        if i*r in pairs:
            count += pairs[i*r]
        if i*r in singles:
            pairs[i] = pairs.get(i, 0) + singles[i*r]

        singles[i] = singles.get(i, 0) + 1

    return count

print(countTriplets([1, 2, 2, 4], 2))
print(countTriplets([1, 3, 9, 9, 27, 81], 3))
print(countTriplets([1, 5, 5, 25, 125], 5))
