import unittest


def max_ball(v0):
    pass


class TestExercise(unittest.TestCase):
    def test_gap(self):
        self.assertEqual(max_ball(37), 10)
        self.assertEqual(max_ball(45), 13)


if __name__ == '__main__':
    unittest.main()
