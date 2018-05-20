import unittest


def tankvol(h, d, vt):
    pass


class TestExercise(unittest.TestCase):
    def test_tank_vol(self):
        self.assertEqual(tankvol(5, 7, 3848), 2940)
        self.assertEqual(tankvol(5, 7, 3848), 2940)
        self.assertEqual(tankvol(2, 7, 3848), 907)
        self.assertEqual(tankvol(2, 8, 5026), 982)
        self.assertEqual(tankvol(4, 9, 6361), 2731)


if __name__ == '__main__':
    unittest.main()
