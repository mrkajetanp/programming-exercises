import unittest


def find_mb(m):
    pass


class TestExercise(unittest.TestCase):
    def test_find_mb(self):
        self.assertEqual(find_mb(4183059834009), 2022)
        self.assertEqual(find_mb(24723578342962), -1)
        self.assertEqual(find_mb(135440716410000), 4824)
        self.assertEqual(find_mb(40539911473216), 3568)
        self.assertEqual(find_mb(26825883955641), 3218)


if __name__ == '__main__':
    unittest.main()
