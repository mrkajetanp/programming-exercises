#!/usr/bin/env python3

def countSwaps(s):
    result = 0

    for i in range(len(s)):
        for j in range(len(s)-1):
            if s[j] > s[j+1]:
                s[j], s[j+1] = s[j+1], s[j]
                result += 1

    print("Array is sorted in {} swaps.".format(result))
    print("First Element: {}".format(s[0]))
    print("Last Element: {}".format(s[-1]))


print(countSwaps([1, 2, 3]))
print(countSwaps([6, 4, 2]))
print(countSwaps([3, 2, 1]))
