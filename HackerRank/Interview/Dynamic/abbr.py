#!/usr/bin/env python3

from collections import Counter

def abbreviation(a, b):
    a = [c for c in reversed(a)]
    b = [c for c in reversed(b)]

    idx = 0
    while a[idx] == b[idx]:
        idx += 1

    a = a[idx:]
    b = b[idx:]

    print(a, b)

    return

print(abbreviation("aBbdD", "BBD"))
# print(abbreviation("daBcd", "ABC"))
# print(abbreviation("Pi", "P"))
# print(abbreviation("AbCdE", "AFE"))
# print(abbreviation("LLZOSYAMQRMBTZXTQMQcKGLR", "LLZOSYAMBTZXMQKLR"))
# print(abbreviation("MGYXKOVSMAHKOLAZZKWXKS", "MGXKOVSAHKOLZKKDP"))
# print(abbreviation("bBccC", "BBC"))
# print(abbreviation("HYDNoeuoeubee", "HYDN"))
