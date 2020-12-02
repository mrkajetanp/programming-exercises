#!/usr/bin/env python3

def longestCommonPrefix(self, strs) -> str:
    if len(strs) == 0:
        return ""

    prefix = strs[0]
    for i in range(len(strs)):
        while not strs[i].startswith(prefix):
            prefix = prefix[:-1]
            if len(prefix) == 0:
                return ""

    return prefix
