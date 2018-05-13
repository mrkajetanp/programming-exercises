import unittest


def fib_list(n):
    fib = [0, 1]

    for i in range(1, n):
        fib.append(fib[i] + fib[i-1])

    fib.remove(0)
    return fib


def perimeter(n):
    return sum(fib_list(n+1)) * 4


class TestExercise(unittest.TestCase):
    def test_perimeter(self):
        self.assertEqual(perimeter(5), 80)
        self.assertEqual(perimeter(7), 216)
        self.assertEqual(perimeter(20), 114624)
        self.assertEqual(perimeter(30), 14098308)


if __name__ == '__main__':
    unittest.main()
