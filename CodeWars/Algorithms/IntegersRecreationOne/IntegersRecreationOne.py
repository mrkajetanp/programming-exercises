import unittest
from math import sqrt, ceil

def sum_square_divisors(n):
    if n == 1:
        return n
    return sum([(i**2 + (n/i)**2) for i in
                range(1, int(ceil(sqrt(n)))) if n%i == 0])

def list_squared(m, n):
    pass

class TestExercise(unittest.TestCase):
    def test_basic(self):
        a = [(1, 1), (42, 2500), (246, 84100)]
        self.assertEqual(list_squared(1, 250), a);
        a = [(1, 1), (42, 2500), (246, 84100)]
        self.assertEqual(list_squared(1, 250), a);
        a = [(42, 2500), (246, 84100)]
        self.assertEqual(list_squared(42, 250), a);
        a = []
        self.assertEqual(list_squared(300, 600), a);

if __name__ == '__main__':
    unittest.main()

