#!/usr/bin/env python3

import bisect

def maximumSum(a, m):
    prefix = [x for x in a]

    for i in range(1, len(a)):
        prefix[i] = (prefix[i-1] + prefix[i]) % m

    result = -100
    processed = []

    for i in range(len(prefix)):
        bisect.insort(processed, prefix[i])
        idx = bisect.bisect_right(processed, prefix[i])
        if idx != len(processed):
            result = max(result, (prefix[i] - processed[idx] + m) % m)

    return result


print(maximumSum([1, 2, 3, 4, 5, 6, 7, -8, 2, 12, 11], 15))
print(maximumSum([3, 3, 9, 9, 5], 7))
print(maximumSum([1, 2, 3], 2))
print(maximumSum([1, 5, 9], 5))
