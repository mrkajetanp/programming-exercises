import unittest
from math import sqrt


def n_prime(n):
    result = 0

    for i in range(2, int(sqrt(n))+1):
        while n % i == 0:
            result += 1
            n /= i

    return (result + 1) if n > 1 else result


def count_kprimes(k, start, end):
    return [x for x in range(start, end+1) if n_prime(x) == k]


def puzzle(s):
    pass


class TestExercise(unittest.TestCase):
    def test_count_kprimes(self):
        a = [1020, 1026, 1032, 1044, 1050, 1053, 1064, 1072, 1092, 1100]
        self.assertEqual(count_kprimes(5, 1000, 1100), a)
        a = []
        self.assertEqual(count_kprimes(12, 100000, 100100), a)

    def test_puzzle(self):
        self.assertEqual(puzzle(100), 0)
        self.assertEqual(puzzle(144), 0)
        self.assertEqual(puzzle(143), 2)


if __name__ == '__main__':
    unittest.main()
