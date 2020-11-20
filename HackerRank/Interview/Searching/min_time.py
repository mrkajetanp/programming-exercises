#!/usr/bin/env python3

from math import ceil
from collections import Counter

def minTime(machines, goal):
    c = Counter(machines)
    fastest = min(c)
    min_days = 1
    max_days = ceil((fastest*goal)/c[fastest])
    while max_days - min_days > 1:
        mid = (min_days + max_days) // 2
        output = sum((mid//x)*y for x, y in c.items())
        if output < goal:
            min_days = mid
        else:
            max_days = mid
    return max_days


print(minTime([1, 3, 5], 30))
print(minTime([2, 3], 5))
print(minTime([1, 3, 4], 10))
print(minTime([4, 5, 6], 12))
