#!/usr/bin/env python3

from collections import defaultdict

def freqQuery(queries):
    values = defaultdict(lambda: 0)
    freqs = defaultdict(lambda: 0)
    result = []

    for op, x in queries:
        if op == 1:
            freqs[values[x]] -= 1
            values[x] += 1
            freqs[values[x]] += 1
        elif op == 2:
            if values[x] > 0:
                freqs[values[x]] -= 1
                values[x] -= 1
                freqs[values[x]] += 1
        else:
            result.append(int(freqs[x] > 0))

    return result

print(freqQuery([(1, 1), (2, 2), (3, 2), (1, 1), (1,1), (2,1), (3, 2)]))
