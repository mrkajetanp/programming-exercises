import unittest


def going(n):
    result = 0

    for i in range(1, n+1):
        result += i
        result /= i

    return float(str(result)[:8])


class TestExercise(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(going(5), 1.275)
        self.assertEqual(going(6), 1.2125)
        self.assertEqual(going(7), 1.173214)
        self.assertEqual(going(8), 1.146651)


if __name__ == '__main__':
    unittest.main()
