#!/usr/bin/env python3

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        rows = ["" for i in range(min(numRows, len(s)))]

        curr_row = 0
        going_down = False

        for c in s:
            rows[curr_row] += c
            if curr_row == 0 or curr_row == numRows - 1:
                going_down = not going_down

            curr_row += 1 if going_down else -1

        return "".join(rows)

sol = Solution()
print(sol.convert("PAYPALISHIRING", 3))
