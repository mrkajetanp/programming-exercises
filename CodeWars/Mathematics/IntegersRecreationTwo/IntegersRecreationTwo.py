import unittest


def prod2sum(a, b, c, d):
    result = []
    n = (a**2 + b**2) * (c**2 + d**2)
    sums = [abs(a*c+b*d), abs(a*d+b*c), abs(a*c-b*d), abs(a*d-b*c)]

    for i in sums:
        for j in sums:
            if i**2 + j**2 == n:
                pair = [min(i, j), max(i, j)]

                if pair not in result:
                    result.append(pair)

    return sorted(result)


class TestExercise(unittest.TestCase):
    def test_prod2sum(self):
        self.assertEqual(prod2sum(1, 2, 1, 3), [[1, 7], [5, 5]])
        self.assertEqual(prod2sum(2, 3, 4, 5), [[2, 23], [7, 22]])
        self.assertEqual(prod2sum(1, 2, 2, 3), [[1, 8], [4, 7]])
        self.assertEqual(prod2sum(1, 1, 3, 5), [[2, 8]])
        self.assertEqual(prod2sum(10, 11, 12, 13), [[2, 263], [23, 262]])


if __name__ == '__main__':
    unittest.main()
