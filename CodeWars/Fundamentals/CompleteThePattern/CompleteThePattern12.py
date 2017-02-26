import unittest


def pattern(n):
    if n < 1:
        return ""
    res = ""
    temp = list(' '*(2*n-1))

    for i in range(n):
        temp[i] = str((i+1) % 10)
        temp[2*n-2-i] = str((i+1) % 10)
        res += "".join(temp) + '\n'
        temp = list(' '*(2*n-1))

    for i in range(n-2, -1, -1):
        temp[i] = str((i+1) % 10)
        temp[2*n-2-i] = str((i+1) % 10)
        res += "".join(temp) + '\n'
        temp = list(' '*(2*n-1))

    return res[:-1]


class CompleteThePatternTest(unittest.TestCase):
    def testCompletePattern(self):
        self.assertEquals(pattern(3), "1   1\n 2 2 \n  3  \n 2 2 \n1   1")
        self.assertEquals(pattern(15), "1                           1\n 2                         2 \n  3                       3  \n   4                     4   \n    5                   5    \n     6                 6     \n      7               7      \n       8             8       \n        9           9        \n         0         0         \n          1       1          \n           2     2           \n            3   3            \n             4 4             \n              5              \n             4 4             \n            3   3            \n           2     2           \n          1       1          \n         0         0         \n        9           9        \n       8             8       \n      7               7      \n     6                 6     \n    5                   5    \n   4                     4   \n  3                       3  \n 2                         2 \n1                           1")


suite = unittest.TestLoader().loadTestsFromTestCase(CompleteThePatternTest)
unittest.TextTestRunner(verbosity=2).run(suite)

print(pattern(3))
print(pattern(5))
