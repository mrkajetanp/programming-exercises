#!/usr/bin/env python3

def isBalanced(s):
    pairs = {')':'(', '}':'{', ']':'['}
    stack = []

    for c in s:
        if c not in pairs:
            stack.append(c)
            continue

        if len(stack) == 0 or stack.pop() != pairs[c]:
            return "NO"

    return "YES" if len(stack) == 0 else "NO"
