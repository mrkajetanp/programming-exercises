import unittest


def going(n):
    result = 0

    for i in range(1, n+1):
        result += i
        result /= i

    return float(str(result)[:8])


# def going(n):
#     s = 1.0
#     for i in range(2, n + 1):
#         s = s/i + 1
#     return int(s * 1e6) / 1e6


class TestExercise(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(going(5), 1.275)
        self.assertEqual(going(6), 1.2125)
        self.assertEqual(going(7), 1.173214)
        self.assertEqual(going(8), 1.146651)


if __name__ == '__main__':
    unittest.main()
