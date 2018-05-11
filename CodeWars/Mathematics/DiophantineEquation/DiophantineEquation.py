import unittest
from math import sqrt, floor


def sol_equa(n):
    result = []

    for i in range(1, int(floor(sqrt(n)))+1):
        if n % i == 0:
            j = n/i

            if (j-i) % 4 == 0:
                result.append([(i+j)/2, (j-i)/4])

    return result


class TestExercise(unittest.TestCase):
    def test_sol_equa(self):
        self.assertEqual(sol_equa(5), [[3, 1]])
        self.assertEqual(sol_equa(20), [[6, 2]])
        self.assertEqual(sol_equa(9001), [[4501, 2250]])
        self.assertEqual(sol_equa(9004), [[2252, 1125]])


if __name__ == '__main__':
    unittest.main()
