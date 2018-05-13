import unittest


def perimeter(n):
    pass


class TestExercise(unittest.TestCase):
    def test_perimeter(self):
        self.assertEqual(perimeter(5), 80)
        self.assertEqual(perimeter(7), 216)
        self.assertEqual(perimeter(20), 114624)
        self.assertEqual(perimeter(30), 14098308)


if __name__ == '__main__':
    unittest.main()
