#!/usr/bin/env python3

def maxMin(k, arr):
    arr = sorted(arr)
    min_unfair = arr[k-1] - arr[0]

    for i in range(len(arr)-k+1):
        min_unfair = min(min_unfair, arr[i+k-1] - arr[i])

    return min_unfair

print(maxMin(3, [10, 100, 300, 200, 1000, 20, 30]))
print(maxMin(4, [1, 2, 3, 4, 10, 20, 30, 40, 100, 200]))
print(maxMin(2, [1, 2, 1, 2, 1]))
