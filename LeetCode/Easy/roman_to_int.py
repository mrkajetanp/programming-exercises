#!/usr/bin/env python3

def romanToInt(s: str) -> int:
    roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    result = 0
    last = None

    for x in s:
        if last is not None and roman[last] < roman[x]:
            result -= 2*roman[last]
        result += roman[x]
        last = x

    return result
