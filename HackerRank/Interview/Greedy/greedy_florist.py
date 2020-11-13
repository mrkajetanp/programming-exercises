#!/usr/bin/env python3

def getMinimumCost(k, c):
    min_cost = 0
    temp = 0
    previous = 0

    if k >= len(c):
        return sum(c)

    c = sorted(c)

    for x in reversed(c):
        if temp == k:
            temp = 0
            previous += 1
        min_cost += (previous + 1) * x
        temp += 1

    return min_cost


print(getMinimumCost(3, [2, 5, 6]))
print(getMinimumCost(2, [2, 5, 6]))
print(getMinimumCost(3, [1, 3, 5, 7, 9]))
