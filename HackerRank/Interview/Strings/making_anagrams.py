#!/usr/bin/env python3

def makeAnagram(a, b):
    chars_a = [c for c in a]
    chars_b = [c for c in b]

    for c in a:
        if c in chars_b:
            chars_a.remove(c)
            chars_b.remove(c)

    return len(chars_a) + len(chars_b)

print(makeAnagram("cde", "abc"))
