#!/usr/bin/env python3

def minimumSwaps(arr):
    swaps = 0

    val_idx = dict(zip(arr, range(1, len(arr) + 1)))
    print(val_idx)

    for i in range(1, len(arr) + 1):
        if val_idx[i] != i:
            val_idx[arr[i-1]] = val_idx[i]
            arr[val_idx[i]-1] = arr[i-1]
            swaps += 1

    return swaps

print(minimumSwaps([7, 1, 3, 2, 4, 5, 6]))
print(minimumSwaps([4, 3, 1, 2]))
print(minimumSwaps([2, 3, 4, 1, 5]))
print(minimumSwaps([1, 3, 5, 2, 4, 6, 7]))
