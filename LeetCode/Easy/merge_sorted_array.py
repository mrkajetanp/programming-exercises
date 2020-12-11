#!/usr/bin/env python3

def merge(nums1, m: int, nums2, n: int) -> None:
    result = nums1[:n]

    idx = 0
    while nums2:
        while idx < len(result) and nums2[0] > result[idx]:
            idx += 1
        result.insert(idx, nums2.pop(0))

    return result
