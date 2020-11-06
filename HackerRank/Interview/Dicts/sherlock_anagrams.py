#!/usr/bin/env python3

from collections import Counter

def sherlockAndAnagrams(s):
    map = {}

    for i in range(len(s)):
        for j in range(1, len(s) - i + 1):
            key = frozenset(Counter(s[i:i+j]).items())
            map[key] = map.get(key, 0) + 1

    result = 0
    for key in map:
        result += map[key] * (map[key]-1) // 2

    return result


print(sherlockAndAnagrams("abba"))
print(sherlockAndAnagrams("abcd"))
print(sherlockAndAnagrams("ifailuhkqq"))
print(sherlockAndAnagrams("kkkk"))
print(sherlockAndAnagrams("cdcd"))
