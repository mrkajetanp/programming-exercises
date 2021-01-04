class Solution:
    def isHappy(self, n: int) -> bool:

        def sum_of_squares(n):
            return sum([int(x)**2 for x in str(n)])

        seen = set()

        while n not in seen:
            seen.add(n)
            n = sum_of_squares(n)
            if n == 1:
                return True

        return False
