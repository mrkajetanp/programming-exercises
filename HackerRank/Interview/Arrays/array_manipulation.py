#!/usr/bin/env python3

def arrayManipulation(n, queries):
    # +1 to account for sums stretching to the end of the array
    array = [0] * (n+1)
    for query in queries:
        start, end, val = query
        # Add delimeters around the area which should be summed
        array[start-1] += val
        array[end] -= val

    max_val = 0
    val_sum = 0
    for x in array:
        val_sum += x
        max_val = max(max_val, val_sum)

    return max_val



print(arrayManipulation(10, [[1, 5, 3], [4, 8, 7], [6, 9, 1]]))
print(arrayManipulation(5, [[1, 2, 100], [2, 5, 100], [3, 4, 100]]))
