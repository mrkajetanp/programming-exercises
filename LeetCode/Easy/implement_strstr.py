#!/usr/bin/env python3

def strStr(haystack: str, needle: str) -> int:
    if len(needle) == 0:
        return 0

    if len(haystack) == 0:
        return -1

    for i in range(len(haystack)):
        if i+len(needle) > len(haystack):
            return -1

        for j in range(len(needle)):
            if needle[j] == haystack[i+j]:
                if j == len(needle)-1:
                    return i
            else:
                break

    return -1
