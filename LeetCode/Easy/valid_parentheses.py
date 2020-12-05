#!/usr/bin/env python
# -*- coding: utf-8 -*-

def is_valid(s: str) -> bool:
    bracket_pairs = {')': '(', '}': '{', ']': '['}
    stack = []

    for c in s:
        if c in bracket_pairs:
            if not stack or stack.pop() != bracket_pairs[c]:
                return False
        else:
            stack.append(c)
    return not stack
