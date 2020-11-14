#!/usr/bin/env python3

from collections import Counter

def whatFlavors(cost, money):
    costs_freqs = dict(Counter(cost))
    cost_idx = { i+1:v for i, v in enumerate(cost) }

    for i in cost_idx:
        complement = money - cost_idx[i]
        if complement in costs_freqs:
            if cost.index(complement) == i-1:
                continue
            result = [i, cost.index(complement)+1]
            print(min(result), max(result))
            return


print(whatFlavors([1, 4, 5, 3, 2], 4))
print(whatFlavors([2, 2, 4, 3], 4))
