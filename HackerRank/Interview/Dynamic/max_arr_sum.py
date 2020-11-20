#!/usr/bin/env python3

import math

def maxSubsetSum(arr):
    if len(arr) == 0:
        return 0

    if len(arr) == 1:
        return arr[0]

    mval = max(arr[0], arr[1])
    arr[1] = mval

    for i in range(2, len(arr)):
        mval = max(mval, arr[i-2] + arr[i], arr[i])
        arr[i] = mval

    return mval

print(maxSubsetSum([3, 7, 4, 6, 5]))
