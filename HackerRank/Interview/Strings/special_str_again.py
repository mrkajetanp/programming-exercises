#!/usr/bin/env python3

def substrCount(n, s):
    count = len(s)

    for i, char in enumerate(s):
        diff_char_idx = None

        for j in range(i+1, n):
            if char == s[j]:
                if diff_char_idx is None:
                    count += 1
                elif j - diff_char_idx == diff_char_idx - i:
                    count += 1
                    break
            else:
                if diff_char_idx is None:
                    diff_char_idx = j
                else:
                    break

    return count

print(substrCount(5, "asasd"))
print(substrCount(8, "mnonopoo"))
print(substrCount(7, "abcbaba"))
print(substrCount(4, "aaaa"))
