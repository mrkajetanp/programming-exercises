#!/usr/bin/env python3

def minimumAbsoluteDifference(arr):
    values = sorted(arr)
    min_value = abs(values[0] - values[1])

    for i in range(1, len(values)):
        min_value = min(min_value, abs(values[i-1] - values[i]))

    return min_value

print(minimumAbsoluteDifference([3, -7, 0]))
print(minimumAbsoluteDifference([-59, -36, -13, 1, -53, -92, -2, -96, -54, 75]))
print(minimumAbsoluteDifference([1, -3, 71, 68, 17]))
