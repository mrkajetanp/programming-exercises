#/usr/bin/env python3

class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        minus = x < 0
        x = abs(x)
        MIN_INT = -2**31
        MAX_INT = 2**31 - 1

        while x != 0:
            pop = x % 10
            x //= 10
            if rev > MAX_INT / 10 or rev == MAX_INT / 10 and pop > 7:
                return 0
            if rev < MIN_INT / 10 or rev == MIN_INT / 10 and pop < -8:
                return 0
            rev = rev * 10 + pop

        return rev if not minus else -rev
