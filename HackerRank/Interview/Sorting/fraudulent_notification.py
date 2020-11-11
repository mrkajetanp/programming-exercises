#!/usr/bin/env python3

import math

def activityNotifications(expenditure, d):
    count = 0

    i1 = math.floor((d-1)/2)
    i2 = math.ceil((d-1)/2)

    counts = [0 for x in range(201)]
    for i in range(d):
        counts[expenditure[i]] += 1

    for i in range(d, len(expenditure)):
        j = 0
        k = 0
        while k <= i1:
            m1 = j
            k += counts[j]
            j += 1

        j = 0
        k = 0
        while k <= i2:
            m2 = j
            k += counts[j]
            j += 1

        m = (m1 + m2) / 2

        if expenditure[i] >= m * 2:
            count += 1

        counts[expenditure[i-d]] -= 1
        counts[expenditure[i]] += 1

    return count

print(activityNotifications([2, 3, 4, 2, 3, 6, 8, 4, 5], 5))
print(activityNotifications([1, 2, 3, 4, 4], 4))
