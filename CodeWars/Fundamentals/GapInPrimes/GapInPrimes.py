import unittest
from math import sqrt


def is_prime(n):
    return all([n % i != 0 for i in range(2, int(sqrt(n))+1)])


def gap(g, m, n):
    pass


class TestExercise(unittest.TestCase):
    def test_gap(self):
        self.assertEqual(gap(2, 100, 110), [101, 103])
        self.assertEqual(gap(4, 100, 110), [103, 107])
        self.assertEqual(gap(6, 100, 110), None)
        self.assertEqual(gap(8, 300, 400), [359, 367])


if __name__ == '__main__':
    unittest.main()
