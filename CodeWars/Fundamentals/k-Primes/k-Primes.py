import unittest


def count_kprimes(k, start, nd):
    pass


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
