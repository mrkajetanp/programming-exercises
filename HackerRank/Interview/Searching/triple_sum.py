#!/usr/bin/env python3

def triplets(a, b, c):
    result = 0

    a = list(sorted(set(a)))
    b = list(sorted(set(b)))
    c = list(sorted(set(c)))

    ai = 0
    bi = 0
    ci = 0

    while bi < len(b):
        while ai < len(a) and a[ai] <= b[bi]:
            ai += 1

        while ci < len(c) and c[ci] <= b[bi]:
            ci += 1

        result += ai * ci
        bi += 1

    return result


print(triplets([3, 5, 7], [3, 6], [4, 6, 9]))
print(triplets([1, 3, 5], [2, 3], [1, 2, 3]))
print(triplets([1, 4, 5], [2, 3, 3], [1, 2, 3]))
print(triplets([1, 3, 5, 7], [5, 7, 9], [7, 9, 11, 13]))
