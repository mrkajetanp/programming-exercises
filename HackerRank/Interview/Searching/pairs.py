#!/usr/bin/env python3

def pairs(k, arr):
    result = 0
    i = 0
    j = 1

    arr = sorted(arr)

    while j < len(arr):
        diff = arr[j] - arr[i]

        if diff == k:
            result += 1
            j += 1
        elif diff > k:
            i += 1
        elif diff < k:
            j += 1

    return result


print(pairs(2, [1, 5, 3, 4, 2]))
