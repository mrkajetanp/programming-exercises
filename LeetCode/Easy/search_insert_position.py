#!/usr/bin/env python3

def search_insert(nums, target: int) -> int:
    start = 0
    end = len(nums) - 1
    mid = 0

    while start <= end:
        mid = (start + end) // 2
        curr = nums[mid]

        if curr == target:
            return mid
        if target < curr:
            end = mid - 1
        else:
            start = mid + 1

    return mid + 1 if nums[mid] < target else mid
