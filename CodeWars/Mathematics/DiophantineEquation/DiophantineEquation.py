import unittest


def sol_equa(n):
    pass


class TestExercise(unittest.TestCase):
    def test_sol_equa(self):
        self.assertEqual(sol_equa(5), [[3, 1]])
        self.assertEqual(sol_equa(20), [[6, 2]])
        self.assertEqual(sol_equa(9001), [[4501, 2250]])
        self.assertEqual(sol_equa(9004), [[2252, 1125]])


if __name__ == '__main__':
    unittest.main()
