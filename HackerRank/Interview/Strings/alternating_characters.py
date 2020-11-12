#!/usr/bin/env python3

def alternatingCharacters(s):
    count = 0

    for i in range(1, len(s)):
        if s[i-1] == s[i]:
            count += 1

    return count

print(alternatingCharacters("AAAA"))
print(alternatingCharacters("BBBBB"))
print(alternatingCharacters("ABABABAB"))
print(alternatingCharacters("BABABA"))
print(alternatingCharacters("AAABBB"))
print(alternatingCharacters("AABAAB"))
