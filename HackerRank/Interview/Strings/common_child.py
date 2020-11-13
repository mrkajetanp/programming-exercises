#!/usr/bin/env python3

def commonChild(a, b):
    C = [[0 for y in range(len(b)+1)] for x in range(len(a)+1)]

    for i in range(1, len(a)+1):
        for j in range(1, len(b)+1):
            if a[i-1] == b[j-1]:
                C[i][j] = C[i-1][j-1] + 1
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])

    return C[len(b)][len(a)]

print(commonChild("HARRY", "SALLY"))
print(commonChild("AA", "BB"))
print(commonChild("SHINCHAN", "NOHARAAA"))
print(commonChild("ABCDEF", "FBDAMN"))
